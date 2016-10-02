// Created by Marcin Serwach on 28/09/16.
//
// Lesson 11: OCHamcrest: Text matchers
//
// This lesson shows how to use text matchers from OCHamcrest in mocked methods by OCMock.
//
// Keywords:
// 1. containsSubstring
// 2. endsWith
// 3. startsWith
// 4. equalToIgnoringCase
// 5. stringContainsInOrder
// 6. stringContainsInOrderIn

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

// includes header of OCHamcrest library.
#import <OCHamcrest/OCHamcrest.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"


@interface Lesson11_OCHamcrest_Text : XCTestCase
@end

@implementation Lesson11_OCHamcrest_Text {
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

- (void)test_containsSubstring {
    NSString *value = @"aaaabbbccc";
    NSString *expected = @"bbb";
    // containsSubstring - The argument of mocked method must contain 'expected' string.
    OCMExpect([_listenerProtocol functionWithArg1String:containsSubstring(expected)]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_endsWith {
    NSString *value = @"aaaabbbccc";
    NSString *expected = @"ccc";
    // endsWith - The argument of mocked method must end with 'expected' string.
    OCMExpect([_listenerProtocol functionWithArg1String:endsWith(expected)]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_startsWith {
    NSString *value = @"aaaabbbccc";
    NSString *expected = @"aaa";
    // startsWith - The argument of mocked method must start with 'expected' string.
    OCMExpect([_listenerProtocol functionWithArg1String:startsWith(expected)]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_equalToIgnoringCase {
    NSString *value = @"aaaabbbccc";
    NSString *expected = @"AAAAbbbCCC";
    // equalToIgnoringCase - The argument of mocked method must be equal 'expected' ignoring letter case.
    OCMExpect([_listenerProtocol functionWithArg1String:equalToIgnoringCase(expected)]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_stringContainsInOrder {
    NSString *value = @"aaaabbbccc";
    // stringContainsInOrder - The argument of mocked method must contain given substrings in given order.
    // You have to provide strings but the last argument must be nil.
    OCMExpect([_listenerProtocol functionWithArg1String:stringContainsInOrder(@"a", @"bb", @"ccc", nil)]);
    [_library call_functionWithArg1String:value];
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_stringContainsInOrderIn {
    NSString *value = @"aaaabbbccc";
    // stringContainsInOrderIn - The argument of mocked method must contain given substrings in given order.
    // You have to provide an array.
    OCMExpect([_listenerProtocol functionWithArg1String:stringContainsInOrderIn(@[@"aaa", @"bbb", @"ccc"])]);
    [_library call_functionWithArg1String:value];
    OCMVerifyAll(_listenerProtocol);
}

@end