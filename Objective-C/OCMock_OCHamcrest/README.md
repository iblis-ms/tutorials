#OCMock and OCHamcrest tutorial
This tutorial contains one project that shows how to OCMock in version 3.3.1 and OCHamcrest 6.0. Both of them are widely used libraries for testing Objective-C code. OCMock provides some methods to create mocks and checking if expected calls was called with proper arguments. OCHamcrest contains several useful matchers.

#CocoaPods
Both OCMock and OCHamcrest are downloaded by CocoaPods. To compile tutorial project you need to run:
```
pod install
```
After that you will have a workspace file `OCMock_OCHamcrest.xcworkspace` that should be opened in Xcode.

#Lesson
This tutorial was organized as one Xcode project with a library target `OCMock_OCHamcrest` and a test target `OCMock_OCHamcrest_Tests`. The test target contains several files. Each one touches one kine od features.
1. Simple matchers
2. Advanced matchers
3. Return value from mocked method
4. Block as mocked method argument
5. Calling method
6. Other OCMock features
7. Partial mocking
8. Strict mocking
9. Verification of expect calls
10. OCHamcrest - number matchers
11. OCHamcrest - text matchers
12. OCHamcrest - container matchers
13. OCHamcrest - object matchers
14. OCHamcrest - linking matchers

#Author
Marcin Serwach
