#include <criterion/criterion.h>

#include "linked_list.hpp"

#include <iostream>


using std::clog;
using std::cout;
using std::endl;

void testSetup () {
    //
}

void testTeardown () {
    //
}

TestSuite(linked_list, .init = testSetup, .fini = testTeardown);


Test(linked_list, create) {
    LinkedList<long> ll {};
    long val(-9);

    cr_expect(ll.length() == 0, "Expected empty linked list");
    cr_expect(ll.size() == 0, "Expected empty linked list with 0 size");
    cr_expect_not(ll.clear(), "Expected fail on clearing an empty linked list");
    cr_expect(ll.empty());

    constexpr size_t ll_2_size = 2342;
    LinkedList<long> ll_2(ll_2_size, 777);
    cr_expect(ll_2.length() == ll_2_size);
    cr_expect(ll_2.size() == (sizeof(long) * ll_2_size));
    cr_expect(ll_2.front(val));
    cr_expect_eq(val, 777);
    val = -4;
    cr_expect(ll_2.back(val));
    cr_expect_eq(val, 777);
    cr_expect(ll_2.empty() == false);

    cr_expect(ll_2.clear());
    cr_expect(ll_2.length() == 0);
    cr_expect(ll_2.size() == (sizeof(long) * 0));
    cr_expect(ll_2.empty());
}

Test(linked_list, adding_elements) {
    LinkedList<long> ll {};

    cr_expect(not ll.insert(7, 777));
    cr_expect(not ll.insert(1, 777));
    cr_expect(not ll.remove(1));
    cr_expect(not ll.remove(0));
    cr_expect(ll.empty());
    cr_expect(ll.insert(0, 777));
    cr_expect(not ll.empty());
    cr_expect(not ll.remove(1));
    cr_expect(ll.remove(0));
    cr_expect(ll.empty());
    cr_expect(ll.insert(0, 777));
    cr_expect_eq(ll.length(), 1);
    cr_expect(ll.insert(1, 777));
    cr_expect(ll.insert(1, 777));
    cr_expect(ll.insert(0, 777));
    cr_expect(ll.insert(4, 778));
    cr_expect(not ll.insert(6, 778));
    cr_expect_eq(ll.length(), 5);
    cr_expect(ll.remove(1));
    cr_expect_eq(ll.length(), 4);
    cr_expect(ll.remove(0));
    cr_expect(ll.remove(0));
    cr_expect(ll.remove(0));
    cr_expect(ll.remove(0));
    cr_expect(not ll.remove(0));
}

Test(linked_list, accessors) {
    LinkedList<long> ll {};
    long val(-342);

    cr_expect_eq(ll.size(), 0);
    cr_expect(ll.insert(0, 1));
    cr_expect_eq(ll.length(), 1);
    cr_expect(ll.insert(1, 2));
    cr_expect(ll.insert(2, 3));
    cr_expect(ll.insert(3, 4));
    cr_expect(ll.insert(4, 5));
    cr_expect(ll.insert(5, 6));
    cr_expect(ll.insert(6, 7));
    cr_expect_eq(ll.size(), sizeof(long) * 7);
    cr_expect(ll.get(0, val));
    cr_expect_eq(val, 1);
    cr_expect(ll.get(6, val));
    cr_expect_eq(val, 7);
    cr_expect_not(ll.get(7, val));
    cr_expect_eq(val, 7);
}
