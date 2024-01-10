#!/usr/bin

mkdir -p build
cd build && cmake .. && make -j14
cp ../src/* .
./unit-tests/hardware_tests/*.test
./cpu-simulator