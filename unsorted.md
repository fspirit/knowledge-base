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

Where x is a state vector (like coordintes, angles and derivatives of those)

Which have a solution for x at timestep t like

x(t) = e<sup>At</sup>x(0)

By looking matrix's A eigenvalues we can see if system is stable or unstable (state values go to inf).
But in control theory we introduce term `Bu`, where `u` is input and `B` is some vector that describes how `u` affects the 
state. 

`x' = Ax + Bu`

If we say that `u=-Kx`, that the system description is now

`x' = Ax - BKx` and
`x' = (A - BK)x`,

which essentially then change system's dynamics.






