// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"



CLibrary::CLibrary(IListener *aListener)
  : iListener{aListener}
{
}

void CLibrary::call_functionArg1(int aArg1)
{
  iListener->functionArg1(aArg1);
}

void CLibrary::call_functionArg3(int aArg1, int aArg2, int aArg3)
{
  iListener->functionArg3(aArg1, aArg2, aArg3);
}
