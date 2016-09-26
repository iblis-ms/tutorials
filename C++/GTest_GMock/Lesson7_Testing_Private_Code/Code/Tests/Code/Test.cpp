// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

// TEST/TEST_F creates a class with name, which is a mix of name given in brackets.
// In Library.h you can find: FRIEND_TEST(CTestCase, test);
// This is a macro, that creates a friendship between CLibrary class and this test class.
// Therefore this test class has access to private methods and values.
TEST(CTestCase, test)
{
  ASSERT_EQ(15, CLibrary::add10(5));
}

