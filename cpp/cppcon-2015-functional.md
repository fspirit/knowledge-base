## Functional Stuff

### std::invoke (C++ 17)

Can call:
- Function objects (functors, lambdas, function pointers)=
- PMFs, pointers to member functions
```
invoke(pmf, obj, rest...) is (obj.*pmf)(rest...)
invoke(pmf, ptr, rest...) is ((*ptr).*pmf)(rest...)

```
- PMDs, pointers to member data
```
invoke(pmd, obj) is obj.*pmd
invoke(pmd, ptr) is (*ptr).*pmd
```

Things that use invoke:
- std::function
- reference_wrapper
- bind()
- mem_fn()

Recom: 
- Use invoke in generic code, like algorithms lib

### std::result_of (C++ 11)

Recom: 
- Dont use it
- Use decltype, decltype(auto), auto

### std::mem_fn (C++ 11)

It helps to convert pointers to member functions to function objects.
So, you can pass PMFs to std::algorithms, for instance.

Cons:
- Breaks down as soon as PMFs are pointers to virtual or templated functions.
- Affects performance

Recom:
- Avoid mem_fn
- Use lambdas instead

### std::bind (C++ 11)

Creates partial function invocations. Captures function into function obeject and binds (assignes some predefined value) one or more of its params. See functional programming.

```
const vector<int> v{1, 3, 4, 16}

cout << count_if(v.begin(), v.end(), bind(less<>, _1. 10)) << endl;
```

Cons:
- As it has members its hard to optimize it away (same problem as with mem_fn)
- Bound args passed as lvalues (not good for unique_ptr and etc)

Recom:
- Avoid bind
- Use lambdas instead

### reference_wrapper (C++ 11)

You can use it in places where objects are passed by value and still use references.
Use std::ref to create reference_wrapper.












