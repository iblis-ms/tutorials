// Created by Marcin Serwach on 28/09/16.

#import "ListenerAdapter.h"

@implementation ListenerAdapter

- (void)functionWithoutArg {
    NSLog(@"ListenerAdapter: functionWithoutArg");
}

- (void)functionWithArg1:(int)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1 arg1=%d", arg1);
}

- (void)functionWithArg1:(int)arg1 arg2:(int)arg2 {
    NSLog(@"ListenerAdapter: functionWithArg1 arg1=%d arg2=%d", arg1, arg2);
}

- (void)functionWithArg1String:(NSString *)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1String arg1=%@", arg1);
    
}

- (void)functionWithArg1CustomClass:(CustomClass *)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1CustomClass");
}

- (void)functionWithArg1Selector:(SEL)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1Selector");
}

- (int)functionWithReturn {
    NSLog(@"ListenerAdapter: functionWithoutArg");
    return 0;
}

- (NSString *)functionWithReturnString {
    NSLog(@"ListenerAdapter: functionWithReturnString");
    return @"abc";
}

- (void)functionWithArg1Pointer:(int *)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1Pointer");
}


- (void)functionWithArg1Block:(VoidBlock)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1Block");
}

- (void)functionWithArg1BlockArg:(BlockArg)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1BlockArg");
}

- (void)functionWithArg1PointerPointerString:(NSString **)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1PointerPointerString");
}


- (void)functionWithArg1NSValue:(NSValue *)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1NSValue arg1=%@", arg1);
}


- (void)functionWithArg1Double:(double)arg1 {
    NSLog(@"ListenerAdapter: functionWithArg1Double arg1=%f", arg1);
}

- (void)functionWithArg1NSArray:(NSArray<NSString *> *)arg1 {
    
}

- (void)functionWithArg1NSDictionary:(NSDictionary *)arg1 {
    
}

@end
