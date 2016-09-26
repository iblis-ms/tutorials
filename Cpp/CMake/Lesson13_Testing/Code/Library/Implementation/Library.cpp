// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake

#include "Library.h"

void CLibrary::addProvider(ILibraryCalculateProvider* aProvider)
{
  iProvider = aProvider;
}

void CLibrary::calculate() const
{
  const double result = iProvider->getValueA() * iProvider->getValueB();
  iProvider->onResult(result);
}

ILibraryInterface& CFactory::create()
{
  static CLibrary library;
  return library;
}
