## PID

PID control takes cross track error (**CTE** for short), which is a difference between current location nd location on a reference trajectory, and outputs a steering angle or a throttle or a brake value.

### P-Control

**P** stands for **Proportional** that means that output value (for instance, steering angle) is prorportional to a CTE

```python

steering_angle = - tau_p * CTE
```

where `tau_s` is a parameter which regulates how strong to react to a CTE value, minus is here indicates that when CTE is positive a steering angle must be negative, according to this model.
The less is CTE - the less is controller's output value.

![p-control](/control/p-control.JPG)

The problem with P-control is that it overshoots target reference trajectory, because it can not react quickly when CTE approaches 0, output value (steering angle) still stays non-zero and a car overshoots. The larger is the distance a car travels between steering angle changes the larger is overshoot. 
Usually that is it starts occilating around reference trajectory.

#### Open questions
- Maybe if we make tau_p very small and update steering angle frequently, we will be able to resctict overshooting to min, but in this case approaching to target trajectory can take forever.

### PD-Control

**D** stands for **Derivative**. We add another term, when calculating output - a rate of change (a derivative) of CTE with respect to time.

```python
steering_angle = - tau_p * CTE - tau_d * (current_cte - prev_cte) / time_delta
```

The effect of **D** term: when CTE decreases, for example from 1 to 0.75, a diff `(current_cte - prev_cte)` will be `-0.25`, if we assume `time_delta` to be `1`, then

```
steering_angle = -tau_p * 0.75 - tau_d * -0.25 = -tau_p * 0.75 + tau_d * 0.25 
``` 

so second term makes total output less, making steering softer.
The larger is CTE change - the larger will be **D** term.

### PID-Control

There can be a systematic bias, for instance, when front wheels of the car are rotated to the side from the start (a mechanical problem). In this case, the car will not react properly to steering. For instance, if the driver steers to the right, car drives to the left. A human driver will adopt and start steering harder, but PD-Control will not react properly and the result will be driving with a  




