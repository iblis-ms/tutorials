# Comments start with hash
# 
# CMakeLists.txt files contain configurations of targets (executable files, libraries, custom targets, etc.).

CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR) # minimal version should be required
                                                  # FATAL_ERROR - error if you have older 
                                                  # version. You can remove FATAL_ERROR
                                                  # to not stop processing with older CMake.

project(CMakeLesson1 VERSION 1.2.3 LANGUAGES CXX) # project name - It defines a variable $PROJECT_NAME, 
                                                  # CXX - language of project; here C++ which is written as CXX
                                                  # VERSION - Major (here: 1), minor (here: 2), patch (here: 3)
 
add_executable(${PROJECT_NAME} main.cpp) # creates executable file.
                                         # The first argument is a name.
                                         # Next arguments are source files. 
                                         # You can provide more source files.

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
