# CMake tutorial - lesson 1 - the simplest case.
This lesson shows how to use CMake program to build HelloWorld application. This is the simplest case. CMake generates build files i. e.: Makefile files on Linux platform, so after that you should run make command to compile project. The list of genarators is available on https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html. CMake reads CMakeLists.txt, therefore you most of CMake code is in CMakeLists.txt files.

Run command to generates project files (assumed that you are in sibling directory of Code directory):
```
cmake ../Code
```
The folder Code contains CMakeLists.txt file. The command above will generate Visual Studio project on Windows, Makefiles on Linux - these default generators. You can specify generators i. e.: for Visual Studio 2017:
```
cmake -G "Visual Studio 15 2017" ../Code
```

To compile:
```
cmake --build .
```
Note that you have to provide path to already generated project, i. e.: for generated Visual Studio project it runs Visual Studio compiler.

You can specify C++ and C compiler. CMake reads paths to compilers from environment variables:
- CC - path to C compiler
- CXX - path to C++ compiler

# Target of this lesson
After this lesson you will know how to:
- prepare a build system to build the HelloWorld program,
- write a comment inside CMake code.

*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake)*
