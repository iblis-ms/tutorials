// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#include "Library.h"

CLibrary::CLibrary(IListener *aListener)
    :
      iListener { aListener }
{
}

void CLibrary::call_functionVector(const std::vector<int>& aVector)
{
  iListener->functionVector(aVector);
}

