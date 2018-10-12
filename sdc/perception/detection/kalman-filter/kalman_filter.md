## Kalman Filter

Can be used to 
1. Observing an unmeasureble state, for instance observing an internal temparature of engine using some math model and external temp.
2. When observing state directly, but when both process and measurement models include noise, can be used to combine predicted and measured state and give an estimate with a lower covariance.

### Example for self-driving cars:

We have a system state, for instance location (x, y)

We assume that a ral world process is defined (for car its a car motion model) like this (its a linear process):

```
x[t] = A * x[t-1] + B * u[t] + w
``` 

Where `x` is a system state, `A` is a system transition matrix, which defines how do we go from state x[t-1] to x[t], u[t] is some system input, like
controls (wheel angel, throttle) or fuel flow or whatever.
And `w` is a noise, which is usually assumed to be gaussian, `w ~ N(0, Q)`.
Usually we dont know exact `A`, `B` and `w` for a real world process.

Next, the measurement model, we know that measurement `y[t]` comes from

```
y[t] = C * x[t] + v
```

Where `x[t]` is car's state and `v` is measurement noise (`v ~ N(0, R)`) and `C` is a measurement function which transforms systems state to a measurement.
If we measure system's state directly, then C is 1.

Okay, then we define some A and B and w from physics, experiments or whatever for a motion model and get some estimated  `x_[t]`.
Next we receive some `y[t]` from a real world and now we combine predicted `x[t]` with measured `y[t]` to receive a more accurate estimate.

**Very important assumption: the state of a model is assumed to be gaussion.**

Okay that first step is the prediction, we get predicted state `x_[t]` and its covariance `P_[t]`

```
x_[t] = A * x[t-1] + B * u[t]
P_[t] = A * P[t-1] * A.T + Q
```

Where `P_` is a state covariance matrix, which is updated with process noise `Q`.

Next, we need to estimate a Kalman gain, which purpose is to create a balance between a predicted amd a measured states according to their variances:

```
K = P_[t] * C.T / (C * P_[t] * C.T + R)
x[t] = x_[t] + K(y[t] - C * x_[t])
```

So, if R -> 0, K = C.T, than y[t] is trusted 100% and `x[t] = y[t]`.
Or if P -> 0, than K = 0 and x[t] = x_[t].

Last step is we update `P`
```
P[t] = (I - K*C) * P
```

Now we have new state `x[t]` and `P[t]` and are waiting for a new measurement to come.

### Resources:
1. https://www.mathworks.com/videos/series/understanding-kalman-filters.html