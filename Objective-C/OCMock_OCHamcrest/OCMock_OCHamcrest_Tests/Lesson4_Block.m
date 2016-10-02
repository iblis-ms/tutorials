// Created by Marcin Serwach on 28/09/16.
//
// Lesson 4: Block
//
// This lesson shows how to call a block that was passed as an argument.
//
// Keywords:
// 1. [OCMArg invokeBlock]
// 2. [OCMArg invokeBlockWithArgs:]

#import <XCTest/XCTest.h>

// Includes header of OCMock library.
#import <OCMock/OCMock.h>

#import "Library.h"
#import "ListenerProtocol.h"
#import "ListenerAdapter.h"

@interface Lesson4_Block : XCTestCase

@end

@implementation Lesson4_Block {
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

- (void)test_invokeBlock {
    VoidBlock block = ^{
        NSLog(@"test_Expect_FunctionWithArg1Block block");
    };
    // You can set a expect call whose argument is a block, which will be invoked.
    OCMExpect([_listenerProtocol functionWithArg1Block:[OCMArg invokeBlock]]);
    
    [_library call_functionWithArg1Block:block];
    
    OCMVerifyAll(_listenerProtocol);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

- (void)test_invokeBlockWithArgs {
    BlockArg block = ^(int arg1, NSString *arg2){
        NSLog(@"test_Expect_FunctionWithArg1Block arg1=%d arg2=%@", arg1, arg2);
    };
    // You can also call block with arguments. However you have to:
    // - pass 'NSNumber' 'int' argument
    // - pass nil as the last argument
    OCMExpect([_listenerProtocol functionWithArg1BlockArg:([OCMArg invokeBlockWithArgs:[NSNumber numberWithInt:1], @"abc", nil])]);
    
    [_library call_functionWithArg1BlockArg:block];
    
    OCMVerifyAll(_listenerProtocol);
}

@end