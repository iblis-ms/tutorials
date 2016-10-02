// Created by Marcin Serwach on 28/09/16.

#import <Foundation/Foundation.h>
#import "ListenerProtocol.h"

// This a class that contains methods which call listener methods.
// The listener object is provided by 'initWithProtocol'.
// Methods in this class have prefix 'call_' and after the prefix
// is a name of listener method, that is called by method of Library
// class. Arguments of methods are forwarded to listener's method.
@interface Library : NSObject

- (instancetype)initWithProtocol:(id<ListenerProtocol>)listener;

- (void)call_functionWithoutArg;

- (void)call_functionWithArg1:(int)arg1;

- (void)call_functionWithArg1:(int)arg1 arg2:(int)arg2;

- (void)call_functionWithArg1String:(NSString *)arg1;

- (void)call_functionWithArg1CustomClass:(CustomClass *)arg1;

- (void)call_functionWithArg1Selector:(SEL)arg1;

- (int)call_functionWithReturn;

- (NSString *)call_functionWithReturnString;

- (void)call_functionWithArg1Pointer:(int *)arg1;

typedef void (^VoidBlock)();

- (void)call_functionWithArg1Block:(VoidBlock)arg1;

typedef void (^BlockArg)(int, NSString *);

- (void)call_functionWithArg1BlockArg:(BlockArg)arg1;

- (void)call_functionWithArg1PointerPointerString:(NSString **)arg1;

- (void)call_functionWithArg1NSValue:(NSValue *)arg1;

- (void)call_functionWithArg1Double:(double)arg1;

- (void)call_functionWithArg1NSArray:(NSArray<NSString *> *)arg1;

- (void)call_functionWithArg1NSDictionary:(NSDictionary *)arg1;


@end
