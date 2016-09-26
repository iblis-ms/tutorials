// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

class IListener
{
public:
  virtual ~IListener() = default;

  virtual void functionWithArgs(int aArg1, int aArg2, int aArg3) = 0;
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  void call_functionWithArgs(int aArg1, int aArg2, int aArg3);

private:

  IListener *iListener;
};

#endif // LIBRARY_H_
