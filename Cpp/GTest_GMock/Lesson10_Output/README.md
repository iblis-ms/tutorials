#GTest & GMock tutorial - lesson 10 - GTest: Output
GTest can create a output XML that can be easily read by continuous integration tools.

#How to filter tests
To write a result of tests to *path_to_xmlfile.xml* file you need to run: `./library_test --gtest_output=xml:path_to_xmlfile.xml`. If you run just `./library_test --gtest_output=xml`, the test result will be located in *test_detail.xml* file. You can also create the environment variable `export GTEST_OUTPUT=xml` and run `./library_test` which is equivalent to `./library_test --gtest_output=xml`. *GTEST_OUTPUT* variable can also have a path to xml file.

#Target of this lesson
After this lesson you will know how to:
- create XML file with result of testing.


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock)*
