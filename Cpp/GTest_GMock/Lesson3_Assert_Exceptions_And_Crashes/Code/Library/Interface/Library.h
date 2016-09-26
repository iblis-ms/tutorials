// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef LIBRARY_H_
#define LIBRARY_H_

class CLibrary
{
public:

  //! \brief Throws an exception: std::runtime_error{"Exception!!!"}
  static void throwException();

  //! \brief Empty method that doesn't throw any exception.
  static void notThrowException();

  //! \brief Exits program with a given message and EXIT_FAILURE exit code.
  //! \param aErrorMessage The error message that will be provided.
  static void deathTest_exitWithMessage(const char* aErrorMessage);

  //! \brief Exists program with a given message and EXIT_SUCCESS exit code.
  //! \param aMessage The message that will be provided.
  static void deathTest_normalExit(const char* aMessage);

  //! \brief Exits program with a given message and raising a SIGINT signal.
  //! \param aErrorMessage The error message that will be provided.
  static void deathTest_signalExit(const char* aErrorMessage);
};

#endif // LIBRARY_H_
