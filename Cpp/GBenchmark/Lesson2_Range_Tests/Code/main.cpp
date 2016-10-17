// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>

#include <string>
#include <sstream>
#include <cstring>

////////////////////////////////////////////////////////////////////////////////

//! \brief factorial method.
//! \param aValue Value to calculate its factorial.
//! \return Factorial value of the given value.
long factorial(long aValue)
{
  if (aValue == 1)
  {
    return 1;
  }
  return factorial(aValue - 1) * aValue;
}

//! \brief Benchmark method for 'factorial' method.
void Benchmark_factorial(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  { // KeepRunning checks if the test should still run.
    factorial(value);
  }
}

//! \brief Binomial Theorem. n!/((n-k)!k!) https://en.wikipedia.org/wiki/Binomial_theorem
//! \param aN Value n.
//! \param aK Value k.
//! \return Factorial value of the given value.
long binomialTheorem(long aN, long aK)
{
  return factorial(aN) / (factorial(aN - aK) * factorial(aK));
}

//! \brief Benchmark method for 'binomialTheorem' method.
void Benchmark_binomialTheorem(benchmark::State& aState)
{
  const int n = aState.range(0);
  const int k = aState.range(1);
  while (aState.KeepRunning())
  { // KeepRunning checks if the test should still run.
    binomialTheorem(n, k);
  }
}

////////////////////////////////////////////////////////////////////////////////
//                                    Arg                                     //
////////////////////////////////////////////////////////////////////////////////

// While registration you can provide arguments.
// Here the Benchmark_fibonacci will be called with following arguments in range(0): 8, 64, 512, 4096, 32768
BENCHMARK(Benchmark_factorial)->Arg(8)->Arg(64)->Arg(1 << 9)->Arg(1 << 12)->Arg(1 << 15);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8             2 ns          2 ns  329431120
 Benchmark_factorial/64            2 ns          2 ns  317386255
 Benchmark_factorial/512           2 ns          2 ns  330414864
 Benchmark_factorial/4k            2 ns          2 ns  316226172
 Benchmark_factorial/32k           2 ns          2 ns  334169427
 -------------------------------------OUTPUT--------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//                                  Range                                     //
////////////////////////////////////////////////////////////////////////////////
// GBenchmark has Range option that allows providing argument in easier way.
// Range(x, y) means:
// x - the first value
// y - the last value
// The default multiplier is 8.
// The method will be called with x value, after that with 8 * x, after 8 * 8 * x, etc.
// Here: 8, 64, 512, 4096, 32768
BENCHMARK(Benchmark_factorial)->Range(8, 1<<15);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8             2 ns          2 ns  319230008
 Benchmark_factorial/64            2 ns          2 ns  331265406
 Benchmark_factorial/512           2 ns          2 ns  328905104
 Benchmark_factorial/4k            2 ns          2 ns  334954036
 Benchmark_factorial/32k           2 ns          2 ns  332971995
 -------------------------------------OUTPUT--------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//                             RangeMultiplier                                //
////////////////////////////////////////////////////////////////////////////////
// You can also provide different step factor by RangeMultiplier(z) where 'z' is a factor.
// Here: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
BENCHMARK(Benchmark_factorial)->RangeMultiplier(2)->Range(1, 1 << 10);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/1             2 ns          2 ns  332945895
 Benchmark_factorial/2             2 ns          2 ns  333254606
 Benchmark_factorial/4             2 ns          2 ns  334778111
 Benchmark_factorial/8             2 ns          2 ns  326767674
 Benchmark_factorial/16            2 ns          2 ns  334089628
 Benchmark_factorial/32            2 ns          2 ns  334182832
 Benchmark_factorial/64            2 ns          2 ns  331313109
 Benchmark_factorial/128           2 ns          2 ns  323196937
 Benchmark_factorial/256           2 ns          2 ns  333020072
 Benchmark_factorial/512           2 ns          2 ns  333584096
 Benchmark_factorial/1024          2 ns          2 ns  320416632
 -------------------------------------OUTPUT--------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//                    Range - you can provide multiple ranges                 //
////////////////////////////////////////////////////////////////////////////////
// You can also set more ranges.
// Here: 1, 2, 4, 8, 16, 32, 128, 256, 512, 1024, 2048, 4096
BENCHMARK(Benchmark_factorial)->RangeMultiplier(2)->Range(1, 1 << 5)->Range(1 << 8, 1 << 12);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/1             2 ns          2 ns  333575767
 Benchmark_factorial/2             2 ns          2 ns  335345030
 Benchmark_factorial/4             2 ns          2 ns  313025259
 Benchmark_factorial/8             2 ns          2 ns  327057893
 Benchmark_factorial/16            2 ns          2 ns  315178688
 Benchmark_factorial/32            2 ns          2 ns  313625847
 Benchmark_factorial/256           2 ns          2 ns  320426650
 Benchmark_factorial/512           2 ns          2 ns  302959890
 Benchmark_factorial/1024          2 ns          2 ns  304803544
 Benchmark_factorial/2k            2 ns          2 ns  293850686
 Benchmark_factorial/4k            2 ns          2 ns  303471918
 -------------------------------------OUTPUT--------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//                                DenseRange                                  //
////////////////////////////////////////////////////////////////////////////////
// DenseRange(x, y, z):
// x - start value
// y - stop value
// z - value that will be added in each iteration
// Here: 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31
BENCHMARK(Benchmark_factorial)->DenseRange(1, 10, 3);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/1           2 ns          2 ns  315168301
 Benchmark_factorial/4           2 ns          2 ns  313732329
 Benchmark_factorial/7           2 ns          2 ns  307412595
 Benchmark_factorial/10          2 ns          2 ns  339113237
 -------------------------------------OUTPUT--------------------------------------
 */

/*******************************************************************************/
/*                  Providing more arguments per iteration                     */
/*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//                                   Args                                     //
////////////////////////////////////////////////////////////////////////////////
// You can provide a vector of values. Full vector will be available in benchmark iteration.
BENCHMARK(Benchmark_binomialTheorem)->Args(std::vector<int>
    { 6, 2});
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_binomialTheorem/6/2          2 ns          2 ns  337571608
 -------------------------------------OUTPUT--------------------------------------
 */

// C++11 syntax makes it easier
BENCHMARK(Benchmark_binomialTheorem)->Args({6, 2});
// for pair you can write:
BENCHMARK(Benchmark_binomialTheorem)->ArgPair(6, 2);

////////////////////////////////////////////////////////////////////////////////
//                       Range for multiple values                            //
////////////////////////////////////////////////////////////////////////////////

// You can set up range for multi values benchmark.
BENCHMARK(Benchmark_binomialTheorem)->RangePair(64, 512, 1, 8);
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_binomialTheorem/64/1           2 ns          2 ns  341623328
 Benchmark_binomialTheorem/512/1          2 ns          2 ns  341307873
 Benchmark_binomialTheorem/64/8           2 ns          2 ns  338758068
 Benchmark_binomialTheorem/512/8          2 ns          2 ns  340422494
 -------------------------------------OUTPUT--------------------------------------
 */

//  The above example can be written:
BENCHMARK(Benchmark_binomialTheorem)->Ranges(std::vector<std::pair<int, int>>{std::pair<int, int>{64, 512}, std::pair<int, int>{1, 8}});
// C++11 allows writing it simpler.
BENCHMARK(Benchmark_binomialTheorem)->Ranges({{64, 512}, {1, 8}});

// You can also change multiplier:
BENCHMARK(Benchmark_binomialTheorem)->RangeMultiplier(4)->Ranges({{64, 512}, {1, 8}});
/*
 Output of benchmark:
 -------------------------------------OUTPUT--------------------------------------
 Benchmark_binomialTheorem/64/1           2 ns          2 ns  340288941
 Benchmark_binomialTheorem/256/1          2 ns          2 ns  340489427
 Benchmark_binomialTheorem/512/1          2 ns          2 ns  343643742
 Benchmark_binomialTheorem/64/4           2 ns          2 ns  342279332
 Benchmark_binomialTheorem/256/4          2 ns          2 ns  331593956
 Benchmark_binomialTheorem/512/4          2 ns          2 ns  338831053
 Benchmark_binomialTheorem/64/8           2 ns          2 ns  339814469
 Benchmark_binomialTheorem/256/8          2 ns          2 ns  337281335
 Benchmark_binomialTheorem/512/8          2 ns          2 ns  338095593
 -------------------------------------OUTPUT--------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//                       Custom argument/range                                //
////////////////////////////////////////////////////////////////////////////////

 void customArguments(benchmark::internal::Benchmark* aBenchmark) {
  for (int i = 64; i <= 512; i *= 8) {
    for (int j = 1; j <= 8; j *= 8) {
      aBenchmark->Args({i, j});
    }
  }
}

// Apply - requires pointer to method.
BENCHMARK(Benchmark_binomialTheorem)->Apply(customArguments);

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////
// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
