#!/bin/bash

output="Output"
if [ -d "$output" ]
then
  rm -r "$output"
fi
mkdir "$output"

cd "$output"
cmake ../Code -DCMAKE_BUILD_TYPE=Release
make
./GBenchmark_Lesson2
cd -

if [ "$1" == "eclipse" ]
then
  projectFolder="Eclipse_Project"
  if [ -d "$projectFolder" ]
  then
    rm -r "$projectFolder"
  fi
  mkdir "$projectFolder"
  cd "$projectFolder"
  cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D_ECLIPSE_VERSION=4.2  ../Code
  cd -
fi

if [ "$1" == "Xcode" ]
then
  projectFolder="Xcode_Project"
  if [ -d "$projectFolder" ]
  then
    rm -r "$projectFolder"
  fi
  mkdir "$projectFolder"
  cd "$projectFolder"
  cmake -G Xcode -D CMAKE_BUILD_TYPE=Debug  ../Code
  cd -

fi
