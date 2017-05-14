# OCMock, OCHamcrest and KNMParametrizedTest tutorial
This tutorial contains one project that shows how to OCMock in version 3.3.1, OCHamcrest 6.0 and KNMParametrizedTest. All of them are widely used libraries for testing Objective-C code. OCMock provides some methods to create mocks and checking if expected calls was called with proper arguments. OCHamcrest contains several useful matchers. KNMParametrizedTest helps writing parametrized tests.s

# CocoaPods
OCMock, OCHamcrest and KNMParametrizedTest are downloaded by CocoaPods. To compile tutorial project you need to run:

```bash
pod install
```

After that you will have a workspace file `OCMock_OCHamcrest.xcworkspace` that should be opened in Xcode.

# Lesson
This tutorial was organized as one Xcode project with a library target `OCMock_OCHamcrest` and a test target `OCMock_OCHamcrest_Tests`. The test target contains several files. Each one touches one kine od features.

1. [Simple matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson1_SimpleMatchers.m)
2. [Advanced matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson2_AdvancedMatcher.m)
3. [Return value from mocked method](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson3_Return.m)
4. [Block as mocked method argument](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson4_Block.m)
5. [Calling method](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson5_Call.m)
6. [Other OCMock features](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson6_Other.m)
7. [Partial mocking](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson7_Partial.m)
8. [Strict mocking](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson8_Strict.m)
9. [Verification of expect calls](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson9_Verify.m)
10. [OCHamcrest - number matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson10_OCHamcrest_Numbers.m)
11. [OCHamcrest - text matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson11_OCHamcrest_Text.m)
12. [OCHamcrest - container matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson12_OCHamcrest_Container.m)
13. [OCHamcrest - object matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson13_OCHamcrest_Object.m)
14. [OCHamcrest - linking matchers](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson14_OCHamcrest_Logic.m)
15. [KNMParametrizedTest - parametrized tests](https://github.com/iblis-ms/tutorials/blob/master/Objective-C/OCMock_OCHamcrest/OCMock_OCHamcrest_Tests/Lesson15_KNMParametrizedTest.m)

# Author
Marcin Serwach
