## What representations for path can be used for local path generation? (Name two most popular ones and are their pro/cons)

The result of optimization problem solution is the params of parametric curve **r(u)**.

**r(u)** is usually a set of parametrized functions: **a(u)**, **b(u)** and etc. Which describe how some values **a** and **b** change with a change of **u**. 
**u** is either an arc length or a unitless variable in interval [0; 1].

There are 2 main types of parametric curves used for local path planning:
1. Quintic spline
2. Quibic spiral

*Quintic spline*

Describes changes in cartesian coordinates, u is unitless thing in interval [0; 1]

x(u) = &alpha;<sub>5</sub>u<sup>5</sup> + &alpha;<sub>4</sub>u<sup>4</sup> + ... + &alpha;<sub>0</sub>\
y(u) = &beta;<sub>5</sub>u<sup>5</sup> + &beta;<sub>4</sub>u<sup>4</sup> + ... + &beta;<sub>0</sub>

Total: 12 params

Pro:

For given starting/final states (x0, y0, &theta;0, K0) and (xf, yf, &theta;f, Kf) there is a closed form solution to find
&beta;0..5 and &alpha;0..5.

y(0) = &beta;<sub>0</sub>\
x(0) = &alpha;<sub>0</sub>

y(1) = ... + y(0)\
x(1) = ... + x(0)

Con:

Curvature is not that easily calculated from x, y and it derivatives

K(u) = x'(u)y''(u) - y'(u)x''(u) / (x'(u)<sup>2</sup> + y'(u)<sup>2</sup>)<sup>3/2</sup>

So solution can be discontiniuos in K. It's hard to properly constrain curvature (set proper constraints through x and y).

*Qubic Spiral*

Describe change in heading &theta; and curvature K.

K(u) = &alpha;<sub>3</sub>s<sup>3</sup> + &alpha;<sub>2</sub>s<sup>2</sup> + ... + &alpha;<sub>0</sub>\
&theta;(s) = &theta;<sub>0</sub> + &int;(0 to s) of K(s)ds (as K(s) = &theta;'(s)) = \
    &theta;<sub>0</sub> + &alpha;<sub>3</sub>u<sup>4</sup>/4 + &alpha;<sub>2</sub>u<sup>3</sup>/3 + ... + &alpha;<sub>0</sub>
x(s) = x<sub>0</sub> + &int;(0 to s)cos(&theta;(s'))ds'
y(s) = y<sub>0</sub> + &int;(0 to s)sin(&theta;(s'))ds'

Pro:
Since a spiral is a polynomial function of curvature, the curvature value will not change extremely quickly like it can in the case of quintic splines. This means we can constrain the curvature of only a few points in the spiral and the spiral will very likely satisfy the curvature constraints across the entire curve.

Con:
The downside of using polynomial spirals is that there is no closed form solution of the position and heading of the spiral (expressions to calculate them contain integrals and thus complicated/iterative computation is required) , unlike the case in the quintic spline. Therefore, we must perform an iterative optimization in order to generate a spiral that satisfies our boundary conditions. As can be seen here, the position equations results in Fresnel integrals, which have no closed form solution. We therefore need to use numerical approximation techniques to compute the final end points of the spiral.

---

## What is optimization problem formulation for local path generation? What is input/output? What is the difference between hard & soft constraints? Which objective functions can be used?

Optimization problem consists of 

1. Cost/objective/loss functional (function that takes functions as input and returns some number), which we would wnat to minimize, i.e. f(r(u)) - means we will put different r(u) functions into f and choose the one which makes f(r(u)) minimal.

One example for cost function is function, which minimizes bending energy (curvature squared) along the whole path. Target r(u) in this case is quibic spiral.
So its &int;0 to sf of (&alpha;<sub>3</sub>s<sup>3</sup> + &alpha;<sub>2</sub>s<sup>2</sup> + ... + &alpha;<sub>0</sub>)<sup>2</sup>ds

2. Constraints. 
- Boundary conditions. For path generation we need to ensure that starting x, y, &theta;, K are equal to current values and final state (xf, yf, &theta;f, Kf) is also where we want to be. 
- Kinematic constraints. Also we need to restrict curvature K along the path. We can not check every point along the path so we take some points along the path, like 0, length/3, 2length/3, length and check that |K(u)| < K<sub>max</sub> for each of them. 
- Obstacles. x and y coordinates should not get into some areas where it's not possible to drive.

Input to problem would be values for starting state, final state, K<sub>max</sub>, obstacles locations and sizes and so on.

Output would be parametric curve r(u). To be more precise we have to choose at first exact form of r(u), like quintic spline
or quibic spiral and then opmization alorothms will select params for those curves which minimize objective functional.

The main issue we can see here has to do with the equality constraints of the final position and heading. Because equality constraints must be satisfied exactly, it is quite hard for a numerical optimizer to generate a feasible solution from an infeasible starting point which is often what is given to the optimizer for an arbitrary problem instance. 

To alleviate this issue, it is common in optimization to soft inequality constraints to improve optimizer performance. Soft constraints convert a strict constraint into a heavily penalized term in the objective function. **By heavily penalized, we mean that the constraint penalty term coefficient should be at least an order of magnitude larger than the general optimization objective.**

So we convert our loss function into **f<sub>be</sub>(&alpha;0..N) + BIG_COEEF1(x(sf) - xf) + BIG_COEEF2(y(sf) - yf) + BIG_COEEF3(&theta;(sf) - &theta;f)**

General rule is reduce number of strict equality constraints and number of params to be calculated as much as possible, allowing optimizer to find the solution faster.


---
## Which libs can be used to solve local path generation optimization problem?

Python: ScyPy

SciPy optimized library contains a generic minimize function.

```
result = sp.minimize(objective_function, x_0, method='L-BFGS-B',
					 jac=objective_jacobian, bounds=bounds,
					 options={'disp' : True})
```

Some examples of the available optimization methods include conjugate gradient, Nelder-Mead, dogleg, and BFGS. 

Examples of objective function and its jacobian (vector of partial derivatives)

```
def objective_function(x):
    return x[0]**2 + 4*x[0]*x[1]

def objective_jacobian(x):
    return np.array([2*x[0] + 4x[1], 4*x[0]])
```

As boudns param we can pass array of different types of constraints. (examples can be lokked up in SciPy documentation)


---
## What is velocity profile for a path? How can it be generated? (Name several methods) What is input/output for that process?

Velocity profile is an array of velocity values, one for each timestemp.
Essentially wnat we have as an input is target velocity, which can be defined by different factors (road signs, other object, speed limits).

So once we have that target velocity we need to reach it a hold into it.

Approaches to reach target velocity would be 
- Linearly go for it and reach it at the end of time horizon.
- Linearly go for it and reach it at as soon as possible (co.

---
## What is Minkowski sum? Draw an example with 2 shapes. How is it used in motion planning? Draw an example of some workspace.




