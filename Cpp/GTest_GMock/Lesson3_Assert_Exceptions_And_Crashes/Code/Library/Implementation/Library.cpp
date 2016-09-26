// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include "Library.h"
#include <stdexcept>
#include <cstdio>
#include <csignal>
#include <cstdlib>

void CLibrary::throwException()
{
  throw std::runtime_error { "Exception!!!" };
}

void CLibrary::notThrowException()
{
}

void CLibrary::deathTest_exitWithMessage(const char* aErrorMessage)
{
  // prints an error message
  std::perror(aErrorMessage);
  // exits program with an error code
  std::exit(EXIT_FAILURE);
}

void CLibrary::deathTest_normalExit(const char* aMessage)
{
  // prints a message
  std::perror(aMessage);
  std::exit(EXIT_SUCCESS);
}

void CLibrary::deathTest_signalExit(const char* aErrorMessage)
{
  // prints an error message
  std::perror(aErrorMessage);
  std::raise(SIGINT);
}
