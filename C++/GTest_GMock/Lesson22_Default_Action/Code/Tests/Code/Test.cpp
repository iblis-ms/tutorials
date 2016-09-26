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

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple)
{
  // ON_CALL(...) - You can provide a default actions for calling mocked methods.
  IListenerMock listenerMock;
  CLibrary library{&listenerMock};
  
  // A syntax is similar to EXPECT_CALL. 
  ON_CALL(listenerMock, functionArg3(_, _, _)).WillByDefault(DoAll(
    Invoke([](int aArg1, int aArg2, int aArg3){
      std::cout<<"Default action for functionArg3: aArg1: "<<aArg1<<" aArg2: "<<aArg2<<" aArg3: "<<aArg3<<std::endl;
    }),
    Return(10)));

  // There wasn't any EXPECT_CALL, therefore the default action for functionArg3 will be run.
  // GMock displays warning about calling mocked methods without EXPECT_CALL.
  /* Output:
  GMOCK WARNING:
  Uninteresting mock function call - taking default action specified at:
  */
  library.call_functionArg3(1, 2, 3);
}
