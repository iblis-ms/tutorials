# CMake tutorial - lesson 3 - Libraries
This is the fundamental lesson. You will compile: a static library, a shared library and a header only library. After that executable program that uses these libraries. Header only library isn't exactly library, because it only contains header files without binary artifacts. It is typical type of library for template classes artifacts.

Run command to generates project files (assumed that you are in sibling directory of Code directory):
```
cmake ../Code
```
For Windows you need to export symbols:
```
cmake -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE ..\code
```

To compile:
```
cmake --build .
```


# Target of this lesson
After this lesson you will know how to:
- compile static, shared and header only libraries,
- provide an external API of libraries,
- split an external API with internal header files,
- how to link targets.


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake)*
