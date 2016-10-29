cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

project(Move)

# sets add folder with FindGBenchmark.cmake that allows to use find_package(GBenchmark).
# CMake doesn't have support for Google Benchmark, therefore we need to add modoule manually.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${${PROJECT_NAME}_SOURCE_DIR}/../cmake/")

# finds Boost
find_package(Boost 1.58 COMPONENTS timer REQUIRED)

# finds GBenchmark
find_package(GBenchmark REQUIRED)

# finds thread library
find_package(Threads REQUIRED)

################# BOOST #################
set(BOOST_NAME "boost_move")

# Sets source files
set(BOOST_SRC "boost_main.cpp")

# Creates the test program
add_executable(${BOOST_NAME} ${BOOST_SRC})

# Links the test program with Google Benchmark and Boost library
target_link_libraries(${BOOST_NAME} PRIVATE ${Boost_LIBRARIES} PRIVATE ${GBENCHMARK_LIBRARIES} PRIVATE ${CMAKE_THREAD_LIBS_INIT})
# Links the headers directory of Google Benchmark
target_include_directories(${BOOST_NAME} PRIVATE ${Boost_INCLUDE_DIRS} PRIVATE ${GBENCHMARK_INCLUDE_DIRS})

target_compile_options(${BOOST_NAME} PUBLIC "-std=c++03") # c++03 = c++98 + TR1, so it isn't standard itself.

################# C++ 11 #################

set(CPP11_NAME "cpp11_move")

# Sets source files
set(CPP11_SRC "cpp11_main.cpp")

# Creates the test program
add_executable(${CPP11_NAME} ${CPP11_SRC})

# Links the test program with Google Benchmark
target_link_libraries(${CPP11_NAME} PRIVATE ${GBENCHMARK_LIBRARIES} PRIVATE ${CMAKE_THREAD_LIBS_INIT})
# Links the headers directory of Google Benchmark
target_include_directories(${CPP11_NAME} PRIVATE ${GBENCHMARK_INCLUDE_DIRS})

set_property(TARGET ${CPP11_NAME} PROPERTY CXX_STANDARD 11)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/Move_Boost_C++11
