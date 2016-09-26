// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include "StaticLibraryFactory.h"
#include "StaticLibraryHeader.h"

CStaticLibraryInterface& CStaticLibraryFactory::create()
{
  static CStaticLibraryHeader object;
  return object;
}
