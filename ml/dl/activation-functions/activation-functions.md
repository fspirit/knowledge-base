## Activations Functions

### Sigmoid

`1/(1+exp(-x)`

Cons:

1. If x is to large or too small - local gradient `dz/dx` is close to 0 and gradient doesnt flow backwards.
2. Output is not centered around zero (its [0; 1]), which leads to slower convergence.
2. Its expensive to compute.


### Tahn

`tahn(x)`

Is a better version of *Sigmoid*.
Is centered around zero but neuron saturation problem still remains.

### ReLu

`max(0, x)`

Gradient flows OK when x is much larger then 0. 
Learning converges 6x times faster then *Tahn* in practice.

Default choice.


### Leaky ReLu

`max(0.01x, x)`

Is not equal to  0 when x < 0. That might help with keeping the gradient flowing, but is not confirmed.


### Maxout

`max(w1*x + b, w2*x + b)`

Has twice as much params and computational complexity.

## Rules Of Thumb 

1. By default use *ReLu*.
2. Experiment with *Leaky Relu* and *Maxout*.
3. Dont expect much from *Tahn*
4. Dont use *Sigmoid*.