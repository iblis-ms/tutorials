// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "LibraryInterface.h"

class CLibraryCalculateProvider : public ILibraryCalculateProvider
{
public:
  virtual double getValueA() const;
  virtual double getValueB() const;
  virtual void onResult(double aResult);
};

class CLibrary : public ILibraryInterface
{
public:
  
  virtual void addProvider(ILibraryCalculateProvider* aProvider);
  virtual void calculate() const;
private:
  ILibraryCalculateProvider* iProvider;
};

#endif // LIBRARY_H_
