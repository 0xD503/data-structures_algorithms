#include <criterion/criterion.h>

#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"
#include "queue.hpp"
//#include "stack.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(sequence_if, .init = setUp, .fini = tearDown);


template<typename T>
void testEmptySequenceIf (DynamicSequenceInterface<T> *seq) {
    cr_assert_not_null(seq);
    T val(-1237);

    cr_expect_not(seq->front(val));
    cr_expect_eq(val, -1237);
    cr_expect_not(seq->back(val));
    cr_expect_eq(val, -1237);
}

template<typename T>
void testSequenceIf (DynamicSequenceInterface<T> *seq) {
    cr_assert_not_null(seq);
    T val(-1237);

    cr_expect(seq->front(val));
    cr_expect_eq(val, 2);
    cr_expect(seq->back(val));
    cr_expect_eq(val, 8);
}


Test(sequence_if, dynamic_array) {
    DynamicArray<long> da;
    DynamicArray<long> da_2 {};
    DynamicArray<long> da_3(4);
    DynamicArray<long> da_4(4, 2);
    da_4.append(8);

    testEmptySequenceIf<long>(&da);
    testEmptySequenceIf<long>(&da_2);
    testEmptySequenceIf<long>(&da_3);
    testSequenceIf<long>(&da_4);
}

Test(sequence_if, linked_list) {
    LinkedList<long> ll;
    LinkedList<long> ll_2 {};
    LinkedList<long> ll_4(4, 2);
    ll_4.append(8);

    testEmptySequenceIf<long>(&ll);
    testEmptySequenceIf<long>(&ll_2);
    testSequenceIf<long>(&ll_4);
}

Test(sequence_if, dual_array_deque) {
    Deque<long> dq;
    Deque<long> dq_2 {};
    Deque<long> dq_3(4);
    Deque<long> dq_4(4, 2);
    dq_4.addBack(8);

    testEmptySequenceIf<long>(&dq);
    testEmptySequenceIf<long>(&dq_2);
    testEmptySequenceIf<long>(&dq_3);
    testSequenceIf<long>(&dq_4);
}

Test(sequence_if, queue) {
    Queue<long> q;
    Queue<long> q_2 {};
    Queue<long> q_3(4);
    Queue<long> q_4(4, 2);
    q_4.add(8);

    testEmptySequenceIf<long>(&q);
    testEmptySequenceIf<long>(&q_2);
    testEmptySequenceIf<long>(&q_3);
    testSequenceIf<long>(&q_4);
}

// Test(sequence_if, stack) {
//     Stack<long> q;
//     Stack<long> q_2 {};
//     Stack<long> q_3(4);
//     Stack<long> q_4(4, 2);
//     q_4.push(8);

//     testEmptySequenceIf<long>(&q);
//     testEmptySequenceIf<long>(&q_2);
//     testEmptySequenceIf<long>(&q_3);
//     testSequenceIf<long>(&q_4);
// }
