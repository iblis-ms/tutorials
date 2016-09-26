#!/bin/bash

output="Output"
if [ -d "$output" ]
then
  rm -r "$output"
fi
mkdir "$output"

cd "$output"
echo "############### PROGRAM ISN'T COMPILING ###############"
echo "CMake adds compilation flag to fail compilation when there is unused variable."
echo "See Code/StaticLibrary/CMakeLists.txt and Code/StaticLibrary/Source/StaticLibraryFactory.cpp:8"
echo "#######################################################"
cmake ../Code
make
