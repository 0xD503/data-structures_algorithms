add_executable(test_queue
  test_queue.c
  ../src/queue.c
  )
add_executable(test_dynamic_array
  test_dynamic_array.c
  ../src/dynamic_array.c
  )

target_link_libraries(test_queue criterion)
target_link_libraries(test_dynamic_array criterion)

add_test(
  NAME test_queue
  COMMAND test_queue
  )
add_test(
  NAME test_dynamic_array
  COMMAND test_dynamic_array
  )
