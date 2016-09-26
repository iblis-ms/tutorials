// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <string>

#include <gtest/gtest_prod.h> // include GTest header that can be used in production code

class CLibrary
{
private:
  // all methods are private (I know that it is unecessary for class)

  //! \brief Adds 10 to given value.
  //! \param aValue Value to which 10 will be added.
  //! \return Return value.
  static int add10(int aValue);

// The macro that creates a friendship declaration between this class and the test class.
  FRIEND_TEST(CTestCase, test);
};

#endif // LIBRARY_H_
