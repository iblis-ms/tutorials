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

class IListenerMock : public IListener // IListener is a interface class
{
public:

  MOCK_METHOD3(functionWithArg, void(int, int&, int*));
  MOCK_METHOD1(functionWithArgFunction, void(std::function<void(int)>));
  MOCK_METHOD0(functionWithReturn, int());
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};


/////////////////////////////////////////////////////// PASSING ALL ARGUMENTS //////////////////
void globalMethodWithArgs(int aArg1, int& aArg2, int* aArg3)
{
  std::cout<<"globalMethod: aArg1="<<aArg1<<" aArg2="<<aArg2<<" aArg3="<<*aArg3<<std::endl;
}

class ClassInvokeFunctionWithArgs{
public:

  void invokeMethodWithArgs(int aArg1, int& aArg2, int* aArg3){
    std::cout<<"memberFunction: aArg1="<<aArg1<<" aArg2="<<aArg2<<" aArg3="<<*aArg3<<std::endl;
  }

  void invokeMethodWithArgs_PartialArgs(int aArg1, int& aArg2){
    std::cout<<"memberFunction partialArgs: aArg1="<<aArg1<<" aArg2="<<aArg2<<std::endl;
  }
};

TEST_F(CMyTestCase, ExpectCall_Invoke_With_Params)
{
  int arg1 = 1;
  int arg2 = 2;
  int arg3 = 3;
  { // Invoke(address_of_global_function) - The given method will be called and arguments passed to mocked method will be passed to give function.
    IListenerMock listener;
    CLibrary library{&listener};

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(Invoke(globalMethodWithArgs));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
  { // Invoke(lambda) - you can provide a lambda instead of global function.
    IListenerMock listener;
    CLibrary library{&listener};

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(Invoke(
      [](int aArg1, int& aArg2, int* aArg3)
        {
          std::cout<<"lambda: aArg1="<<aArg1<<" aArg2="<<aArg2<<" aArg3="<<*aArg3<<std::endl;
        }));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
  { // Invoke(point_to_object, address_of_class_method) - you can also call a method of object. 
    IListenerMock listener;
    CLibrary library{&listener};
    ClassInvokeFunctionWithArgs object;

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(Invoke(&object, &ClassInvokeFunctionWithArgs::invokeMethodWithArgs));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
}

/////////////////////////////////////////////////////// PASSING SOME ARGUMENTS //////////////////

void globalMethodWithArgs_PartialAgs(int aArg1, int& aArg2)
{
  std::cout<<"globalMethod: aArg1="<<aArg1<<" aArg2="<<aArg2<<std::endl;
}

class ClassInvokeFunctionWithPartialArgs{
public:

  void invokeMethodWithArgs_PartialArgs(int aArg1, int& aArg2){
    std::cout<<"memberFunction partialArgs: aArg1="<<aArg1<<" aArg2="<<aArg2<<std::endl;
  }
};

TEST_F(CMyTestCase, ExpectCall_Invoke_Partial_Params)
{
  int arg1 = 1;
  int arg2 = 2;
  int arg3 = 3;
  { // WithArgs<N, M>(Invoke...) - You can pass only selected arguments, here: N-th and M-th. 
    //                             Passing the same argument is allowed: WithArgs<N, n>(...)
    //                             You provide any order of arguments i.e. WithArgs<3, 0, 2>(...)
    IListenerMock listener;
    CLibrary library{&listener};

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(WithArgs<0, 1>(Invoke(globalMethodWithArgs_PartialAgs)));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
  { // As above but with object's method.
    IListenerMock listener;
    CLibrary library{&listener};
    ClassInvokeFunctionWithArgs object;

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(WithArgs<0, 1>(Invoke(&object, &ClassInvokeFunctionWithArgs::invokeMethodWithArgs_PartialArgs)));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
}

/////////////////////////////////////////////////////// PASSING WITHOUT ARGS //////////////////
void globalMethodWithoutArgs()
{
  std::cout<<"globalMethod: without args\n";
}

class ClassInvokeFunctionWithoutArgs{
public:
  void invokeMethodWithoutArgs(){
    std::cout<<"invoke member function without arguments\n";
  }
};

TEST_F(CMyTestCase, ExpectCall_Invoke_Without_Params)
{
  int arg1 = 1;
  int arg2 = 2;
  int arg3 = 3;
  { // InvokeWithoutArgs(address_of_global_function) - The given method will be called without passing arguments.
    IListenerMock listener;
    CLibrary library{&listener};

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(InvokeWithoutArgs(globalMethodWithoutArgs));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
  { // lambda case
    IListenerMock listener;
    CLibrary library{&listener};

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(InvokeWithoutArgs(
      []()
        {
          std::cout<<"lambda: without args\n";
        }));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
  { // object's method
    IListenerMock listener;
    CLibrary library{&listener};
    ClassInvokeFunctionWithoutArgs object;

    EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(InvokeWithoutArgs(&object, &ClassInvokeFunctionWithoutArgs::invokeMethodWithoutArgs));
    library.call_functionWithArg(arg1, arg2, &arg3);
  }
}

/////////////////////////////////////////////////////// RETURN ////////////
int globalReturn()
{
  return 123;
}

TEST_F(CMyTestCase, ExpectCall_Invoke_Return)
{
  // Invoke should return value if mocked method returns a value.
  IListenerMock listener;
  CLibrary library{&listener};

  EXPECT_CALL(listener, functionWithReturn()).WillOnce(Invoke(globalReturn));
  const int returnValue = library.call_functionWithReturn();

  ASSERT_EQ(123, returnValue);
}

TEST_F(CMyTestCase, ExpectCall_Invoke_Return_IgnoreResult)
{
  // IgnoreResult - ignore result of invoked function/lambda.
  IListenerMock listener;
  CLibrary library{&listener};
  int arg1 = 1;
  int arg2 = 2;
  int arg3 = 3;

  EXPECT_CALL(listener, functionWithArg(_, _, _)).WillOnce(IgnoreResult(InvokeWithoutArgs(globalReturn)));
  library.call_functionWithArg(arg1, arg2, &arg3);
}

/////////////////////////////////////////////////////// ARGUMENT IS A FUNCTION ////////////
TEST_F(CMyTestCase, ExpectCall_Invoke_Param)
{

  IListenerMock listener;
  CLibrary library{&listener};
  const int functionArg = 10;

  EXPECT_CALL(listener, functionWithArgFunction(_)).WillOnce(InvokeArgument<0>(functionArg));
  std::function<void(int)> function = [](int aArg){ std::cout<<"argument function: "<<aArg<<std::endl;};
  library.call_functionWithArgFunction(function);
}
