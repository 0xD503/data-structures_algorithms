#!/bin/env sh


./build.sh && \
    cd build && \
    ctest -T test -T coverage
