#ifndef INTERFACE_LIBRARY_H_
#define INTERFACE_LIBRARY_H_

class IInterfaceLibrary
{
public:

  IInterfaceLibrary();

  virtual void iInterfaceLibraryPublicVirtualFunction() = 0;

  virtual void iInterfaceLibraryPublicVirtualFunctionConst() const = 0;

  void iInterfaceLibraryPublicFunction();

  void iInterfaceLibraryPublicFunctionConst() const;

  inline void iInterfaceLibraryPublicInlineFunction();

  inline void iInterfaceLibraryPublicInlineFunctionConst() const;


  int iIInterfaceLibraryPublicVariable;

  const int iIInterfaceLibraryPublicConst;

  static const int skIInterfaceLibraryPublicStaticConst;
  
  static int sIInterfaceLibraryPublicStatic;

protected:

  virtual void iInterfaceLibraryProtectedVirtualFunction() = 0;

  virtual void iInterfaceLibraryProtectedVirtualFunctionConst() const = 0;

  void iInterfaceLibraryProtectedFunction();

  void iInterfaceLibraryProtectedFunctionConst() const;

  inline void iInterfaceLibraryProtectedInlineFunction();

  inline void iInterfaceLibraryProtectedInlineFunctionConst() const;


  int iIInterfaceLibraryProtectedVariable;

  const int iIInterfaceLibraryProtectedConst;

  static const int skIInterfaceLibraryProtectedStaticConst;
  
  static int sIInterfaceLibraryProtectedStatic;

private:

  void iInterfaceLibraryPrivateFunction();

  void iInterfaceLibraryPrivateFunctionConst() const;

  inline void iInterfaceLibraryPrivateInlineFunction();

  inline void iInterfaceLibraryPrivateInlineFunctionConst() const;


  int iIInterfaceLibraryPrivateVariable;

  const int iIInterfaceLibraryPrivateConst;

  static const int skIInterfaceLibraryPrivateStaticConst;
  
  static int sIInterfaceLibraryPrivateStatic;
};

#endif
