# CMake tutorial.

This tutorial contains several lessons, that show the fundamental functionality of CMake. CMake has very unfriendly documentation. There is only one official example, that doesn't describe a basic functionality of CMake, so I decided to write this tutorial. 
All following lessons were tested with CMake version 3.5.2. Please download this version version of CMake. Ubuntu provides older version of CMake via its repository. CMake is changing, it could be not backward compatible.

# What is CMake?
CMake is a program, that provides a system independent build system. CMake is usually used to with C/C++ project. However it can be used with non C like projects as well. CMake doesn't compile nor link. It only calls programs as compiler, linker. Therefore you can use CMake with GCC, Clang, Visual C++, etc. For Linux operating system CMake generates Makefile files, that will be used to compile. CMake is responsible for a proper including header files, source files. CMake helps to easily link static and shared libraries. CMake can be also used for creating environment for compiling or installing. Therefore CMake can call programs, operate on files/directories (moving, copying). CMake can also generate project for IDEs like Eclipse, Xcode or Visual Studio.

# How to read this tutorial?
Tutorial is splitted into several lessons. Each lesson has its own README.md that shows what is the target of lesson. However all CMake code related to the topic of lesson are documented inside CMakeLists.txt or *.CMake files. Each lesson has also run.sh script to build programs.

# Table of content
1. [First, one source file executable program under CMake control](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson1_HelloWorld)
2. [Multi files program. Displaying messages.](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson2_Multi_Files_Appliciation)
3. [Header only library, static library, shared library - Fundamentals of CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson3_Libraries)
4. [Target properties - (i. e. C++11 support)](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson4_Properties)
5. [Install](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson5_Installation)
6. [List structure](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson6_List)
7. [If, while, etc.](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson7_Control_Instructions)
8. [Functions and macros](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson8_Macro_Functions)
9. [Define and passing CMake arguments](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson9_Define)
10. [Custom command and custom target](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson10_Custom_Command)
11. [Find packages](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson11_Find_Package)
12. [Testing](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake/Lesson12_Testing)

# Author
Marcin Serwach
