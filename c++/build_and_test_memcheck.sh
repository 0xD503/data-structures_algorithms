#!/bin/env sh


./build.sh && \
    cd build && \
    ctest -T memcheck
