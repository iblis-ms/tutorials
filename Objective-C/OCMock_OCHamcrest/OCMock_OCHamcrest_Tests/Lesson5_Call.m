// Created by Marcin Serwach on 28/09/16.
//
// Lesson 5: Call
//
// This lesson shows how to invoke a method when a mocked method is called.
//
// Keywords:
// 1. andCall
// 2. andDo

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson5_Call : XCTestCase
@end

@implementation Lesson5_Call {
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

- (void)invokedMethod {
    NSLog(@"Invoked method\n");
}

- (void)test_andCall {
    // You can provide an object and its selector that will be called when an expected method
    // will be called.
    // Here is method without argumetns.
    OCMExpect([_listenerProtocol functionWithoutArg]).andCall(self, @selector(invokedMethod));
    
    [_library call_functionWithoutArg];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)invokedMethod2:(NSString *)arg1 {
    NSLog(@"Invoked method: %@\n", arg1);
}

- (void)test_andCall_arg {
    // You can call also method with arguments. However arguments will be the same arguments,
    // that were passed to mocked method.
    // In this case 'invokeMethod2:' will be called with 'value' argument, because it is passed
    // to 'functionWithArg1String' method.
    OCMExpect([_listenerProtocol functionWithArg1String: [OCMArg any]]).andCall(self, @selector(invokedMethod2:));
    
    NSString *value = @"abc";
    [_library call_functionWithArg1String:value];
    
    OCMVerifyAll(_listenerProtocol);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_andDo {
    // You can also provide a block that will be called. This option requires to return
    // a value that will be returned from mocked method.
    OCMExpect([_listenerProtocol functionWithReturnString]).andDo(^(NSInvocation *invocation)
                                                                  {
                                                                      NSString *abc = @"abc";
                                                                      [invocation setReturnValue:&abc]; });
    NSString *value = @"abc";
    NSString *result = [_library call_functionWithReturnString];
    
    OCMVerifyAll(_listenerProtocol);
    
    XCTAssertEqual(result, value);
}

@end