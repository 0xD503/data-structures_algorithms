#include <criterion/criterion.h>

#include "static_array.hpp"
#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "forward_linked_list.hpp"
#include "deque.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "circular_buffer.hpp"
//#include "skip_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(container_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_container_if (ContainerInterface<T> *cont, const size_t len) {
    cr_assert_not_null(cont);

    cr_expect_eq(cont->length(), len);
}


Test(container_if, static_array) {
    StaticArray<long, 1> arr_1;
    test_container_if<long>(&arr_1, 1);

    StaticArray<int, 7> arr_2{};
    test_container_if<int>(&arr_2, 7);

    StaticArray<char, 7> arr_3;
    test_container_if<char>(&arr_3, 7);
}

Test(container_if, dynamic_array) {
    DynamicArray<long> arr_1;
    test_container_if<long>(&arr_1, 0);

    DynamicArray<int> arr_2(7, 2);
    test_container_if<int>(&arr_2, 7);

    DynamicArray<char> arr_3(13);
    test_container_if<char>(&arr_3, 0);
}

Test(container_if, linked_list) {
    LinkedList<long> arr_1;
    test_container_if<long>(&arr_1, 0);

    LinkedList<int> arr_2(7, 2);
    test_container_if<int>(&arr_2, 7);
}

Test(container_if, forward_linked_list) {
    ForwardLinkedList<long> arr_1;
    test_container_if<long>(&arr_1, 0);

    ForwardLinkedList<int> arr_2(7, 2);
    test_container_if<int>(&arr_2, 7);
}

Test(container_if, dual_array_deque) {
    Deque<long> dq;
    Deque<long> dq_2 {};
    test_container_if<long>(&dq, 0);
    test_container_if<long>(&dq_2, 0);

    Deque<long> dq_2_1(7);
    test_container_if<long>(&dq_2_1, 0);

    Deque<long> dq_3(7, 4);
    test_container_if<long>(&dq_3, 7);
}

Test(container_if, queue) {
    Queue<long> q;
    Queue<long> q_2 {};
    test_container_if<long>(&q, 0);
    test_container_if<long>(&q_2, 0);

    Queue<long> q_2_1(7);
    test_container_if<long>(&q_2_1, 0);

    Queue<long> q_3(7, 4);
    test_container_if<long>(&q_3, 7);
}

Test(container_if, stack) {
    Stack<long> s;
    Stack<long> s_2 {};
    test_container_if<long>(&s, 0);
    test_container_if<long>(&s_2, 0);

    Stack<long> s_2_1(7);
    test_container_if<long>(&s_2_1, 0);

    Stack<long> s_3(7, 4);
    test_container_if<long>(&s_3, 7);
}

Test(container_if, circular_buffer) {
    CircularBuffer<long> cb_2_1(7);
    test_container_if<long>(&cb_2_1, 0);

    CircularBuffer<long> cb_3(7, true);
    test_container_if<long>(&cb_3, 0);
}

// Test(container_if, skip_list) {

// }
