// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <functional>

class IListener
{
public:
  
  virtual void functionWithArg(int aArg1, int& aArg2, int* aArg3) = 0;

  virtual void functionWithArgFunction(std::function<void(int)> aArg1) = 0;

  virtual int functionWithReturn() = 0;
};

class CLibrary
{
public:
  
  CLibrary(IListener *aListener);

  void call_functionWithArg(int aArg1, int& aArg2, int* aArg3);

  void call_functionWithArgFunction(std::function<void(int)> aArg1);

  int call_functionWithReturn();

private:
  
  IListener *iListener;
};

#endif // LIBRARY_H_
