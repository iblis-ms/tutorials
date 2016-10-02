// Created by Marcin Serwach on 28/09/16.
//
// Lesson 10: OCHamcrest: Number matchers
//
// This lesson shows how to use number matchers from OCHamcrest in mocked methods by OCMock.
//
// Most of OCHamcrest matchers works only with objects, not primitives.
//
// Keywords:
// 1. greaterThan
// 2. greaterThanOrEqualTo
// 3. lessThan
// 4. lessThanOrEqualTo
// 5. closeTo
// 6. isFalse
// 7. isTrue

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

// includes header of OCHamcrest library.
#import <OCHamcrest/OCHamcrest.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"


@interface Lesson10_OCHamcrest_Numbers : XCTestCase
@end

@implementation Lesson10_OCHamcrest_Numbers {
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

- (void)test_GreaterThan {
    NSNumber *value = [NSNumber numberWithInt:10];
    NSNumber *lowerValue = [NSNumber numberWithInt:9];
    // greaterThan - The argument of mocked method must be greater than 'lowerValue'.
    // If the argument doesn't fulfil a matcher, the expect call is treaten as not called.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:greaterThan(lowerValue)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_GreaterThanOrEqual {
    NSNumber *value = [NSNumber numberWithInt:10];
    NSNumber *lowerValue = [NSNumber numberWithInt:10];
    // greaterThanOrEqualTo - The argument of mocked method must be greater or equal 'lowerValue'
    OCMExpect([_listenerProtocol functionWithArg1NSValue:greaterThanOrEqualTo(lowerValue)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_LessThan {
    NSNumber *value = [NSNumber numberWithInt:9];
    NSNumber *lowerValue = [NSNumber numberWithInt:10];
    // lessThan - The argument of mocked method must be less than 'lowerValue'.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:lessThan(lowerValue)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_LessThanOrEqual {
    NSNumber *value = [NSNumber numberWithInt:10];
    NSNumber *lowerValue = [NSNumber numberWithInt:10];
    // lessThanOrEqualTo - The argument of mocked method must be less or equal 'lowerValue'
    OCMExpect([_listenerProtocol functionWithArg1NSValue:lessThanOrEqualTo(lowerValue)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_CloseToNSValue {
    NSNumber *value = [NSNumber numberWithDouble:10];
    const double expectedValue = 10.1;
    const double near = 0.2;
    // closeTo - The argument of mocked method must be closed to 'expectedValue', which means
    // (expectedValue - near) < argument < (expectedValue + near)
    OCMExpect([_listenerProtocol functionWithArg1NSValue:closeTo(expectedValue, near)]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_IsFalse {
    NSNumber *value = [NSNumber numberWithBool:NO];
    // isFalse - The argument of mocked method must be NO/false.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:isFalse()]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_IsTrue {
    NSNumber *value = [NSNumber numberWithBool:YES];
    // isTrue - The argument of mocked method must be YES/true.
    OCMExpect([_listenerProtocol functionWithArg1NSValue:isTrue()]);
    
    [_library call_functionWithArg1NSValue:value];
    
    OCMVerifyAll(_listenerProtocol);
}

@end