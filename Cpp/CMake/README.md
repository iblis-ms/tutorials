#CMake tutorial.

This tutorial contains several lessons, that show the fundamental functionality of CMake. CMake has very unfriendly documentation. There is one official example, that doesn't describe a basic functionality of CMake. 
All following lessons were tested with CMake version 3.5.2. Please download this version version of CMake. Ubuntu provides older version of CMake via its repository. CMake is changing, it could be not backward compatible.

#What is CMake?
CMake is a program, that provides a system independent build system. CMake is usually used to with C/C++ project. However it can be used with non C like projects as well. CMake doesn't compile nor link. It only calls programs as compiler, linker. Therefore you can use CMake with GCC, Clang, Visual C++, etc. For Linux operating system CMake generates Makefile files, that will be used to compile. CMake is responsible for a proper including header files, source files. CMake helps to easily link static and shared libraries. CMake can be also used for creating environment for compiling or installing. Therefore CMake can call programs, operate on files/directories (moving, copying). CMake can also generate project for IDEs like Eclipse, Xcode or Visual Studio.

#How to read this tutorial?
Tutorial is splitted into several lessons. Each lesson has its own README.md that shows what is the target of lesson. However all CMake code related to the topic of lesson are documented inside CMakeLists.txt or *.cmake files. Each lesson has also run.sh script to build programs.

#Table of content
1. [First, one source file executable program under CMake control](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson1_HelloWorld)
2. [Multi files program. Displaying messages.](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson2_Multi_Files_Appliciation)
3. [Multi folder program. Public, private headers - API.](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson3_Subdirectories)
4. [Header only library, static library, shared library - Fundamentals of CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson4_Libraries)
5. [Target properties - (i. e. C++11 support)](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson5_Properties)
6. [Install](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson6_Installation)
7. [List structure](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson7_List)
8. [If, while, etc.](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson8_Control_Instructions)
9. [Functions and macros](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson9_Macro_Functions)
10. [Define and passing CMake arguments](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson10_Define)
11. [Custom command and custom target](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson11_Custom_Command)
12. [Find packages](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson12_Find_Package)
13. [Testing](https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake/Lesson13_Testing)

#Author
Marcin Serwach
