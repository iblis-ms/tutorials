// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include <iostream>

// adds GTest header
#include <gtest/gtest.h>
// adds GMock header
#include <gmock/gmock.h>

#include "Library.h"

// to easily use GTest and GMock objects and methods.
using namespace ::testing;

////////////////////////////////////////// MOCK

class IListenerMock : public IListener // IListener is a interface class
{
public:

  MOCK_METHOD1(functionVector, void(const std::vector<int>&));
};

//////////////////////////////////////////// TEST CASE ////////////////

class CMyTestCase : public Test
{
};

///////////////////////////////////////////////////////
TEST_F(CMyTestCase, ExpectCall_containers)
{
  // GMock has special methods for containers

  { // ContainerEq - an argument should have exactly the same content.
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    const std::vector<int> data2 = data;
    EXPECT_CALL(listenerMock, functionVector(ContainerEq(data2))).Times(1);
    library.call_functionVector(data);
  }
  { // Contains - an argument must contain a specific value.
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(Contains(2))).Times(1);
    library.call_functionVector(data);
  }
  { // Contains(Lt(x) - an argument must contains a value less than 'x'. You can use other matchers
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(Contains(Lt(5)))).Times(1);
    library.call_functionVector(data);
  }
  { // Each(x) - an argument must have all values equal to 'x'.
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 2, 2, 2 };
    EXPECT_CALL(listenerMock, functionVector(Each(2))).Times(1);
    library.call_functionVector(data);
  }
  { // Each(Lt(x) - an argument must have all values less than 'x'
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 2, 2, 2 };
    EXPECT_CALL(listenerMock, functionVector(Each(Lt(5)))).Times(1);
    library.call_functionVector(data);
  }
  { // ElementsAre(Lt(5), Gt(0), 3) - an argument must have values that match to the sequence of matchers (order is important)
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(ElementsAre(Lt(5), Gt(0), 3))).Times(1);
    library.call_functionVector(data);
  }
  { // ElementsAreArray(array) - an argument must contain values that are equal to given array (order is important)
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    const int array[] = { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(ElementsAreArray(array))).Times(1);
    library.call_functionVector(data);
  }
  { // IsEmpty() - an argument must contain an empty container
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data;
    EXPECT_CALL(listenerMock, functionVector(IsEmpty())).Times(1);
    library.call_functionVector(data);
  }
  { // Pointwise(method, expected_data) - an argument container whose values must match to the given 'method'. 
    //                                    The method is called for each argument from the argument container and from
    //                                    expected data.
    // Pointwise(Ge(), {1, 3, 4}) - an argument container must have: the 1st value >= 1, the 2nd value >= 3, the 3rd value => 4.
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    const std::vector<int> data2 { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(Pointwise(Ge(), data2))).Times(1);
    library.call_functionVector(data);
  }
  { // SizeIs('x') - an argument container must have given size.
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(SizeIs(3))).Times(1);
    library.call_functionVector(data);
  }
  { // SizeIs(Le(3)) - an argument container must have less than 3 size.
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(SizeIs(Le(3)))).Times(1);
    library.call_functionVector(data);
  }
  { // UnorderedElementsAre(3, 2, 1) - an argument container must have given values (GMock permutates to check)
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(UnorderedElementsAre(3, 2, 1))).Times(1);
    library.call_functionVector(data);
  }
  { // WhenSorted(data1) - an argument container's values are sorted and compared with given 'data1'
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 2, 1, 3 };
    const std::vector<int> data1 { 1, 2, 3 };
    EXPECT_CALL(listenerMock, functionVector(WhenSorted(data1))).Times(1);
    library.call_functionVector(data);
  }
  { // WhenSortedBy(method, data1) - an argument container's values are sorted by given method and compared with given 'data1'
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 2, 1, 3 };
    const std::vector<int> data1 { 3, 2, 1 };
    EXPECT_CALL(listenerMock, functionVector(WhenSortedBy(std::greater<int>(), data1))).Times(1);
    library.call_functionVector(data);
  }
  { // WhenSortedBy(std::greater<int>(), UnorderedElementsAre(1, 2, 3))
    IListenerMock listenerMock; // creates object of mock class
    CLibrary library { &listenerMock };

    const std::vector<int> data { 2, 1, 3 };
    EXPECT_CALL(listenerMock, functionVector(WhenSortedBy(std::greater<int>(), UnorderedElementsAre(3, 2, 1)))).Times(
        1);
    library.call_functionVector(data);
  }
}

