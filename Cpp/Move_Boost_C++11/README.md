#Move semantic in C++11 and in C++03 using Boost.Move
This tutorial shows how big influence has the 'move' on performance. The 'move' was added to C++11 standard. It was based on Boost.Move. This example contains 2 program: boost_move and cpp11_move. I presents Boost.Move which is compatible with C++03 (C++03 = C++98 + TR1), because there many projects that still use this dialect of C++. Both of these program use Google Benchmark to easily compare passing arguments by L-value reference and R-value reference. 

##What is L-value and R-value reference
Let's look at the examples with C++11 semantic:
```

ClassL(const ClassL& aLValueReference)
 : iItem{aLValueReference.iItem->copy()} {
/* The argument object's content is copied to this object. */
}

ClassL obj{ClassL{}};
// Here we are creating one temporary object and it is passing to copy constructor,
// where its content is copied to 'obj'. The temporary object is completely useless,
// but it has to be created and it's content must be copied, so we have to create
// the content twice.

/////////////////////////////////////

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
```
std::vector<ClassL> vL;

ClassL objL;
objL.method();
objL.method(argument);

vL.push_back(objL);
// Here 'objL' will be copied to the array inside the vector, so it content will be
// also copied (which means created twice)

/////////////////////////////////////

ClassR objR;
objR.method();
objR.method(argument);

vL.push_back(std::move(objR));
// Here 'objR' will be "moved" to the array inside the vector. If we don't need to use
// 'objR' after calling 'push_back', this approach meas that the contend is created once.
```

#Table of content
1. Basic Usage
2. Range Tests
3. Templates
4. Prevent Optimization
5. Complexity and Transfer
6. Timers
7. Threads


*Author: Marcin Serwach*
*Tutorial: [https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark](https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark)*
