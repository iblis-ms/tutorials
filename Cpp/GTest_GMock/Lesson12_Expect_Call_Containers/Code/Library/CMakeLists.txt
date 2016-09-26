cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

# Sets source files
set(SRC "Implementation/Library.cpp")

# Creates the library, which will be tested
add_library(${LIBRARY_NAME} ${SRC})

# Sets an interface of the library
target_include_directories(${LIBRARY_NAME} PUBLIC Interface)

# Sets C++11 support
set_property(TARGET ${LIBRARY_NAME} PROPERTY CXX_STANDARD 11)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock
