// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include <iostream>
#include <tuple>

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

  MOCK_METHOD3(functionWithArgs, void(int, int, int));
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Multi_Argument_AllArgs_Particular)
{
  { // With(AllArgs(res)) - The 'res' is 'std::tuple<n0, n1, nN>'. The template arguments are types of method arguments.
    //                      This With(AllArgs(res)) means that an arguments must be equal to given tuple values.
    //                      The 1st argument must be equal the first value from give tuple, etc.
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 3;
    std::tuple<int, int, int> res(1, 2, 3);
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(AllArgs(res)).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
  { // With(AllArgs(Le(res)) - You can provide matchers. Here all values must be lower than values in the given tuple.
    //                         The 1st argument must be less than the 1st tuple value, etc.
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 3;
    std::tuple<int, int, int> res(2, 3, 4);
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(AllArgs(Le(res))).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Multi_Argument_Some_Arguments)
{
  { // With(Args<N, M>(x) - From N to M arguments must be equal values for tuple 'x'.
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 10;
    std::tuple<int, int> res(1, 2);
    // check only the 1st and 2nd argument with the 1st and 2nd value from tuple 'res'.
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(Args<0, 1>(res)).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
  { // With(Args<N, M>(Le(res)) - You can also use matchers like Le.
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 10;
    std::tuple<int, int> res(2, 3);
    // The 1st and 2nd argument must be lower than the 1st and the 2nd tuple 'res' values.
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(Args<0, 1>(Le(res))).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
  { // With(Args<1, 1>(Le(res)) - as above
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 10;
    int b = 2;
    int c = 30;
    std::tuple<int, int> res(2, 3);
    // you can provide bigger tuple than you want to use in checking.
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(Args<1, 1>(Le(res))).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_Multi_Argument_More_Matchers)
{
  { // .With(AllArgs(AllOf(Eq(res1), Gt(res2), Lt(res3)))
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 3;
    std::tuple<int, int, int> res1(1, 2, 3);
    std::tuple<int, int, int> res2(0, 1, 2);
    std::tuple<int, int, int> res3(2, 3, 4);
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(AllArgs(AllOf(Eq(res1), Gt(res2), Lt(res3)))).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
  { // AllOf(Args<0>(Eq(res1)), Args<1>(Eq(res2)), Args<2>(Eq(res3)))
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 3;
    std::tuple<int> res1(a);
    std::tuple<int> res2(b);
    std::tuple<int> res3(c);
    EXPECT_CALL(listener, functionWithArgs(_, _, _)).With(
        AllOf(Args<0>(Eq(res1)), Args<1>(Eq(res2)), Args<2>(Eq(res3)))).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
  { // AllOf(Lt(2), Gt(0))
    IListenerMock listener;
    CLibrary library { &listener };
    int a = 1;
    int b = 2;
    int c = 3;
    EXPECT_CALL(listener, functionWithArgs(AllOf(Lt(2), Gt(0)), _, _)).Times(1);
    library.call_functionWithArgs(a, b, c);
  }
  // the same situation with: AnyOf, Not
}
