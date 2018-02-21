### Common containers in C++

https://www.haroldserrano.com/blog/the-three-types-of-containers-in-c

#### Sequence (each item has a corresponding position, which depends on time of insertion, easy iteration)

- vector
- string
- deque
- list
- forward_list
- array

#### Assosiative ordered (balanced BSTs)

- set
- map
- multiset
- multimap

#### Assosiative unordered (hash tables)

- unordered_set
- unordered_multiset
- unordered_map
- unordered_multimap

#### Container adapters

- queue (deque, list)
- stack (vector, deque, list)
- priority_queue (vector, deque). Builds a heap on top.


### Implementation details

#### Vector

- Implemented as dynamic array (since - O(1) random access time), that is its size increases as we add new items to it. Usually it doubles, as it minimized the amortized insert op time (its amortized O(1)).
- When we push_back item into it, vector copies the item to the heap

#### Set

- Keeps unique items
- Usually implemented as a Red-Black Tree or AVL tree (that is self-balacing BST). All ops are O(log n)

#### List

- Doubly-linked list

#### Stack

- Linked list

#### Queue

- Linked list with tail pointer

#### Deque

#### Priority Queue

