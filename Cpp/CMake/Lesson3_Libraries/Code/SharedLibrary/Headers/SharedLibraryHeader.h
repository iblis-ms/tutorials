// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#ifndef SHARED_LIBRARY_HEADER_H_
#define SHARED_LIBRARY_HEADER_H_

#include "SharedLibraryInterface.h"

class CSharedLibraryHeader : public CSharedLibraryInterface
{
public:

  virtual void sharedSayHello() const;
};

#endif // SHARED_LIBRARY_HEADER_H_
