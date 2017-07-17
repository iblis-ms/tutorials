# CMake tutorial - lesson 1 - the simplest case.
This lesson shows how to use CMake program to build HelloWorld application. This is the simplest case. CMake generates build files i. e.: Makefile files on Linux platform, so after that you should run make command to compile project. The list of genarators is available on https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html. 

Linux, OSX: Run command to generates Makefile files (assumed that you are in sibling directory of Code directory):
```
cmake ../Code
```
To compile:
```
make
```

# Target of this lesson
After this lesson you will know how to:
- prepare a build system to build the HelloWorld program,
- write a comment inside CMake code.

*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake)*
