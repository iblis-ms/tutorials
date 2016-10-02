// Created by Marcin Serwach on 28/09/16.
//
// Lesson 12: OCHamcrest: Container mathers.
//
// This lesson shows how to use container matchers from OCHamcrest in mocked methods by OCMock.
//
// Matchers that end with 'In' require array. The rest of matchers have a argument - array.
//
// Keywords:
// 1. contains
// 2. containsIn
// 3. containsInAnyOrder
// 4. containsInAnyOrderIn
// 5. everyItem
// 6. hasCount
// 7. hasCountOf
// 8. hasEntries
// 9. hasEntriesIn
// 10. hasEntry
// 11. hasItem
// 12. hasItems
// 13. hasItemsIn
// 14. hasKey
// 15. hasValue
// 16. isEmpty
// 17. isIn
// 18. onlyContains
// 19. onlyContainsIn

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

// includes header of OCHamcrest library.
#import <OCHamcrest/OCHamcrest.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"


@interface Lesson12_OCHamcrest_Container : XCTestCase
@end

@implementation Lesson12_OCHamcrest_Container {
    id _listenerProtocol;
    Library *_library;
}

- (void)setUp {
    [super setUp];
    // Creates a strict mock based on protocol.
    _listenerProtocol = OCMStrictProtocolMock(@protocol(ListenerProtocol));
    
    _library = [[Library alloc] initWithProtocol:_listenerProtocol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_contains {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // contains - The argument of mocked method must contain given values. The last argument
    // must be nil.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:contains(@"a", @"b", @"c", nil)]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_containsIn {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // containsIn - The argument of mocked method must contain given values. Expected values are
    // passing as an array.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:containsIn(@[@"a", @"b", @"c"])]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_containsInAnyOrders {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // containsInAnyOrder - The argument of mocked method must contain given values in any order.
    // The last argument must be nil.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:containsInAnyOrder(@"b", @"a", @"c", nil)]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_containsInAnyOrderIn {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // containsInAnyOrderIn - The argument of mocked method must contain given values in any order.
    // Expected values are passing as an array.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:containsInAnyOrderIn(@[@"c", @"b", @"a"])]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_everyItem {
    NSArray<NSString *> *value = @[@"c", @"c", @"c"];
    // everyItem - The argument of mocked method must contain all values that fulfil a given matcher.
    // Here it is 'is' matcher, which means that each value of container must have 'c' string.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:everyItem(is(@"c"))]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasCount_NSArray {
    NSArray<NSString *> *value = @[@"c", @"c", @"c"];
    NSNumber* size = [NSNumber numberWithInt:3];
    // hasCount - The argument of mocked method must be a container whose size fulfils a given matcher.
    // Here it is 'is' matcher, so the size must be equal 'size' variable.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:hasCount(is(size))]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasCount_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    NSNumber* size = [NSNumber numberWithInt:3];
    // as above, but here NSDictionary is used.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasCount(is(size))]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasCountOf_NSArray {
    NSArray<NSString *> *value = @[@"c", @"c", @"c"];
    // hasCountOf - The argument of mocked method must be a container with given size.
    // It is similar to hasCount, but here you have to provide a number not matcher.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:hasCountOf(3)]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasCountOf_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // As above, but NSDictionary is used.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasCountOf(3)]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasEntries {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasEntries - The argument of mocked method must be a dictionary that has following
    // elements. For values you need to provide a matcher. You don't have to specify all values.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasEntries(
                                        @"a", is(@"1"), @"b", is(@"2"), nil)]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasEntriesIn {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    NSDictionary *expect = @{
                             @"a" : @"1",
                             @"b" : @"2"
                             };
    // hasEntriesIn - It is similar to hasEntries, but here you need to provide a NSDictionary object.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasEntriesIn(expect)]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasEntry {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasEntry - It is similar to hasEntries, but it is for only one value.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasEntry(@"a", @"1")]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////


- (void)test_hasItem_NSArray {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // hasItem - The argument of mocked method must have a value that fulfils a given matcher.
    // You can also provide a value, not matcher.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:hasItem(is(@"c"))]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasItem_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasItem - This is a verison of hasItem for NSDictionary. This 'hasItem' is for KEY,
    // not for value.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasItem(@"c")]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasItems_NSArray {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // hasItems - This is a version of 'hasItem' for more than one value. The last item must be
    // nil.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:hasItems(@"c", @"b", nil)]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasItems_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasItems - 'hasItems' checks keys of NSDictionary.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasItems(@"c", @"b", nil)]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasItemsIn_NSArray {
    NSArray<NSString *> *value = @[@"a", @"b", @"c"];
    // hasItemsIn - This is a 'hasItems' for an array.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:hasItemsIn(@[@"c", @"b"])]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasItemsIn_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasItemsIn - As above but for NSDictonary. It checks keys.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasItemsIn(@[@"c", @"b"])]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasKey_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasKey - It checks if an argument has a given key or fulfils a given matcher.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasKey(@"c")]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasValue_NSDictionary {
    NSDictionary *value = @{
                            @"a" : @"1",
                            @"b" : @"2",
                            @"c" : @"3"
                            };
    // hasValue - It checks if an argument has a given value or fulfils a given matcher.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:hasValue(@"2")]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isEmpty_NSArray {
    NSArray<NSString *> *value = @[];
    // isEmpty - It checks if a container is empty.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:isEmpty()]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isEmpty_NSDictionary {
    NSDictionary *value = @{
                            };
    // As above but for NSDictionary.
    OCMExpect([_listenerProtocol functionWithArg1NSDictionary:isEmpty()]);
    
    [_library call_functionWithArg1NSDictionary:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isIn {
    NSString *value = @"a";
    // isIn - The argument of mocked method must be equal to one of a value from given array.
    OCMExpect([_listenerProtocol functionWithArg1String:isIn(@[@"b", @"c", @"a"])]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_onlyContains {
    NSArray<NSString *> *value = @[@"aaa", @"bbb", @"aaa"];
    // onlyContains - The container in the argument must contains given values in arbitrary order.
    // The last argument must be nil.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:onlyContains(@"aaa", @"bbb", nil)]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_onlyContainsIn {
    NSArray<NSString *> *value = @[@"aaa", @"bbb", @"bbb"];
    // onlyContains - The container in the argument must contains given values in arbitrary order.
    OCMExpect([_listenerProtocol functionWithArg1NSArray:onlyContainsIn(@[@"aaa", @"bbb"])]);
    
    [_library call_functionWithArg1NSArray:value];
    
    OCMVerifyAll(_listenerProtocol);
}

@end