#include <criterion/criterion.h>

#include "linked_list.hpp"

#include <iostream>


using std::cout;
using std::clog;
using std::endl;

void testSetup () {
    //
}

void testTeardown () {
    //
}

TestSuite(list_if, .init = testSetup, .fini = testTeardown);
TestSuite(linked_list, .init = testSetup, .fini = testTeardown);


Test(list_if, list_if) {
    LinkedList<long> list{};
    long val(-666);

    cr_expect_eq(list.length(), 0);
    cr_expect_eq(list.first(), 0);
    cr_expect_eq(list.last(), 0);
    cr_expect(not list.get(0, val));
    cr_expect_eq(val, -666);
    cr_expect(not list.get(7, val));
    cr_expect_eq(val, -666);
    cr_expect(not list.set(0, 8));
    cr_expect(list.empty());
    cr_expect(list.clear());

    cr_expect(not list.add(1, 7));
    cr_expect(not list.get(0, val));
    cr_expect_eq(val, -666);
    cr_expect(list.empty());
    cr_expect(list.add(0, 7));
    cr_expect(not list.empty());
    cr_expect(not list.get(1, val));
    cr_expect_eq(val, -666);
    cr_expect(list.get(0, val));
    cr_expect_eq(val, 7);
    cr_expect(list.add(0, 8));
    cr_expect(not list.empty());
    cr_expect(list.get(1, val));
    cr_expect_eq(val, 7);
    cr_expect(list.get(0, val));
    cr_expect_eq(val, 8);
    cr_expect(list.add(0, 1));
    cr_expect(list.add(1, 2));
    cr_expect(list.add(2, 3));
    cr_expect(list.add(3, 4));
    cr_expect(list.add(4, 5));
    cr_expect(list.add(5, 6));
    cr_expect(list.set(6, 7));
    cr_expect(list.set(7, 8));
    for (size_t i(1); i <= 8; i++) {
        cr_expect(list.get(i - 1, val));
        cr_expect_eq(val, i);
    }
}


Test(linked_list, create) {
    LinkedList<long> ll{};

    cr_expect(ll.length() == 0, "Expected empty linked list");
    cr_expect(ll.size() == 0, "Expected empty linked list with 0 size");
    cr_expect(ll.clear() == true, "Expected success at clearing empty linked list");
    cr_expect(ll.empty() == true);

    constexpr size_t ll_2_size = 2342;
    LinkedList<long> ll_2(ll_2_size, 777);
    //clog << "LEN_2_1 " << ll_2.length() << endl;
    cr_expect(ll_2.length() == ll_2_size);
    cr_expect(ll_2.size() == (sizeof(long) * ll_2_size));
    cr_expect(ll_2.first() == 777);
    cr_expect(ll_2.last() == 777);
    cr_expect(ll_2.empty() == false);

    cr_expect(ll_2.clear() == true);
    cr_expect(ll_2.length() == 0);
    cr_expect(ll_2.size() == (sizeof(long) * 0));
    cr_expect(ll_2.empty() == true);
}

Test(linked_list, adding_elements) {
    LinkedList<long> ll{};

    cr_expect(not ll.add(7, 777));
    cr_expect(not ll.add(1, 777));
    cr_expect(not ll.remove(1));
    cr_expect(not ll.remove(0));
    cr_expect(ll.empty());
    cr_expect(ll.add(0, 777));
    cr_expect(not ll.empty());
    cr_expect(not ll.remove(1));
    cr_expect(ll.remove(0));
    cr_expect(ll.empty());
    cr_expect(ll.add(0, 777));
    cr_expect_eq(ll.length(), 1);
    cr_expect(ll.add(1, 777));
    cr_expect(ll.add(1, 777));
    cr_expect(ll.add(0, 777));
    cr_expect(ll.add(4, 778));
    cr_expect(not ll.add(6, 778));
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
    LinkedList<long> ll{};
    long val(-342);

    cr_expect_eq(ll.size(), 0);
    cr_expect(ll.add(0, 1));
    cr_expect_eq(ll.length(), 1);
    cr_expect(ll.add(1, 2));
    cr_expect(ll.add(2, 3));
    cr_expect(ll.add(3, 4));
    cr_expect(ll.add(4, 5));
    cr_expect(ll.add(5, 6));
    cr_expect(ll.add(6, 7));
    cr_expect_eq(ll.size(), sizeof(long) * 7);
    cr_expect(ll.get(0, val));
    cr_expect_eq(val, 1);
    cr_expect(ll.get(6, val));
    cr_expect_eq(val, 7);
    cr_expect(not ll.get(7, val));
    cr_expect_eq(val, 7);
}
