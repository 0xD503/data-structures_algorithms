#include <criterion/criterion.h>

#include <deque.hpp>


void setUp () {
    //
}

void tearDown () {
    //
}

TestSuite(deque_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_deque_if (DequeInterface<T> *deque) {
    //
}


Test(deque_if, dual_array_deque) {
    Deque<long> dq;
    test_deque_if<long>(&dq);
    Deque<long> dq_2{};
    test_deque_if<long>(&dq);
}
