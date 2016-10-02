// Created by Marcin Serwach on 28/09/16.
//
// Lesson 2: Advanced Matchers
//
// This lesson shows how to establish conditions on arguments. You can provide
// a condition that must be fulfilled. If a condition is not fulfilled, an expected
// method is treaten as not called.
//
// Keywords:
// 1. [OCMArg any]
// 2. [OCMArg anyPointer]
// 3. [OCMArg anySelector]
// 4. [OCMArg isNil]
// 5. [OCMArg isNotNil]
// 6. [OCMArg isNotEqual:]
// 7. [OCMArg isKindOfClass:]
// 8. [OCMArg checkWithSelector: onObject:]
// 9. [OCMArg checkWithBlock:]

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson2_AdvancedMatcher : XCTestCase
@end

@implementation Lesson2_AdvancedMatcher {
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

- (void)test_any {
    NSString *value = @"abc";
    // If we don't what to set any condition on argument, we can use [OCMArg any].
    OCMExpect([_listenerProtocol functionWithArg1String:[OCMArg any]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_anyPointer {
    int value = 3;
    // You can also expect any pointer as an argument of a mock method call.
    OCMExpect([_listenerProtocol functionWithArg1Pointer:(int*)[OCMArg anyPointer]]);
    
    [_library call_functionWithArg1Pointer:&value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

+(void)testSelector {
}

- (void)test_anySelector {
    // You can also expect a method call with any selector as an argument.
    OCMExpect([_listenerProtocol functionWithArg1Selector:[OCMArg anySelector]]);

    [_library call_functionWithArg1Selector:@selector(testSelector)];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isNil {
    NSString *value = nil;
    // You can expect a method call with 'nil' argument.
    OCMExpect([_listenerProtocol functionWithArg1String:[OCMArg isNil]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isNotNil {
    NSString *value = @"abc";
    // You can expect a method call with not 'nil' argument.
    OCMExpect([_listenerProtocol functionWithArg1String:[OCMArg isNotNil]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isNotEqual {
    NSString *value = @"abc";
    // You can expect a method call with an argument that is not equal as a givne value.
    OCMExpect([_listenerProtocol functionWithArg1String:[OCMArg isNotEqual:@"def"]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isKindOfClass {
    NSString *value = @"abc";
    // You can expect a method call with an argument that is a object of a given class.
    OCMExpect([_listenerProtocol functionWithArg1String:[OCMArg isKindOfClass:[NSString class]]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (BOOL)checkSelector:(NSString *)arg1 {
    return [arg1 isEqualToString:@"abc"];
}

- (void)test_checkWithSelector {
    NSString *value = @"abc";
    // You can expect a method call with an argument that will be checked by given selector.
    // You need to provide a selector and an object whose selector will be called.
    // Note that the argument of selector should match to the type of the argument.
    OCMExpect([_listenerProtocol functionWithArg1String:
               [OCMArg checkWithSelector:@selector(checkSelector:) onObject:self]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_checkWithBlock {
    NSString *value = @"abc";
    // You can expect ethod call with an argument that will be checked by given block.
    OCMExpect([_listenerProtocol functionWithArg1String:[OCMArg checkWithBlock:^BOOL(id value){
        return [@"abc" isEqual:value];
    }]]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

@end