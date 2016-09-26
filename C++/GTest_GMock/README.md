#GTest & GMock tutorial

This tutorial contains several lessons that show how to use GTest and GMock. They are widely used testing frameworks for C++. Most people use only minor part of their functionality.

#GTest
GTest is a testing framework, which allows to write unit and functional tests. Tests are splitted into test cases than into particular tests. GTest allows to compare output of your code to expected results. It supports many types of asserts that can help you to test your code. You can find GTest framework on GitHub: [https://github.com/google/googletest](https://github.com/google/googletest).

#GMock
GMock is also a testing framework. However it should be used to test if a particular method with a expected argument was called. Therefore you can check if the behavior of your code is proper for a given situation. GMock uses GTest framework inside. You can find GTest framework on GitHub: [https://github.com/google/googletest](https://github.com/google/googletest).

#This tutorial
All tutorial lessons are provided with CMake project. CMake has a find_package function, which can help you to use GTest and GMock. CMake has support to find GTest library, but not GMock. However you can use GMock module plug in for CMake here: [https://github.com/triglav/cmake-findgmock](https://github.com/triglav/cmake-findgmock).
Each lesson has its own README.md file with explanation and run.sh script to build and run tests. 
NOTE: This a very short tutorial with huge piece of information, therefore each lesson touches something new. I will not explain once again things that were explained in previous lessons.

#Table of content
1. [GTest: CMake configuration and basic tests](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson1_Configuration_And_Simple_Tests)
2. [GTest: SetUp & TearDown](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson2_SetUp_TearDown)
3. [GTest: Asserts for exceptions and crashes](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson3_Assert_Exceptions_And_Crashes)
4. [GTest: Predicates](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson4_Predicates)
5. [GTest: Parametrized tests](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson5_Parametrized_tests)
6. [GTest: Type tests](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson6_Type_Tests)
7. [GTest: Testing a private part of code](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson7_Testing_Private_Code)
8. [GTest: Test information](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson8_Test_Information)
9. [GTest: Filters](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson9_Filter)
10. [GTest: Output format](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson10_Output)
11. [GMock: EXPECT_CALL - Basic use cases](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson11_Expect_Call_Basics)
12. [GMock: EXPECT_CALL - Containers](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson12_Expect_Call_Containers)
13. [GMock: EXPECT_CALL - Return values](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson13_Expect_Call_Return)
14. [GMock: EXPECT_CALL - Multi arguments and pointers](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson14_Expect_Call_Multi_Argument)
15. [GMock: EXPECT_CALL - Pointers and References](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson15_Expect_Call_Pointers_References)
16. [GMock: EXPECT_CALL - Calling more than one](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson16_Expect_Call_Repeat_Calling)
17. [GMock: EXPECT_CALL - Saving and setting arguments](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson17_Expect_Call_Save_And_Set_Args)
18. [GMock: EXPECT_CALL - Invoke](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson18_Expect_Call_Invoke)
19. [GMock: EXPECT_CALL - Do more actions](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson19_Expect_Call_Do_More_Actions)
20. [GMock: EXPECT_CALL - After & Sequences](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson20_Expect_Call_After_And_Sequences)
21. [GMock: Template mocking](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson21_Expect_Call_Templates)
22. [GMock: Default actions](https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock/Lesson22_Default_Action)


#Author
Marcin Serwach
