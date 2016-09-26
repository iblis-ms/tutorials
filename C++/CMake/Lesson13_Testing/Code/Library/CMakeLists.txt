project(Library)

add_library(${PROJECT_NAME} Implementation/Library.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC Interface PRIVATE Headers)

#################### ADD TEST
# GTest & GMock are here: https://github.com/google/googletest
# You can download it as a zip file and extract the content.
# You should have a structure like:
#
# googletest-master
#      |- googlemock 
#             ...
#      |- googletest
#             ...
#      |- CMakeLists.txt
#
# Note that there is CMakeLists.txt. So you can use CMake to compile it.
# Create a new folder 'Output' and enter to it:
#
# mkdir Output && cd Output
#
# Compile GTest and GMock:
#
# cmake ../ && make
#
# Install GTest and GMock in your machine: 
#
# sudo make install
#
# Now CMake would find GTest and GMock

# finding GTest is provided by CMake module
find_package(GTest)

# To find GMock I added CMake module: Code/CMakeSupport/FindGMock.cmake downloaded from https://github.com/triglav/cmake-findgmock.
# To find GMock, CMake is looking for FindGMock.cmake - prefix Find and extension cmake. 
# CMake is checking location in CMAKE_MODULE_PATH to find this file. 
# Therefore we need to update it. 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${${PROJECT_NAME}_SOURCE_DIR}/../CMakeSupport/")
find_package(GMock) 

# Sets a test target name
set(TEST_TARGET_NAME ${PROJECT_NAME}_test) 

# Creates a test program
add_executable(${TEST_TARGET_NAME} Tests/Test.cpp)

# Links the test program with GTest & GMock
target_link_libraries(${TEST_TARGET_NAME} PRIVATE ${GTEST_BOTH_LIBRARIES} PRIVATE ${GMOCK_LIBRARIES} PRIVATE ${PROJECT_NAME} )
target_include_directories(${TEST_TARGET_NAME} PRIVATE ${GTEST_INCLUDE_DIRS} PRIVATE ${GMOCK_INCLUDE_DIRS} PRIVATE Interface PRIVATE Headers)
# GTest requires pthread, so add it.
set_target_properties(${TEST_TARGET_NAME} PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)

# Adds a test program to a CMake test
add_test(NAME ${TEST_TARGET_NAME} COMMAND ${TEST_TARGET_NAME})


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake
