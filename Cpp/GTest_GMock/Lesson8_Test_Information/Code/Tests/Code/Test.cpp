// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include <iostream>

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

////////////////////////////////////// TEST CASE ////////////
class CMyTestCase : public Test
{
public:

  static void SetUpTestCase()
  {
    std::cout << "<-------------------- SetUpTestCase ------------>\n";
    // You can get current test case information by UnitTest::GetInstance()
    const TestCase* testCase = UnitTest::GetInstance()->current_test_case();
    // TestCase has several methods. Here we just want to get number of tests.
    const int count = testCase->test_to_run_count();
    for (int i = 0; i < count; ++i)
    {
      // Here you can get information of each test from the test case.
      const TestInfo* test = testCase->GetTestInfo(i);
      // Let's take a name of test.
      const char* testName = test->name();
      std::cout << "This test case contains test: " << testName << std::endl;
    }
    std::cout << "</------------------- SetUpTestCase ------------>\n";
  }

  virtual void SetUp()
  {
    std::cout << "<-------------------- SetUp ------------>\n";
    // In SetUp we can get the current test. 
    const TestInfo* testInfo = UnitTest::GetInstance()->current_test_info();
    // there are several information. 
    const char* testName = testInfo->test_case_name();
    const char* name = testInfo->name();
    const char* typeParamName = testInfo->type_param();
    const char* valueOfParam = testInfo->value_param();
    const char* fileName = testInfo->file();
    int line = testInfo->line();
    bool run = testInfo->should_run();

    std::cout << "Test name: " << testName << "\nName: " << name << "\nType of param of parametrized test: "
        << (typeParamName ? typeParamName : "null") << "\nValue param of parametrized test: "
        << (valueOfParam ? valueOfParam : "null") << "\nFile name: " << fileName << "\nLine: " << line
        << "\nShould be run: " << run << "\n";
    std::cout << "</------------------- SetUp ------------>\n";
  }

  virtual void TearDown()
  {
    std::cout << "<-------------------- TearDown ------------>\n";
    const TestInfo* testInfo = UnitTest::GetInstance()->current_test_info();
    // we can check the result of test.
    const TestResult* result = testInfo->result();
    if (result->Passed())
    {
      std::cout << "Test passed :) \n";
    }
    else if (result->Failed())
    {
      std::cout << "Test failed :( \n";
      if (result->HasFatalFailure())
      {
        std::cout << "There was a fatal failure\n";
      }
      else if (result->HasNonfatalFailure())
      {
        std::cout << "There was a nonfatal failure\n";
      }
    }
    std::cout << "</------------------- TearDown ------------>\n";
  }
};

TEST_F(CMyTestCase, testCase_fail_FAIL)
{
  FAIL();
}

TEST_F(CMyTestCase, testCase_success)
{
  ASSERT_TRUE(true);
}
