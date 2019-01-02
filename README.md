# explain

explain is an industrial grade compiler for [XPLN].

[XPLN]: https://github.com/bozsahin/ceng444/blob/master/project-material/xpl-specs-fall2018.pdf

It features:

* LALR(1) parser generated using `flex` and `bison`
* LLVM on the backend

## Requirements

The project was built using the following tooling, earlier versions are not tested:

* CMake >= 3.13
* C++ compiler with C++14 core language support (gcc >= 5.1 or Clang >= 3.5)
* flex >= 2.5
* bison >= 3.2
* LLVM >= 7.0.0

## Build

    mkdir build
    cd build
    cmake ..
    make

On macOS, the CMake script will issue a warning about the installed Bison version. Make sure that Bison 3.2 (or greater)
is used when building this project.

## Usage

Usage will be described later.