#include <criterion/criterion.h>

#include "container_interface.hpp"
#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"


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
    cr_expect(cont->clear());
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
    DynamicArray<long> da_2{};
    DynamicArray<long> da_2_1(7);
    test_container_if<long>(&da);
    test_container_if<long>(&da_2);
    test_container_if<long>(&da_2_1);

    DynamicArray<long> da_3(7, 4);
    test_non_empty_container_if<long>(&da_3);
}

Test(container_if, linked_list) {
    LinkedList<long> ll;
    LinkedList<long> ll_2{};
    test_container_if<long>(&ll);
    test_container_if<long>(&ll_2);

    LinkedList<long> ll_3(7, 4);
    test_non_empty_container_if<long>(&ll_3);
}

Test(container_if, dual_array_deque) {
    Deque<long> dq;
    Deque<long> dq_2{};
    test_container_if<long>(&dq);
    test_container_if<long>(&dq_2);

    Deque<long> dq_3(7, 4);
    test_non_empty_container_if<long>(&dq_3);
}
