// Created by Marcin Serwach on 28/09/16.
//
// Lesson 9: Verify
//
// This lesson shows how to verify if a mocked method was called.
//
// Keywords:
// 1. OCMVerifyAll
// 2. OCMVerify
// 3. OCMVerifyAllWithDelay

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"


@interface Lesson9_Verify : XCTestCase
@end

@implementation Lesson9_Verify {
    id _listenerProtocol;
    Library *_library;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)setUp {
    [super setUp];
    // Creates a strict mock based on protocol.
    _listenerProtocol = OCMStrictProtocolMock(@protocol(ListenerProtocol));
    
    _library = [[Library alloc] initWithProtocol:_listenerProtocol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_verifyAll {
    OCMExpect([_listenerProtocol functionWithoutArg]);
    [_library call_functionWithoutArg];
    // Verifies if all expected methods on '_listenerProtocol' were called.
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_verifyMethodArg_queue {
    OCMExpect([_listenerProtocol functionWithArg1:1]);
    OCMExpect([_listenerProtocol functionWithArg1:2]);
    OCMExpect([_listenerProtocol functionWithArg1:3]);
    [_library call_functionWithArg1:1];
    [_library call_functionWithArg1:2];
    [_library call_functionWithArg1:3];
    // Verifies if all expected methods on '_listenerProtocol' were called.
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_verifyMethodArg_queue2 {
    OCMExpect([_listenerProtocol functionWithArg1:1]);
    OCMExpect([_listenerProtocol functionWithArg1:2]);
    [_library call_functionWithArg1:1];
    [_library call_functionWithArg1:2];
    // Verifies if all expected methods on '_listenerProtocol' were called.
    OCMVerifyAll(_listenerProtocol);
    
    OCMExpect([_listenerProtocol functionWithArg1:3]);
    [_library call_functionWithArg1:3];
    // Verifies if all expected methods on '_listenerProtocol' were called.
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_verifyMethod {
    OCMExpect([_listenerProtocol functionWithoutArg]);
    [_library call_functionWithoutArg];
    // Verifies if 'functionWithoutArg' method on '_listenerProtocol' was called.
    OCMVerify([_listenerProtocol functionWithoutArg]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_verifyMethodArg {
    OCMExpect([_listenerProtocol functionWithArg1:1]);
    [_library call_functionWithArg1:1];
    // Verifies if 'functionWithArg1' method on '_listenerProtocol' was called with an argument value 1.
    OCMVerify([_listenerProtocol functionWithArg1:1]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)method {
    [NSThread sleepForTimeInterval:0.2f];
    [_library call_functionWithoutArg];
}

- (void)test_verifyAll_thread {
    OCMExpect([_listenerProtocol functionWithoutArg]);
    [NSThread detachNewThreadSelector:@selector(method) toTarget:self withObject:nil];
    
    NSTimeInterval delay = 0.5;
    // Verifies if all expected methods on '_listenerProtocol' were called but the verification
    // will be delayed.
    OCMVerifyAllWithDelay(_listenerProtocol, delay);
}


@end