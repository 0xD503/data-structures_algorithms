cmake_minimum_required(VERSION 3.14..3.22)


project(
  data_structures_and_algorithms_cxx
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -coverage -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -stdlib=libc++")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE RelWithDebInfo)
#set(CMAKE_BUILD_TYPE Release)

#append_coverage_compiler_flags()
# set(GCC_COVERAGE_COMPILER_FLAGS "-g -O3 -fprofile-arcs -ftest-coverage")
# set(GCC_COVERAGE_LINK_FLAGS "-coverage -lgcov")

## use clang++, not g++
#set(CMAKE_LINKER "lld")
# set(CMAKE_C_COMPILER_WORKS 1)
# set(CMAKE_CXX_COMPILER_WORKS 1)
#set(CMAKE_CXX_STANDARD_LIBRARIES)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
# set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
# set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
#set(CMAKE_EXE_LINKER_FLAGS "-lc++abi")

include_directories(
  ${CMAKE_SOURCE_DIR}/include
)
link_directories(
  ${CMAKE_SOURCE_DIR}/lib
)

# add_compile_options(
#   -stdlib=libsdfdsffsdc++
# )

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/dynamic_array.cpp
  src/linked_list.cpp
  src/deque.cpp
  src/queue.cpp
  src/stack.cpp
)

## testing
include(CTest)
enable_testing()

add_subdirectory(tests/)
