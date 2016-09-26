// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <vector>

class IListener
{
public:
  virtual ~IListener() = default;

  virtual void functionVector(const std::vector<int>& aVector) = 0;
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  void call_functionVector(const std::vector<int>& aVector);

private:

  IListener *iListener;
};

#endif // LIBRARY_H_
