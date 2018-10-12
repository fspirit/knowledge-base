## Bayes Localization Filter

Localization - a process, during which a robot (vehicle) position on the map is determined.

Problems:
1. Robot measurements are inexact and are prone to noise.
2. Robot motion is inexact and is prone to noise.

That is, when a robot reports, that it senses red color, we can not be 100% sure the red color is there. We introduce probabilistic distributions, like
P (There is RED | Robot sees RED), P (There is RED | Robot sees GREEN).

That is, if we command robot to move 1 meter right, we cannot be 100% sure, that after motion robot will be exaclty 1m right.

The state of a robot (vehicle) is represented by set a random variables. For instance, if we have x & y coords, the state is (X, Y), both X and Y have are R.V. and have expectation and variance. Expectations of our R.Vs is where we believe our robot is most likely is at the moment. Variances give us understanding of how precise our belief is.

We constanly update params of these R.V., when we receive new measurement and move.

Wheh we receive new measurement we use Bayes Rule to update our state. We take current state as a Prior, estimate Evidence as a likelihood of 
new mesurement given that prior and get new state as Prior * Evidence (normalized).

```
P ( x | z ) = eta * P ( z | x ) * P ( x ) or
P ( new state | new measurement) = eta * (observation model) * (motion model)
```

Motion Model -> predict step.
Observation Model -> update step.

### Markov Assumption

Markov assumption says that next state  depends only on current state and not on any preceding ones. Thats is - current state already includes information about all the previous states, measurements and controls.


**The Bayes Localization Filter Markov Localization** is a general framework for recursive state estimation.
That means this framework allow us to use the previous state (state at t-1) to estimate a new state (state at t) using only current observations
and controls (observations and control at t), rather than the entire data history (data from 0:t).

### Motion Model

We use bicycle model.

If yaw' is const than

```
x1 = x0 + v * dt * cos(yaw0)
y1 = y0 + v * dt * sin(yaw0)
yaw1 = yaw0 (no yaw change)
```

if yaw' is not const then

```
x1 = x0 + v / yaw' * ( sin(yaw0 + yaw' * dt) - sin(yaw0))
y1 = y0 + v / yaw' * ( cos(yaw0) - cos(yaw0 + yaw' * dt))
yaw1 = yaw0 + yaw' * dt
```


Another way is to use **Motion Sensor Data (Odometry)**

```
x1 = x0 + number_od_wheel_turns * cos(yaw0) * wheel_circumference
y1 = y0 + number_od_wheel_turns * sin(yaw0) * wheel_circumference

```

Wet road and bumps can affect the precision of this model.


#### Note On Frames Of Reference

*Localization* - uses both map coords (landmarks) and vehicle coords (measurements). The task is to find the position of a car in map coords.
*Perception* / Sensor Fusion - can use only vehicle coords (measurements are in vehicle coords).





