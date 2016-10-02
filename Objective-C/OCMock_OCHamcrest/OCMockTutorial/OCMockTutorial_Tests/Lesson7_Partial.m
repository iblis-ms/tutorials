// Created by Marcin Serwach on 28/09/16.
//
// Lesson 7: Partial mocking
//
// This lesson shows how to use a partial mocking. The partial mocking means that
// only some method will be mocked. You need to provide an real object.
//
// Keywords:
// 1. OCMPartialMock
// 2. andForwardToRealObject

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson7_Partial : XCTestCase
@end

@implementation Lesson7_Partial {
    id _listenerPartial;
    Library *_library;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)setUp {
    [super setUp];
    // Creates a partial mock. You need to provide a real object.
    _listenerPartial = OCMPartialMock([ListenerAdapter new]);
    
    _library = [[Library alloc] initWithProtocol:_listenerPartial];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_andForwardToRealObject {
    // Partial mocking allows a forwarding a method calling to real object.
    OCMStub([_listenerPartial functionWithoutArg]).andForwardToRealObject();
    
    [_library call_functionWithoutArg];
    
    OCMVerify([_listenerPartial functionWithoutArg]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_andForwardToRealObject_arg {
    // You can also forward a method call with an argument.
    OCMStub([_listenerPartial functionWithArg1:1]).andForwardToRealObject();
    
    [_library call_functionWithArg1:1];
    
    OCMVerify([_listenerPartial functionWithArg1:1]);
}
@end