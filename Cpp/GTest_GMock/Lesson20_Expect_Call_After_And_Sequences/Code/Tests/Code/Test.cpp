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
  MOCK_METHOD1(functionArg1, void(int)); 
  MOCK_METHOD3(functionArg3, void(int, int, int));
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_After)
{
  // After(expectation_object) - you can provide an order of calling method. An expect call should be called after expect call whose Expectation object is provided.
  IListenerMock listenerMock;
  CLibrary library{&listenerMock};

  // the 1st expect call
  Expectation expectation1 = EXPECT_CALL(listenerMock, functionArg1(1)).Times(1);
  // the 2nd expect call on different method. It should be called after the 1st one.
  Expectation expectation2 = EXPECT_CALL(listenerMock, functionArg3(10, 11, 12)).Times(1).After(expectation1);
  // the 3rd expect call on different method. It should be called after the 1st one.
  Expectation expectation3 = EXPECT_CALL(listenerMock, functionArg1(3)).Times(1).After(expectation1);
  // the 4th expect call on different method. It should be called after the 2nd call and after the 3rd call.
  EXPECT_CALL(listenerMock, functionArg3(20, 21, 22)).Times(1).After(expectation2, expectation3);

  // calls
  library.call_functionArg1(1);
  library.call_functionArg3(10, 11, 12);
  library.call_functionArg1(3);
  library.call_functionArg3(20, 21, 22);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_After_Set)
{
  // ExpectationSet is a set of Expectation.
  IListenerMock listenerMock; 
  CLibrary library{&listenerMock};

  // functionArg1 should be called 4 times with following arguments: 0, 1, 2, 3.
  ExpectationSet expectSet;
  for (int i = 0; i < 4; i++) {
    expectSet += EXPECT_CALL(listenerMock, functionArg1(i));
  }
  // after that functionArg3 should be called once.
  EXPECT_CALL(listenerMock, functionArg3(1, 2, 3)).After(expectSet);

  library.call_functionArg1(0);
  library.call_functionArg1(1);
  library.call_functionArg1(2);
  library.call_functionArg1(3);
  library.call_functionArg3(1, 2, 3);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_After_Sequence)
{
  // InSequence(sequence1, ... sequenceN) - you can put expect calls in a sequence to check if methods were called in a proper order.
  IListenerMock listenerMock;
  CLibrary library{&listenerMock};
  Sequence sequence1, sequence2;
  // functionArg1(1) must be called at first
  EXPECT_CALL(listenerMock, functionArg1(1)).Times(1).InSequence(sequence1, sequence2);
  // after that functionArg1(2) and functionArg1(3) must be called. However an order of these calls is not specified.
  EXPECT_CALL(listenerMock, functionArg1(2)).Times(1).InSequence(sequence1);
  EXPECT_CALL(listenerMock, functionArg1(3)).Times(1).InSequence(sequence2);

  library.call_functionArg1(1);
  library.call_functionArg1(2);
  library.call_functionArg1(3);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall)
{
  {
  IListenerMock listenerMock;
  CLibrary library{&listenerMock};
  // checking if function was called is done in a deconstructor of mocked object.
  EXPECT_CALL(listenerMock, functionArg1(1)).Times(1);
  library.call_functionArg1(1);
  }
  {
    IListenerMock listenerMock;
    CLibrary library{&listenerMock};

    EXPECT_CALL(listenerMock, functionArg1(1)).Times(1);
    library.call_functionArg1(1);
    // you can check if expected methods were called.
    Mock::VerifyAndClearExpectations(&listenerMock);
  }
  {
    IListenerMock listenerMock;
    CLibrary library{&listenerMock};

    EXPECT_CALL(listenerMock, functionArg1(1)).Times(1);
    library.call_functionArg1(1);
    // you can check if expected methods were called. It also removes default actions.
    Mock::VerifyAndClear(&listenerMock);
  }
}

