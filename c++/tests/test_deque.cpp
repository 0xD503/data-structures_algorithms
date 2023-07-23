#include <criterion/criterion.h>

#include "deque.hpp"

#include <iostream>


using std::cout;
using std::endl;

void setUp () {
    //
}

void tearDown () {
    //
}

TestSuite(deque_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_deque_if (DequeInterface<T> *dq) {
    cr_assert_not_null(dq);
    T val(-2);

    cr_expect(dq->empty());
    cr_expect_eq(dq->length(), 0);

    cr_expect_eq(val, -2);
    cr_expect_not(dq->front(val));
    cr_expect_eq(val, -2);
    cr_expect_not(dq->back(val));
    cr_expect_eq(val, -2);

    cr_expect(dq->addFront(8));
    cr_expect_eq(dq->length(), 1);
    cr_expect(dq->back(val));
    cr_expect_eq(val, 8);
    cr_expect(dq->front(val));
    cr_expect_eq(val, 8);
    cr_expect(dq->addFront(9));
    cr_expect_eq(dq->length(), 2);
    cr_expect(dq->back(val));
    cr_expect_eq(val, 8);
    cr_expect(dq->front(val));
    cr_expect_eq(val, 9);
    cr_expect(dq->addFront(10));
    cr_expect_eq(dq->length(), 3);
    cr_expect(dq->addFront(11));
    cr_expect_eq(dq->length(), 4);
    cr_expect(dq->front(val));
    cr_expect_eq(val, 11);
    cr_expect(dq->back(val));
    cr_expect_eq(val, 8);
    //cout << "length: " << dq->length() << endl;
    cr_expect_eq(dq->length(), 4);

    for (long i(7); i > 0; i--) {
        cr_expect(dq->addBack(i));
        cr_expect(dq->back(val));
        cr_expect_eq(val, i);
        cr_expect(dq->front(val));
        cr_expect_eq(val, 11);
    }
    //cout << "length: " << dq->length() << endl;
    cr_expect_eq(dq->length(), 11); /// 4f + 7b
    for (long i(12); i < 20; i = i + 2) {
        cr_expect(dq->addFront(i));
        cr_expect(dq->front(val));
        cr_expect_eq(val, i);
        cr_expect(dq->back(val));
        cr_expect_eq(val, 1);
    }
    //cout << "length: " << dq->length() << endl;
    cr_expect_eq(dq->length(), 15); /// 8f + 7b

    for (long i(18); i > 15; i--) {
        cr_expect(dq->removeBack());
        cr_expect(dq->front(val));
        cr_expect_eq(val, 18);
        cr_expect(dq->back(val));
        cr_expect_eq(val, (5 - (i - 15)));
    }
    //cout << "length: " << dq->length() << endl;
    cr_expect_eq(dq->length(), 12); /// 8f + 4b
    for (long i(16); i >= 12; i = i - 2) {
        cr_expect(dq->removeFront());
        cr_expect(dq->back(val));
        cr_expect_eq(val, 4);
        cr_expect(dq->front(val));
        cr_expect_eq(val, i);
    }

    cr_expect_eq(dq->length(), 9); /// 5f + 4b
    val = dq->length();
    for (long i(val); i > 0; i--) {
        cr_expect(dq->back(val));
        cr_expect_eq(val, 9 - i + 4);
        cr_expect(dq->front(val));
        cr_expect_eq(val, 12);
        cr_expect_not(dq->empty());
        cr_expect(dq->removeBack());
    }

    cr_expect(dq->empty());

    for (size_t i(0); i < 900; i++) {
        cr_expect(dq->addFront(i));
    }
    for (size_t i(1); i <= 100; i++) {
        cr_expect(dq->addBack(-i));
    }
    for (size_t i(0); i < 200; i++) {
        cr_expect(dq->removeFront());
    }
    for (size_t i(0); i < 200; i++) {
        cr_expect(dq->removeBack());
    }
    for (size_t i(0); i < 100; i++) {
        cr_expect(dq->removeFront());
    }
    for (size_t i(0); i < 500; i++) {
        cr_expect(dq->removeBack());
    }

    cr_expect(dq->empty());
    cr_expect_not(dq->removeFront());
    cr_expect_not(dq->removeBack());
    val = -77;
    cr_expect_not(dq->front(val));
    cr_expect_eq(val, -77);
    cr_expect_not(dq->back(val));
    cr_expect_eq(val, -77);
    cr_expect_eq(dq->length(), 0);
}

template<typename T>
void test_non_empty_deque_if (DequeInterface<T> *dq) {
    cr_assert_not_null(dq);
    T val(-2);

    cr_expect_not(dq->empty());

    cr_expect_eq(val, -2);
    cr_expect(dq->front(val));
    cr_expect_eq(val, 2);
    cr_expect(dq->back(val));
    cr_expect_eq(val, 2);

    cr_expect(dq->addFront(8));
    cr_expect(dq->back(val));
    cr_expect_eq(val, 2);
    cr_expect(dq->front(val));
    cr_expect_eq(val, 8);
    cr_expect(dq->addFront(9));
    cr_expect(dq->back(val));
    cr_expect_eq(val, 2);
    cr_expect(dq->front(val));
    cr_expect_eq(val, 9);
    cr_expect(dq->addFront(10));
    cr_expect(dq->addFront(11));
    cr_expect(dq->front(val));
    cr_expect_eq(val, 11);
    cr_expect(dq->back(val));
    cr_expect_eq(val, 2);

    cr_expect_not(dq->empty());
}


Test(deque_if, dual_array_deque) {
    Deque<long> dq;
    Deque<long> dq_2{};
    Deque<long> dq_3(3);
    Deque<long> dq_6(4);
    Deque<long> dq_4(3, 2);
    Deque<long> dq_5(4, 2);

    cr_expect_eq(dq_4.length(), 3);
    cr_expect_eq(dq_5.length(), 4);

    Deque<long> dq_7(3, 2);
    Deque<long> dq_8(14, 2);
    cr_expect_eq(dq_7.length(), 3);
    cr_expect_eq(dq_8.length(), 14);

    test_deque_if<long>(&dq);
    test_deque_if<long>(&dq_2);
    test_deque_if<long>(&dq_3);
    test_deque_if<long>(&dq_6);
    test_non_empty_deque_if<long>(&dq_4);
    test_non_empty_deque_if<long>(&dq_5);
}
