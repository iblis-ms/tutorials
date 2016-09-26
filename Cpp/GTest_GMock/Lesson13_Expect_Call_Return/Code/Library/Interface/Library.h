// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <vector>

class IListener
{
public:
  virtual ~IListener() = default;

  virtual int functionReturnInt() = 0;

  virtual const int& functionReturnIntRef() = 0;

  virtual int&& functionReturnIntRValue() = 0;
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  int call_functionReturnInt();

  const int& call_functionReturnIntRef();

  int&& call_functionReturnIntRValue();

private:

  IListener *iListener;
};

#endif // LIBRARY_H_
