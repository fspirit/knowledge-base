## C++ compilers on MacOS


### GCC/g++

GCC is a big bag of software. The typical process, as I understand it, is for a GCC frontend to lex and parse the code, convert to GCC's internal Register Transfer Language, and then for a backend to write out native code.

So one typical flow is: C code ---> GCC's C frontend ---> RTL ---> GCC's x86 backend ---> x86 machine code.

GCC supports several frontends: C, C++, Java, Objective C, Go, and Fortran.

GCC supports several backends: 32-bit x86, 64-bit x86, little endian ARM, big endian ARM, MIPS, SPARC, PowerPC, etc.

Frontends convert text to RTL, backends convert RTL to machine code of some sort.

### LLVM/clang

LLVM is a middle-layer machine-agnostic computation representation, similar in concept to GCC's RTL. It is its own type system and instruction set, an Intermediate Form (IF). If I understand correctly, LLVM's IF is richer, more expressive, and much more flexible than GCC's RTL, which serves many benefits. Compiler front-ends for LLVM for many different languages can all compile down to LLVM IF. This can be used for 'conventional' languages like C, C++, Java, etc, but it can also be used for 'unconventional' programming tasks like GPU shaders.

LLVM is, perhaps, two things then. LLVM-the-machine, which is the type system and instruction set, which is probably better referred to as "LLVM IF"; and LLVM-the-API, which is software for manipulating code in the LLVM IF, such as the LLVM JIT compiler, or perhaps the LLVM x86 machine code backend.

Clang is a front-end for LLVM that processes C-family languages: C, C++, Objective C, Objective C++. Clang converts C/C++/etc to LLVM IF, LLVM performs optimizations on the IF, and the LLVM x86 backend writes out x86 machine code for execution.

Despite the name, LLVM is not a Virtual Machine in the traditional sense - it is a computation model and representation that lends itself well to the task of manipulating code.

LLVMs popularity comes from the fact that it is a fully reified compiler API. It can be used for performing static analysis on code ("does this code ever accidentally use uninitialized memory?"), optimization, code parsing (such as for building IDEs). GCC's internals are very highly coupled, and so using GCC in this manner is incredibly difficult. One example is that GCC's frontends perform some optimizations during parsing, so it is not possible to always get a perfect representation of the code-as-typed, for eg, reporting errors and performing squiggle-line syntax highlighting, because some information might have been lost.

As I understand it, Clang preserves the unoptimized parsed syntax, making it possible for 3rd party tools to use its output and equate transformations back to the original text, most notably, Clang's error messages are much more helpful because they can highlight the exact part of the line that is in question.

