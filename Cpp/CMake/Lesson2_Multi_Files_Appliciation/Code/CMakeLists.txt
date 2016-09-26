CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR) # minimal version should be required
                                                  # FATAL_ERROR - error if you have older 
                                                  # version

project(CMakeLesson2) # project name. It defines a variable $PROJECT_NAME

set(SOURCE_FILES main.cpp Class.cpp) # variable SOURCE_FILES definition in the current scope (this file).

message(STATUS "Source files: ${SOURCE_FILES}")
# The first argument can be omitted. Following options are possible:
# (none)         = Important information
# STATUS         = Incidental information: Source files: main.cpp;Class.cpp
# WARNING        = CMake Warning, continue processing
# AUTHOR_WARNING = CMake Warning (dev), continue processing
# SEND_ERROR     = CMake Error, continue processing,
#                              but skip generation
# FATAL_ERROR    = CMake Error, stop processing and generation
# DEPRECATION    = CMake Deprecation Error or Warning if variable
#                  CMAKE_ERROR_DEPRECATED or CMAKE_WARN_DEPRECATED
#                  is enabled, respectively, else no message.
#
# Note: CMake calculates expression in the argument. Therefore value of ${SOURCE_FILES}
#       will be displayed. It is similar to a shell syntax.

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) # creates executable file.
                                                # The first argument is a name.
                                                # Next arguments are source files.
                                                # Arguments can be passing via variables.

# NOTE: The header Class.h is in the same folder as source files of exec. 
#       Therefore it isn't required to provide path to it.


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
