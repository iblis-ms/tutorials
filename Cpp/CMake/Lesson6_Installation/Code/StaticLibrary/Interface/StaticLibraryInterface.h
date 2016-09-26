// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake

#ifndef STATIC_LIBRARY_INTERFACE_H_
#define STATIC_LIBRARY_INTERFACE_H_

class CStaticLibraryInterface
{
public:
  virtual ~CStaticLibraryInterface(){};

  virtual void staticSayHello() const = 0;
};

#endif // STATIC_LIBRARY_INTERFACE_H_
