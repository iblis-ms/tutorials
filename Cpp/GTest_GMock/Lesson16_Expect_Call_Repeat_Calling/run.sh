#!/bin/bash

output="Output"
if [ -d "$output" ]
then
  rm -r "$output"
fi
mkdir "$output"

cd "$output"
cmake ../Code
make
make test
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
