// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
    :
      iListener { aListener }
{
}

int CLibrary::call_functionReturnInt()
{
  return iListener->functionReturnInt();
}

void CLibrary::call_functionNoReturn()
{
  iListener->functionNoReturn();
}
