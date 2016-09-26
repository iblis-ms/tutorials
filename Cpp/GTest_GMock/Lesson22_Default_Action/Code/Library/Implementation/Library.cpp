// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
  : iListener{aListener}
{
}

int CLibrary::call_functionArg3(int aArg1, int aArg2, int aArg3)
{
  return iListener->functionArg3(aArg1, aArg2, aArg3);
}
