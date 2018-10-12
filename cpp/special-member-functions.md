### Special Member Functions

#### Rule Of Three (C++ 98)

The Rule of Three states that if you declare any of a copy constructor, copy assignment operator, or destructor, you should declare all three.

#### Rule Of Zero (C++ 11)

Do not define any special function ops and they will be generated.

#### Rule Of 6 (C++ 11)

Play safe.

If you define any of
- Default constructor
- Destructor
- Copy constructor
- Copy assignment operator
- Move constructor
- Move assignment operator

Define (default, delete) all others.

#### Specific Rules

The C++11 rules governing the special member functions are thus:

**Default constructor**: Same rules as C++98. Generated only if the class contains no user-declared constructors.

**Destructor**: Essentially same rules as C++98; sole difference is that destructors are noexcept by default (see Item 14). As in C++98, virtual only if a base class destructor is virtual.

**Copy constructor**: Same runtime behavior as C++98: memberwise copy construction of non-static data members. Generated only if the class lacks a user-declared copy constructor. Deleted if the class declares a move operation. Generation of this function in a class with a user-declared copy assignment operator or destructor is deprecated.

**Copy assignment operator**: Same runtime behavior as C++98: memberwise copy assignment of non-static data members. Generated only if the class lacks a user-declared copy assignment operator. Deleted if the class declares a move operation. Generation of this function in a class with a user-declared copy constructor or destructor is deprecated.

**Move constructor** and **move assignment operator**: Each performs memberwise moving of non-static data members. Generated only if the class contains no user-declared copy operations, move operations, or destructor.