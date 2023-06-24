#!/bin/env sh


./build.sh && \
    cd build && \
    ctest --output-on-failure -T memcheck
