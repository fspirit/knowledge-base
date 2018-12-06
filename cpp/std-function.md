## Why do we need it

std::function can wrap any callable object: function pointer, functor, lamdbda fuction.

Especially its useful when we wnat to pass lambda (which type we dont't know) to a function, without making it a template function.

For example, we could do

```
auto f = [](int i){ return i + 2; }

template<typename F>
void foo(const F& f);

foo(f); // Type autodeduction works here
```

But template functions have several cons: 
- The code must be exposed in header files
- Compiling time increases
- Template functions can't be virtual

With std::function we can do the following

```
auto f = [](int i){ return i + 2; }

void foo(std::function<int(int)> f);

foo(f); 
```

std::function receives instance of lambda's type and stores its copy inside. It has implecit conversion from callable types.

### Performance overhead of std::function

- Creates several copies of passed object
- Puts a copy of callable object on the heap, if the object is large enough

Can we deal with this cons?

- We can pass a reference wrapper, instead of a real instance (std::cref, std::ref)
- We can kepp the callable tiny enough, so it wont be copied to the heap