#!/bin/bash

mkdir -p build
cmake -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../bin -DCMAKE_BUILD_TYPE=Debug -G Ninja -S . -B ./build
cmake --build ./build --target Citer -j 12

./bin/Citer
