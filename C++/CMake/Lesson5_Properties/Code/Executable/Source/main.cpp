// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include "ExecutableHeader.h"
#include "StaticLibraryFactory.h"

int main()
{
  CExecutableHeader exec;
  exec.execSayHello();

  CStaticLibraryInterface& staticLib = CStaticLibraryFactory::create();
  staticLib.staticSayHello();

  return 0;
}
