// Created by Marcin Serwach on 14/10/16.
//
// Lesson 15: KNMParametrizedTest - parametrized tests
//
// This lesson shows how to write parametrized tests. This approach allows using
// the same test for different sets of data.
//
// Keywords:
// 1. KNMParametrizedTests
// 2. KNMParametersFor
// 3. parametersForTestWithSelector
// 4. NIL
// 5. VALUE

#import <XCTest/XCTest.h>
#import <KNMParametrizedTests/KNMParametrizedTests.h>

@interface Lesson15_KNMParametrizedTest : XCTestCase
@end

@implementation Lesson15_KNMParametrizedTest

///////////////////// MACROS ////////////////////////

// KNMParametersFor is a macro whose arguments will be passed to the test. Each test run will have one value form the given table.
// Arguments:
// testSimple_String - a name of test.
// @[@"Value1", @"Value2"] - an array of value. The given test will be run with one item from this array.
KNMParametersFor(testSimple_String, @[@"Value1", @"Value2"])
- (void)testSimple_String:(NSString *)arg
{
    NSLog(@"testSimple_String arg: %@", arg);
    BOOL result = [arg hasPrefix:@"Value"];
    XCTAssertTrue(result);
}

// Another example.
KNMParametersFor(testSimple_Number, @[@1, @2])
- (void)testSimple_Number:(NSNumber *)arg
{
    NSLog(@"testSimple_Number arg: %d", [arg intValue]);
    BOOL result = [arg intValue] < 10;
    XCTAssertTrue(result);
}

// You can provide NSDictonary to each test run to easily get values.
KNMParametersFor(testSimpler_Dictionary, @[@{@"key1" : @"value_A1", @"key2" : @"value_A2"}, @{@"key1" : @"value_B1", @"key2" : @"value_B2"}])
- (void)testSimpler_Dictionary:(NSDictionary *)arg
{
    NSString *value1 = arg[@"key1"];
    NSString *value2 = arg[@"key2"];
    NSLog(@"testSimpler_Dictionary arg.value1: %@ arg.value2: %@", value1, value2);
    
    BOOL result = [value1 hasPrefix:@"value_A"] || [value2 hasPrefix:@"value_B"];
    XCTAssertTrue(result);
}

///////////////////// DATA BY NAME ////////////////////////

// You write a class method that returns a NSArray object with values for test.
// The name of method must start with 'parametersFor' and after that must be
// a name of a test. The first letter of name must be upper case.
//
// Here: parametersForTestDataFromMethod will provide data for testDataFromMethod
+ (NSArray *)parametersForTestDataFromMethod {
    return @[@10, @20];
}

- (void)testDataFromMethod:(NSUInteger)arg {
    NSLog(@"testDataFromMethod arg: %ld", arg);
    XCTAssertTrue(arg >= 10);
}

// You can use name with underscore and test name without upper case.
+ (NSArray *)parametersFor_testDataFromMethodUnderscore {
    return @[@30, @40];
}

- (void)testDataFromMethodUnderscore:(NSUInteger)arg {
    NSLog(@"testDataFromMethodUnderscore arg: %ld", arg);
    XCTAssertTrue(arg >= 10);
}

///////////////////// DATA BY SELECTOR ////////////////////////

// There is another approach. You can write a class method '(NSArray *)parametersForTestWithSelector:(SEL)selector'
// which should return an array of data for test based on selector. The provided
// selector is a selector of a test method.
+ (NSArray *)parametersForTestWithSelector:(SEL)selector {
    if (selector == @selector(testMethodSelectorString:)) {
        // return values for 'testMethodSelectorString:' - array of NSString
        return @[@"a", @"b"];
    }
    else if (selector == @selector(testMethodSelectorNumber:)) {
        // return values for 'testMethodSelectorNumber:' - array of NSNumber
        return @[@1, @2];
    }
    return nil;
}

- (void)testMethodSelectorString:(NSString*)arg{
    
    NSLog(@"testMethodSelectorString arg: %@", arg);
    BOOL result = (arg.length == 1);
    XCTAssertTrue(result);
}

- (void)testMethodSelectorNumber:(NSNumber*)arg{
    NSLog(@"testMethodSelectorNumber arg: %d", [arg intValue]);
    BOOL result = [arg intValue] < 10;
    XCTAssertTrue(result);
}

///////////////////// C STRUCTURES ////////////////////////

// VALUE macro helps to return C structures.
+ (NSArray *)parametersForTest_CStyleStructures {
    return @[ VALUE(NSMakeRange(10, 10)), VALUE(NSMakeRange(20, 20)) ];
}

- (void)test_CStyleStructures:(NSRange)range {
    NSLog(@"test_CStyleStructures range.location: %ld range.length: %ld", range.location, range.length);
    XCTAssertTrue(range.length >= 10);
}

///////////////////// NIL ////////////////////////

// NIL is a special macro for nil value.
+ (NSArray *)parametersForTestStringNil {
    return @[@"", NIL];
}

- (void)testStringNil:(NSString *)arg {
    NSLog(@"tTestStringNil arg: %@", arg);
    XCTAssertTrue(arg == nil || arg.length == 0);
}

@end