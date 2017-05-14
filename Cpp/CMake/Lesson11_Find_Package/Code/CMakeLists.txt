CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

project(CMakeLesson12) 

add_executable(${PROJECT_NAME} main.cpp)

# CMake provides find_package that you can use it to easily find libraries to link.
# You can check what packages are provided on https://CMake.org/CMake/help/v3.0/manual/CMake-modules.7.html.

###################################### BOOST #############################
# Let's start with Boost library.
# See https://CMake.org/CMake/help/v3.0/module/FindBoost.html
# You can install it: sudo apt-get install libboost-all-dev
#
# find_package arguments with a proper order
# Boost - a library name
# version - (optional) a version of Boost 
# EXACT - (optional) a exactly this version. Without EXACT newer version is allowed
# REQUIRED - (optional) with REQUIRED processing would fail if library not found
find_package(Boost 1.58.0 EXACT REQUIRED)

# Each library provides several variables, that allow to use it.
# For Boost library you can check them here: https://CMake.org/CMake/help/v3.0/module/FindBoost.html
# Some of them will be displayed below.
message(STATUS "Boost version: ${Boost_VERSION}")
message(STATUS "Boost include directories: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")

# Adds the Boost's include directory to the executable target.
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})


##################################### OPEN GL ###########################

# OpenGL module is described here: https://CMake.org/CMake/help/v3.0/module/FindOpenGL.html
find_package(OpenGL)

if (${OPENGL_FOUND})
  message(STATUS "OpenGL include directory: ${OPENGL_INCLUDE_DIR}")
  message(STATUS "OpenGL libraries: ${OPENGL_LIBRARIES}")
else ()
  message(STATUS "OpenGL not found")
endif ()


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
