// Created by Marcin Serwach on 28/09/16.
//
// Lesson 1: Simple Matchers
//
// This lesson shows how to check if a particular method was called and if arguments
// have proper values.
// OCMock allows us to mock method based on protocol (OCMProtocolMock) or based on
// class (OCMClassMock). OCMProtocolMock creates object that implements given protocol,
// but OCMClassMock creates an object of class that extends class given as an argument.
// For both cases OCMock allows calling method that wasn't marked as an expected call.
// There is also a strict mock, which will throw an exception when not expected method.
// will be called.
//
// Tests use 'ListenerProtocol' protocol whose a mock object is created. This object
// is passed to 'Library' object. The object of 'Library' class has method that call
// protocol's method, i.e. 'call_functionWithoutArg' from 'Library' calls 'functionWithoutArg'
// of given in 'initWithProtocol' method protocol object. Therefore protocol method
// named 'x' is called by 'Library' method 'call_x'.
//
// Keywords:
// 1. OCMProtocolMock
// 2. OCMClassMock
// 3. OCMVerifyAll


#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson1_SimpleMatchers : XCTestCase
@end

@implementation Lesson1_SimpleMatchers {
    id _listenerProtocol;
    Library *_library;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)setUp {
    [super setUp];
    // You can mock by providing a protocol:
    // - OCMProtocolMock(@protocol(_Protocol_Name_))
    // or you can mock class
    // - OCMClassMock([_Class_Name_ class]);
     _listenerProtocol = OCMProtocolMock(@protocol(ListenerProtocol));
    
    // The '_library' has methods that calls method of protocol given in 'initWithProtocol' method.
    _library = [[Library alloc] initWithProtocol:_listenerProtocol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)testFunctionWithoutArg {
    // OCMExpect says that given method must be called.
    //           Here we expect a call of 'functionWithoutArg' on '_listenerProtocol' object.
    OCMExpect([_listenerProtocol functionWithoutArg]);
    
    // The method 'call_functionWithoutArg' calls 'functionWithoutArg' on '_listenerProtocol' object.
    [_library call_functionWithoutArg];
    
    // Now it is required to verify if all expected methods were called.
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)testFunctionWithArg1 {
    const int value = 10;
    
    // You can expect a method call with a particular value of argument.
    // Here we expect a 'functionWithArg1' with argument equals 10.
    OCMExpect([_listenerProtocol functionWithArg1:value]);
    
    // 'call_functionWithArg1' calls 'functionWithArg1' on '_listenerProtocol' object.
    [_library call_functionWithArg1:value];
    
    // Now it is required to verify if a expected method was called with given argument.
    // It is less confortable method, so I prefere to use OCMVerifyAll.
    OCMVerify([_listenerProtocol functionWithArg1:value]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)testFunctionWithArg1Arg2 {
    const int value1 = 10;
    const int value2 = 20;
    
    // The is an example of a method expect call that has more than one argument.
    OCMExpect([_listenerProtocol functionWithArg1:value1 arg2:value2]);
    
    [_library call_functionWithArg1:value1 arg2:value2];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)testFunctionWithArg1String {
    NSString *value = @"abc";
    NSString *expected = @"abc";
    
    // This is an example of a method expect call with an object in argument.
    // It is 'isEqual' method called to check if a value is equal to expect one.
    OCMExpect([_listenerProtocol functionWithArg1String:expected]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)testFunctionWithArg1Custom {
    CustomClass *value = [CustomClass new];
    
    // This is an example of a method expect call with an object of a custom class.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:value]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

@end
