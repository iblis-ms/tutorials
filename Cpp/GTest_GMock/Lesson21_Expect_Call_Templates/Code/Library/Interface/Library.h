// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>

template<typename T>
class IListener
{
public:
  
  virtual void functionArg1(T aArg1) = 0;
  virtual T functionReturn() = 0;
};

template<typename T>
class CLibrary
{
public:

  CLibrary(IListener<T> *aListener)
    : iListener{aListener}
  {
  }

  void call_functionArg1(T aArg1)
  {
    iListener->functionArg1(aArg1);
  }

  T call_functionReturn()
  {
    return iListener->functionReturn();
  }

private:
  
  IListener<T> *iListener;
};

#endif // LIBRARY_H_
