// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"

int CLibrary::add10(int aValue)
{
  return 10 + aValue;
}

double CLibrary::multiply12_3(double aValue)
{
  return 12.3 * aValue;
}

std::string CLibrary::addPrefix(const char* aPrefix, const char* aTxt)
{
  return std::string { aPrefix } + std::string { aTxt };
}

const char* CLibrary::getCStyleString()
{
  return "abc";
}
