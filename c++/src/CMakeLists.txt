##

set(USER_CURR_OBJECT_TARGET static_array)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/static_array.hpp
)

set(USER_CURR_OBJECT_TARGET dynamic_array)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/dynamic_array.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET linked_list)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/linked_list.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET forward_linked_list)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/forward_linked_list.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET deque)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/deque.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET queue)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/queue.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET stack)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/stack.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET circular_buffer)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/circular_buffer.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET skip_list)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/skip_list.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_OBJECT_TARGET}
  random_number_generator
)


set(USER_CURR_OBJECT_TARGET hash_table)
add_library(
  ${USER_CURR_OBJECT_TARGET}
  OBJECT
  ../include/hash_table.hpp
)


## algorithms
set(USER_CURR_OBJECT_TARGET random_number_generator)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  algorithms/rng.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET binary_search)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/algorithms/binary_search.hpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET hash)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/algorithms/hash.hpp
)
target_include_directories(
  ${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
