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

//! \brief This a mock of class that has virtual and nonvirtual methods. Only pure virtual method must be mocked, 
//!        mocking other methods is not needed. We can only do GMock operation on mocked methods.
//!        To mock methods it is required to use public inheritance.
//!        This the simplest case, next lesson will show how to use more complex methods.
class IListenerMock : public IListener // IListener is a interface class
{
public:
  // MOCK_METHODx - 'x' is a number of arguments. The 'functionNoArg' doesn't have any arguments so MOCK_METHOD0 was used.
  // MOCK_METHOD0(name_of_mocked_method, type); - the 1st argument is name of method to mock.
  //                                            - the 2nd is a type of method: void - because it returns void; in brackets should be method arguments
  MOCK_METHOD0(functionNoArg, void()); // Mock of: virtual void functionNoArg() = 0;

  // for const methods: MOCK_CONST_METHODx - CONST was added in the middle of the macro.
  MOCK_CONST_METHOD0(constFunctionNoArg, void());// Mock of: virtual void constFunctionNoArg() const = 0;

  // There is 1 argument, so MOCK_METHOD1, and void(int) - int is a type of argument
  MOCK_METHOD1(functionArg1, void(int));// Mock of: virtual void functionArg1(int aArg1) = 0;
  MOCK_CONST_METHOD1(constFunctionArg1, void(int));// Mock of: virtual void constFunctionArg1(int aArg1) const = 0;

  // There are 3 arguments, so MOCK_METHOD3 and void(int, int, int) - all 3 arguments have 'int' type.
  MOCK_METHOD3(functionArg3, void(int, int, int));// Mock of: virtual void functionArg3(int aArg1, int aArg2, int aArg3) = 0;
  MOCK_CONST_METHOD3(constFuncitonArg, void(int, int, int));// Mock of: virtual void constFuncitonArg(int aArg1, int aArg2, int aArg3) const = 0;

  // There is 1 argument with 'double' type
  MOCK_METHOD1(functionArg1Double, void(double));// Mock of: virtual void functionArg1Double(double aArg1) = 0;

// you can also write a name of arguments

  // There is 1 argument with 'const char*' type.
  MOCK_METHOD1(functionArg1Str, void(const char* aArg1));// Mock of; virtual void functionArg1Str(const char* aArg1) = 0;

  // This is a mock for nonvirtual method.
  MOCK_METHOD0(functionNonVirtual, void());// Mock of: void functionNonVirtual();

};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // EXPECT_CALL macro checks if method was called. 
  // EXPECT_CALL(object, method) - the 1st argument is object of the mocked class.
  //                               the 2nd argument is method with brackets
  // Times(1) - it means that this method should be called only once.
  EXPECT_CALL(listenerMock, functionNoArg()).Times(1);

  // There is no difference between const and nonconst method.
  EXPECT_CALL(listenerMock, constFunctionNoArg()).Times(1);

  // This 'call_functionNoArg' call listener's method functionNoArg.
  library.call_functionNoArg();
  library.call_constFunctionNoArg();
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_no_call)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // we expect a call
  EXPECT_CALL(listenerMock, functionNoArg()).Times(1);
  // but we don't call it, so the test will fail.

  /* Output:
   [ RUN      ] CMyTestCase.ExpectCall_simple_no_call
   /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson11_Expect_Call_Basics/Code/Tests/Code/Test.cpp:88: Failure
   Actual function call count doesn't match EXPECT_CALL(listenerMock, functionNoArg())...
   Expected: to be called once
   Actual: never called - unsatisfied and active
   [  FAILED  ] CMyTestCase.ExpectCall_simple_no_call (0 ms)
   */
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_call_not_expected)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // we expect that this method will NOT be called.
  EXPECT_CALL(listenerMock, functionNoArg()).Times(0);
  // but call it. The test will fail.
  library.call_functionNoArg();

  /*
   [ RUN      ] CMyTestCase.ExpectCall_simple_call_not_expected
   /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson11_Expect_Call_Basics/Code/Tests/Code/Test.cpp:105: Failure
   Mock function called more times than expected - returning directly.
   Function call: functionNoArg()
   Expected: to be never called
   Actual: called once - over-saturated and active
   [  FAILED  ] CMyTestCase.ExpectCall_simple_call_not_expected (0 ms)
   */
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_argument)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // Check if method with argument will be called.
  // _ (underscore) means that it could be any value of argument.
  EXPECT_CALL(listenerMock, functionArg1(_)).Times(1);

  library.call_functionArg1(12); // pass 12 value

  // We can check methods with more arguments.
  EXPECT_CALL(listenerMock, functionArg3(_, _, _)).Times(1);
  library.call_functionArg3(1, 2, 3); // pass 1, 2, 3 values
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_exactly_argument)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  const int argument = 10;

  // We can expect a particular value of argument of method
  // Here we expect that the method 'functionArg1' will be called with the argument equals the 'argument' variable.
  EXPECT_CALL(listenerMock, functionArg1(argument)).Times(1);

  // the 'call_functionArg1' call listener's 'functionArg1' method and passes to it arguments.
  library.call_functionArg1(argument);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_exactly_argument_fail)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // everything as was in the previous test
  const int argument = 10;
  EXPECT_CALL(listenerMock, functionArg1(argument)).Times(1);
  // how ever we call method with a different argument than it is expected.
  library.call_functionArg1(12);

  /* Output:
   /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson11_Expect_Call_Basics/Code/Tests/Code/Test.cpp:152: EXPECT_CALL(listenerMock, functionArg1(argument))...
   Expected arg #0: is equal to 10
   Actual: 12
   Expected: to be called once
   Actual: never called - unsatisfied and active
   /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson11_Expect_Call_Basics/Code/Tests/Code/Test.cpp:152: Failure
   Actual function call count doesn't match EXPECT_CALL(listenerMock, functionArg1(argument))...
   Expected: to be called once
   Actual: never called - unsatisfied and active
   [  FAILED  ] CMyTestCase.ExpectCall_simple_exactly_argument_fail (0 ms)
   */
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_exactly_argument_fail_twice)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // everything as was in the previous test
  const int argument = 10;
  EXPECT_CALL(listenerMock, functionArg1(argument)).Times(1);
  // how ever we call method with a different argument than it is expected.
  library.call_functionArg1(12);
  // and after that we call it with the expected argument.
  library.call_functionArg1(10);

  /* Output:
   Unexpected mock function call - returning directly.
   Function call: functionArg1(12)
   Google Mock tried the following 1 expectation, but it didn't match:

   /home/iblis/workspaces/tutorials/Cpp/GTest_GMock/Lesson11_Expect_Call_Basics/Code/Tests/Code/Test.cpp:175: EXPECT_CALL(listenerMock, functionArg1(argument))...
   Expected arg #0: is equal to 10
   Actual: 12
   Expected: to be called once
   Actual: never called - unsatisfied and active
   [  FAILED  ] CMyTestCase.ExpectCall_simple_exactly_argument_fail_twice (0 ms)
   */
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_matchers)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // You can provide matchers to arguments
  // Eq(x) - an argument is equal to 'x'
  // Ne(x) - an argument is not equal to 'x'
  // Ge(x) - an argument is greater than 'x' or equal to 'x'
  // Le(x) - an argument is less than 'x' or equal to 'x'
  // Gt(x) - an argument is greater than 'x'
  // Lt(x) - an argument is less than 'x'

  /// 1st example

  // The 1st argument must be 1
  // The 2nd cannot be 2
  // The 3rd argument is 3
  EXPECT_CALL(listenerMock, functionArg3(Eq(1), Ne(2), 3)).Times(1);
  library.call_functionArg3(1, 0, 3); // pass 1, 0, 3 values

  /// 2nd example

  // The 1st argument must be greater than 1
  // The 2nd argument must greater than 1 or exactly 1
  // The 3rd argument must less or equal 3
  EXPECT_CALL(listenerMock, functionArg3(Gt(1), Ge(2), Le(3))).Times(1);
  library.call_functionArg3(2, 2, 2);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_matchers_double)
{
  IListenerMock listenerMock; // creates object of mock class
  CLibrary library { &listenerMock };

  // GTest has special asserts for doubles, GMock also has them.

  const double argument = 3.3;

  // DoubleEq(x) - checks if an argument is equal to 'x' (sometimes Eq doesn't work properly, because of double precision, see the 1st lesson)
  EXPECT_CALL(listenerMock, functionArg1Double(DoubleEq(argument))).Times(1);
  library.call_functionArg1Double(argument);

  // DoubleNear(x, y) - the argument must be: (x - y) <= argument <= (x + y)
  EXPECT_CALL(listenerMock, functionArg1Double(DoubleNear(argument, 0.3))).Times(1);
  library.call_functionArg1Double(argument + 0.2);

  // Not a number (NaN) - double can hold a value that is not a number.
  // DoubleEq and DoubleNear treats NaN == NaN as false

  // NanSensitiveDoubleEq(x) - the as DoubleEq(x) but NaN == NaN is true
  const double notANumber = std::nan("");
  EXPECT_CALL(listenerMock, functionArg1Double(NanSensitiveDoubleEq(notANumber))).Times(1);
  library.call_functionArg1Double(notANumber);

  // NanSensitiveDoubleNear(x) - the as DoubleNear(x) but NaN == NaN is true
  EXPECT_CALL(listenerMock, functionArg1Double(NanSensitiveDoubleNear(notANumber, 0.3))).Times(1);
  library.call_functionArg1Double(notANumber);
}

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_simple_string)
{
  // GMock has special matchers for C-style strings

  const char* value1 = "abc";
  const char* value2 = "def";
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // StrEq(x) - an argument must be equal 'x'
    EXPECT_CALL(listenerMock, functionArg1Str(StrEq(value1))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // StrNe(x) - an argument must be different than 'x'
    EXPECT_CALL(listenerMock, functionArg1Str(StrNe(value2))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // StrCaseEq(x) - an argument must be equal 'x' (case insensitivity)
    const char* valueUpperCase = "ABC";
    EXPECT_CALL(listenerMock, functionArg1Str(StrCaseEq(valueUpperCase))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // StrCaseNe(x) - an argument must be different than 'x' (case insensitivity)
    EXPECT_CALL(listenerMock, functionArg1Str(StrCaseNe(value2))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // StartsWith(x) - an argument must start with 'x'
    const char* prefix = "ab";
    EXPECT_CALL(listenerMock, functionArg1Str(StartsWith(prefix))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // EndsWith(x) - an argument must end with 'x'
    const char* suffix = "bc";
    EXPECT_CALL(listenerMock, functionArg1Str(EndsWith(suffix))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // HasSubstr(x) - an argument must contain 'x'
    const char* substring = "b";
    EXPECT_CALL(listenerMock, functionArg1Str(HasSubstr(substring))).Times(1);
    library.call_functionArg1Str(value1);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // ContainsRegex(x) - an argument must have substring that match to the regular expression 
    const char* value3 = "DaC";
    const char* regex = "[a-b]";
    EXPECT_CALL(listenerMock, functionArg1Str(ContainsRegex(regex))).Times(1);
    library.call_functionArg1Str(value3);
  }
  {
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    // MatchesRegex(x) - an argument must match to the regular expression (entire argument)
    const char* digits = "123";
    const char* regex2 = "[1-3]{3}";
    EXPECT_CALL(listenerMock, functionArg1Str(MatchesRegex(regex2))).Times(1);
    library.call_functionArg1Str(digits);
  }
}

