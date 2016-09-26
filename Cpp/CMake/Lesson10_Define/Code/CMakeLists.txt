cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

project(CMakeLesson10)

add_executable(${PROJECT_NAME} main.cpp)

#### SETTING C #DEFINE

# See https://cmake.org/cmake/help/v3.0/command/target_compile_definitions.html
# target_compile_definitions allows to specify if 'define' should be passed further.
# PRIVATE - 'define' will NOT be passed further
# INTERFACE - 'define' will be passed further
# PUBLIC - 'define' will be passed further
target_compile_definitions(${PROJECT_NAME} PRIVATE DEFINE_VALUE=123 OPTION1=1)

#### PASSING CMAKE ARGUMENT

# Passing a argument to CMake
#
# See https://cmake.org/cmake/help/v3.0/command/option.html
# option(<option_variable> help string describing option" [initial value])
# <option_variable> - variable name 
# [initial value] - value if variable is not set
# 
# Calling and passing 123 value: 
# cmake path -DMY_CMAKE_ARGUMENT=123 
# See -D prefix. 
option(MY_CMAKE_ARGUMENT "CMake argument description" ON)

message(STATUS "MY_CMAKE_ARGUMENT=${MY_CMAKE_ARGUMENT}")


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake
