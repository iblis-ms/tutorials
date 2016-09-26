// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

class Base
{
public:

  Base(int aArg1);
  virtual ~Base() = default;

  bool operator==(const Base& aArg1) const;
private:
  int iField1;
};

class Derivative : public Base
{
public:

  Derivative(int aArg1, int aArg2);

  bool operator==(const Derivative& aArg1) const;

private:
  int iField2;
};

class IListener
{
public:
  virtual ~IListener() = default;

  virtual void functionWithPointer(int* aArg) = 0;

  virtual void functionWithCustomPointer(Base* aArg) = 0;

  virtual void functionWithReference(int& aArg) = 0;
};

class CLibrary
{
public:

  CLibrary(IListener *aListener);

  void call_functionWithPointer(int* aArg);

  void call_functionWithCustomPointer(Base* aArg);

  void call_functionWithReference(int& aArg);

private:

  IListener *iListener;
};

#endif // LIBRARY_H_
