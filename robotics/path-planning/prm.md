### Probabilistic Roadmap (PRM/PRM*)

### Sources

- https://theclassytim.medium.com/robotic-path-planning-prm-prm-b4c64b1f5acb
- https://journals.sagepub.com/doi/abs/10.1177/0278364911406761
- http://lavalle.pl/planning/ch5.pdf

### Overview

Instead of generating a fresh graph with each desired path, PRM builds a single roadmap that aims to cover a good portion of the Cfree area. 
A shortest path planning algorithm is then used to navigate across the roadmap. 
The point of PRM is important to note. PRM itself does not find a path, but builds a practical graph for traveling through a region. 
Once the roadmap is constructed a desired search algorithm — Dijkstra’s algorithm, A*, Bellman-Ford — is used to determine an optimal path.

So PRM generates the graph and then another algo is used to navigate through it.

### Basic PRM

```
PRM Pseudo Code

G(V,E) = Null //Initialize a graph as empty
limit = n //number of nodes to make graph out of
Rad = r //radius of neighborhoods 
For itr in 0...limit:
    Xnew = RandomPosition()
    Xnearest = Near(G(V,E),Xnew,Rad) //find all nodes within a Rad
    Xnearest = sort(Xnearest) //sort by increasing distance
    For node in Xnearest:
        if not ConnectedComp(Xnew,node) and not Obstacle(Xnew,node):
            G(V,E) += {Xnew,node} //add edge and node to graph
            Xnew.comp += node.comp//add Xnew to connected component
Return G(V,E)
```

New node is randomly sampled, then its connected to nodes within Rad to it, making sure edge does not go through obstacle and that new node and considered
for connection node do not already belong to the same connected component, thus reducing number of edges.

PRM-based path planner generates very square path going from one component to another.


### PRM*

Key ideas here is to shrink (exponentially depending on number of already generated nodes) radius where we consider nodes for 
connection to newly created node and dropping the requirement that they should not already belong to the same connected component.

Which means we generate more edges - longer graph generation time.

It creates denser graph with more edges and generates smoother and straighter paths.

```
G(V,E) = Null //Initialize a graph as empty
limit = n //number of nodes to make graph out of
For itr in 0...limit:
    Xnew = RandomPosition()
    Rad = yprm*(log(itr)/(itr))^(1/d)
    Xnearest = Near(G(V,E),Xnew,Rad) //find all nodes within a Rad
    For node in Xnearest:
        if not Obstacle(Xnew,node):
            G(V,E) += {Xnew,node}connected component
Return G(V,E)
```

### Important 

PRM suits situations where the enviroment is static, no moving obstacles. 
Otherwise we will have to regenerate the graph (or parts of it) every time step - which will be inefficient.
Better use RRT or other methods with dynamic obstacles.
