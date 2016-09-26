// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include <iostream>

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

class CMyTestCase1 : public Test
{
};

TEST_F(CMyTestCase1, testCase_fail)
{
  FAIL();
}

TEST_F(CMyTestCase1, testCase_success)
{
  ASSERT_TRUE(true);
}

////////

class CMyTestCase2 : public Test
{
};

TEST_F(CMyTestCase2, testCase_fail)
{
  FAIL();
}

TEST_F(CMyTestCase2, testCase_success)
{
  ASSERT_TRUE(true);
}
