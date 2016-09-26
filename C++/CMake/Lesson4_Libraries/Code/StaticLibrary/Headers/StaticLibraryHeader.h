// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#ifndef STATIC_LIBRARY_HEADER_H_
#define STATIC_LIBRARY_HEADER_H_

#include "StaticLibraryInterface.h"

class CStaticLibraryHeader : public CStaticLibraryInterface
{
public:

  virtual void staticSayHello() const;
};

#endif // STATIC_LIBRARY_HEADER_H_
