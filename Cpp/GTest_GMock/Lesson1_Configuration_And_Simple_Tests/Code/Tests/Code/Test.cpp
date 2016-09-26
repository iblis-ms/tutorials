// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"
#include <iostream>

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

// GTest has TEST macro. In the brackets you have to write a name of a test case and a test name.
// GTest creates a class whose name will be a concatenation of values given in brackets.
// The content of TEST is a test body.
TEST(TestCase, testCase_fatal_fail_FAIL)
{
  // The fatal error stops executing a test.
  FAIL()<< "This is a optional description for the fatal error";
  std::cout << "This will not be displayed, because the fatal error was before. \n";
  /*
   [ RUN      ] TestCase.testCase_fatal_fail
   /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson1_Configuration_And_Simple_Tests/Code/Tests/Code/Test.cpp:14: Failure <----- The path will be different on your machine.
   Failed
   This is a optional description for the fatal error <------ Here is the optional message
   [  FAILED  ] TestCase.testCase1_fatal_fail (0 ms)
   */
}

TEST(TestCase, testCase_nonfatal_fail_FAIL)
{
  // The nonfatal error doesn't stop executing test.
  ADD_FAILURE()<< "This is a optional description for the nonfatal error";
  std::cout << "This will be displayed, because there wasn't be a fatal error before.\n";
}

///////////////////////////////////////////////////////////////////////////////////
// GTest has several types of asserts: ASSERT_xxx and EXPECT_xxx.
// ASSERT_xxx - if assert is failing, the test will stop with failure immediately - there will be a fatal error. 
// EXPECT_xxx - if assert is failing, the test will fail, but not immediately - there will be a nonfatal error.
//
// I will show you the ASSERT_xxx option only. You can use the EXPECT_xxx option for all cases - you just need to change ASSERT prefix with EXPECT.
// The ASSERT_xxx option is usually used.

/////////////////////////////////////// SIMPLE ASSERT /////////////////////////////
TEST(TestCase, testCase_ASSERT_simple)
{
  // Test data
  const int expectedResult = 15;
  const int actualResult = CLibrary::add10(5);

  // Checks if 'actualResult' is equal with 'expectedResult'. If they aren't equal, the test will fail with fatal error.
  // expectedResult == actualResult 
  ASSERT_EQ(expectedResult, actualResult)<< "The optional description that will be displayed if this test failed";

  ASSERT_EQ(expectedResult, actualResult); // as above but without the description.

  // ASSERT_GT is: 20 > actualResult
  ASSERT_GT(20, actualResult);

  // ASSERT_GE is: 20 >= actualResult
  ASSERT_GE(20, actualResult);
  ASSERT_GE(expectedResult, actualResult);

  // ASSERT_LT is: 0 < actualResult
  ASSERT_LT(0, actualResult);

  // ASSERT_LE is: 0 <= actualResult
  ASSERT_LE(0, actualResult);
  ASSERT_LE(expectedResult, actualResult);

  // Test if the value in bracket is true.
  ASSERT_TRUE(expectedResult == actualResult);

  // Test if the value in bracket is false.
  ASSERT_FALSE(expectedResult != actualResult);

  const int nearExpectedResult = 13;
  const int near = 2;
  // you can also provide interval: (nearExpectedResult - near) <= actualResult <= (nearExpectedResult + near)
  ASSERT_NEAR(nearExpectedResult, actualResult, near);
}

///////////////////////////////// SIMPLE ASSERT FOR STRING ////////////////////////
TEST(TestCase, testCase_ASSERT_string)
{
  // Test data
  const char* expectedResult = "abc";
  const char* actualResult = CLibrary::getCStyleString();

  // Compares C-style strings (case sensitivity)
  ASSERT_STREQ(expectedResult, actualResult);

  const char* notExpectedResult = "def";
  // Compares C-style strings - if there are NOT equal. (case sensitivity)
  ASSERT_STRNE(notExpectedResult, actualResult);

  const char* caseIndependentExpectedResult = "AbC";
  // Compares C-style strings (case insensitivity)
  ASSERT_STRCASEEQ(caseIndependentExpectedResult, actualResult);

  const char* notCaseIndependentExpectedResult = "DeF";
  // Compares C-style strings - if there are NOT equal. (case insensitivity)
  ASSERT_STRCASENE(notCaseIndependentExpectedResult, actualResult);
}

///////////////////////////////// SIMPLE ASSERT FOR DOUBLE ////////////////////////
TEST(TestCase, testCase_ASSERT_doubles)
{
  // Test data
  const double expectedResult = 1;
  // sum of 0.1 is not equal 1, because of binary representation of double and float.
  double actualResult = 0;
  for (int i = 0; i < 10; ++i)
  {
    actualResult += 0.1;
  }
  // Checks if 10 * 0.1 != 1. 
  ASSERT_NE(expectedResult, actualResult);
  // It should be ASSERT_DOUBLE_EQ used instead of ASSERT_EQ.
  ASSERT_DOUBLE_EQ(expectedResult, actualResult);

  // There is also ASSERT_DOUBLE_NE - to check if is not equal 

  // For float type, you should use ASSERT_FLOAT_EQ, ASSERT_FLOAT_NE.
}

/////////////////////////////// DISABLE TEST
TEST(TestCase, DISABLED_testCase_ASSERT_doubles) // this test will not run. However it will be shown: YOU HAVE 1 DISABLED TEST
{
  FAIL();
}

