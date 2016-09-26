// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include <iostream>
#include <iterator>

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

  MOCK_METHOD1(functionWithArgValue, void(int));
  MOCK_METHOD1(functionWithArgPointer, void(const int*));
  MOCK_METHOD1(functionWithArgReference, void(const int&));

  MOCK_METHOD1(functionWithArgPointerNonConst, void(int*));
  MOCK_METHOD1(functionWithArgReferenceNonConst, void(int&));
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Save_Value_Arguments)
{
  // Argument passing by value.
  // SaveArg<N>(&obj) - You can save value of a N-th argument to the given object.
  IListenerMock listener;
  CLibrary library{&listener};
  int actualValue;
  const int expectedValue = 10;
  EXPECT_CALL(listener, functionWithArgValue(_)).WillOnce(SaveArg<0>(&actualValue));
  library.call_functionWithArgValue(expectedValue);

  ASSERT_EQ(actualValue, expectedValue);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Save_Reference_Arguments)
{
  // Argument passing by reference.
  // SaveArg<N>(&obj) - You can save value of a N-th argument to the given object.
  IListenerMock listener;
  CLibrary library{&listener};
  int actualValue;
  const int expectedValue = 10;
  EXPECT_CALL(listener, functionWithArgReference(_)).WillOnce(SaveArg<0>(&actualValue));
  library.call_functionWithArgReference(expectedValue);

  ASSERT_EQ(actualValue, expectedValue);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Save_Pointer_Arguments)
{
  // Argument passing by reference.
  // SaveArgPointee<N>(&obj) - You can save value of a N-th argument to the given object.
  IListenerMock listener;
  CLibrary library{&listener};
  int actualValue;
  int* actualValuePtr = &actualValue;
  const int expectedValue = 10;
  EXPECT_CALL(listener, functionWithArgPointer(_)).WillOnce(SaveArgPointee<0>(actualValuePtr));
  library.call_functionWithArgPointer(&expectedValue);

  ASSERT_EQ(actualValue, expectedValue);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Deleting_Pointer_Arguments)
{
  // Argument passing by reference.
  // DeleteArg<N>(&obj) - You can save value of a N-th argument to the given object.
  IListenerMock listener;
  CLibrary library{&listener};
  const int* value = new int{32};
  EXPECT_CALL(listener, functionWithArgPointer(_)).WillOnce(DeleteArg<0>());
  library.call_functionWithArgPointer(value);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Set_Argument_Reference)
{
  // SetArgReferee<N>(&obj) - You can set value of a N-th argument. The argument must be a reference.
  IListenerMock listener;
  CLibrary library{&listener};
  int value = 0;
  const int newValue = 100;
  EXPECT_CALL(listener, functionWithArgReferenceNonConst(_)).WillOnce(SetArgReferee<0>(newValue));
  library.call_functionWithArgReferenceNonConst(value);

  ASSERT_EQ(newValue, value);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Set_Argument_Pointer)
{
  // SetArgPointee<N>(&obj) - You can set value of a N-th argument. The argument must be a pointer.
  IListenerMock listener;
  CLibrary library{&listener};
  int value = 0;
  const int newValue = 100;
  EXPECT_CALL(listener, functionWithArgPointerNonConst(_)).WillOnce(SetArgPointee<0>(newValue));
  library.call_functionWithArgPointerNonConst(&value);

  ASSERT_EQ(newValue, value);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Set_Argument_Pointer_To_Array)
{
  // SetArrayArgument<N>(x, y) - You can set values of a N-th argument. The argument must be a container/array. 
  //                             The new values are provided by begin iterator 'x' and end iterator 'y'.
  IListenerMock listener;
  CLibrary library{&listener};
  int value[] = {1, 2};
  const int newValue[] = {100, 101};
  EXPECT_CALL(listener, functionWithArgPointerNonConst(_)).WillOnce(SetArrayArgument<0>(std::begin(newValue), std::end(newValue)));
  library.call_functionWithArgPointerNonConst(value);

  ASSERT_EQ(newValue[0], value[0]);
  ASSERT_EQ(newValue[1], value[1]);
}
