add_executable(test_dynamic_array
  test_dynamic_array.c
  ../src/dynamic_array.c
  )
add_executable(test_dynamic_matrix
  test_dynamic_matrix.c
  ../src/dynamic_matrix.c
  )
#add_executable(test_queue
#  test_queue.c
#  ../src/queue.c
#  )

target_link_libraries(test_dynamic_array criterion)
target_link_libraries(test_dynamic_matrix criterion)
#target_link_libraries(test_queue criterion)

add_test(
  NAME test_dynamic_array
  COMMAND test_dynamic_array
  )
add_test(
  NAME test_dynamic_matrix
  COMMAND test_dynamic_matrix
  )
# add_test(
#   NAME test_queue
#   COMMAND test_queue
#   )
