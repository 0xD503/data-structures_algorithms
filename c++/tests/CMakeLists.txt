## Tests

include(Dart)


## valgrind
find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)

## coverage
#find_program(CTEST_COVERAGE_COMMAND NAMES gcov)

# #
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(TestStaticArray
  test_static_array.cpp
  ../src/static_array.cpp
)
add_executable(TestDynamicContainerInterface
  test_dynamic_container_if.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
  ../src/deque.cpp
  ../src/queue.cpp
  ../src/stack.cpp
  ../src/circular_buffer.cpp
)
add_executable(TestSequenceInterface
  test_dynamic_sequence_if.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
  ../src/deque.cpp
  ../src/queue.cpp
  ../src/stack.cpp
)
add_executable(TestIndexableSequenceInterface
  test_indexable_dynamic_sequence_if.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
  ../src/deque.cpp
)
add_executable(TestListInterface
  test_list_interface.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
)
add_executable(TestDynamicArray
  test_dynamic_array.cpp
  ../src/dynamic_array.cpp
)
add_executable(TestLinkedListInterface
  test_linked_list_interface.cpp
  ../src/linked_list.cpp
  ../src/forward_linked_list.cpp
)
add_executable(TestLinkedList
  test_linked_list.cpp
  ../src/linked_list.cpp
)
add_executable(TestForwardLinkedList
  test_forward_linked_list.cpp
  ../src/forward_linked_list.cpp
)
add_executable(TestDeque
  test_deque.cpp
  ../src/deque.cpp
  ../src/dynamic_array.cpp
)
add_executable(TestQueue
  test_queue.cpp
  ../src/queue.cpp
  ../src/deque.cpp
  ../src/dynamic_array.cpp
)
add_executable(TestStack
  test_stack.cpp
  ../src/stack.cpp
  ../src/deque.cpp
  ../src/dynamic_array.cpp
)
add_executable(TestCircularBuffer
  test_circular_buffer.cpp
  ../src/circular_buffer.cpp
  ../src/queue.cpp
  ../src/deque.cpp
  ../src/dynamic_array.cpp
)
# add_executable(TestSkipList
#   test_skip_list.cpp
#   ../src/skip_list.cpp
#   ../src/dynamic_array.cpp
#   ../src/forward_linked_list.cpp
# )

target_link_libraries(TestStaticArray criterion)
target_link_libraries(TestDynamicContainerInterface criterion)
target_link_libraries(TestSequenceInterface criterion)
target_link_libraries(TestIndexableSequenceInterface criterion)
target_link_libraries(TestListInterface criterion)
target_link_libraries(TestDynamicArray criterion)
target_link_libraries(TestLinkedListInterface criterion)
target_link_libraries(TestLinkedList criterion)
target_link_libraries(TestForwardLinkedList criterion)
target_link_libraries(TestDeque criterion)
target_link_libraries(TestQueue criterion)
target_link_libraries(TestStack criterion)
target_link_libraries(TestCircularBuffer criterion)
#target_link_libraries(TestSkipList criterion)

add_test(
  NAME TestStaticArray
  COMMAND TestStaticArray
)
add_test(
  NAME TestDynamicContainerInterface
  COMMAND TestDynamicContainerInterface
)
add_test(
  NAME TestSequenceInterface
  COMMAND TestSequenceInterface
)
add_test(
  NAME TestIndexableSequenceInterface
  COMMAND TestIndexableSequenceInterface
)
add_test(
  NAME TestListInterface
  COMMAND TestListInterface
)
add_test(
  NAME TestDynamicArray
  COMMAND TestDynamicArray
)
add_test(
  NAME TestLinkedListInterface
  COMMAND TestLinkedListInterface
)
add_test(
  NAME TestLinkedList
  COMMAND TestLinkedList
)
add_test(
  NAME TestForwardLinkedList
  COMMAND TestForwardLinkedList
)
add_test(
  NAME TestDeque
  COMMAND TestDeque
)
add_test(
  NAME TestQueue
  COMMAND TestQueue
)
add_test(
  NAME TestStack
  COMMAND TestStack
)
add_test(
  NAME TestCircularBuffer
  COMMAND TestCircularBuffer
)
# add_test(
#   NAME TestSkipList
#   COMMAND TestSkipList
# )

#
#find_package(CodeCoverage)
#include(CodeCoverage)
#include(CodeCoverage)
#append_coverage_compiler_flags()

#
