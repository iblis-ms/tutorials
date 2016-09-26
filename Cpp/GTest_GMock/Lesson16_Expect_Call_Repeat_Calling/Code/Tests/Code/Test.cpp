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

class IListenerMock : public IListener // IListener is a interface class
{
public:

  MOCK_METHOD0(functionReturnInt, int());
  MOCK_METHOD0(functionNoReturn, void());
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_No_ReturnValue_Exactly)
{
  IListenerMock listener;
  CLibrary library { &listener };
  // Times(x) - the mocked function should called exactly 'x' times. You can also write Times(Exactly(x)).
  EXPECT_CALL(listener, functionNoReturn()).Times(3);

  library.call_functionNoReturn();
  library.call_functionNoReturn();
  library.call_functionNoReturn();
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_No_ReturnValue_AtLeast)
{
  IListenerMock listener;
  CLibrary library { &listener };
  // Times(AtLeast(x)) - the mocked function should called at least 'x' times.
  EXPECT_CALL(listener, functionNoReturn()).Times(AtLeast(2));

  // let's called 4 times.
  library.call_functionNoReturn();
  library.call_functionNoReturn();
  library.call_functionNoReturn();
  library.call_functionNoReturn();
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_No_ReturnValue_AtMost)
{
  IListenerMock listener;
  CLibrary library { &listener };
  // Times(AtMost(x)) - the mocked function should called at most 'x' times.
  EXPECT_CALL(listener, functionNoReturn()).Times(AtMost(2));

  // let's called once.
  library.call_functionNoReturn();
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_No_ReturnValue_Between)
{
  IListenerMock listener;
  CLibrary library { &listener };
  // Times(Between(x, y)) - the mocked function should called at least 'x' and at most 'y' times.
  EXPECT_CALL(listener, functionNoReturn()).Times(Between(2, 4));

  // let's called 3 times.
  library.call_functionNoReturn();
  library.call_functionNoReturn();
  library.call_functionNoReturn();
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Return_value)
{
  IListenerMock listener;
  CLibrary library { &listener };
  // You can write several WillOnce. The mocked function will return value in Return. 
  // Note that order of returned values is the same as calling.
  EXPECT_CALL(listener, functionReturnInt()).WillOnce(Return(1)).WillOnce(Return(2)).WillOnce(Return(3));

  ASSERT_EQ(library.call_functionReturnInt(), 1);
  ASSERT_EQ(library.call_functionReturnInt(), 2);
  ASSERT_EQ(library.call_functionReturnInt(), 3);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Return_value_Multiple)
{
  IListenerMock listener;
  CLibrary library { &listener };
  // Times(x).WillRepeatedly(Return(y)) - the mocked function should be called 'x' times and returns 'y' each time.
  EXPECT_CALL(listener, functionReturnInt()).Times(3).WillRepeatedly(Return(0));

  ASSERT_EQ(library.call_functionReturnInt(), 0);
  ASSERT_EQ(library.call_functionReturnInt(), 0);
  ASSERT_EQ(library.call_functionReturnInt(), 0);

  //NOTE: You cannot use Times after WillRepeatedly. WillOnce cannot also be used after WillRepeatedly.
}
