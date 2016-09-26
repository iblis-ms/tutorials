// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
  : iListener{aListener}
{
}

void CLibrary::call_functionWithArgValue(int aArg1)
{
  iListener->functionWithArgValue(aArg1);
}

void CLibrary::call_functionWithArgPointer(const int* aArg1)
{
  iListener->functionWithArgPointer(aArg1);
}

void CLibrary::call_functionWithArgReference(const int& aArg1)
{
  iListener->functionWithArgReference(aArg1);
}

void CLibrary::call_functionWithArgPointerNonConst(int* aArg1)
{
  iListener->functionWithArgPointerNonConst(aArg1);
}

void CLibrary::call_functionWithArgReferenceNonConst(int& aArg1)
{
  iListener->functionWithArgReferenceNonConst(aArg1);
}
