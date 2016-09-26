// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include "Library.h"
#include "gtest/gtest.h"

using namespace ::testing;

class CLibrary_Test : public Test
{
};

TEST_F(CLibrary_Test, False)
{
  ASSERT_TRUE(false);
}

TEST_F(CLibrary_Test, True)
{
  ASSERT_TRUE(true);
}

