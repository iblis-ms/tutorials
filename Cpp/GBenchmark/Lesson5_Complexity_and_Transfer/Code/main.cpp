// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>

#include <list>

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//                                Complexity                                  //
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

//! \brief Benchmark method for 'factorial' method with optimization.
void Benchmark_factorial(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    benchmark::DoNotOptimize(factorial(value));
  }
  aState.SetComplexityN(value); // provide input size.
}

// Google Benchmark can check complexity of your code i.e: O(n), O(n^2), etc.
// Google Benchmark will display complexity and the normalized root square.
BENCHMARK(Benchmark_factorial)->Range(8, 1<<15)->Complexity();
/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8            4 ns          3 ns  221325626
 Benchmark_factorial/64         126 ns        122 ns    6251538
 Benchmark_factorial/512       1083 ns       1050 ns     675448
 Benchmark_factorial/4k        8387 ns       8182 ns      83994
 Benchmark_factorial/32k      64419 ns      63759 ns      10809
 Benchmark_factorial_BigO       1.97 N       1.95 N
 Benchmark_factorial_RMS          1 %          1 %
-------------------------------------OUTPUT--------------------------------------
*/

// Google Benchmark can be run against given complexity. You can easily check if your
// implementation has given complexity.
// Here, O(log(n)) is established. The calculation of factorial is O(n), so we can expect
// big RMS in output.
BENCHMARK(Benchmark_factorial)->Range(8, 1<<15)->Complexity(benchmark::oLogN);
/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
 Benchmark_factorial/8            4 ns          4 ns  195032537
 Benchmark_factorial/64         118 ns        118 ns    6107588
 Benchmark_factorial/512       1000 ns        999 ns     706501
 Benchmark_factorial/4k        8065 ns       8065 ns      86410
 Benchmark_factorial/32k      64407 ns      64408 ns      10744
 Benchmark_factorial_BigO    2166.89 lgN    2166.87 lgN
 Benchmark_factorial_RMS        132 %        132 %
-------------------------------------OUTPUT--------------------------------------
*/

// You can also provide your expected complexity by lambda/function.
// Here, O(1/n) - the bigger input, the smaller complexity :D.
BENCHMARK(Benchmark_factorial)->Range(8, 1<<15)->Complexity([](int n)->double{return 1.0 / n; });


////////////////////////////////////////////////////////////////////////////////
//                              Speed transfer                                //
////////////////////////////////////////////////////////////////////////////////

int addList(int aSize){
  std::list<int> list;
  for (int i = 0; i < aSize; ++i){
    list.push_back(1);
  }
  return list.size();
}

//! \brief Benchmark method for 'factorial' method with optimization.
void Benchmark_addList(benchmark::State& aState)
{
  const int value = aState.range(0);
  while (aState.KeepRunning())
  {
    benchmark::DoNotOptimize(addList(value));
  }
  // To get speed, you have to calculate transfered data for this run.
  // numberOfBytes = numberOfIteration * size * sizeof(listValueType)
  const int numberOfBytes = aState.iterations() * value * sizeof(int);
  aState.SetBytesProcessed(numberOfBytes);
}

// Google Benchmark can check speed of data transfer.
// Here, we are testing std:list... (you can easily compare it with std::vector).
BENCHMARK(Benchmark_addList)->Range(8, 1<<15);
/*
Output of benchmarks:
-------------------------------------OUTPUT--------------------------------------
Benchmark_addList/8            299 ns        299 ns    2343296   102.038MB/s
Benchmark_addList/64          2171 ns       2171 ns     310619   112.469MB/s
Benchmark_addList/512        17641 ns      17642 ns      37985    110.71MB/s
Benchmark_addList/4k        146254 ns     146244 ns       4865   106.842MB/s
Benchmark_addList/32k      1252758 ns    1252762 ns        566   99.7795MB/s
-------------------------------------OUTPUT--------------------------------------
*/

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////
// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
