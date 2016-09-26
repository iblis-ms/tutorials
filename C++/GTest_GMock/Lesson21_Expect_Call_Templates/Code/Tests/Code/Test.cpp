// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include <iostream>

// adds GTest header
#include <gtest/gtest.h>
// adds GMock header
#include <gmock/gmock.h>

#include "Library.h"

// to easily use GTest and GMock objects and methods.
using namespace ::testing;

////////////////////////////////////////// MOCK

// To mock template class you need to create a template mock class.
template<typename T>
class IListenerMock : public IListener<T> // IListener is a interface class
{
public:
  // Note that macro ends with T.
  MOCK_METHOD1_T(functionArg1, void(T)); 
  MOCK_METHOD0_T(functionReturn, T());
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Template)
{
  // EXPECT_CALL with whole related methods are exactly the same.
  IListenerMock<int> listenerMock;
  CLibrary<int> library{&listenerMock};
  const int returnValue = 11;

  EXPECT_CALL(listenerMock, functionArg1(1)).Times(1);
  EXPECT_CALL(listenerMock, functionReturn()).WillOnce(Return(returnValue));

  library.call_functionArg1(1);
  const int result = library.call_functionReturn();
  ASSERT_EQ(result, returnValue);

}

