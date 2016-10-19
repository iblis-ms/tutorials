// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>


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

////////////////////////////////////////////////////////////////////////////////
//                                  Range                                     //
////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmark method for 'factorial' method with optimisation.
void Benchmark_factorial_optimisation(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    factorial(value);
  }
}

BENCHMARK(Benchmark_factorial_optimisation)->Range(8, 1<<15);

//! \brief Benchmark method for 'factorial' method without optimisation.
void Benchmark_factorial_preventOptimisation(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    // Prevent optimisation.
    benchmark::DoNotOptimize(factorial(value));
    // Force writing cached values into memory.
    benchmark::ClobberMemory();
  }
}

BENCHMARK(Benchmark_factorial_preventOptimisation)->Range(8, 1<<15);

/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8             2 ns          2 ns  332886490
 Benchmark_factorial/64            2 ns          2 ns  332813635
 Benchmark_factorial/512           2 ns          2 ns  333047354
 Benchmark_factorial/4k            2 ns          2 ns  300123144
 Benchmark_factorial/32k           2 ns          2 ns  335810416
 Benchmark_factorial2/8            3 ns          3 ns  238232830
 Benchmark_factorial2/64         115 ns        115 ns    6173887
 Benchmark_factorial2/512        971 ns        971 ns     715267
 Benchmark_factorial2/4k        8112 ns       8113 ns      85956
 Benchmark_factorial2/32k      63163 ns      63165 ns      10634
-------------------------------------OUTPUT--------------------------------------
*/

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////
// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
