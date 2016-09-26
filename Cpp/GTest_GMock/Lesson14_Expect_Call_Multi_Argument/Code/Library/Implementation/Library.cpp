// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
    :
      iListener { aListener }
{
}

void CLibrary::call_functionWithArgs(int aArg1, int aArg2, int aArg3)
{
  iListener->functionWithArgs(aArg1, aArg2, aArg3);
}
