#!/bin/env sh


mkdir -p build
cd build
#LDFLAGS="-fuse-ld=lld" cmake -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ ..
#export CC=clang
#export CXX=clang++
##cmake -DCMAKE_CXX_COMPILER_WORKS=1 ..
cmake ..
