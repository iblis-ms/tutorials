// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake

#include "Class.h"

int main() 
{
  CClass array[5];
  for (int i = 0; i < 5; ++i)
  {
    array[i].sayHello();
  }
  return 0;
}
