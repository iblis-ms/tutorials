// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

class IListener
{
public:
  
  virtual void functionWithArgValue(int aArg1) = 0;
  virtual void functionWithArgPointer(const int* aArg1) = 0;
  virtual void functionWithArgReference(const int& aArg1) = 0;

  virtual void functionWithArgPointerNonConst(int* aArg1) = 0;
  virtual void functionWithArgReferenceNonConst(int& aArg1) = 0;
};

class CLibrary
{
public:
  
  CLibrary(IListener *aListener);

  void call_functionWithArgValue(int aArg1);

  void call_functionWithArgPointer(const int* aArg1);

  void call_functionWithArgReference(const int& aArg1);

  void call_functionWithArgPointerNonConst(int* aArg1);

  void call_functionWithArgReferenceNonConst(int& aArg1);
private:
  
  IListener *iListener;
};

#endif // LIBRARY_H_
