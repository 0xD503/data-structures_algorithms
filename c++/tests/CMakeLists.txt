## Tests

add_executable(TestDynamicArray
  test_dynamic_array.cpp
  ../src/dynamic_array.cpp
)
add_executable(TestLinkedList
  test_linked_list.cpp
  ../src/linked_list.cpp
)

target_link_libraries(TestDynamicArray criterion)
target_link_libraries(TestLinkedList criterion)

add_test(
  NAME TestDynamicArray
  COMMAND TestDynamicArray
)
add_test(
  NAME TestLinkedList
  COMMAND TestLinkedList
)
