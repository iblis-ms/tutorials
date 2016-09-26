// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include "SharedLibraryHeader.h"

#include <iostream>

void CSharedLibraryHeader::sharedSayHello() const
{
  std::cout<<"Shared: hello\n";
}
