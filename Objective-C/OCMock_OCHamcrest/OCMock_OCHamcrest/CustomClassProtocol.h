// Created by Marcin Serwach on 28/09/16.

#import <Foundation/Foundation.h>

// This is an example of a custom protocol.
@protocol CustomClassProtocol <NSObject>

@property NSString* strProperty;

- (void)custom_functionWithoutArg;

- (NSString *)custom_functionWithArg1Str:(NSString *)arg1;

@end
