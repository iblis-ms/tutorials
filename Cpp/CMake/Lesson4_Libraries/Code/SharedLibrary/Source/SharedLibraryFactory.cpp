// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#include "SharedLibraryFactory.h"
#include "SharedLibraryHeader.h"

CSharedLibraryInterface& CSharedLibraryFactory::create()
{
  static CSharedLibraryHeader object;
  return object;
}
