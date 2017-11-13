# CMake tutorial - lesson 5 - Installation
CMake can be used to specify installation process. Check build output directories.

Linux, OSX: Run command to generates Makefile files (assumed that you are in sibling directory of Code directory):
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
To install:
```
cmake --build . --target INSTALL
```


# Target of this lesson
After this lesson you will know how to:
- prepare an installation process.


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake)*
