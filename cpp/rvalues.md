## Rvalues, Move Semantics & Perfect Forwarding

http://thbecker.net/articles/rvalue_references/section_01.html

Lvalues is something we can take address of.
Rvalues is not an lvalues (usually temp objects, return values from functions/type conversion results)

Rvalues allow to implement 

### Move Semantics

It a quick and cheap way to construct one object from another (usuaaly by just moving everythin from temp object to the object which is being constructed and resetting the temp object)

### Perfect forwarding

A way to pass params to a ctor or another fubction without any overhead (passing by value).

Without rvalue refs there were 2 problems
1. If you pass by value you get additional copying
2. If you pass by ref you have to create overloads for all combinations of const/non-const params.

```
template<typename T>
void foo(T&&);

Here, the following apply:
When foo is called on an lvalue of type A, then T resolves to A& and hence, by the reference collapsing rules above, the argument type effectively becomes A&.
When foo is called on an rvalue of type A, then T resolves to A, and hence the argument type becomes A&&.
```

So with rvalues refs you can pass lvalues and rvalues and everything will work just fine.

std::move 
1. Casts its param to rvalue
2. Hides the name of variable so that compiler could use move semantics (Because if rvalue has a name - its now an lvalue).

https://www.linkedin.com/learning/c-plus-plus-move-semantics
