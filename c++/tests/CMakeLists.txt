## Tests

include(Dart)


## valgrind
find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)

## coverage
#find_program(CTEST_COVERAGE_COMMAND NAMES gcov)


set(USER_CURR_TEST_TARGET TestStaticArray)
add_executable(${USER_CURR_TEST_TARGET}
  test_static_array.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  static_array
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestDynamicContainerInterface)
add_executable(${USER_CURR_TEST_TARGET}
  test_dynamic_container_if.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  dynamic_array
  linked_list
  forward_linked_list
  deque
  queue
  stack
  circular_buffer
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestSequenceInterface)
add_executable(${USER_CURR_TEST_TARGET}
  test_dynamic_sequence_if.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  dynamic_array
  linked_list
  deque
  queue
  stack
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestIndexableDynamicSequenceInterface)
add_executable(${USER_CURR_TEST_TARGET}
  test_indexable_dynamic_sequence_if.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  dynamic_array
  linked_list
  deque
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestListInterface)
add_executable(${USER_CURR_TEST_TARGET}
  test_list_interface.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  dynamic_array
  linked_list
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestDynamicArray)
add_executable(${USER_CURR_TEST_TARGET}
  test_dynamic_array.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  dynamic_array
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestLinkedListInterface)
add_executable(${USER_CURR_TEST_TARGET}
  test_linked_list_interface.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  linked_list
  forward_linked_list
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestLinkedList)
add_executable(${USER_CURR_TEST_TARGET}
  test_linked_list.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  linked_list
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestForwardLinkedList)
add_executable(${USER_CURR_TEST_TARGET}
  test_forward_linked_list.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  forward_linked_list
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestDeque)
add_executable(${USER_CURR_TEST_TARGET}
  test_deque.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  deque
  dynamic_array
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestQueue)
add_executable(${USER_CURR_TEST_TARGET}
  test_queue.cpp
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  queue
  deque
  dynamic_array
  criterion
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestStack)
add_executable(${USER_CURR_TEST_TARGET}
  test_stack.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  stack
  deque
  dynamic_array
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

set(USER_CURR_TEST_TARGET TestCircularBuffer)
add_executable(${USER_CURR_TEST_TARGET}
  test_circular_buffer.cpp
)
target_include_directories(${USER_CURR_TEST_TARGET}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${USER_CURR_TEST_TARGET}
  circular_buffer
  queue
  deque
  dynamic_array
  criterion
)
add_test(
  NAME ${USER_CURR_TEST_TARGET}
  COMMAND ${USER_CURR_TEST_TARGET}
)

# add_executable(TestSkipList
#   test_skip_list.cpp
# #   ../src/skip_list.cpp
#   ../src/dynamic_array.cpp
#   ../src/forward_linked_list.cpp
# )

#
#find_package(CodeCoverage)
#include(CodeCoverage)
#include(CodeCoverage)
#append_coverage_compiler_flags()

#
