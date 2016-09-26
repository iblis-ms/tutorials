// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <string>

class CLibrary
{
public:

  //! \brief Adds 10 to given value.
  //! \param aValue Value to which 10 will be added.
  //! \return Return value.
  static int add10(int aValue);

  //! \brief Multiplies given value by 12.3.
  //! \param aValue Value that will be multiplied by 12.3.
  //! \return Result.
  static double multiply12_3(double aValue);

  //! \brief Adds given prefix to given text.
  //! \param aPrefix Prefix.
  //! \param aTxt Text.
  //! \return Result - text with prefix.
  static std::string addPrefix(const char* aPrefix, const char* aTxt);

  //! \brief Returns a C-style string.
  //! \return C-style string: abc.
  static const char* getCStyleString();
};

#endif // LIBRARY_H_
