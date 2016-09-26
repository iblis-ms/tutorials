#include "InterfaceLibrary.h"
#include <iostream>

void iInterfaceLibraryGlobalFunction()
{
  std::cout<<"void iInterfaceLibraryGlobalFunction()\n";
}

int iInterfaceLibraryGlobalVariable = 0;

const int iInterfaceLibraryGlobalConst = 0;

namespace
{
  void iInterfaceLibraryAnonymousNamespaceFunction()
  {
    std::cout<<"void iInterfaceLibraryAnonymousNamespaceFunction()\n";
  }

  int iInterfaceLibraryAnonymousNamespaceVariable = 0;
  const int iInterfaceLibraryAnonymousNamespaceConst = 0;
}

const int IInterfaceLibrary::skIInterfaceLibraryPublicStaticConst = 0;

int IInterfaceLibrary::sIInterfaceLibraryPublicStatic = 0;

const int IInterfaceLibrary::skIInterfaceLibraryProtectedStaticConst = 0;

int IInterfaceLibrary::sIInterfaceLibraryProtectedStatic = 0;

const int IInterfaceLibrary::skIInterfaceLibraryPrivateStaticConst = 0;

int IInterfaceLibrary::sIInterfaceLibraryPrivateStatic = 0;

IInterfaceLibrary::IInterfaceLibrary()
  : iIInterfaceLibraryPublicVariable{0}
  , iIInterfaceLibraryPublicConst{0}
  , iIInterfaceLibraryProtectedVariable{0}
  , iIInterfaceLibraryProtectedConst{0}
  , iIInterfaceLibraryPrivateVariable{0}
  , iIInterfaceLibraryPrivateConst{0} 
{}

void IInterfaceLibrary::iInterfaceLibraryPublicFunction()
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPublicFunction()\n";
}

void IInterfaceLibrary::iInterfaceLibraryPublicFunctionConst() const
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPublicFunctionConst() const\n";
}

void IInterfaceLibrary::iInterfaceLibraryPublicInlineFunction()
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPublicInlineFunction()\n";
}

void IInterfaceLibrary::iInterfaceLibraryPublicInlineFunctionConst() const
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPublicInlineFunctionConst() const\n";
}

void IInterfaceLibrary::iInterfaceLibraryProtectedFunction()
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryProtectedFunction()\n";
}

void IInterfaceLibrary::iInterfaceLibraryProtectedFunctionConst() const
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryProtectedFunctionConst() const\n";
}

void IInterfaceLibrary::iInterfaceLibraryProtectedInlineFunction()
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryProtectedInlineFunction()\n";
}

void IInterfaceLibrary::iInterfaceLibraryProtectedInlineFunctionConst() const
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryProtectedInlineFunctionConst() const\n";
}

void IInterfaceLibrary::iInterfaceLibraryPrivateFunction()
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPrivateFunction()\n";
}

void IInterfaceLibrary::iInterfaceLibraryPrivateFunctionConst() const
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPrivateFunctionConst() const\n";
}

void IInterfaceLibrary::iInterfaceLibraryPrivateInlineFunction()
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPrivateInlineFunction()\n";
}

void IInterfaceLibrary::iInterfaceLibraryPrivateInlineFunctionConst() const
{
  std::cout<<"void IInterfaceLibrary::iInterfaceLibraryPrivateInlineFunctionConst() const\n";
}
