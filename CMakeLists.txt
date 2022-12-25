cmake_minimum_required(VERSION 3.14..3.22)

project(
  data_structures
  VERSION 1.0
  LANGUAGES C
  )

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
#set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -Og")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -O3")
set(CMAKE_C_FLAGS_RELEASE "-O3")

set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_compile_options(
  ""
  )

include_directories(
  include/
  )

add_executable(${PROJECT_NAME}
  src/main.c
  src/dynamic_array.c
  #src/queue.c
  )

add_subdirectory(tests/)
