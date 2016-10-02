// Created by Marcin Serwach on 28/09/16.
//
// Lesson 8: Strict mocking
//
// This lesson shows how to use a strict mocking. The strict mocking means that
// only expected methods can be called. The calling methods, that weren't expected,
// throws an exception.
// There are special versions of macros that create strict mock objects:
// - OCMStrictClassMock - for objects
// - OCMStrictProtocolMock - for protocols
//
// All matchers and actions can be with a strick mock object.
//
// Keywords:
// 1. OCMStrictClassMock
// 2. OCMStrictProtocolMock

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson8_Strict : XCTestCase
@end

@implementation Lesson8_Strict {
    id _listenerProtocol;
    Library *_library;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)setUp {
    [super setUp];
    
    // Creates a strict mock based on protocol.
    // You can also use OCMStrictClassMock([ListenerAdapter class]) for classes
    _listenerProtocol = OCMStrictProtocolMock(@protocol(ListenerProtocol));
    
    _library = [[Library alloc] initWithProtocol:_listenerProtocol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_strict_mock {
    // Please, comment a expect call below and you will see an exception, so the test will fail.
    OCMExpect([_listenerProtocol functionWithoutArg]);
    
    [_library call_functionWithoutArg];
    
    OCMVerifyAll(_listenerProtocol);
}
@end