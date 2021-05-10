# C++20 Playground

A toy repository dedicated to exploring the C++20 new features as they're gradually getting wider support by the compilers.
Note, as of now it does not seem to work out of the box with any compiler of the big three.

## GCC

```bash
mkdir -p build
g++ -o build/cpp20-playground -std=c++20 -fmodules-ts main.cpp
```

With GCC 11.1.1 on Fedora 34 this fails complaining about missing compiled module file `gcm.cache/./usr/include/c++/11/cstdlib.gcm`.

## Clang

```bash
mkdir -p build
clang++ -o build/cpp20-playground -std=c++20 main.cpp
```

With Clang 12.0.0 on Fedora 34 this fails because the headers "cannot be imported because they are not known to be header units".

## MSVC

This one is difficult. Microsoft is being themselves and use different syntax for importing modules (`import std.core;`).
