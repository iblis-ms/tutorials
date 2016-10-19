cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

project(GBenchmark_Lesson4)


# sets add folder with FindGBenchmark.cmake that allows to use find_package(GBenchmark).
# CMake doesn't have support for Google Benchmark, therefore we need to add modoule manually.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${${PROJECT_NAME}_SOURCE_DIR}/../../cmake/")

# finds GBenchmark
find_package(GBenchmark REQUIRED)

# finds thread library
find_package(Threads REQUIRED)

# Sets source files
set(SRC "main.cpp")

# Creates the test program
add_executable(${PROJECT_NAME} ${SRC})

# Links the test program with Google Benchmark
target_link_libraries(${PROJECT_NAME} PRIVATE ${GBENCHMARK_LIBRARIES} PRIVATE ${CMAKE_THREAD_LIBS_INIT})
# Links the headers directory of Google Benchmark
target_include_directories(${PROJECT_NAME} PRIVATE ${GBENCHMARK_INCLUDE_DIRS})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GBenchmark
