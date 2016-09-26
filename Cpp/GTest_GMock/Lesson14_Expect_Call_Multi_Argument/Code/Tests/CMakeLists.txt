cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

# finds GTest
find_package(GTest)

# sets add folder with FindGMock.cmake that allows to use find_package(GMock).
# CMake doesn't have support for GMock, therefore we need to add modoule manually.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${${PROJECT_NAME}_SOURCE_DIR}/../../cmake/")

# finds GMock
find_package(GMock)

# Sets the test target name
set(TEST_TARGET_NAME library_test) 

# Sets source files
set(SRC "Code/Test.cpp")

# Creates the test program
add_executable(${TEST_TARGET_NAME} ${SRC})

# Sets the C++11 support
set_property(TARGET ${TEST_TARGET_NAME} PROPERTY CXX_STANDARD 11)

# Links the test program with GTest
# Links the binary
target_link_libraries(${TEST_TARGET_NAME} PRIVATE ${GTEST_BOTH_LIBRARIES} PRIVATE ${GMOCK_BOTH_LIBRARIES} PRIVATE ${LIBRARY_NAME})
# Links the headers directory
target_include_directories(${TEST_TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIRS} PRIVATE ${GMOCK_INCLUDE_DIRS})

# Adds PThread library, because it is required by GTest.
set_target_properties(${TEST_TARGET_NAME} PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)

# Adds the test program to CMake test
add_test(NAME ${TEST_TARGET_NAME} COMMAND ${TEST_TARGET_NAME})

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock
