## Constexpr

`const` guarantees that a program does not change an object’s value. However, const does not guarantee which type of initialization the object undergoes.

Consider:

```
const int mx = numeric_limits<int>::max();  // OK: runtime initialization
```

The function max() merely returns a literal value. However, because the initializer is a function call, mx undergoes runtime initialization. Therefore, you cannot use it as a constant expression:

```
int arr[mx];  // error: “constant expression required”
```

`constexpr` is a new C++11 keyword that rids you of the need to create macros and hardcoded literals. It also guarantees, under certain conditions, that objects undergo static initialization. It controls the evaluation time of an expression. By enforcing compile-time evaluation of its expression, constexpr lets you define true constant expressions that are crucial for time-critical applications, system programming, templates, and generally speaking, in any code that relies on compile-time constants.

Tips from the book Effective Modern C++ by Scott Meyers about constexpr:

- `constexpr` objects are const and are initialized with values known during compilation;
- `constexpr` functions produce compile-time results when called with arguments whose values are known during compilation;
- `constexpr` objects and functions may be used in a wider range of contexts than non-constexpr objects and functions;
- `constexpr` is part of an object’s or function’s interface.

According to book of "The C++ Programming Language 4th Editon" by Bjarne Stroustrup
• `const`: meaning roughly ‘‘I promise not to change this value’’ (§7.5). This is used primarily to specify interfaces, so that data can be passed to functions without fear of it being modified.
The compiler enforces the promise made by const.
• `constexpr`: meaning roughly ‘‘to be evaluated at compile time’’ (§10.4). This is used primarily to specify constants
