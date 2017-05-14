// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#ifndef STATIC_LIBRARY_FACTORY_H_
#define STATIC_LIBRARY_FACTORY_H_

#include "StaticLibraryInterface.h"

class CStaticLibraryFactory
{
public:

  static CStaticLibraryInterface& create();

};

#endif // STATIC_LIBRARY_FACTORY_H_
