// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#include "SharedLibraryHeader.h"

#include <iostream>

void CSharedLibraryHeader::sharedSayHello() const
{
  std::cout<<"Shared: hello\n";
}
