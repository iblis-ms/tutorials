// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>

class IListener
{
public:
  
  virtual void functionArg1(int aArg1) = 0;
  virtual void functionArg3(int aArg1, int aArg2, int aArg3) = 0;
};

class CLibrary
{
public:
  
  CLibrary(IListener *aListener);

  void call_functionArg1(int aArg1);

  void call_functionArg3(int aArg1, int aArg2, int aArg3);

private:
  
  IListener *iListener;
};

#endif // LIBRARY_H_
