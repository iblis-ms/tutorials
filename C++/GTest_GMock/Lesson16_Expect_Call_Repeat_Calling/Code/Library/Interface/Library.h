// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <vector>

class IListener
{
public:
  virtual ~IListener() = default;

  virtual int functionReturnInt() = 0;
  virtual void functionNoReturn() = 0;
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  int call_functionReturnInt();

  void call_functionNoReturn();
private:

  IListener *iListener;
};

#endif // LIBRARY_H_
