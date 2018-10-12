### Virtual Functions

http://yosefk.com/c++fqa/inheritance-virtual.html

#### What's the difference between how virtual and non-virtual member functions are called?

Non-virtual functions are resolved at compile time. virtual functions are resolved at run time.

The compiler must generate some code to do the run-time resolution. This code must be able to look at an object and find the version of the function defined by the class of the object. This is usually done by creating a table of virtual functions for each class having them (the "vtable"). All objects of the class have an implicitly generated member pointer (the "vptr"), initialized to point to the class vtable by all constructors.

To implement a virtual function call, the compiler generates code similar to that it would produce from the C expression 
`(*p->vptr->func_ptr)`. That is, it dereferences the object pointer to fetch the vptr, then fetches the function pointer from a fixed offset, then calls the function through the pointer.
The exact cost depends on complicated stuff like page faults, multiple inheritance, etc.

#### When should my destructor be virtual?

The rule of thumb is - when you have a virtual function. Strictly speaking, you need it when you want someone to be able to derive classes from your class, create objects with new, and delete them via pointers to a base class.

FQA: The situations when the rule of thumb is not good enough were not reported on our planet. Use this rule of thumb, if only to suppress compiler warnings. Too bad the C++ compiler doesn't use the rule silently itself - it could simply make the destructor virtual in these cases.

### Pointers & Reference Differences, when to use each

http://yosefk.com/c++fqa/ref.html
- Prefer references to raw pointers to pass arguments to the functions
- References can not be null (cool!)

### What is RAI? How it works?

We make wrappers for resources (heap memory, locks, db conncetions, network) and then we acquire this resources in wrappers constructors and release them on objects' destruction.
