// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////

//! \brief factorial method.
//! \param aValue Value to calculate its factorial.
//! \return Factorial value of the given value.
long factorial(long aValue){
    if (aValue == 1){
        return 1;
    }
    return factorial(aValue - 1) * aValue;
}

////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmar method for 1st benchmark.
void Benchmark_factorial1(benchmark::State& aState) {
    const int value = aState.range(0);
    while (aState.KeepRunning()) { // KeepRunning checks if the test should still run.
        factorial(value);
    }
}

// While registration you can provide arguments.
// Here the Benchmark_fibonacci will be called with following arguments in range(0): 8, 64, 512, 4096, 32768
BENCHMARK(Benchmark_factorial1)->Arg(8)->Arg(64)->Arg(1 << 9)->Arg(1 << 12)->Arg(1 << 15);

// You can also use Args to provided a vector of values.
BENCHMARK(Benchmark_factorial1)->Args(std::vector<int>{8 ,64, 1 << 9, 1 << 12, 1 << 15});

// C++11 syntaxt makes it easier
BENCHMARK(Benchmark_factorial1)->Args({8 ,64, 1 << 9, 1 << 12, 1 << 15});

////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmar method for 1st benchmark.
void Benchmark_factorial2(benchmark::State& aState) {
    const int value = aState.range(0);
    while (aState.KeepRunning()) { // KeepRunning checks if the test should still run.
        factorial(value);
    }
}

// GBenchmark has Range option that allows providing argument in easier way.
// Range(x, y) means:
// x - the first value
// y - the last value
// The method will be called with x value, after that with 8 * x, after 8 * 8 * x, etc.
// Here: 8, 64, 512, 4096, 32768
BENCHMARK(Benchmark_factorial2)->Range(8, 1<<15);

////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmar method for 1st benchmark.
void Benchmark_factorial3(benchmark::State& aState) {
    const int value = aState.range(0);
    while (aState.KeepRunning()) { // KeepRunning checks if the test should still run.
        factorial(value);
    }
}

// You can also provide different step factor by RangeMultiplier(z) where 'z' is a factor.
// Here: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
BENCHMARK(Benchmark_factorial3)->RangeMultiplier(2)->Range(1, 1 << 10);

////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmar method for 1st benchmark.
void Benchmark_factorial4(benchmark::State& aState) {
    const int value = aState.range(0);
    while (aState.KeepRunning()) { // KeepRunning checks if the test should still run.
        factorial(value);
    }
}

// You can also set more ranges.
// Here: 1, 2, 4, 8, 16, 32, 128, 256, 512, 1024, 2048, 4096
BENCHMARK(Benchmark_factorial4)->RangeMultiplier(2)->Range(1, 1 << 5)->Range(1 << 8, 1 << 12);

////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmar method for 1st benchmark.
void Benchmark_factorial5(benchmark::State& aState) {
    const int value = aState.range(0);
    while (aState.KeepRunning()) { // KeepRunning checks if the test should still run.
        factorial(value);
    }
}

// There is also Ranges with vector argument. The above example can be written:
BENCHMARK(Benchmark_factorial5)->RangeMultiplier(2)->Ranges(std::vector<std::pair<int, int>>{std::pair<int, int>{1, 1 << 5}, std::pair<int, int>{1 << 8, 1 << 12}});

// C++11 allows writing it simpler.
BENCHMARK(Benchmark_factorial5)->RangeMultiplier(2)->Ranges({{1, 1 << 5}, {1 << 8, 1 << 12}});

////////////////////////////////////////////////////////////////////////////////

//! \brief Benchmark for memset & mempcy method. - Example take from Google Benchmark documentation.
void Benchmark_memcpy(benchmark::State& aState) {
    const int size = aState.range(0);
    char* src = new char[size];
    char* dst = new char[size];
    memset(src, 'x', size);
    while (aState.KeepRunning()) {
        memcpy(dst, src, size);
    }
    aState.SetBytesProcessed(int64_t(aState.iterations()) * int64_t(size));
    delete[] src;
    delete[] dst;
}

BENCHMARK(Benchmark_memcpy)->Range(8, 1<<15);

#if 0
Benchmark* DenseRange(int start, int limit, int step = 1);

// Run this benchmark once with "args" as the extra arguments passed
// to the function.
// REQUIRES: The function passed to the constructor must accept arg1, arg2 ...
Benchmark* Args(const std::vector<int>& args);

// Equivalent to Args({x, y})
// NOTE: This is a legacy C++03 interface provided for compatibility only.
//   New code should use 'Args'.
Benchmark* ArgPair(int x, int y) {
    std::vector<int> args;
    args.push_back(x);
    args.push_back(y);
    return Args(args);
}

// Run this benchmark once for a number of values picked from the
// ranges [start..limit].  (starts and limits are always picked.)
// REQUIRES: The function passed to the constructor must accept arg1, arg2 ...
Benchmark* Ranges(const std::vector<std::pair<int, int> >& ranges);

// Equivalent to Ranges({{lo1, hi1}, {lo2, hi2}}).
// NOTE: This is a legacy C++03 interface provided for compatibility only.
//   New code should use 'Ranges'.
Benchmark* RangePair(int lo1, int hi1, int lo2, int hi2) {
    std::vector<std::pair<int, int> > ranges;
    ranges.push_back(std::make_pair(lo1, hi1));
    ranges.push_back(std::make_pair(lo2, hi2));
    return Ranges(ranges);
}

#endif

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////

// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
