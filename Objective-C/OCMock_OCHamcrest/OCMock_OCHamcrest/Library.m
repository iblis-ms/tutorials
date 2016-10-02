// Created by Marcin Serwach on 28/09/16.

#import "Library.h"

@implementation Library {
    id<ListenerProtocol> _listener;
}

- (instancetype)initWithProtocol:(id<ListenerProtocol>)listener {
    if ((self = [super init])) {
        _listener = listener;
    }
    return self;
}

- (void)call_functionWithoutArg {
    [_listener functionWithoutArg];
}

- (void)call_functionWithArg1:(int)arg1 {
    [_listener functionWithArg1:arg1];
}

- (void)call_functionWithArg1:(int)arg1 arg2:(int)arg2 {
    [_listener functionWithArg1:arg1 arg2:arg2];
}

- (void)call_functionWithArg1String:(NSString *)arg1 {
    [_listener functionWithArg1String:arg1];
}

- (void)call_functionWithArg1CustomClass:(CustomClass *)arg1 {
    [_listener functionWithArg1CustomClass:arg1];
}

- (void)call_functionWithArg1Selector:(SEL)arg1 {
    [_listener functionWithArg1Selector:arg1];
}

- (int)call_functionWithReturn {
    return [_listener functionWithReturn];
}

- (NSString *)call_functionWithReturnString {
    return [_listener functionWithReturnString];
}

- (void)call_functionWithArg1Pointer:(int *)arg1 {
    [_listener functionWithArg1Pointer:arg1];
}

- (void)call_functionWithArg1Block:(VoidBlock)arg1 {
    [_listener functionWithArg1Block:arg1];
}


- (void)call_functionWithArg1BlockArg:(BlockArg)arg1 {
    [_listener functionWithArg1BlockArg:arg1];
}

- (void)call_functionWithArg1PointerPointerString:(NSString **)arg1 {
    [_listener functionWithArg1PointerPointerString:arg1];
}

- (void)call_functionWithArg1NSValue:(NSValue *)arg1 {
    [_listener functionWithArg1NSValue:arg1];
    
}
- (void)call_functionWithArg1Double:(double)arg1 {
    [_listener functionWithArg1Double:arg1];
}

- (void)call_functionWithArg1NSArray:(NSArray<NSString *> *)arg1 {
    [_listener functionWithArg1NSArray:arg1];
}

- (void)call_functionWithArg1NSDictionary:(NSDictionary *)arg1 {
    [_listener functionWithArg1NSDictionary:arg1];
}

@end
