# CMake tutorial - lesson 4 - Properties
Properties are related to many things (see: [CMake properties](https://CMake.org/CMake/help/v3.0/manual/CMake-properties.7.html "CMake properties")). You can provide target specific properties i. e. compilation flags.

Run command to generates project files (assumed that you are in sibling directory of Code directory):
```
cmake ../Code
```
To compile:
```
cmake --build .
```
NOTE: This project will not compile. See comments in Code\StaticLibrary\CMakeLists.txt. There are specified flags to treat warnings as error and there is unused variable which causes warning (error).

# Target of this lesson
After this lesson you will know how to:
- set and get properties.


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake](https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake)*
