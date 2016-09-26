#!/bin/bash

output="Output"
if [ -d "$output" ]
then
  rm -r "$output"
fi
mkdir "$output"

cd "$output"
CMake ../Code
make
make test
