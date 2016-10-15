// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark

// adds Google Benchmark header
#include <benchmark/benchmark.h>

#include <string>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////

//! \brief Function that will be called by Google Benchmark. Here we are checking operator+= of std::string.
//! \param aState The argument that links Google Benchmark with function. It contains benchmark arguments and state benchmark run itself.
void Benchmark_StringConcatenation_plus(benchmark::State& aState) {
    std::string result;
    
    // Google Benchmark repeats running a benchmark method. The number of iteration is limited to 1e9. Moreover time of benchmarking one method is bounded by 'benchmark_min_time' argument and 5x 'benchmark_min_time'.
    while (aState.KeepRunning()) { // KeepRunning checks if the test should still run.
        result += "a";
    }
}

// You have to register method to Google Benchmark
BENCHMARK(Benchmark_StringConcatenation_plus);

////////////////////////////////////////////////////////////////////////////////

//! \brief This is also benchmark method that tests std::string::append method.
//! \param aState See Benchmark_StringConcatenation_plus
void Benchmark_StringConcatenation_append(benchmark::State& aState) {
    std::string result;
    while (aState.KeepRunning()) {
        result.append("a");
    }
}

// You have to register method to Google Benchmark
BENCHMARK(Benchmark_StringConcatenation_append);

////////////////////////////////////////////////////////////////////////////////

//! \brief This is also benchmark method that tests operator<< of std::stringstream.
//! \param aState See Benchmark_StringConcatenation_plus
void Benchmark_StringConcatenation_stringstream(benchmark::State& aState) {
    std::stringstream result;
    while (aState.KeepRunning()) {
        result<<"a";
    }
}

// You have to register method to Google Benchmark
BENCHMARK(Benchmark_StringConcatenation_stringstream);


////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////

// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();


////////////////////////////////////////////////////////////////////////////////
//                                   OUTPUT                                   //
////////////////////////////////////////////////////////////////////////////////

/*
The output of program should be similar to below one:
-------------------------------------OUTPUT--------------------------------------
 Run on (8 X 1000 MHz CPU s)
 2016-10-15 11:14:47
 Benchmark                                           Time           CPU Iterations
 ---------------------------------------------------------------------------------
 Benchmark_StringConcatenation_plus                 13 ns         25 ns   28034089
 Benchmark_StringConcatenation_append               13 ns         25 ns   29431056
 Benchmark_StringConcatenation_stringstream         19 ns         36 ns   17722775
-------------------------------------OUTPUT---------------------------------------
The 1st line shows information about your CPU.
The 2nd line contains time.
After that the benchmark results are presented. The 1st column presents benchmark method.
The 2nd column presents time of method execution and CPU time. The unit of them can be changed.
The last column has number of iterations.
 
You may wondering how a benchmark method is called. I added displaying length of string 
at the end of the benchmark method. 
 
-------------------------------------OUTPUT--------------------------------------
 Run on (8 X 1000 MHz CPU s)
 2016-10-15 11:36:38
 Benchmark                                           Time           CPU Iterations
 ---------------------------------------------------------------------------------
 String length: 1
 String length: 10
 String length: 100
 String length: 1000
 String length: 10000
 String length: 100000
 String length: 1000000
 String length: 10000000
 String length: 30117372
 Benchmark_StringConcatenation_plus                 13 ns         23 ns   30117372
 String length: 1
 String length: 10
 String length: 100
 String length: 1000
 String length: 10000
 String length: 100000
 String length: 1000000
 String length: 10000000
 String length: 30679955
 Benchmark_StringConcatenation_append               12 ns         24 ns   30679955
 String length: 1
 String length: 10
 String length: 100
 String length: 1000
 String length: 10000
 String length: 100000
 String length: 1000000
 String length: 10000000
 String length: 100000000
 Benchmark_StringConcatenation_stringstream         20 ns         19 ns  100000000
-------------------------------------OUTPUT--------------------------------------
*/