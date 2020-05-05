## Control Bootcamp

### What is the problems control theory tries to solve? What are types of control possible?

Control theory tries to get desired behavior out of dynamical system (pendulum, robot, air waves, country economy).
There can can be passive control (like windshields on a truck) which gets desired behavior without putting some energy into 
the system actively.
Or active control, where some input for a system is actively produced.
Active control is further classified into open-loop (feed-forward) and closed-loop (feedback).

### What are the advantages of feedback control over feedforward (open-loop) control?

So why feedback? Because feedforward can not handle properly the following:
1. Uncertainty (internal disturbances in the system which a not captured well by the system model)
2. Instabillity. (feedback control changes internal systems dynamincs so its more stable)
3. External disturbances. There are some external disturbancies, which are hard to predict or model correctly. But by introducing feddback, its possible to handle them.
4. Enegry efficiency. Feeback allows to input only so much energy as needed to get desired behavior.

### How can feeback change the dynamics of the system to make it more stable?

Control theory deals mostly with systems described by ordinary differential equations:

`x'(t) = Ax`

Where `x` is a state vector (like coordintes, angles and derivatives of those)

Which have a solution for `x` at timestep `t` like

x(t) = e<sup>At</sup>x(0)

By looking matrix's A eigenvalues we can see if system is stable or unstable (state values go to inf).
But in control theory we introduce term `Bu`, where `u` is input and `B` is some vector that describes how `u` affects the 
state. 

`x' = Ax + Bu`

If we say that `u=-Kx`, that the system description is now

`x' = Ax - BKx` and
`x' = (A - BK)x`,

which essentially then change system's dynamics.

### How do we transform system of ODE x'=Ax into eigenvectors coordinates and what advantages would it give? 

Put here a screen shot of notebook calc.

Eigenvectors are such vectors that

<p>
A&xi;=&lambda;&xi;
</p>

where A is a matrix and &lambda; is an eigenvalue.

The key equation here is `AT=TD` where T is a matrix of eigenvectors [&xi;0, &xi1, ... &xi;n] for A and D is a diagonal matrix 
with &lambda;0, &lambda;1, ... &lambda;n at diagonal. Coming from that is `A=TDinv(T)`.

Now, the solution for x(t) is 

x(t)=e<sup>At</sup>x(0)

e<sup>At</sup> is a complicated matter, to get values for that we use Taylor series decompotion and get:

e<sup>At</sup> = I + At + A^2t^2/2! + A^3t^3/3! ...

but once we substitute A for `A=TDinv(T)` it gets and notice that A<sup>n</sup> = TD<sup>n</sup>inv(T)

I + At + A^2t^2/2! + A^3t^3/3! ... = </br>
Tinv(T) + TDinv(T)t + TD^2inv(T)t^2/2! + ... = </br>
T[I + Dt + D^2t^2/2! +....]inv(T) = </br>
Te<sup>Dt</sup>inv(T)

and to estimate e<sup>Dt</sup> is quite easy, since D is diagonal, e<sup>Dt</sup> will also be diagonal but with 
e<sup>&lambda;0t</sup>, e<sup>&lambda;1t</sup> ... e<sup>&lambda;nt</sup> on diagonal.

Hence, once we get [T, D] = eig(A), we can easily calculate x(t) as Te<sup>Dt</sup>inv(T)x(0).










