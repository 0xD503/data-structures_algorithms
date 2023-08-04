#include <criterion/criterion.h>

#include "container_interface.hpp"
#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "circular_buffer.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(container_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_container_if (ContainerInterface<T> *cont) {
    cr_assert_not(cont == nullptr);

    cr_expect(cont->empty());
    cr_expect_eq(cont->length(), 0);
    cr_expect_not(cont->clear());
    cr_expect(cont->empty());
    cr_expect_eq(cont->length(), 0);
}

template<typename T>
void test_non_empty_container_if (ContainerInterface<T> *cont) {
    cr_assert_not(cont == nullptr);

    cr_expect_not(cont->empty());
    cr_expect_eq(cont->length(), 7);
    cr_expect(cont->clear());
    cr_expect(cont->empty());
    cr_expect_eq(cont->length(), 0);
}


Test(container_if, dynamic_array) {
    DynamicArray<long> da;
    DynamicArray<long> da_2 {};
    test_container_if<long>(&da);
    test_container_if<long>(&da_2);

    DynamicArray<long> da_2_1(7);
    cr_expect(da_2_1.empty());
    cr_expect_eq(da_2_1.length(), 0);
    cr_expect_not(da_2_1.clear());

    DynamicArray<long> da_3(7, 4);
    test_non_empty_container_if<long>(&da_3);
}

Test(container_if, linked_list) {
    LinkedList<long> ll;
    LinkedList<long> ll_2 {};
    test_container_if<long>(&ll);
    test_container_if<long>(&ll_2);

    // LinkedList<long> ll_2_1(7);
    // cr_expect(ll_2_1.empty());
    // cr_expect_eq(ll_2_1.length(), 0);
    // cr_expect(ll_2_1.clear());

    LinkedList<long> ll_3(7, 4);
    test_non_empty_container_if<long>(&ll_3);
}

Test(container_if, dual_array_deque) {
    Deque<long> dq;
    Deque<long> dq_2 {};
    test_container_if<long>(&dq);
    test_container_if<long>(&dq_2);

    Deque<long> dq_2_1(7);
    cr_expect(dq_2_1.empty());
    cr_expect_eq(dq_2_1.length(), 0);
    cr_expect_not(dq_2_1.clear());

    Deque<long> dq_3(7, 4);
    test_non_empty_container_if<long>(&dq_3);
}

Test(container_if, queue) {
    Queue<long> q;
    Queue<long> q_2 {};
    test_container_if<long>(&q);
    test_container_if<long>(&q_2);

    Queue<long> q_2_1(7);
    cr_expect(q_2_1.empty());
    cr_expect_eq(q_2_1.length(), 0);
    cr_expect_not(q_2_1.clear());

    Queue<long> q_3(7, 4);
    test_non_empty_container_if<long>(&q_3);
}

Test(container_if, stack) {
    Stack<long> q;
    Stack<long> q_2 {};
    test_container_if<long>(&q);
    test_container_if<long>(&q_2);

    Stack<long> q_2_1(7);
    cr_expect(q_2_1.empty());
    cr_expect_eq(q_2_1.length(), 0);
    cr_expect_not(q_2_1.clear());

    Stack<long> q_3(7, 4);
    test_non_empty_container_if<long>(&q_3);
}

Test(container_if, circular_buffer) {
    CircularBuffer<long> cb_2_1(7);
    cr_expect(cb_2_1.empty());
    cr_expect_eq(cb_2_1.length(), 0);
    cr_expect_not(cb_2_1.clear());

    CircularBuffer<long> cb_3(7, true);
    test_container_if<long>(&cb_3);
}
