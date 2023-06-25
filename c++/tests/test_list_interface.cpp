#include <criterion/criterion.h>

#include "dynamic_array.hpp"
#include "linked_list.hpp"


void testSetUp () {
    //
}

void testTearDown () {
    //
}


TestSuite(list_if, .init = testSetUp, .fini = testTearDown);


template<typename T>
void test_list_if(ListInterface<T> *list) {
    cr_assert_not_null(list);
    T val(-126);

    cr_expect_eq(list->length(), 0);
    cr_expect_not(list->front(val));
    cr_expect_eq(val, -126);
    cr_expect_not(list->back(val));
    cr_expect_eq(val, -126);
    cr_expect_not(list->get(0, val));
    cr_expect_eq(val, -126);
    cr_expect_not(list->get(7, val));
    cr_expect_eq(val, -126);
    cr_expect_not(list->set(0, 8));
    cr_expect(list->empty());
    cr_expect_not(list->clear());

    cr_expect_not(list->insert(1, 7));
    cr_expect_not(list->get(0, val));
    cr_expect_eq(val, -126);
    cr_expect(list->empty());
    cr_expect(list->insert(0, 7));
    cr_expect_not(list->empty());
    cr_expect_not(list->get(1, val));
    cr_expect_eq(val, -126);
    cr_expect(list->get(0, val));
    cr_expect_eq(val, 7);
    cr_expect(list->insert(0, 8));
    cr_expect_not(list->empty());
    cr_expect(list->get(1, val));
    cr_expect_eq(val, 7);
    cr_expect(list->get(0, val));
    cr_expect_eq(val, 8);
    //cr_expect(list->insert(0, 1));
    cr_expect(list->insert(0, 2));
    cr_expect(list->insert(1, 3));
    cr_expect(list->insert(2, 4));
    cr_expect(list->insert(3, 5));
    cr_expect(list->insert(4, 6));
    cr_expect(list->swap(5, 6));
    cr_expect_not(list->swap(7, 6));
    cr_expect_not(list->swap(7, 8));
    cr_expect_not(list->swap(5, 7));
    cr_expect(list->prepend(1));
    cr_expect(list->append(9));
    for (size_t i(1); i <= 9; i++) {
        cr_expect(list->get(i - 1, val));
        cr_expect_eq(val, i);
    }
    cr_expect(list->set(0, 8));
    cr_expect(list->get(0, val));
    cr_expect_eq(val, 8);
    cr_expect_not(list->empty());
    cr_expect(list->clear());
    cr_expect(list->empty());
}

Test(list_if, dynamic_array) {
  DynamicArray<long> da_1{};
  test_list_if<long>(&da_1);
  DynamicArray<char> da_2{};
  test_list_if<char>(&da_2);
}

Test(list_if, linked_list) {
  LinkedList<long> da_1{};
  test_list_if<long>(&da_1);
  LinkedList<char> da_2{};
  test_list_if<char>(&da_2);
}
