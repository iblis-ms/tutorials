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

//! \brief This mock class contains methods that return by value, by reference and by r-value reference.
class IListenerMock : public IListener // IListener is a interface class
{
public:

  MOCK_METHOD1(functionWithPointer, void(int*));
  MOCK_METHOD1(functionWithCustomPointer, void(Base*));
  MOCK_METHOD1(functionWithReference, void(int&));
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_References)
{
  // Ref(x) - an argument must by reference with value equal to 'x'.
  IListenerMock listener;
  CLibrary library { &listener };

  int value = 20;
  EXPECT_CALL(listener, functionWithReference(Ref(value))).Times(1);
  library.call_functionWithReference(value);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Pointers)
{
  // Pointee(x) - an argument of mocked must be pointer which points to the object that can be compare with 'x'.
  //              The 'bool operator==(const X&, const Argument&);' is called (where X is type of 'x').
  IListenerMock listener;
  CLibrary library { &listener };

  int value = 20;
  EXPECT_CALL(listener, functionWithPointer(Pointee(value))).Times(1);
  library.call_functionWithPointer(&value);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Pointers_Null)
{
  // IsNull() - an argument cannot be NULL.
  IListenerMock listener;
  CLibrary library { &listener };

  EXPECT_CALL(listener, functionWithPointer(IsNull())).Times(1);
  library.call_functionWithPointer(nullptr);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Pointers_NotNull)
{
  // IsNull() - an argument cannot be NULL.
  IListenerMock listener;
  CLibrary library { &listener };

  int value = 20;
  EXPECT_CALL(listener, functionWithPointer(NotNull())).Times(1);
  library.call_functionWithPointer(&value);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Custom_Pointers)
{
  // Pointee(x) - an argument of mocked must be pointer which points to the object that can be compare with 'x'.
  //              The 'bool operator==(const X&, const Argumetn&);' is called (where X is type of 'x').
  IListenerMock listener;
  CLibrary library { &listener };
  Derivative derivative { 1, 2 };
  Base base { 1 };
  EXPECT_CALL(listener, functionWithCustomPointer(Pointee(base))).Times(1);
  library.call_functionWithCustomPointer(&derivative);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Dynamic_Cast)
{
  // WhenDynamicCastTo<Derivative*>(Pointee(x)) - an argument of mocked must be pointer. The argument pointer will dynamic_cast<Derivative*>
  //                                              and the pointing value will be compared with the given 'x' value.
  IListenerMock listener;
  CLibrary library { &listener };
  Derivative derivative { 1, 2 };
  Base* base = &derivative;
  // WhenDynamicCastTo<Derivative*> changes behavior. There will be called 'bool operator==(const Derivative&, const Derivative&)'.
  // Without WhenDynamicCastTo<Derivative*> there will be called 'bool operator==(const Base&, const Base&)'
  EXPECT_CALL(listener, functionWithCustomPointer(WhenDynamicCastTo<Derivative*>(Pointee(derivative)))).Times(1);
  library.call_functionWithCustomPointer(base);
}

