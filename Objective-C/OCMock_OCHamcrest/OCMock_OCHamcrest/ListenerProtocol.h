// Created by Marcin Serwach on 28/09/16.

#import <Foundation/Foundation.h>
#import "CustomClass.h"

// This is a listener whose mock objects will be used.
@protocol ListenerProtocol <NSObject>

- (void)functionWithoutArg;

- (void)functionWithArg1:(int)arg1;

- (void)functionWithArg1:(int)arg1 arg2:(int)arg2;

- (void)functionWithArg1String:(NSString *)arg1;

- (void)functionWithArg1CustomClass:(CustomClass *)arg1;

- (void)functionWithArg1Selector:(SEL)arg1;

- (int)functionWithReturn;

- (NSString *)functionWithReturnString;

- (void)functionWithArg1Pointer:(int *)arg1;

typedef void (^VoidBlock)();

- (void)functionWithArg1Block:(VoidBlock)arg1;

typedef void (^BlockArg)(int, NSString *);

- (void)functionWithArg1BlockArg:(BlockArg)arg1;

- (void)functionWithArg1PointerPointerString:(NSString **)arg1;

- (void)functionWithArg1NSValue:(NSValue *)arg1;

- (void)functionWithArg1Double:(double)arg1;

- (void)functionWithArg1NSArray:(NSArray<NSString *> *)arg1;

- (void)functionWithArg1NSDictionary:(NSDictionary *)arg1;

@end