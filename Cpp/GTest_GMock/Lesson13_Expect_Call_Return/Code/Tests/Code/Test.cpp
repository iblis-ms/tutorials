// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include <iostream>

// adds GTest header
#include <gtest/gtest.h>
// adds GMock header
#include <gmock/gmock.h>

#include "Library.h"

// to easily use GTest and GMock objects and methods.
using namespace ::testing;

////////////////////////////////////////// MOCK

//! \brief This mock class contains methods that return by value, by reference and by r-value reference.
class IListenerMock : public IListener // IListener is a interface class
{
public:

  MOCK_METHOD0(functionReturnInt, int());
  MOCK_METHOD0(functionReturnIntRef, const int&());
  MOCK_METHOD0(functionReturnIntRValue, int&&());

};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Return_value)
{
  IListenerMock listener;
  CLibrary library { &listener };

  // The simplest approach - return by value
  const int value = 10;
  // WillOnce(action) - It means that this method should be called exactly one time. 
  //                   It brackets should be placed an action that will be invoke when method will be called.
  // Return(x) - The mocked method will return 'x' - by default by value.
  EXPECT_CALL(listener, functionReturnInt()).WillOnce(Return(value));

  const int actual = library.call_functionReturnInt();

  ASSERT_EQ(value, actual);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Return_reference)
{
  IListenerMock listener;
  CLibrary library { &listener };

  const int value = 10;
  // ByRef(x) - it means that mocked method should return a reference to 'x'.
  EXPECT_CALL(listener, functionReturnInt()).WillOnce(Return(ByRef(value)));

  const int& actual = library.call_functionReturnInt();

  ASSERT_EQ(value, actual);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Return_R_value_reference)
{
  IListenerMock listener;
  CLibrary library { &listener };

  const int value = 10;
  // ByRef(x) - It means that mocked method should return a r-valeu reference to 'x'.
  //            There types (like std::future<T>) that can only be moved, because copy is forbidden.
  EXPECT_CALL(listener, functionReturnInt()).WillOnce(Return(ByMove(value)));

  int&& actual = library.call_functionReturnInt();
  // we cannot used 'value' because it was moved.
  ASSERT_EQ(10, actual);
}
