// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"

// adds GTest header
#include <gtest/gtest.h>

using namespace ::testing;

class CMyTestCase : public Test
{
};

TEST_F(CMyTestCase, testCase_exceptions)
{
  // You can check type of the exception.
  // The first argument is a function call, the second one is a type of the exception.
  ASSERT_THROW(CLibrary::throwException(), std::runtime_error);

  // You can also check if throw an exception without testing a type of the exception.
  ASSERT_ANY_THROW(CLibrary::throwException());

  // You can test if method doesn't throw an exception.
  ASSERT_NO_THROW(CLibrary::notThrowException());
}

TEST_F(CMyTestCase, testCase_deathTest)
{
  const char* errorMessage = "123";
  // You can test if a method exits program with a proper error message. 
  // The 1st argument is a method call, the 2nd is a regular expression of error message. 
  // In this case 'deathTest_exitWithMessage' writes '123' error message. 
  ASSERT_DEATH(CLibrary::deathTest_exitWithMessage(errorMessage), errorMessage);

  // It is similar to above example, but it also checks if the exit code is correct.
  ASSERT_EXIT(CLibrary::deathTest_normalExit(errorMessage), ExitedWithCode(EXIT_SUCCESS), errorMessage);

  // It is also similar to above example, but it checks the signal code.
  ASSERT_EXIT(CLibrary::deathTest_signalExit(errorMessage), KilledBySignal(SIGINT), errorMessage);
}
