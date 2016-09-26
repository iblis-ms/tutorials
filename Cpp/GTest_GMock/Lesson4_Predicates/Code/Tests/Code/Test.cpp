// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

#include <iostream>
#include <cstring>

// adds GTest header
#include <gtest/gtest.h>

using namespace ::testing;

class CMyTestCase : public Test
{
};

////////////////////// PREDICATES
// There are ASSERT_xxx and EXPECT_xxx predicates. I will show you only ASSERT_xxx type, but you can change it to EXPECT_xxx
// to change fatal errors in case failure to errors.

bool isABCString(const char* aTxt)
{
  return std::strcmp("abc", aTxt) == 0;
}

TEST_F(CMyTestCase, testCase_1ArgPredicate)
{
  // The 1st argument is predicate - address of function that will be called to test if the 2nd argument is correct.
  // A function's name is also its address, so 'isABCString' function will be called. It should return true if 
  // the value is correct. It has to have one argument with the same type as the 2nd argument of ASSERT_PRED_1.
  ASSERT_PRED1(isABCString, CLibrary::getCStyleString());
}

//////////////////////

TEST_F(CMyTestCase, testCase_1ArgPredicateL)
{
  // You can also use C++11 lambda.
  ASSERT_PRED1([](const char* aTxt)
  {
    return std::strcmp("abc", aTxt) == 0;}, CLibrary::getCStyleString());
}

/////////////////////

bool isString(const char* aTxt1, const char* aTxt2)
{
  return std::strcmp(aTxt1, aTxt2) == 0;
}

TEST_F(CMyTestCase, testCase_2ArgsPredicate)
{
  // You can use predicates with more than one argument, but you have to use ASSERT_PREDx. The 'x' is the number of
  // of arguments. The order of arguments of ASSERT_PREDx is also the order of predicate function arguments.
  // Here you have 2 arguments and the predicate method 'isString' also has 2 arguments.
  ASSERT_PRED2(isString, "abc", CLibrary::getCStyleString());
}

/////////////////////

AssertionResult isABCStringWithResult(const char* aTxt)
{
  if (std::strcmp("abc", aTxt) == 0)
  {
    // It will be displayed for ASSERT_FALSE - when success isn't expected.
    return AssertionSuccess() << aTxt << " is abc";
  }
  else
  {
    // It will be displayed for ASSERT_TRUE - when failure isn't expected.
    return AssertionFailure() << aTxt << " is NOT abc";
  }
}

TEST_F(CMyTestCase, testCase_1ArgPredicateWithResult_FAIL)
{
  // Predicates can return AssertResult object, which can be easily used to write a proper description.
  ASSERT_FALSE(isABCStringWithResult(CLibrary::getCStyleString())); // Check failure message.
      /*
       Failure message:
       [ RUN      ] CMyTestCase.testCase_1ArgPredicateWithResult
       /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson4_Predicates/Code/Tests/Code/Test.cpp:84: Failure
       Value of: isABCStringWithResult(CLibrary::getCStyleString())
       Actual: true (abc is abc)
       Expected: false
       [  FAILED  ] CMyTestCase.testCase_1ArgPredicateWithResult (0 ms)
       */

}

/////////////////////

//! \brief Predicate with formatter. Note: you can provide more arguments.
//! \param aExp1Name Name of the 1st variable
//! \param aExpr2Name Name of the 2nd variable
//! \param aExpr1Value Value of the 1st variable
//! \param aExpr2Value Value of the 2nd variable
//! \return Result object.
AssertionResult myPredicateFormatter(
    const char* aExp1Name,
    const char* aExpr2Name,
    const char* aExpr1Value,
    const char* aExpr2Value)
{
  if (std::strcmp(aExpr1Value, aExpr2Value) == 0)
  {
    // It will be displayed for ASSERT_FALSE - when success isn't expected.
    return AssertionSuccess() << "variable named: " << aExp1Name << "=" << aExpr1Value << " is equal to variable "
        << aExpr2Name << "=" << aExpr2Value;
  }
  else
  {
    // It will be displayed for ASSERT_TRUE - when failure isn't expected.
    return AssertionFailure() << "variable named: " << aExp1Name << "=" << aExpr1Value << " is NOT equal to variable "
        << aExpr2Name << "=" << aExpr2Value;
  }
}

TEST_F(CMyTestCase, testCase_predicateWithFormatter_FAIL)
{
  // You can write your predicates with a proper formatter. It is useful when checked objects don't have overloaded operator<< for std::ostream.
  ASSERT_PRED_FORMAT2(myPredicateFormatter, "abc1", CLibrary::getCStyleString()); // Check failure message.
      /*
       Failure message:
       [ RUN      ] CMyTestCase.testCase_predicateWithFormatter
       /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson4_Predicates/Code/Tests/Code/Test.cpp:123: Failure
       variable named: "abc1"=abc1 is NOT equal to variable CLibrary::getCStyleString()=abc
       [  FAILED  ] CMyTestCase.testCase_predicateWithFormatter (0 ms)
       */
}

