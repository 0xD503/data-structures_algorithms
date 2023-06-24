#!/bin/env sh


./build.sh && \
    cd build && \
    ctest --output-on-failure -T test -T coverage && \
    cd .. && \
    lcov -c -d . -o build/coverage.info && \
    genhtml build/coverage.info --output-directory html-out
