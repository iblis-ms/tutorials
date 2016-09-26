// Author: Marcin Serwach
#include "StaticLibraryFactory.h"
#include "StaticLibraryHeader.h"

CStaticLibraryInterface& CStaticLibraryFactory::create()
{
  static CStaticLibraryHeader object;
  return object;
}
