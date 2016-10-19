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
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    aState.PauseTiming(); // turn off timer
    const int changedValue = value * value / 10;
    aState.ResumeTiming(); // turn on timer
    benchmark::DoNotOptimize(factorial(changedValue));
  }
}

BENCHMARK(Benchmark_factorial_pause)->Range(8, 1<<15);
/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8          178 ns        180 ns    3917723
 Benchmark_factorial/64         291 ns        294 ns    2394353
 Benchmark_factorial/512       1135 ns       1139 ns     608871
 Benchmark_factorial/4k        7904 ns       7917 ns      88303
 Benchmark_factorial/32k      62028 ns      62087 ns      11239
-------------------------------------OUTPUT--------------------------------------
*/


////////////////////////////////////////////////////////////////////////////////
//                              Providing timers                              //
////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmark method for 'factorial' method.
void Benchmark_factorial_myTimers(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    const auto start = std::chrono::high_resolution_clock::now();
    benchmark::DoNotOptimize(factorial(value));
    const auto end  = std::chrono::high_resolution_clock::now();

    const auto elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    // Sets seconds of method execution.
    aState.SetIterationTime(elapsed_seconds.count());
  }
}

BENCHMARK(Benchmark_factorial_myTimers)->Range(8, 1<<15);


////////////////////////////////////////////////////////////////////////////////
//                               Set time unit                                //
////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmark method for 'factorial' method.
void Benchmark_factorial(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    const int changedValue = value * value / 10;
    benchmark::DoNotOptimize(factorial(value));
  }
}

BENCHMARK(Benchmark_factorial)->Range(8, 1<<15)->Unit(benchmark::kMicrosecond);
/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8                     0 us          0 us  225366765
 Benchmark_factorial/64                    0 us          0 us    6052062
 Benchmark_factorial/512                   1 us          1 us     724040
 Benchmark_factorial/4k                    8 us          8 us      88269
 Benchmark_factorial/32k                  62 us         62 us      11263
-------------------------------------OUTPUT--------------------------------------
*/


////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////
// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();

