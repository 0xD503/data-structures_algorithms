cmake_minimum_required(VERSION 3.14..3.22)


project(
  data_structures_and_algorithms_cxx
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
#set(CMAKE_BUILD_TYPE Release)


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
)


add_subdirectory(tests/)
