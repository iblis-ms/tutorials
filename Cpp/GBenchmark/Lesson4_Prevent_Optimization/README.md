#Google Benchmark - Lesson 4 - Prevent Optimization

Google Benchmark [https://github.com/google/benchmark](https://github.com/google/benchmark) has ability to prevent optimization. CPU caches data and instructions, which has huge impact on benchmarks. Caches benchmarks methods can't simulate your production environment. Google Benchmark uses some assembler instruction to clean cache (exactly, to mark cached memory outdated).

#Target of this lesson
After this lesson you will know how to:
- prevent optimalization.

#Used methods, macros & objects
- DoNotOptimize
- ClobberMemory

*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock)*

