// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
  : iListener{aListener}
{
}

void CLibrary::call_functionWithArg(int aArg1, int& aArg2, int* aArg3)
{
  iListener->functionWithArg(aArg1, aArg2, aArg3);
}

void CLibrary::call_functionWithArgFunction(std::function<void(int)> aArg1)
{
  iListener->functionWithArgFunction(aArg1);
}

int CLibrary::call_functionWithReturn()
{
  return iListener->functionWithReturn();
}

