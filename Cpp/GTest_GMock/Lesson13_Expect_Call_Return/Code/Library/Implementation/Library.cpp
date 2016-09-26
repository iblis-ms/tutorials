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

const int& CLibrary::call_functionReturnIntRef()
{
  return iListener->functionReturnIntRef();
}

int&& CLibrary::call_functionReturnIntRValue()
{
  return iListener->functionReturnIntRValue();
}
