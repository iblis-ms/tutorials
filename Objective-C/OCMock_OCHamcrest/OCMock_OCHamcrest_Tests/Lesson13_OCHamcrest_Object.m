// Created by Marcin Serwach on 28/09/16.
//
// Lesson 13: OCHamcrest: Object Matchers
//
// This lesson shows how to use object matchers from OCHamcrest in mocked methods by OCMock.
//
// Keywords:
// 1. conformsTo
// 2. equalTo
// 3. hasDescription
// 4. hasProperty
// 5. instanceOf
// 6. isA
// 7. nilValue
// 8. notNilValue
// 9. sameInstance
// 10. throwsException

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

// includes header of OCHamcrest library.
#import <OCHamcrest/OCHamcrest.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"


@interface Lesson13_OCHamcrest_Object : XCTestCase
@end

@implementation Lesson13_OCHamcrest_Object {
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

- (void)test_conformsTo {
    CustomClass *value = [CustomClass new];
    // conformsTo - The argument of mocked method must implement a given protocol.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:conformsTo(@protocol(CustomClassProtocol))]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_equalTo {
    NSString *value = @"aaaabbbccc";
    // equalTo - The argument of mocked method must be equal a given object.
    OCMExpect([_listenerProtocol functionWithArg1String:equalTo(@"aaaabbbccc")]);
    
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasDescription {
    CustomClass *value = [CustomClass new];
    // hasDescription - The argument of mocked method must have a discription that fulfils a given
    // matcher or is equal to a given object.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:hasDescription(@"description")]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_hasProperty {
    CustomClass *value = [CustomClass new];
    // hasProperty - The argument of mocked method must have a property, whose name is given and
    // a value of this property must fulfil a givne matcher or be equal to a given object.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:hasProperty(@"strProperty", @"abc")]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_instanceOf {
    CustomClass *value = [CustomClass new];
    // instanceOf - The argument of mocked method must be an instance of a given class or an instance
    // of class that inherits a given class.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:instanceOf([NSObject class])]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_isA {
    CustomClass *value = [CustomClass new];
    // isA - The argument of mocked method must be an instance of a given class, NOT an instance
    // of class that inherits a given class.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:isA([CustomClass class])]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_nilValue {
    CustomClass *value = nil;
    // nilValue - The argument of mocked method must be nil.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:nilValue()]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_notNilValue {
    CustomClass *value = [CustomClass new];
    // notNilValue - The argument of mocked method mustn't be nil.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:notNilValue()]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_sameInstance {
    CustomClass *value = [CustomClass new];
    // sameInstance - The argument of mocked method must exactly the same as a given one.
    OCMExpect([_listenerProtocol functionWithArg1CustomClass:sameInstance(value)]);
    
    [_library call_functionWithArg1CustomClass:value];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_throwsException {
    NSException* exception = [NSException exceptionWithName:@"name" reason:@"reason" userInfo:nil];
    VoidBlock block = ^{ @throw exception;};
    // throwsException - It expects that a mocked method will throw an exception.
    OCMExpect([_listenerProtocol functionWithArg1Block:throwsException(sameInstance(exception))]);
    
    [_library call_functionWithArg1Block:block];
    
    OCMVerifyAll(_listenerProtocol);
}

@end