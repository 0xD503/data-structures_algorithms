cmake_minimum_required(VERSION 3.14..3.22)


project(data_structures_and_algorithms_cxx
  VERSION 0.1
  DESCRIPTION "Basic data structures and algorithms implemented in C++"
  LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -Wsign-conversion")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-undefined-func-template -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++ -coverage -fprofile-arcs -ftest-coverage")

set(CMAKE_CXX_FLAGS_DEBUG "-gdwarf-4 -O0")
#set(CMAKE_CXX_FLAGS_DEBUG "-gdwarf-4 -O0 -fsanitize=address")
#set(CMAKE_CXX_FLAGS_DEBUG "-gdwarf-4 -Og")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-gdwarf-4 -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-gdwarf-4 -Og")
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

# add_compile_options(
#   -stdlib=libsdfdsffsdc++
# )

configure_file(include/config.hpp.in config.hpp)


add_subdirectory(src)

add_executable(${PROJECT_NAME}
  src/main.cpp
)
target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  PUBLIC ${PROJECT_BINARY_DIR} # for CMake generated includes
)
target_link_libraries(${PROJECT_NAME}
  static_array
  dynamic_array
  linked_list
  forward_linked_list
  deque
  queue
  stack
  circular_buffer
  skip_list
)

## testing
include(CTest)
enable_testing()

add_subdirectory(tests/)
