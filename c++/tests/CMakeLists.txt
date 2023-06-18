## Tests

add_executable(TestDynamicArray
  test_dynamic_array.cpp
  ../src/dynamic_array.cpp
)
add_executable(TestLinkedList
  test_linked_list.cpp
  ../src/linked_list.cpp
)
add_executable(TestListInterface
  test_list_interface.cpp
  ../src/dynamic_array.cpp
  ../src/linked_list.cpp
)

target_link_libraries(TestDynamicArray criterion)
target_link_libraries(TestLinkedList criterion)
target_link_libraries(TestListInterface criterion)

add_test(
  NAME TestDynamicArray
  COMMAND TestDynamicArray
)
add_test(
  NAME TestLinkedList
  COMMAND TestLinkedList
)
add_test(
  NAME TestListInterface
  COMMAND TestListInterface
)
