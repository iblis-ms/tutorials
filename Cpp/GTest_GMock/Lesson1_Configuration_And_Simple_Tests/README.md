#GTest & GMock tutorial - lesson 1 - GTest: CMake configuration and basic tests
CMake supports testing via CTest program. You can find CMake tutorial here: [https://github.com/iblis-ms/tutorials/tree/master/CMake](https://github.com/iblis-ms/tutorials/tree/master/CMake). You can easily use GTest framework for testing. 

GTest supports many kind of asserts, that allow you to check if your code works correctly. This lesson tests example of library. You can check how to connect your component with tests.

Run command to generates Makefile files (assumed that you are in sibling directory of Code directory):
```
cmake ../Code
```
To compile:
```
make
```
To run tests:
```
make test
```
However it doesn't show you tests for test cases and it doesn't allow you to easily run specific test case or test suite. Therefore it is better to run the test program directly.

#Target of this lesson
After this lesson you will know how to:
- configure CMake to use GTest
- write simple tests with basic GTest functionality
- disable tests

#Used methods, macros & objects
- TEST
- FAIL
- ADD_FAILURE
- ASSERT_EQ
- ASSERT_NQ
- ASSERT_GE
- ASSERT_GT
- ASSERT_NE
- ASSERT_NT
- ASSERT_TRUE
- ASSERT_FALSE
- ASSERT_NEAR
- ASSERT_STREQ
- ASSERT_STRNE
- ASSERT_STRCASEEQ
- ASSERT_STRCASENE
- ASSERT_DOUBLE_EQ
- ASSERT_FLOAT_EQ


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock)*

