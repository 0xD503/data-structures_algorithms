##

set(USER_CURR_OBJECT_TARGET static_array)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  ../include/static_array.hpp
)

set(USER_CURR_OBJECT_TARGET dynamic_array)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  dynamic_array.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET linked_list)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  linked_list.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET forward_linked_list)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  forward_linked_list.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET deque)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  deque.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET queue)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  queue.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET stack)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  stack.cpp
)
target_include_directories(${USER_CURR_OBJECT_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set(USER_CURR_OBJECT_TARGET circular_buffer)
add_library(${USER_CURR_OBJECT_TARGET} OBJECT
  circular_buffer.cpp
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
