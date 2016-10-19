// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>

#include <vector>
#include <list>

////////////////////////////////////////////////////////////////////////////////
//                               Template type                                //
////////////////////////////////////////////////////////////////////////////////

//! \brief Adds elements to the container.
//! \tparam TConteiner Container type
//! \param aSize Number of elements.
template<typename TConteiner>
void add(int aSize){
  TConteiner con;
  for (int i = 0; i < aSize; ++i)
  {
    typename TConteiner::value_type value;
    con.push_back(value);
  }
}

//! \brief The benchmark method should also have template.
template<typename TConteiner>
void Benchmark_add(benchmark::State& aState)
{
  const int size = aState.range(0);
  while (aState.KeepRunning())
  {
    add<TConteiner>(size);
  }
}

// Registers benchmark. You need to provide benchmark method and template type.
// All range, arguments related method can be used as well.
// Here is std::vector with int used.
BENCHMARK_TEMPLATE(Benchmark_add, std::vector<int>)->Range(1<<0, 1<<10);
// Here is std::list used.
BENCHMARK_TEMPLATE(Benchmark_add, std::list<int>)->Range(1<<0, 1<<10);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_add<std::vector<int>>/1            32 ns         32 ns   21173841
 Benchmark_add<std::vector<int>>/8           140 ns        140 ns    4927834
 Benchmark_add<std::vector<int>>/64          330 ns        330 ns    2063483
 Benchmark_add<std::vector<int>>/512        1021 ns       1021 ns     679955
 Benchmark_add<std::vector<int>>/1024       1504 ns       1504 ns     456810
 Benchmark_add<std::list<int>>/1              32 ns         32 ns   21476841
 Benchmark_add<std::list<int>>/8             274 ns        274 ns    2554629
 Benchmark_add<std::list<int>>/64           2028 ns       2028 ns     342741
 Benchmark_add<std::list<int>>/512         16087 ns      16088 ns      41682
 Benchmark_add<std::list<int>>/1024        32538 ns      32539 ns      21572
 -------------------------------------OUTPUT--------------------------------------
 */


////////////////////////////////////////////////////////////////////////////////
//                           More templates type                              //
////////////////////////////////////////////////////////////////////////////////


//! \brief Adds elements to the container.
//! \tparam TConteiner1 Container type
//! \tparam TConteiner2 Container type
//! \param aSize Number of elements.
template<typename TConteiner1, typename TConteiner2>
void add2Types(int aSize){
  TConteiner1 con1;
  for (int i = 0; i < aSize; ++i)
  {
    typename TConteiner1::value_type value;
    con1.push_back(value);
  }
  TConteiner2 con2;
  for (int i = 0; i < aSize; ++i)
  {
    typename TConteiner2::value_type value;
    con2.push_back(value);
  }
}

//! \brief The benchmark method should also have template.
template<typename TConteiner1, typename TConteiner2>
void Benchmark_add2Types(benchmark::State& aState)
{
  const int size = aState.range(0);
  while (aState.KeepRunning())
  {
    add2Types<TConteiner1, TConteiner2>(size);
  }
}

// You can used variadic number of templates.
BENCHMARK_TEMPLATE(Benchmark_add2Types, std::vector<int>, std::list<int>)->Range(1<<0, 1<<10);
// Here is std::list used.
BENCHMARK_TEMPLATE(Benchmark_add2Types, std::list<int>, std::vector<int>)->Range(1<<0, 1<<10);

/*
Output of benchmark:
-------------------------------------OUTPUT--------------------------------------
 Benchmark_add2Types<std::vector<int>, std::list<int>>/1            69 ns         69 ns    9843324
 Benchmark_add2Types<std::vector<int>, std::list<int>>/8           422 ns        422 ns    1648778
 Benchmark_add2Types<std::vector<int>, std::list<int>>/64         2476 ns       2476 ns     283208
 Benchmark_add2Types<std::vector<int>, std::list<int>>/512       23144 ns      23145 ns      29953
 Benchmark_add2Types<std::vector<int>, std::list<int>>/1024      45407 ns      45403 ns      15373
 Benchmark_add2Types<std::list<int>, std::vector<int>>/1            74 ns         74 ns    9099878
 Benchmark_add2Types<std::list<int>, std::vector<int>>/8           439 ns        439 ns    1608838
 Benchmark_add2Types<std::list<int>, std::vector<int>>/64         2447 ns       2447 ns     277089
 Benchmark_add2Types<std::list<int>, std::vector<int>>/512       18341 ns      18341 ns      38240
 Benchmark_add2Types<std::list<int>, std::vector<int>>/1024      35452 ns      35452 ns      19743
-------------------------------------OUTPUT--------------------------------------
*/


////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////
// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
