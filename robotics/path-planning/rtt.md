## Describe RTT/BidirectionalRTT/RTT* algorithms for path planning. Problem setup. Completeness. Running time.

### Sources

https://theclassytim.medium.com/robotic-path-planning-rrt-and-rrt-212319121378

### Setup

We have configuration space for a robot with some configurations marked as undesirable, because they will cause collision.
We have target configuration or set or target configurations.
We also have a robot motion model, which could tell us if its possible to apply certain control `u` to a robot to go
from A to B and which `u` will it then be.

### RTT Algorithm

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


Runtime:  K * nearest_neighbour_perf(K) 

Completeness: If x_goal is reachable  from starting point, algorithm will find it, given enough steps K.

Optimality: Does not guarantee shortest path.

Builds very square trees.

### Bidirectional RTT

Starts building trees from intial and goal positions simulteneously.

Pros:
- converges faster.

### RTT*

When adding new node to the tree it checks weather some nodes in proximity to new node can be made its chidren to lower their costs.
The cost of the node is the distance from parent node.

```
Rad = r
G(V,E) // Graph containing edges and vertices
For itr in range(0…n)
    Xnew = RandomPosition()
    If Obstacle(Xnew) == True, try again
    Xnearest = Nearest(G(V,E),Xnew)
    Cost(Xnew) = Distance(Xnew,Xnearest)
    Xbest,Xneighbors = findNeighbors(G(V,E),Xnew,Rad)
    Link = Chain(Xnew,Xbest)
    For x’ in Xneighbors
        If Cost(Xnew) + Distance(Xnew,x’) < Cost(x’)
            Cost(x’) = Cost(Xnew)+Distance(Xnew,x’)
            Parent(x’) = Xnew
            G += {Xnew,x’}
    G += Link 
Return G
```

Pros:
- gives optimality guarantees
- builds shorter / straighter paths

Cons:
- is slower than RTT because of additional collision checking when rewiring the nodes
