// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include <iostream>

// adds GTest header
#include <gtest/gtest.h>

// to easily use GTest objects and methods.
using namespace ::testing;

//! \brief This class defines also a test case. It must extend GTest's Test. This approach should be used, because it allows to 
//!        put variables in class and not use global variables. Moreover you can use some methods like SetUp/TearDown etc.
//!        Each test case has its own object of this class. It is created before a test case and destroy after test case.
class CMyTestCase : public Test
{
public:

  //! \brief This SetUpTestCase is called before all tests in this test case.
  //!        You can use it to allocate a 'static' resource, which will be common for all tests.
  static void SetUpTestCase()
  {
    std::cout << "This SetUpTestCase method is called once before all test cases\n";
  }

  //! \brief This SetUp method is called before each test. 
  //!        It is often used to initialize variables.
  //!        You can also use default constructor. However if something can throw exception, you should put your code in SetUp. 
  virtual void SetUp()
  {
    std::cout << "This SetUp method is called before each test case\n";
  }

  //! \brief This TearDown method is called after each test case.
  //!        It is often used for releasing resources after each test case.
  //!        You can also move your code to a deconstructor. However TearDown is better, because you can throw exception from it.
  //!        Throwing a exception from a deconstructor provides to undefined behavior.
  virtual void TearDown()
  {
    std::cout << "This TearDown method is called after each test case\n";
  }

  //! \bref This TearDownTestCase is called after all tests in this test case.
  //!       You can use it to deallocate a 'static' resource.
  static void TearDownTestCase()
  {
    std::cout << "This TearDownTestCase method is called once after all test cases\n";
  }
};

// GTest has TEST_F macro. In the brackets you have to write a name of class - a test case and the name of a particular test.
// GTest creates new class which extends the class given in the 1st argument.
// The content of TEST_F is a test body.
TEST_F(CMyTestCase, testCase_fail_FAIL)
{
  // SetUp and TearDown are called even test is failing.
  FAIL();
}

TEST_F(CMyTestCase, testCase_success)
{
  // SetUp and TearDown are called even test is failing.
  ASSERT_TRUE(true);
}
