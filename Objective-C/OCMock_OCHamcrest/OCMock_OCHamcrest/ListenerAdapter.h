// Created by Marcin Serwach on 28/09/16.

#import <Foundation/Foundation.h>
#import "ListenerProtocol.h"

// This an adapter of a listener protocol.
@interface ListenerAdapter : NSObject<ListenerProtocol>

- (void)functionWithoutArg;

- (void)functionWithArg1:(int)arg1;

- (void)functionWithArg1:(int)arg1 arg2:(int)arg2;

- (void)functionWithArg1String:(NSString *)arg1;

- (void)functionWithArg1CustomClass:(CustomClass *)arg1;

- (void)functionWithArg1Selector:(SEL)arg1;

- (int)functionWithReturn;

- (NSString *)functionWithReturnString;

- (void)functionWithArg1Pointer:(int *)arg1;

- (void)functionWithArg1Block:(VoidBlock)arg1;

- (void)functionWithArg1BlockArg:(BlockArg)arg1;

- (void)functionWithArg1PointerPointerString:(NSString **)arg1;

@end
