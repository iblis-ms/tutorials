#ifndef HEADER_LIBRARY_H_
#define HEADER_LIBRARY_H_

#include "InterfaceLibrary.h"

class CHeaderLibrary : public IInterfaceLibrary
{
public:

  CHeaderLibrary();
  
  virtual void iInterfaceLibraryPublicVirtualFunction();

  virtual void iInterfaceLibraryPublicVirtualFunctionConst() const;

  void cHeaderLibraryPublicFunction();

  void cHeaderLibraryPublicFunctionConst() const;

  inline void cHeaderLibraryPublicInlineFunction();

  inline void cHeaderLibraryPublicInlineFunctionConst() const;


  int iCHeaderLibraryPublicVariable;

  const int iCHeaderLibraryPublicConst;

  static const int skCHeaderLibraryPublicStaticConst;
  
  static int sCHeaderLibraryPublicStatic;

protected:

  virtual void iInterfaceLibraryProtectedVirtualFunction();

  virtual void iInterfaceLibraryProtectedVirtualFunctionConst() const;

  void cHeaderLibraryProtectedFunction();

  void cHeaderLibraryProtectedFunctionConst() const;

  inline void cHeaderLibraryProtectedInlineFunction();

  inline void cHeaderLibraryProtectedInlineFunctionConst() const;


  int iCHeaderLibraryProtectedVariable;

  const int iCHeaderLibraryProtectedConst;

  static const int skCHeaderLibraryProtectedStaticConst;
  
  static int sCHeaderLibraryProtectedStatic;

private:

  void cHeaderLibraryPrivateFunction();

  void cHeaderLibraryPrivateFunctionConst() const;

  inline void cHeaderLibraryPrivateInlineFunction();

  inline void cHeaderLibraryPrivateInlineFunctionConst() const;


  int iCHeaderLibraryPrivateVariable;

  const int iCHeaderLibraryPrivateConst;

  static const int skCHeaderLibraryPrivateStaticConst;
  
  static int sCHeaderLibraryPrivateStatic;
};

#endif
