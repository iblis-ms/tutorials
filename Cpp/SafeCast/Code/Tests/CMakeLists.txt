cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

include(conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

# Sets the test target name
set(TEST_TARGET_NAME SafeCastTest) 

# Sets source files
set(SRC "Code/Test.cpp")

# Creates the test program
add_executable(${TEST_TARGET_NAME} ${SRC})

# Sets the C++14 support
set_property(TARGET ${TEST_TARGET_NAME} PROPERTY CXX_STANDARD 14)

# Links the test program with GTest
# Links the binary
target_link_libraries(${TEST_TARGET_NAME} PRIVATE ${CONAN_LIBS} PRIVATE ${LIBRARY_NAME})
# Links the headers directory
target_include_directories(${TEST_TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIRS})

# Adds PThread library, because it is required by GTest.
set_target_properties(${TEST_TARGET_NAME} PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)

# Adds the test program to CMake test
add_test(NAME ${TEST_TARGET_NAME} COMMAND ${TEST_TARGET_NAME})

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock
