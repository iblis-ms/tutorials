// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include "ExecutableHeader.h"
#include "SharedLibraryFactory.h"
#include "StaticLibraryFactory.h"
#include "HeaderOnlyLibraryInterface.h"

int main()
{
  CExecutableHeader exec;
  exec.execSayHello();

  CSharedLibraryInterface& sharedLib = CSharedLibraryFactory::create();
  sharedLib.sharedSayHello();

  CStaticLibraryInterface& staticLib = CStaticLibraryFactory::create();
  staticLib.staticSayHello();

  CHeaderOnlyLibraryInterface headerOnlyLib;
  headerOnlyLib.headerOnlySayHello();

  return 0;
}
