// Created by Marcin Serwach on 28/09/16.
//
// Lesson 3: Return
//
// This lesson shows how to return a value from mocked method.
//
// Keywords:
// 1. andReturn

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson3_Return : XCTestCase
@end

@implementation Lesson3_Return {
    id _listenerProtocol;
    Library *_library;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)setUp {
    [super setUp];
    // Creates a mock that fulfils a given protocol.
    _listenerProtocol = OCMProtocolMock(@protocol(ListenerProtocol));
    
    _library = [[Library alloc] initWithProtocol:_listenerProtocol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_andReturn_primitive {
    const int value = 10;
    // You can set an expect call on a method that returns a value.
    // Here, a primitive value will be returned when 'functionWithReturn' will be called.
    OCMExpect([_listenerProtocol functionWithReturn]).andReturn(value);
    
    // Stores returned value.
    const int result = [_library call_functionWithReturn];
    
    OCMVerifyAll(_listenerProtocol);
    // just to check if a proper value was returned.
    XCTAssertEqual(result, value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_andReturn_object {
    NSString *value = @"abc";
    // You can also return an object.
    OCMExpect([_listenerProtocol functionWithReturnString]).andReturn(value);
    
    NSString *result = [_library call_functionWithReturnString];
    
    OCMVerifyAll(_listenerProtocol);
    XCTAssertEqual(result, value);
}
@end