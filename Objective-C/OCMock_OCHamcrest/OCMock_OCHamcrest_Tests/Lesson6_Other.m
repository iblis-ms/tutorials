// Created by Marcin Serwach on 28/09/16.
//
// Lesson 6: Other
//
// This lesson shows how to throw an exception from mocked method and how to send notifications.
//
// Keywords:
// 1. andThrow
// 2. andPost

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson6_Other : XCTestCase
@end

@implementation Lesson6_Other {
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

- (void)test_andThrow {
    NSException *exception = [NSException
                      exceptionWithName:@"TestException"
                      reason:@"because I can"
                      userInfo:nil];
    // You can throw an exception when a mocked method will be called.
    OCMExpect([_listenerProtocol functionWithoutArg]).andThrow(exception);
    
    BOOL expectionCought = NO;
    @try {
        // this will called mocked method, so an exception will be thrown.
        [_library call_functionWithoutArg];
    }
    @catch(NSException *e) {
        expectionCought = YES;
    }
    
    OCMVerifyAll(_listenerProtocol);
    
    XCTAssertTrue(expectionCought);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_andPost {
    // Adds observer for the notification.
    [[NSNotificationCenter defaultCenter] addObserverForName:@"MyNotification" object:self queue:nil usingBlock:^(NSNotification *note){
        NSLog(@"NOTIFICATION");
    }];
    
    // prepares a notification
    NSNotification *notification = [[NSNotification alloc] initWithName:@"MyNotification" object:self userInfo:nil];
    // This is an example how to send a notification when a mocked method will be called.
    OCMExpect([_listenerProtocol functionWithoutArg]).andPost(notification);
    
    [_library call_functionWithoutArg];
    
    OCMVerifyAll(_listenerProtocol);
}
@end