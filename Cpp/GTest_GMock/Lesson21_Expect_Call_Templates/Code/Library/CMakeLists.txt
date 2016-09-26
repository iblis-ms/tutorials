cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

# Creates the library, which will be tested
add_library(${LIBRARY_NAME} INTERFACE)

# Sets an interface of the library
target_include_directories(${LIBRARY_NAME} INTERFACE Interface)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock
