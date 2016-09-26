// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include "StaticLibraryHeader.h"

#include <iostream>

void CStaticLibraryHeader::staticSayHello() const
{
  std::cout<<"Static: hello\n";
}
