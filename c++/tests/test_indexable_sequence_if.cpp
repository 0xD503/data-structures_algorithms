#include <criterion/criterion.h>

#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"


void testSetUp () {
    //
}

void testTearDown () {
    //
}


TestSuite(indexable_seq_if, .init = testSetUp, .fini = testTearDown);


template<typename T>
void testEmptyIndexableSequenceIf (
    IndexableSequenceInterface<T> *indexableSeq) {
    cr_assert_not_null(indexableSeq);
    T val(-1237);

    cr_expect_not(indexableSeq->front(val));
    cr_expect_eq(val, -1237);
    cr_expect_not(indexableSeq->back(val));
    cr_expect_eq(val, -1237);
    cr_expect_not(indexableSeq->get(0, val));
    cr_expect_eq(val, -1237);
    cr_expect_not(indexableSeq->set(0, 1));
}

template<typename T>
void testIndexableSequenceIf (IndexableSequenceInterface<T> *indexableSeq) {
    cr_assert_not_null(indexableSeq);
    T val(-1237);

    cr_expect_eq(indexableSeq->length(), 5);

    cr_expect(indexableSeq->front(val));
    cr_expect_eq(val, 2);
    cr_expect(indexableSeq->back(val));
    cr_expect_eq(val, 8);

    for (size_t i(0); i < indexableSeq->length(); i++) {
        cr_expect(indexableSeq->set(i, static_cast<T>(i + 1)));
    }
    cr_expect_not(indexableSeq->set(indexableSeq->length(), 5));
    for (size_t i(0); i < indexableSeq->length(); i++) {
        cr_expect(indexableSeq->get(i, val));
        cr_expect_eq(val, static_cast<T>(i + 1));
    }
    val = -1;
    cr_expect_not(indexableSeq->get(indexableSeq->length(), val));
    cr_expect_eq(val, -1);
}


Test(indexable_seq_if, dynamic_array) {
    DynamicArray<long> da;
    DynamicArray<long> da_2 {};
    DynamicArray<long> da_3(4);
    DynamicArray<long> da_4(4, 2);
    da_4.append(8);

    testEmptyIndexableSequenceIf<long>(&da);
    testEmptyIndexableSequenceIf<long>(&da_2);
    testEmptyIndexableSequenceIf<long>(&da_3);
    testIndexableSequenceIf<long>(&da_4);
}

Test(indexable_seq_if, linked_list) {
    LinkedList<long> ll;
    LinkedList<long> ll_2 {};
    LinkedList<long> ll_4(4, 2);
    ll_4.append(8);

    testEmptyIndexableSequenceIf<long>(&ll);
    testEmptyIndexableSequenceIf<long>(&ll_2);
    testIndexableSequenceIf<long>(&ll_4);
}

Test(indexable_seq_if, dual_array_deque) {
    Deque<long> dq;
    Deque<long> dq_2 {};
    Deque<long> dq_3(4);
    Deque<long> dq_4(4, 2);
    dq_4.addBack(8);

    testEmptyIndexableSequenceIf<long>(&dq);
    testEmptyIndexableSequenceIf<long>(&dq_2);
    testEmptyIndexableSequenceIf<long>(&dq_3);
    testIndexableSequenceIf<long>(&dq_4);
}
