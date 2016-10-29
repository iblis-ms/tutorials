#Move  in C++11 and in C++03 using Boost.Move
This tutorial shows how big influence has the 'move' on performance. The 'move' was added to C++11 standard. It was based on Boost.Move. This example contains 2 program: boost_move and cpp11_move. I presents Boost.Move which is compatible with C++03 (C++03 = C++98 + TR1), because there many projects that still use this dialect of C++. Both of these program use Google Benchmark to easily compare passing arguments by L-value reference and R-value reference. 

##What is L-value and R-value reference
Let's look at the examples with C++11 semantic:
```C++

ClassL(const ClassL& aLValueReference)
 : iItem{aLValueReference.iItem->copy()} {
/* The argument object's content is copied to this object. */
}

ClassL obj{ClassL{}};
// Here we are creating one temporary object and it is passing to copy constructor,
// where its content is copied to 'obj'. The temporary object is completely useless,
// but it has to be created and it's content must be copied, so we have to create
// the content twice.

//////////////////////////////////////////////////////////////////////////////////////////

ClassR(ClassR&& aRValueReference)
 : iItem{std::move(aLValueReference.iItem)} {
aLValueReference.iItem = nullptr;
/* The argument object's content is moved to this object. */
}

ClassR obj{ClassR{}};
// Here we are creating also one temporary object and it is passing to move constructor.
// However move constructor "moves" content of temporary object to 'obj' and after that
// sets it to null. Therefore the work that was done to create content of the temporary
// object is not useless. 
```

Another example:
```C++
std::vector<ClassL> vL;

ClassL objL;
objL.method();
objL.method(argument);

vL.push_back(objL);
// Here 'objL' will be copied to the array inside the vector, so it content will be
// also copied (which means created twice)

//////////////////////////////////////////////////////////////////////////////////////////

ClassR objR;
objR.method();
objR.method(argument);

vL.push_back(std::move(objR));
// Here 'objR' will be "moved" to the array inside the vector. If we don't need to use
// 'objR' after calling 'push_back', this approach meas that the contend is created once.
```

##Results

Boost_Benchmark_copy & Cpp11_Benchmark_copy means passing objects by reference and copied them inside method. Time of creation origin objects is not included.

Benchmark_rvalueConstructor & Cpp11_Benchmark_rvalueConstructor is passing object by r-value reference and "moving" their content inside method. Time of creation origin objects is not included.

Benchmark_rvalueConstructorInitialization & Benchmark_rvalueConstructorInitialization means passing by R-value reference temporary objects. Time of creation temporary objects is included.

|Benchmark                                             |        Time   |        CPU   |  Iterations  |
|:-----------------------------------------------------|:-------------:|:------------:|:------------:|
|Boost_Benchmark_copy/1                                |      602 ns   |    1199 ns   |   515274     |
|Boost_Benchmark_copy/2                                |      582 ns   |    1163 ns   |   509417     |
|Boost_Benchmark_copy/4                                |      549 ns   |     597 ns   |  5988020     |
|Boost_Benchmark_copy/8                                |      655 ns   |    1308 ns   |   548134     |
|Boost_Benchmark_copy/16                               |      688 ns   |     743 ns   |  4744280     |
|Boost_Benchmark_copy/32                               |      851 ns   |    1700 ns   |   381480     |
|Boost_Benchmark_copy/64                               |     1493 ns   |    2986 ns   |   229855     |
|Boost_Benchmark_copy/128                              |     2509 ns   |    4896 ns   |   139159     |
|Boost_Benchmark_copy/256                              |     4532 ns   |    5080 ns   |   753760     |
|Boost_Benchmark_copy/512                              |    15057 ns   |   17527 ns   |   251870     |
|Boost_Benchmark_copy/1024                             |    29724 ns   |   27800 ns   |   130130     |
|Boost_Benchmark_copy/2k                               |    59065 ns   |  117042 ns   |     6003     |
|Boost_Benchmark_copy/4k                               |   105361 ns   |  209909 ns   |     2776     |
|Boost_Benchmark_copy/8k                               |   225966 ns   |  250130 ns   |    10000     |
|Boost_Benchmark_copy/16k                              |  1316724 ns   | 1704721 ns   |      383     |
|Boost_Benchmark_copy/32k                              |  3070288 ns   | 3742550 ns   |     1000     |
|Boost_Benchmark_copy_BigO                             |   5.97 NlgN   |  7.36 NlgN   |              |
|Boost_Benchmark_copy_RMS                              |        40 %   |       38 %   |              |
|Boost_Benchmark_rvalueConstructor/1                   |     1305 ns   |    2183 ns   |  1000000     |
|Boost_Benchmark_rvalueConstructor/2                   |     1338 ns   |    1216 ns   |   579902     |
|Boost_Benchmark_rvalueConstructor/4                   |     1276 ns   |    1118 ns   |   599510     |
|Boost_Benchmark_rvalueConstructor/8                   |     1309 ns   |    2894 ns   |   585412     |
|Boost_Benchmark_rvalueConstructor/16                  |     1267 ns   |    2808 ns   |   589503     |
|Boost_Benchmark_rvalueConstructor/32                  |     1279 ns   |    1125 ns   |   600817     |
|Boost_Benchmark_rvalueConstructor/64                  |     1308 ns   |     934 ns   |  5936830     |
|Boost_Benchmark_rvalueConstructor/128                 |     1525 ns   |    1258 ns   |  6654370     |
|Boost_Benchmark_rvalueConstructor/256                 |     1562 ns   |    1271 ns   |   532400     |
|Boost_Benchmark_rvalueConstructor/512                 |     1845 ns   |    1516 ns   |   454729     |
|Boost_Benchmark_rvalueConstructor/1024                |     2138 ns   |   11704 ns   |   100000     |
|Boost_Benchmark_rvalueConstructor/2k                  |     2131 ns   |    4192 ns   |   406353     |
|Boost_Benchmark_rvalueConstructor/4k                  |     2145 ns   |    1741 ns   |   397289     |
|Boost_Benchmark_rvalueConstructor/8k                  |     2225 ns   |    1771 ns   |   385382     |
|Boost_Benchmark_rvalueConstructor/16k                 |   271488 ns   |  303789 ns   |    10000     |
|Boost_Benchmark_rvalueConstructor/32k                 |   611182 ns   | 1005392 ns   |     1000     |
|Boost_Benchmark_rvalueConstructor_BigO                |    0.00 N^2   |   0.00 N^2   |              |
|Boost_Benchmark_rvalueConstructor_RMS                 |        54 %   |       24 %   |              |
|Boost_Benchmark_rvalueConstructorInitialization/1     |      584 ns   |    1167 ns   |   605505     |
|Boost_Benchmark_rvalueConstructorInitialization/2     |      573 ns   |     620 ns   |  5711120     |
|Boost_Benchmark_rvalueConstructorInitialization/4     |      558 ns   |    1115 ns   |   583761     |
|Boost_Benchmark_rvalueConstructorInitialization/8     |      633 ns   |     736 ns   |  5666820     |
|Boost_Benchmark_rvalueConstructorInitialization/16    |      691 ns   |     751 ns   |  4766570     |
|Boost_Benchmark_rvalueConstructorInitialization/32    |      861 ns   |    1721 ns   |   390634     |
|Boost_Benchmark_rvalueConstructorInitialization/64    |     1151 ns   |    1299 ns   |  1000000     |
|Boost_Benchmark_rvalueConstructorInitialization/128   |     1994 ns   |    3985 ns   |   173996     |
|Boost_Benchmark_rvalueConstructorInitialization/256   |     3444 ns   |    3979 ns   |  1032780     |
|Boost_Benchmark_rvalueConstructorInitialization/512   |     6533 ns   |    7097 ns   |   527560     |
|Boost_Benchmark_rvalueConstructorInitialization/1024  |    16735 ns   |   18096 ns   |   202170     |
|Boost_Benchmark_rvalueConstructorInitialization/2k    |    33491 ns   |   66092 ns   |    10837     |
|Boost_Benchmark_rvalueConstructorInitialization/4k    |    64419 ns   |   70815 ns   |    52200     |
|Boost_Benchmark_rvalueConstructorInitialization/8k    |   128841 ns   |  257094 ns   |     2518     |
|Boost_Benchmark_rvalueConstructorInitialization/16k   |  1018181 ns   | 1166555 ns   |      548     |
|Boost_Benchmark_rvalueConstructorInitialization/32k   |  2275822 ns   | 6496996 ns   |      255     |
|Boost_Benchmark_rvalueConstructorInitialization_BigO  |    0.00 N^3   |   0.00 N^3   |              | 
|Boost_Benchmark_rvalueConstructorInitialization_RMS   |        83 %   |       19 %   |              |
|Cpp11_Benchmark_copy/1                                |      594 ns   |     1175 ns  |   563317     |
|Cpp11_Benchmark_copy/2                                |      574 ns   |    1148 ns   |   538959     |
|Cpp11_Benchmark_copy/4                                |      558 ns   |     599 ns   |  5816270     |
|Cpp11_Benchmark_copy/8                                |      593 ns   |    1185 ns   |   560951     |
|Cpp11_Benchmark_copy/16                               |      689 ns   |     782 ns   |  5033440     |
|Cpp11_Benchmark_copy/32                               |      823 ns   |     889 ns   |  3965870     |
|Cpp11_Benchmark_copy/64                               |     1553 ns   |    3103 ns   |   231991     |
|Cpp11_Benchmark_copy/128                              |     2905 ns   |    3463 ns   |  1000000     |
|Cpp11_Benchmark_copy/256                              |     4815 ns   |    5598 ns   |   744860     |
|Cpp11_Benchmark_copy/512                              |    13246 ns   |   15957 ns   |   100000     |
|Cpp11_Benchmark_copy/1024                             |    27214 ns   |   51979 ns   |    10000     |
|Cpp11_Benchmark_copy/2k                               |    53182 ns   |   61796 ns   |    68380     |
|Cpp11_Benchmark_copy/4k                               |   116275 ns   |  128740 ns   |    29410     |
|Cpp11_Benchmark_copy/8k                               |   295315 ns   |  569838 ns   |     1309     |
|Cpp11_Benchmark_copy/16k                              |  1415012 ns   | 1821892 ns   |     1000     |
|Cpp11_Benchmark_copy/32k                              |  4014000 ns   |10742490 ns   |      155     |
|Cpp11_Benchmark_copy_BigO                             |    0.00 N^3   |   0.00 N^3   |              |
|Cpp11_Benchmark_copy_RMS                              |        63 %   |       19 %   |              |
|Cpp11_Benchmark_rvalueConstructor/1                   |     1459 ns   |    1301 ns   |   541486     |
|Cpp11_Benchmark_rvalueConstructor/2                   |     1437 ns   |    3137 ns   |   537280     |
|Cpp11_Benchmark_rvalueConstructor/4                   |     1384 ns   |    1190 ns   |   542350     |
|Cpp11_Benchmark_rvalueConstructor/8                   |     1470 ns   |    1304 ns   |   527553     |
|Cpp11_Benchmark_rvalueConstructor/16                  |     1644 ns   |    3212 ns   |   514056     |
|Cpp11_Benchmark_rvalueConstructor/32                  |     1699 ns   |    2949 ns   |   592919     |
|Cpp11_Benchmark_rvalueConstructor/64                  |     1644 ns   |    3136 ns   |   537321     |
|Cpp11_Benchmark_rvalueConstructor/128                 |     1470 ns   |   11221 ns   |   100000     |
|Cpp11_Benchmark_rvalueConstructor/256                 |     1491 ns   |    1221 ns   |   538279     |
|Cpp11_Benchmark_rvalueConstructor/512                 |     2072 ns   |    1759 ns   |   384945     |
|Cpp11_Benchmark_rvalueConstructor/1024                |     2242 ns   |    1794 ns   |   347295     |
|Cpp11_Benchmark_rvalueConstructor/2k                  |     2213 ns   |    4273 ns   |   396013     |
|Cpp11_Benchmark_rvalueConstructor/4k                  |     2565 ns   |    1937 ns   |   345372     |
|Cpp11_Benchmark_rvalueConstructor/8k                  |     2377 ns   |    2624 ns   |  3760610     |
|Cpp11_Benchmark_rvalueConstructor/16k                 |   271599 ns   |  403892 ns   |    10000     |
|Cpp11_Benchmark_rvalueConstructor/32k                 |   620094 ns   | 1005520 ns   |     1000     |
|Cpp11_Benchmark_rvalueConstructor_BigO                |    0.00 N^2   |   0.00 N^2   |              |
|Cpp11_Benchmark_rvalueConstructor_RMS                 |        52 %   |       45 %   |              |
|Cpp11_Benchmark_rvalueConstructorInitialization/1     |      570 ns   |     632 ns   |  5920760     |
|Cpp11_Benchmark_rvalueConstructorInitialization/2     |      595 ns   |    1189 ns   |   550133     |
|Cpp11_Benchmark_rvalueConstructorInitialization/4     |      553 ns   |     615 ns   |  6105650     |
|Cpp11_Benchmark_rvalueConstructorInitialization/8     |      620 ns   |    1238 ns   |   551781     |
|Cpp11_Benchmark_rvalueConstructorInitialization/16    |      701 ns   |    1401 ns   |  1000000     |
|Cpp11_Benchmark_rvalueConstructorInitialization/32    |      786 ns   |     853 ns   |  4178410     |
|Cpp11_Benchmark_rvalueConstructorInitialization/64    |     1108 ns   |    2215 ns   |   306244     |
|Cpp11_Benchmark_rvalueConstructorInitialization/128   |     1935 ns   |    1868 ns   |  1000000     |
|Cpp11_Benchmark_rvalueConstructorInitialization/256   |     3338 ns   |    6610 ns   |   103510     |
|Cpp11_Benchmark_rvalueConstructorInitialization/512   |     6499 ns   |   12703 ns   |    52740     |
|Cpp11_Benchmark_rvalueConstructorInitialization/1024  |    16916 ns   |   33287 ns   |   100000     |
|Cpp11_Benchmark_rvalueConstructorInitialization/2k    |    32888 ns   |   33531 ns   |    94560     |
|Cpp11_Benchmark_rvalueConstructorInitialization/4k    |    67220 ns   |  133853 ns   |     4917     |
|Cpp11_Benchmark_rvalueConstructorInitialization/8k    |   130235 ns   |  141029 ns   |    25260     |
|Cpp11_Benchmark_rvalueConstructorInitialization/16k   |  1009030 ns   | 1152429 ns   |      564     |
|Cpp11_Benchmark_rvalueConstructorInitialization/32k   |  2282993 ns   | 2600690 ns   |     2600     |
|Cpp11_Benchmark_rvalueConstructorInitialization_BigO  |   4.44 NlgN   |  5.07 NlgN   |              |
|Cpp11_Benchmark_rvalueConstructorInitialization_RMS   |        44 %   |       42 %   |              |

##Discussion
There is huge difference between passing object by R-value reference and L-value reference. For small object passing L-value reference is a little faster. To the specific size of object passing by R-value has almost constant time. After that caching is not so efficient. Creating temporary object and passing it by R-value reference is also faster than passing by L-value reference.

##Summary
Use R-value reference if you can. If you have to use old C++ dialect, you can take Boost.Move. 

*Author: Marcin Serwach*
