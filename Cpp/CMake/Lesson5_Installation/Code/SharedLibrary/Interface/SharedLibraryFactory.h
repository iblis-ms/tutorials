// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#ifndef SHARED_LIBRARY_FACTORY_H_
#define SHARED_LIBRARY_FACTORY_H_

#include "SharedLibraryInterface.h"

class CSharedLibraryFactory
{
public:

  static CSharedLibraryInterface& create();

};

#endif // SHARED_LIBRARY_FACTORY_H_
