I have an idea for our DBW and waypoint_updater mode

[9:13] 
Waypoints should be on (max speed) or off (0) - DONE

[9:14] 
If the car should be accelerating the waypoint velocity should be at max
If the car should be stopping the waypoint velocity should be zero for the calculated stopping distance

[9:14] 
The DBW can use a PID controller for steering

[9:15] 
For accelerating and decelerating:

[9:15] 
If waypoint has velocity greater than car’s accelerate by an amount 
If waypoint has velocity less than car’s accelerate (-) by an amount
These amounts can be constant or dynamic. If dynamic they would change over time up to a max.

[9:16] 
I got this from the #team-leads channel 
“In response, we adjusted our deceleration value to a max of 0.25 and acceleration to a max of 0.025. 


For braking, we use the percentage mode and (using dbw_test.py) - HOW TO USE DBW_TEST?

**Check to which /topics and which msg types bag is using**

```
rosbag info $path_to_bag
```


```
roslaunch twist_controller dbw_test.launch
```

Nodes loaded
- rosbag with msgs to /vehicle/*cmd remapped to /actual/*cmd
- dbw_test.py
- include twist_controller dbw.launch, which loads
	- dbw_node.py with lots of params


**But in general processes launched with roslaunch have a working directory in $ROS_HOME and if $ROS_HOME not set `~/.ros` is set as a working dir for roslaunch nodes.**

