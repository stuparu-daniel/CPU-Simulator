#!/usr/bin

mkdir -p build
cd build && cmake .. && make -j14
cp ../src/* .
./cpu-simulator