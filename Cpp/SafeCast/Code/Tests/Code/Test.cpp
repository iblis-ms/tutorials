// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "SafeCast.h"
#include <iostream>

#include <gtest/gtest.h>

using namespace ::testing;

TEST(TestCase, testCase_fatal_fail_FAIL)
{
	int b = 10;
	int a = safe_cast<int>(b);
	//ASSERT_EQ(b, a);

}


