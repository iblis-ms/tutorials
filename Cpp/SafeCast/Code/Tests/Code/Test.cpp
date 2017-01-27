// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "SafeCast.h"
#include <iostream>

#include <gtest/gtest.h>

using namespace ::testing;
using namespace ::NSafeCast;

class CSafeCastTest : public Test
{
};

TEST_F(CSafeCastTest, test)
{
	const long base = std::numeric_limits<long>::max();
	const int converted = safe_cast<int, long>(base);
	const int expected = std::numeric_limits<int>::max();
	ASSERT_EQ(converted, expected);
}
int main(int argc, char **argv) {
	InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


