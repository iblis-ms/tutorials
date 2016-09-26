// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#ifndef HEADER_ONLY_LIBRARY_INTERFACE_H_
#define HEADER_ONLY_LIBRARY_INTERFACE_H_

#include <iostream>

class CHeaderOnlyLibraryInterface
{
public:

  void headerOnlySayHello() const
  {
    std::cout<<"HEADER ONLY: hello\n";
  }
};

#endif // HEADER_ONLY_LIBRARY_INTERFACE_H_
