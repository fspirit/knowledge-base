Three ways to init

```
int a(0);

int a = 5;

int a {6};
```

Uniform init works in almost all the cases.
As part of member init:

```
class A
{
private:
    int x{0};
    int z(0) // WILL NOT COMPILE
}
```

For uncopybile objects:

```
atomic<int> a{0};
atomic<int> b = 9; // WILL NOT COMPILE AS COPY CTOR IS CALLED
```