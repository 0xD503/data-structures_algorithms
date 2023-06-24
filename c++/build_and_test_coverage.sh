#!/bin/env sh


./build.sh && \
    cd build && \
    ctest -T test -T coverage && \
    lcov -c -d . -o coverage.info && \
    genhtml coverage.info --output-directory html-out
