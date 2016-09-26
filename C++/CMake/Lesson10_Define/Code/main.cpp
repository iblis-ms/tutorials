// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/cmake

#include <iostream>

int main()
{
#ifdef OPTION1
  std::cout<<"Option1 present\n";
#else // not OPTION1
  std::cout<<"Option1 NOT present\n";
#endif // OPTION1

  std::cout<<"DEFINE_VALUE="<<DEFINE_VALUE<<std::endl;
  return 0;
}
