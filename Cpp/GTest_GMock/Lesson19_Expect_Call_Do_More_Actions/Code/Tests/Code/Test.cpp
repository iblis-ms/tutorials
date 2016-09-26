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

class IListenerMock : public IListener // IListener is a interface class
{
public:

  MOCK_METHOD3(functionArg3, int(int, int, int));

};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

void methodWithArgs(int aArg1, int aArg2, int aArg3)
{
  std::cout<<"method with args: aArg1: "<<aArg1<<" aArg2: "<<aArg2<<" aArg3: "<<aArg3<<std::endl;
}

void methodWithoutArgs()
{
  std::cout<<"method without args\n";
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple)
{
  // DoAll(...) - You can provide more than one action. You need to put all actions into DoAll.
  //              The last action must return a value of mocked function.
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library{&listenerMock};
  int arg1;
  int arg2;
  const int returnValue = 10;

  EXPECT_CALL(listenerMock, functionArg3(_, _, _)).WillOnce(DoAll(
    SaveArg<0>(&arg1), // save the first arg.
    SaveArg<1>(&arg2),  // save the second arg.
    Invoke(methodWithArgs), // invoke one method
    InvokeWithoutArgs(methodWithoutArgs), //invoke another method.
    Return(returnValue)));

  const int returnResult = library.call_functionArg3(1, 2, 3);
  ASSERT_EQ(returnValue, returnResult);
}
