# GTest & GMock tutorial - lesson 11 - GMock: EXPECT_CALL - basics
This lesson explains what it is GMock and shows a basic functionality of GMock.

# GMock
GTest library was used to check values, results that were returned by functions. GMock is a library that helps you to check if a particular method was called with expected arguments. 
GMock is not supported by CMake, there you need to provide a path to FindGMock.cmake file to CMake variable's CMAKE_MODULE_PATH (see CMakeLists.txt in Tests folder).

# Automatic mock method generation
You can use automatic script *gmock_gen.py* to automatically generate mock methods. It is located under: googlemock/scripts/generator.
```
./gmock_gen.py path_to_header_file
```

# Target of this lesson
After this lesson you will know how to:
- mock methods,
- use a basic functionality of EXPECT_CALL:
a) check numerical arguments (equal, less, greater, etc)
b) check string arguments

# Used methods, macros & objects
- EXPECT_CALL
- Times
Mocks:
- MOCK_METHOD0, MOCK_METHOD1, MOCK_METHOD2, etc.
- MOCK_CONST_METHOD0, MOCK_CONST_METHOD1, MOCK_CONST_METHOD2, etc
Matchers:
- Eq, Ne, Ge, Le, Gt, Lt
- DoubleEq, DoubleNear
- NanSensitiveDoubleEq, NanSensitiveDoubleNear
- StrEq, StrNe
- StrCaseEq, StrCaseNe
- StartsWith, EndsWith
- HasSubstr
- ContainsRegex, MatchesRegex


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock)*
