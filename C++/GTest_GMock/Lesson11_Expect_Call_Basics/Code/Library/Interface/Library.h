// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>

class IListener
{
public:
  virtual ~IListener() = default;

  virtual void functionNoArg() = 0;
  virtual void constFunctionNoArg() const = 0;

  virtual void functionArg1(int aArg1) = 0;
  virtual void constFunctionArg1(int aArg1) const = 0;

  virtual void functionArg3(int aArg1, int aArg2, int aArg3) = 0;
  virtual void constFuncitonArg(int aArg1, int aArg2, int aArg3) const = 0;

  virtual void functionArg1Double(double aArg1) = 0;

  virtual void functionArg1Str(const char* aArg1) = 0;

  void functionNonVirtual()
  {
    std::cout << "IListener: functionNonVirtual\n";
  }
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  void call_functionNoArg();

  void call_constFunctionNoArg() const;

  void call_functionArg1(int aArg1);

  void call_constFunctionArg1(int aArg1) const;

  void call_functionArg3(int aArg1, int aArg2, int aArg3);

  void call_constFuncitonArg(int aArg1, int aArg2, int aArg3) const;

  void call_functionArg1Double(double aArg1);

  void call_functionArg1Str(const char* aArg1);

  void call_functionNonVirtual();
private:

  IListener *iListener;
};

#endif // LIBRARY_H_
