// Author: Marcin Serwach
#include "StaticLibraryHeader.h"

#include <iostream>

void CStaticLibraryHeader::staticSayHello() const
{
  std::cout<<"Static: hello\n";
}
