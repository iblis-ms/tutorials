// Created by Marcin Serwach on 28/09/16.
//
// Lesson 14: OCHamcrest: Logic operators
//
// This lesson shows how to link matchers
//
// Keywords:
// 1. allOf
// 2. allOfIn
// 3. anyOf
// 4. anyOfIn
// 5. anything
// 6. isNot

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

// includes header of OCHamcrest library.
#import <OCHamcrest/OCHamcrest.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"


@interface Lesson14_OCHamcrest_Logic : XCTestCase
@end

@implementation Lesson14_OCHamcrest_Logic {
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

- (void)test_allOf {
    NSNumber *value = [NSNumber numberWithInt:10];
    NSNumber *lowerValue = [NSNumber numberWithInt:9];
    NSNumber *greaterValue = [NSNumber numberWithInt:11];
    // allOf - It links matchers and all of them must be fulfilled. This is a boolean operator &&.
    // The expected call below expects an argument that fulfils: 9 < x < 11.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:allOf(greaterThan(lowerValue), lessThan(greaterValue), nil)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_allOfIn {
    NSNumber *value = [NSNumber numberWithInt:10];
    NSNumber *lowerValue = [NSNumber numberWithInt:9];
    NSNumber *greaterValue = [NSNumber numberWithInt:11];
    // allOfIn - It is a array version of 'allOf'.
    // The expected call below expects an argument that fulfils: 9 < x < 11.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:allOfIn(@[greaterThan(lowerValue), lessThan(greaterValue)])]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_anyOf {
    NSNumber *value = [NSNumber numberWithInt:3];
    NSNumber *lowerValue = [NSNumber numberWithInt:9];
    NSNumber *greaterValue = [NSNumber numberWithInt:11];
    // anyOf - It links matchers and at least one of them must be fulfilled. This is a boolean operator ||.
    // The expected call below expects an argument that fulfils: x < 9 || 11 < x
    OCMExpect([_listenerProtocol functionWithArg1NSValue:anyOf(greaterThan(greaterValue), lessThan(lowerValue), nil)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_anyOfIn {
    NSNumber *value = [NSNumber numberWithInt:3];
    NSNumber *lowerValue = [NSNumber numberWithInt:9];
    NSNumber *greaterValue = [NSNumber numberWithInt:11];
    // anyOfIn - It is a array version of 'anyOf'.
    // The expected call below expects an argument that fulfils: x < 9 || 11 < x
    OCMExpect([_listenerProtocol functionWithArg1NSValue:anyOfIn(@[greaterThan(greaterValue), lessThan(lowerValue)])]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_anything {
    NSNumber *value = [NSNumber numberWithInt:3];
    // anything - This is a matcher that allows passing any argument.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:anything()]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isNot {
    NSNumber *value = [NSNumber numberWithInt:8];
    NSNumber *lowerValue = [NSNumber numberWithInt:9];
    // isNot - This is a matcher that negates a given matcher.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:isNot(greaterThan(lowerValue))]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

@end