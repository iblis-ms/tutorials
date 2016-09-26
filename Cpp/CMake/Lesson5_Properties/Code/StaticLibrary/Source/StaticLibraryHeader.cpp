// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake

#include "StaticLibraryHeader.h"

#include <iostream>
#include <vector>

void CStaticLibraryHeader::staticSayHello() const
{
  std::cout<<"Static: hello\n";

  std::vector<int> v{1, 2, 3, 4};
  for (const auto& item : v)
  {
    std::cout<<item<<std::endl;
  }
}
