cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

# add_subdirectory allows CMake to enter to a given directory.
# This directory MUST contain CMakeLists.txt file.
#
# NOTE: The order of folders is important.
add_subdirectory(HeaderOnlyLibrary)
add_subdirectory(SharedLibrary)
add_subdirectory(StaticLibrary)
add_subdirectory(Executable)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake
