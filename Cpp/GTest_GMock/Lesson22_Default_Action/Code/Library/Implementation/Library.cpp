// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
  : iListener{aListener}
{
}

int CLibrary::call_functionArg3(int aArg1, int aArg2, int aArg3)
{
  return iListener->functionArg3(aArg1, aArg2, aArg3);
}


int CLibrary::call_functionArg1(int aArg1)
{
  return iListener->functionArg1(aArg1);
}
