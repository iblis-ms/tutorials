CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR) # minimal version should be required
                                                  # FATAL_ERROR - error if you have older 
                                                  # version

project(CMakeLesson3) # project name. It defines a variable $PROJECT_NAME

set(SOURCE_FILES Source/main.cpp Source/Class.cpp) # variable SOURCE_FILES definition in current scope (this file).


add_executable(${PROJECT_NAME} ${SOURCE_FILES}) # creates executable file.
                                                # The first argument is a name.
                                                # Next arguments are source files.
                                                # Arguments can be passing via variables.

target_include_directories(${PROJECT_NAME} PRIVATE Headers) # Header files are in Headers folder.
# The first argument is a target created by add_executable or add_library.
# Options:
# PUBLIC - public headers that contain public API of library
# PRIVATE - private headers that cannot be used for linking
# INTERFACE - public headers of header only library 
#
# You can pass more than one folder. Each folder should be have a proper option before path.
#
# All PUBLIC and INTERFACES paths are stored in property: INTERFACE_SYSTEM_INCLUDE_DIRECTORIES
#
# IMPORTANT: This function must be written AFTER add_library/add_executable to pass target.

# DON'T use include_directories, because it adds header directories to all targets in file, but you can provide
# more than one target in one CMakeLists.txt file.


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
