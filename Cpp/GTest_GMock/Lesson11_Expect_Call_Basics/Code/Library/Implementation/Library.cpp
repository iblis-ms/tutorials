// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
    :
      iListener { aListener }
{
}

void CLibrary::call_functionNoArg()
{
  iListener->functionNoArg();
}

void CLibrary::call_constFunctionNoArg() const
{
  iListener->constFunctionNoArg();
}

void CLibrary::call_functionArg1(int aArg1)
{
  iListener->functionArg1(aArg1);
}

void CLibrary::call_constFunctionArg1(int aArg1) const
{
  iListener->constFunctionArg1(aArg1);
}

void CLibrary::call_functionArg3(int aArg1, int aArg2, int aArg3)
{
  iListener->functionArg3(aArg1, aArg2, aArg3);
}

void CLibrary::call_constFuncitonArg(int aArg1, int aArg2, int aArg3) const
{
  iListener->constFuncitonArg(aArg1, aArg2, aArg3);
}

void CLibrary::call_functionArg1Double(double aArg1)
{
  iListener->functionArg1Double(aArg1);
}

void CLibrary::call_functionArg1Str(const char* aArg1)
{
  iListener->functionArg1Str(aArg1);
}

void CLibrary::call_functionNonVirtual()
{
  iListener->functionNonVirtual();
}
