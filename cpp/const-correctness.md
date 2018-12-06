When people talk about *const-correctness* they usually speak about const methods and const referencee/pointers to methods.

`Const` method can not modify class members or call non-const methods on `this` (essentially, you have `const this` pointer in such methods).
When you have const ref/pointer, you cannot call non-const methods on it.

The message is:

Put `const` whenever possible as it shows clearly how the method or object reference can be used, and makes compile time guarantee, that an object state will not be mutated, when it is not supposed to be mutated.
As all the `const` stuff is checked at compile time, it brings no additional runtime overhead.

Its still possible to change the class member field in const function, using the `mutable` keyword.

```
Declaring the const-ness of a parameter is just another form of type safety. It is almost as if a const std::string, for example, is a different class than an ordinary std::string, since the const variant is missing the various mutative operations in the non-const variant (e.g., you can imagine that a const std::string simply doesn't have an assignment operator).

If you find ordinary type safety helps you get systems correct (it does; especially in large systems), you'll find const correctness helps also.
```

http://www.dietmar-kuehl.de/mirror/c++-faq/const-correctness.html
