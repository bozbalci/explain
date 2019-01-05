# explain

explain is an _industrial grade_ compiler for [XPLN]. It is built using `flex`, `bison` and LLVM.

[XPLN]: https://github.com/bozsahin/ceng444/blob/master/project-material/xpl-specs-fall2018.pdf

## Features

* Error reporting
* Optimizations
* Pretty-printer for the abstract syntax tree
* Emitting LLVM intermediate representation
* Native code generation for X86, X86-64, PowerPC, PowerPC-64, ARM, MIPS and many more architectures

## Planned features

* Source locations in the AST for better error reporting
* Support for the DWARF debugging standard
* More aggressive optimizations including function inlining
* Just-in-time compilation and interpreter support

## Requirements

The project was built using the following tooling, earlier versions are not tested:

* CMake >= 3.13
* C++ compiler with C++14 core language support (gcc >= 5.1 or Clang >= 3.5)
* Boost >= 1.60
* `flex` >= 2.5
* `bison` >= 3.2
* LLVM >= 7.0.0

## Build

    $ mkdir build
    $ cd build
    $ cmake .. && make

On macOS, the CMake script will issue a warning about the installed Bison version. Make sure that Bison 3.2 (or greater)
is used when building this project.

## Usage

After compiling, install `explain` somewhere in your path. To see all available options, invoke `explain` with `--help`.

    $ explain --help
    explain, the industrial grade XPLN compiler

    General options:
      -h [ --help ]          print this help message and exit
      -v [ --version ]       print version and exit
      -i [ --input ] arg     input file
      -o [ --output ] arg    output file
    
    Debugging options:
      --trace-scan           run scanner in debug mode
      --trace-parse          run parser in debug mode
    
    Stage selection options:
      --emit-ast             emit AST in pretty-printed form
      --emit-llvm            emit LLVM representation only
      -c                     generate object file
    
    If no stage selection option is specified, then every stage will be run and
    the linker is run to produce an executable.

## Example

### convert.xpln: Convert °F to °C

This example is located at `examples/convert.xpln`.

    fun convert(fahr)
        return (fahr - 32) * 5 / 9;
    endf;
    
    while 1 > 0
        input fahr;
        result := convert(fahr);
        output result;
    endw;
    
    return 0;

Compile with `explain` and run:

    $ explain convert.xpln -o convert
    $ ./convert
    100
    37.777778
    ^C

If you would like to link to a separate C/C++ program, invoke `explain` with `-c` to emit an object file. Note that the
top-level function is named `xpln_main` and a function defined with the name `main` in XPLN programs is mangled (their
new name would be `xpln_mangled_main`.)

    $ explain convert.xpln -o convert.o -c
    $ cat > driver.c
    #include <stdio.h>
    
    extern double convert(double);

    int main(int argc, char **argv)
    {
        printf("100 F is approx. %.2lf C\n", convert(100.0));

        return 0;
    }
    ^D
    $ cc -o driver driver.c convert.o 
    $ ./driver
    100 F is approx. 37.78 C

If you would like to emit LLVM code, you can do so by using `--emit-llvm`. You can then use this file with other
programs in the LLVM toolchain (`llc`, `opt`, `llvm-as`, etc.) for fun and profit.

    $ explain convert.xpln -o convert.ll --emit-llvm
    $ cat convert.ll
    ; ModuleID = 'convert.xpln'
    source_filename = "convert.xpln"
    target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
    target triple = "x86_64-apple-darwin18.0.0"
    
    @ifmt = internal constant [4 x i8] c"%lf\00"
    @ofmt = internal constant [5 x i8] c"%lf\0A\00"
    
    declare i32 @scanf(i8*, ...)
    
    declare i32 @printf(i8*, ...)
    
    define double @convert(double %fahr) {
    entry:
      %0 = fadd double %fahr, -3.200000e+01
      %1 = fmul double %0, 5.000000e+00
      %2 = fdiv double %1, 9.000000e+00
      ret double %2
    }
    
    define double @xpln_main() {
    entry:
      %fahr = alloca double, align 8
      br label %cond
    
    cond:                                             ; preds = %cond, %entry
      %0 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @ifmt, i64 0, i64 0), double* nonnull %fahr)
      %fahr1 = load double, double* %fahr, align 8
      %1 = call double @convert(double %fahr1)
      %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %1)
      br label %cond
    }
 
To obtain a pretty-printed form of the abstract syntax tree after some basic manipulations, invoke `explain` with the
`--emit-ast` flag.

    $ explain examples/fibonacci.xpln -o fibonacci.ast --emit-ast
    $ cat fibonacci.ast
    fun fib
      args
        arg n
      if
        or
          ==
            n
            0
          ==
            n
            1
      then
        return
          1
      else
        return
          +
            call fib
              args
                arg
                  -
                    n
                    1
            call fib
              args
                arg
                  -
                    n
                    2
    
    fun xpln_main
      args
      return
        call fib
          args
            arg
              10
