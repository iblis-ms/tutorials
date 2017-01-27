cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

project(SafeCastProject)

# Sets a library name
set(LIBRARY_NAME "SafeCast")

# Adds a subdirectory, which contains library
add_subdirectory(Library)

# Enables testing
enable_testing()

# Adds a subdirectory with tests for the library previously added
add_subdirectory(Tests)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock


