### Why use nullptr?

If we have two functions like foo(int i) and foo(void* ptr) and ptr can be null for some reasons, than using 0 or NULL will give compiler hardtimes and most probably foo(int i) will be called. In the same time nullptr is a pointer (as it has type std::nullptr_t implicitly converts to all raw pointer types, and that’s what makes nullptr act as if it were a pointer of all types) and overload resolution with come down to foo(void *ptr).

So, using nullptr instead of 0 or NULL avoids overload resolution surprises.

Properties of nullptr:
Property 1: It has it’s own type std::nullptr_t and
Property 2: It is implicitly convertible and comparable to any pointer type or pointer-to-member type but
Property 3: It is not implicitly convertible or comparable to integral types, except for bool.

#### Using smart pointers like if (!ptr)

Smart pointers like unique_ptr and shared_ptr have implicit conversions to bool that checks the internal pointer against nullptr, so the second is preferred in those cases, because the intent is well understood.

#### Using ptr, that can be nullptr like if (!ptr)

```
A prvalue of arithmetic, unscoped enumeration, pointer, or pointer to member type can be converted to a prvalue of type bool. A zero value, null pointer value, or null member pointer value is converted to false; any other value is converted to true. A prvalue of type std::nullptr_t can be converted to a prvalue of type bool; the resulting value is false.
```