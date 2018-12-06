### Dynamic

- Inheritance
- Virtual functions (pure virtual functions)
- Vtables for every class in hierarchy
- Runtime overhead of using vtable to get the function pointer

```
class A
{
public 
    virtual std::string foo() = 0;
}

class B: public A
{
public 
    std::string  foo() { return "bla" };
}

class C: public A
{
public:
    std::string  foo() { return "london is a capital of great britain" };
}
```

### Static

- Templates
- Compile time code generation
- Possible template code bloat

```
class B
{
public 
    public foo() { return "bla" };
}

class C
{
public 
    std::string foo() { return "london is a capital of great britain" };
}

template<typename T>
std::string call_foo(const T& t)
{
    return t.foo();
}

```