#include "HeaderLibrary.h"
#include <iostream>

void cHeaderLibraryGlobalFunction()
{
  std::cout<<"void cHeaderLibraryGlobalFunction()\n";
}

int cHeaderLibraryGlobalVariable = 0;

const int cHeaderLibraryGlobalConst = 0;

namespace
{
  void cHeaderLibraryAnonymousNamespaceFunction()
  {
    std::cout<<"void cHeaderLibraryAnonymousNamespaceFunction()\n";
  }

  int cHeaderLibraryAnonymousNamespaceVariable = 0;
  const int cHeaderLibraryAnonymousNamespaceConst = 0;
}

const int CHeaderLibrary::skCHeaderLibraryPublicStaticConst = 0;

int CHeaderLibrary::sCHeaderLibraryPublicStatic = 0;

const int CHeaderLibrary::skCHeaderLibraryProtectedStaticConst = 0;

int CHeaderLibrary::sCHeaderLibraryProtectedStatic = 0;

const int CHeaderLibrary::skCHeaderLibraryPrivateStaticConst = 0;

int CHeaderLibrary::sCHeaderLibraryPrivateStatic = 0;

CHeaderLibrary::CHeaderLibrary()
  : iCHeaderLibraryPublicVariable{0}
  , iCHeaderLibraryPublicConst{0}
  , iCHeaderLibraryProtectedVariable{0}
  , iCHeaderLibraryProtectedConst{0}
  , iCHeaderLibraryPrivateVariable{0}
  , iCHeaderLibraryPrivateConst{0}
{}


void CHeaderLibrary::iInterfaceLibraryPublicVirtualFunction()
{
  std::cout<<"void CHeaderLibrary::iInterfaceLibraryPublicVirtualFunction()\n";
}

void CHeaderLibrary::iInterfaceLibraryPublicVirtualFunctionConst() const
{
  std::cout<<"void CHeaderLibrary::iInterfaceLibraryPublicVirtualFunctionConst() const\n";
}

void CHeaderLibrary::iInterfaceLibraryProtectedVirtualFunction()
{
  std::cout<<"void CHeaderLibrary::iInterfaceLibraryProtectedVirtualFunction()\n";
}

void CHeaderLibrary::iInterfaceLibraryProtectedVirtualFunctionConst() const
{
  std::cout<<"void CHeaderLibrary::iInterfaceLibraryProtectedVirtualFunctionConst() const\n";
}

void CHeaderLibrary::cHeaderLibraryProtectedFunction()
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryProtectedFunction()\n";
}

void CHeaderLibrary::cHeaderLibraryProtectedFunctionConst() const
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryProtectedFunctionConst() const\n";
}

void CHeaderLibrary::cHeaderLibraryProtectedInlineFunction()
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryProtectedInlineFunction()\n";
}

void CHeaderLibrary::cHeaderLibraryProtectedInlineFunctionConst() const
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryProtectedInlineFunctionConst() const\n";
}

void CHeaderLibrary::cHeaderLibraryPrivateFunction()
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryPrivateFunction()\n";
}

void CHeaderLibrary::cHeaderLibraryPrivateFunctionConst() const
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryPrivateFunctionConst() const\n";
}

void CHeaderLibrary::cHeaderLibraryPrivateInlineFunction()
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryPrivateInlineFunction()\n";
}

void CHeaderLibrary::cHeaderLibraryPrivateInlineFunctionConst() const
{
  std::cout<<"void CHeaderLibrary::cHeaderLibraryPrivateInlineFunctionConst() const\n";
}
