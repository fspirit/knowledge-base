### What representations for path can be used for local path generation? (Name two most popular ones and are their pro/cons)

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

**TODO**: Why is it pro?

Con:

Curvature is not that easily calculated from x, y and it derivatives

K(u) = x'(u)y''(u) - y'(u)x''(u) / (x'(u)<sup>2</sup> + y'(u)<sup>2</sup>)<sup>3/2</sup>

So solution can be discontiniuos in K. It hard to properly constrain curvature (set proper constraints through x and y).

*Qubic Spiral*

Describe change in heading &theta; and curvature K.

K(u) = &alpha;<sub>3</sub>s<sup>3</sup> + &alpha;<sub>2</sub>s<sup>2</sup> + ... + &alpha;<sub>0</sub>\
&theta;(s) = &theta;<sub>0</sub> + integral(0 to s) of K(s)ds (as K(s) = Q'(s)) = \
    &theta;<sub>0</sub> + &alpha;<sub>3</sub>u<sup>4</sup>/4 + &alpha;<sub>2</sub>u<sup>3</sup>/3 + ... + &alpha;<sub>0</sub>


**TODO**: Finish

### What is optimization problem formulation for local path generation? What is input/output? What is the difference between hard & soft constraints? Which objective functions can be used?

### Which libs can be used to solve local path generation optimization problem?

### What is velocity profile for a path? How can it be generated? (Name several methods) What is input/output for that process?

Velocity profile is an array of velocity values, one for each timestemp.
Essentially wnat we have as an input is target velocity, which can be defined by different factors (road signs, other object, speed limits).

So once we have that target velocity we need to reach it a hold into it.

Approaches to reach target velocity would be 
- Linearly go for it and reach it at the end of time horizon.
- Linearly go for it and reach it at as soon as possible (co.

### What is Minkowski sum? Draw an example with 2 shapes. How is it used in motion planning? Draw an example of some workspace.




