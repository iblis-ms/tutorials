// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake

#ifndef LIBRARY_INTERFACE_H_
#define LIBRARY_INTERFACE_H_

class ILibraryCalculateProvider
{
public:
  virtual double getValueA() const = 0;
  virtual double getValueB() const = 0;
  virtual void onResult(double aResult) = 0;
};

class ILibraryInterface
{
public:
  virtual ~ILibraryInterface(){}
  
  virtual void addProvider(ILibraryCalculateProvider* aProvider) = 0;
  virtual void calculate() const = 0;
};

class CFactory
{
public:
  static ILibraryInterface& create();
};

#endif // LIBRARY_INTERFACE_H_
