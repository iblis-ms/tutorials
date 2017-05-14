# GTest & GMock tutorial - lesson 9 - GTest: Filters
GTest allows to run only specific tests. You can pass a regular expression that filters test.

# How to filter tests
This lesson contains following test:
- CMyTestCase1.testCase_fail
- CMyTestCase1.testCase_success
- CMyTestCase2.testCase_fail
- CMyTestCase2.testCase_success

The test program can be run with `--gtest_filter=regex` arguments to filter tests. Look at the examples below:
1. `./library_test  --gtest_filter=*`
Runs all test cases with all tests - without filtering
2. `./library_test  --gtest_filter=CMyTestCase1.*`
Runs tests from *CMyTestCase1* test case: 
- CMyTestCase1.testCase_fail
- CMyTestCase1.testCase_success
3. `./library_test  --gtest_filter=*.testCase_success`
Runs tests from any test case whose name is *testCase_success*
- CMyTestCase1.testCase_success
- CMyTestCase2.testCase_success
4. `./library_test --gtest_filter=*TestCase1.TestCase1*`
Runs tests whose full names contain *TestCase1.testCase*, so names of tests case end with *TestCase1* and test names start with *TestCase1*.
- CMyTestCase1.testCase_fail
- CMyTestCase1.testCase_success
5. `./library_test --gtest_filter=*TestCase*.*fail`
Runs tests whose test case contains *TestCase* and the name of test itself ends with *fail*.
- CMyTestCase1.testCase_fail
- CMyTestCase2.testCase_fail
6. `./library_test --gtest_filter=-*TestCase*.*fail`
Note, minus sign, which negates filter.
- CMyTestCase1.testCase_success
- CMyTestCase2.testCase_success

# Other parameters
# # Shuffle
You can shuffle test to check if there are not related to each other by passing *--gtest_shuffle*.
# # Repeat
You can repeat test by providing *--gtest_repeat=1000* or repeat forever: *--gtest_repeat=-1*. You can repeat only filtered tests: *gtest_repeat=1000 --gtest_filter=FooBar*.

# Target of this lesson
After this lesson you will know how to:
- run specific tests by passing filter
- shuffle tests
- repeat tests

*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock)*
