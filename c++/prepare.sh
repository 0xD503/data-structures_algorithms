#!/usr/bin/env sh


mkdir -p build
cd build
#LDFLAGS="-fuse-ld=lld" cmake -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ ..
cmake ..
