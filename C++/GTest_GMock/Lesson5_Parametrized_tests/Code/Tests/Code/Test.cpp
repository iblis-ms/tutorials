// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include <iostream>
#include <cstring>
#include <tuple>

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

//////////////////////////// PARAMETRIZED TEST FOR INT

//! \brief This class is a test suite for parametrized tests of type int.
class CMyParametrizedTest : public TestWithParam<int>
{
};

// This is a test case that will be called for given parameters.
TEST_P(CMyParametrizedTest, testParam)
{
  const int& paramValue = GetParam(); // get param value
  ASSERT_LE(paramValue, 50); // simple assert
}

//////////////// values

// This creates parametrized tests with values given in the 3rd argument
INSTANTIATE_TEST_CASE_P(ParamTest_Values,// name of a test instance
    CMyParametrizedTest,// name of a test suite
    Values(1, 2, 3));// test parameters
    /* The code above will display:
     [----------] 3 tests from ParamTest_Values/CMyParametrizedTest
     [ RUN      ] ParamTest_Values/CMyParametrizedTest.testParam/0
     [       OK ] ParamTest_Values/CMyParametrizedTest.testParam/0 (0 ms)
     [ RUN      ] ParamTest_Values/CMyParametrizedTest.testParam/1
     [       OK ] ParamTest_Values/CMyParametrizedTest.testParam/1 (0 ms)
     [ RUN      ] ParamTest_Values/CMyParametrizedTest.testParam/2
     [       OK ] ParamTest_Values/CMyParametrizedTest.testParam/2 (0 ms)
     [----------] 3 tests from ParamTest_Values/CMyParametrizedTest (0 ms total)
     */

//////////////// range of values

INSTANTIATE_TEST_CASE_P(ParamTest_Range,// name of a test instance
    CMyParametrizedTest,// name of a test suite
    Range(1, 20, 3));// begin=1, end=20, step=3 (optional)

//////////////// values from STL vector or any container

const std::vector<int> paramTestValues { 1, 5, 6 }; // could be runtime calculated
INSTANTIATE_TEST_CASE_P(ParamTest_Container,// name of a test instance
    CMyParametrizedTest,// name of a test suite
    ValuesIn(paramTestValues));// any container, or begin(), end()

//////////////////////////// PARAMETRIZED TEST FOR STRING

//! \brief This class is a test suite for parametrized tests of type string.
class CMyParametrizedTest_String : public TestWithParam<const char*>
{
};

TEST_P(CMyParametrizedTest_String, testParam)
{
  const char* paramValue = GetParam(); // get param value
  ASSERT_EQ(std::strlen(paramValue), 3); // simple assert - check if all values have 3 letters.
}

INSTANTIATE_TEST_CASE_P(InstantiationName, CMyParametrizedTest_String, Values("abc", "def", "ghi"));

//////////////////////////// SPECIAL CASE FOR BOOL TYPE

//! \brief This class is parametrized tests for bool type.
class CMyParametrizedTest_Bool : public TestWithParam<bool>
{
};

// This is a test case that will be called for given parameters.
TEST_P(CMyParametrizedTest_Bool, testParam)
{
  const bool& paramValue = GetParam(); // get param value
  ASSERT_TRUE(paramValue || !paramValue); // simple assert that always pass
}

INSTANTIATE_TEST_CASE_P(ParamTest_Bool, CMyParametrizedTest_Bool, Bool()); // true/false - you can test you code with both values. The same as Values(false, true);
    /*  The code above will display:
     [----------] 2 tests from ParamTest_Bool/CMyParametrizedTest_Bool
     [ RUN      ] ParamTest_Bool/CMyParametrizedTest_Bool.testParam/0
     [       OK ] ParamTest_Bool/CMyParametrizedTest_Bool.testParam/0 (0 ms)
     [ RUN      ] ParamTest_Bool/CMyParametrizedTest_Bool.testParam/1
     [       OK ] ParamTest_Bool/CMyParametrizedTest_Bool.testParam/1 (0 ms)
     [----------] 2 tests from ParamTest_Bool/CMyParametrizedTest_Bool (0 ms total)
     */

//////////////////////////// SPECIAL CASE FOR INT TYPE - CARTESIAN - more params

//! \brief There can be more than one parameter in parametrized tests. To use more parameters, you must use std::tuple.
//!        You can use a Cartesian product to create values of parameters.
class CMyParametrizedTest_MoreParams : public TestWithParam<std::tuple<int, int>>
{
};

TEST_P(CMyParametrizedTest_MoreParams, testParam)
{
  const std::tuple<int, int>& paramValue = GetParam(); // get param value
  ASSERT_LE(std::get < 0 > (paramValue) + std::get < 1 > (paramValue), 10); // simple assert
}

INSTANTIATE_TEST_CASE_P(ParamTest_CartesianProduct, CMyParametrizedTest_MoreParams,
    Combine(Values(1, 2, 3), Values(4, 5, 6))); // There will be used a Cartesian product
