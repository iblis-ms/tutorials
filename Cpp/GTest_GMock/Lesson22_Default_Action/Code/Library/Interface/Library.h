// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>

class IListener
{
public:

  virtual int functionArg3(int aArg1, int aArg2, int aArg3) = 0;
  virtual int functionArg1(int aArg1) = 0;
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  int call_functionArg3(int aArg1, int aArg2, int aArg3);
  int call_functionArg1(int aArg1);

private:
  
  IListener *iListener;
};

#endif // LIBRARY_H_
