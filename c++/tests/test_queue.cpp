#include <criterion/criterion.h>

#include "queue.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(queue_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_queue_if (QueueInterface<T> *queue) {
    cr_assert_not_null(queue);
    T val(-4);

    cr_expect(queue->empty());
    cr_expect_not(queue->clear());
    cr_expect(queue->empty());

    cr_expect_not(queue->front(val));
    cr_expect_eq(val, -4);
    cr_expect_not(queue->back(val));
    cr_expect_eq(val, -4);

    cr_expect(queue->add(9));
    cr_expect(queue->front(val));
    cr_expect_eq(val, 9);
    cr_expect(queue->back(val));
    cr_expect_eq(val, 9);
    cr_expect(queue->add(89));
    cr_expect(queue->add(689));
    cr_expect(queue->front(val));
    cr_expect_eq(val, 9);
    cr_expect(queue->back(val));
    cr_expect_eq(val, 689);

    cr_expect(queue->clear());
    cr_expect(queue->empty());
}

template<typename T>
void test_non_empty_queue_if (QueueInterface<T> *queue) {
    cr_assert_not_null(queue);

    cr_expect_not(queue->empty());

    //

    cr_expect(queue->clear());
    cr_expect(queue->empty());
}


Test(queue_if, queue) {
    Queue<long> q;
    Queue<long> q_2{};
    Queue<long> q_3(87);
    Queue<long> q_4(87, 66);
    Queue<char> q_5(878, 126);

    test_queue_if(&q);
    test_queue_if(&q_2);
    //test_queue_if(&q_3);

    test_non_empty_queue_if(&q_4);
    test_non_empty_queue_if(&q_5);
}
