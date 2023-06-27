## Tests

include(Dart)


## valgrind
find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)

## coverage
#find_program(CTEST_COVERAGE_COMMAND NAMES gcov)


add_executable(TestContainerInterface
  test_container_if.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
  ../src/deque.cpp
  ../src/queue.cpp
  ../src/stack.cpp
)
add_executable(TestSequenceInterface
  test_sequence_if.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
  ../src/deque.cpp
  ../src/queue.cpp
  ../src/stack.cpp
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
add_executable(TestLinkedList
  test_linked_list.cpp
  ../src/linked_list.cpp
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

target_link_libraries(TestContainerInterface criterion)
target_link_libraries(TestSequenceInterface criterion)
target_link_libraries(TestListInterface criterion)
target_link_libraries(TestDynamicArray criterion)
target_link_libraries(TestLinkedList criterion)
target_link_libraries(TestDeque criterion)
target_link_libraries(TestQueue criterion)
target_link_libraries(TestStack criterion)

add_test(
  NAME TestContainerInterface
  COMMAND TestContainerInterface
)
add_test(
  NAME TestSequenceInterface
  COMMAND TestSequenceInterface
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
  NAME TestLinkedList
  COMMAND TestLinkedList
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

#
#find_package(CodeCoverage)
#include(CodeCoverage)
#include(CodeCoverage)
#append_coverage_compiler_flags()

#
