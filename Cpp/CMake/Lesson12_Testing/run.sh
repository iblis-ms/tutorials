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
echo "These test are NOT passing, Test.cpp:15"
make test
