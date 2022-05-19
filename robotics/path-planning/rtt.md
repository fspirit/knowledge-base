## Describe RTT/BidirectionalRTT/RTT* algorithms for path planning. Problem setup. Completeness. Running time.

### Sources

https://theclassytim.medium.com/robotic-path-planning-rrt-and-rrt-212319121378

### Setup

We have configuration space for a robot with some configurations marked as undesirable, because they will cause collision.
We have target configuration or set or target configurations.
We also have a robot motion model, which could tell us if its possible to apply certain control `u` to a robot to go
from A to B and which `u` will it then be.

### Algorithm

```
x_goal = region()
G = graph()
for i in (0, K):
    x_new = generate_new_random_state()
    if is_obstacle(x_new):
        continue
    x_near = nearest(G, x_new)
    G.append ( Link(x_new, x_near))
    if x_new in x_goal:
        return G
```



### Runtime

K * nearest_neighbour_perf(K) 

### Completeness

If x_goal is reachable  from starting point, algorithm will find it, given enough steps K.

### Optimality

Does not guarantee shortest path.

### Variants / Upgrades:

Bidirectional RTT (maybe separate topic) - converges faster.
RTT* - gives optimality guarantees
