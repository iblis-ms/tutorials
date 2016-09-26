cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

project(Cpp/GTest_GMock_Lesson11)

# Sets a library name
set(LIBRARY_NAME "LibraryToTest")

# Adds a subdirectory, which contains library
add_subdirectory(Library)

# Enables testing
enable_testing()

# Adds subdirectory with tests for the library previously added
add_subdirectory(Tests)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock


