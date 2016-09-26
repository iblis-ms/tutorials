// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include <iostream>
#include <cstring>

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

//////////////////////////// TYPE INDEPENDENT TESTS

//! \brief The declaration of a method that provides a input value for tests without definition.
//!        The definition is required only for template types that will be used.
template<typename TType>
TType getInputValue();

//! \brief The method that provides a input value for tests.
//! \return The input value for type 'int'
template<>
int getInputValue()
{
  return 5;
}

//! \brief The method that provides a input value for tests.
//! \return The input value for type 'double'.
template<>
double getInputValue()
{
  return 1.3;
}
;

//! \brief The declaration of a method that provides an expected value for tests without definition.
//!        The definition is required only for template types that will be used.
template<typename TType>
TType getExpectedValue();

//! \brief The method that provides an expected value for tests.
//! \return The input value for type 'int'
template<>
int getExpectedValue()
{
  return 10;
}

//! \brief The method that provides an expected value for tests.
//! \return The input value for type 'double'.
template<>
double getExpectedValue()
{
  return 2.6;
}
;

//////////// 
//! \brief This class provides a base for type independent tests.
template<typename TType>
class CTypeIndependentTest : public Test
{
public:
  CTypeIndependentTest()
      :
        iInput { getInputValue<TType>() } // sets the input value
        ,
        iExpected { getExpectedValue<TType>() } // set the expected value
  {
  }

protected:
  TType iInput;
  TType iExpected;
};

// Provides a list of types - it is easier to use typedef/using
typedef Types<int, double> TestingTypes;
TYPED_TEST_CASE(CTypeIndependentTest, TestingTypes); // sets types

// Body of the type independent test
TYPED_TEST(CTypeIndependentTest, test){
ASSERT_EQ(this->iInput * 2, this->iExpected);
}

/* Output:
 [----------] 1 test from CTypeIndependentTest/0, where TypeParam = int    <----- type
 [ RUN      ] CTypeIndependentTest/0.test
 [       OK ] CTypeIndependentTest/0.test (0 ms)
 [----------] 1 test from CTypeIndependentTest/0 (0 ms total)

 [----------] 1 test from CTypeIndependentTest/1, where TypeParam = double    <----- type
 [ RUN      ] CTypeIndependentTest/1.test
 [       OK ] CTypeIndependentTest/1.test (0 ms)
 [----------] 1 test from CTypeIndependentTest/1 (0 ms total)
 */
