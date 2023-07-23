#!/bin/env sh


mkdir -p build
find . -iregex "\(.*\.c\|.*\.cpp\|.*\.h\|.*\.hpp\)" -not -path "./build/*" > build/files_list.txt
clang-format --files=build/files_list.txt
