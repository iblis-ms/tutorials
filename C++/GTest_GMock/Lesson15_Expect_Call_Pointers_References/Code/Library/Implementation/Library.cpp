// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"
#include <iostream>

Base::Base(int aArg1)
    :
      iField1 { aArg1 }
{
}

bool Base::operator==(const Base& aArg1) const
{
  std::cout << "Base: operator== was called\n";
  return iField1 == aArg1.iField1;
}

Derivative::Derivative(int aArg1, int aArg2)
    :
      Base { aArg1 },
      iField2 { aArg2 }
{
}

bool Derivative::operator==(const Derivative& aArg1) const
{
  std::cout << "Derivative: operator== was called\n";
  if (static_cast<Base>(*this) == static_cast<Base>(aArg1))
  {
    return iField2 == aArg1.iField2;
  }
  return false;
}

CLibrary::CLibrary(IListener *aListener)
    :
      iListener { aListener }
{
}

void CLibrary::call_functionWithPointer(int* aArg)
{
  iListener->functionWithPointer(aArg);
}

void CLibrary::call_functionWithCustomPointer(Base* aArg)
{
  iListener->functionWithCustomPointer(aArg);
}

void CLibrary::call_functionWithReference(int& aArg)
{
  iListener->functionWithReference(aArg);
}
