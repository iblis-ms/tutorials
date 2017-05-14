# Google Benchmark - Lesson 1 - Simple usage

Google Benchmark [https://github.com/google/benchmark](https://github.com/google/benchmark) is a framework for benchmarking your code. You can check complexity of your code by running your methods with different set of input data. This framework allows easily providing big number of input data. 

Google Benchmark is not supported by CMake, there you need to provide a path to FindGBenchmark.cmake file to CMake variable's CMAKE_MODULE_PATH.

Google Benchmark and your test program should be compiled in Release mode. Google Benchmark has some features to doesn't allow compiler to optimize your code.

```
cmake ../Code -DCMAKE_BUILD_TYPE=Release
```
To compile:
```
make
```
To run tests:
```
./GBenchmark_Lesson1
```

# Target of this lesson
After this lesson you will know how to:
- configure CMake to use Google Benchmark
- write simple benchmark methods.

# Used methods, macros & objects
- BENCHMARK
- BENCHMARK_MAIN
- benchmark::State
- benchmark::State::KeepRunning

*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock)*

