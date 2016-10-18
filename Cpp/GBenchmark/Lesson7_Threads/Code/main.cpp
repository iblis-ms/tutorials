// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>

#include <chrono>

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//                              Pausing timers                                //
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
void Benchmark_factorial_pause(benchmark::State& aState)
{
  if (aState.thread_index == 0) {
    // Setup code here for the 1st thread
  }
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    benchmark::DoNotOptimize(factorial(value));
  }
  if (aState.thread_index == 0) {
    // Tear down code here for the 1st thread
  }
}

BENCHMARK(Benchmark_factorial_pause)->Range(8, 1<<15);
BENCHMARK(Benchmark_factorial_pause)->Threads(3)->Range(8, 1<<15);
BENCHMARK(Benchmark_factorial_pause)->Threads(3)->Range(8, 1<<15)->UseRealTime();
/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
Benchmark_factorial_pause/8                                3 ns          3 ns  225538647
Benchmark_factorial_pause/64                             114 ns        114 ns    6143160
Benchmark_factorial_pause/512                            963 ns        963 ns     721416
Benchmark_factorial_pause/4k                            7756 ns       7756 ns      89066
Benchmark_factorial_pause/32k                          62248 ns      62247 ns      11060
Benchmark_factorial_pause/8/threads:3                      2 ns          5 ns  168650145
Benchmark_factorial_pause/64/threads:3                    52 ns        147 ns    4727397
Benchmark_factorial_pause/512/threads:3                  433 ns       1252 ns     568260
Benchmark_factorial_pause/4k/threads:3                  3611 ns       9794 ns      69063
Benchmark_factorial_pause/32k/threads:3                28133 ns      80302 ns       8817
Benchmark_factorial_pause/8/real_time/threads:3            2 ns          5 ns  300000000
Benchmark_factorial_pause/64/real_time/threads:3          54 ns        151 ns   13658235
Benchmark_factorial_pause/512/real_time/threads:3        444 ns       1229 ns    1590747
Benchmark_factorial_pause/4k/real_time/threads:3        3659 ns       9859 ns     201072
Benchmark_factorial_pause/32k/real_time/threads:3      28981 ns      79703 ns      24432

-------------------------------------OUTPUT--------------------------------------
*/

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////
// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
