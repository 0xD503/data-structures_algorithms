#!/bin/env sh


find . -iregex "\(.*\.c\|.*\.cpp\|.*\.h\|.*\.hpp\)" -not -path "./build/*" | xargs clang-format -i
