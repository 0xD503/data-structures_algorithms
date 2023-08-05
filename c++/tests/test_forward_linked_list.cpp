#include <criterion/criterion.h>

#include "forward_linked_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}

TestSuite(forward_linked_list, .init = setUp, .fini = tearDown);


Test(linked_list, create) {
    ForwardLinkedList<long> fll {};
    long val(-9);

    cr_expect(fll.length() == 0, "Expected empty linked list");
    cr_expect(fll.size() == 0, "Expected empty linked list with 0 size");
    cr_expect_not(fll.clear(), "Expected fail on clearing an empty linked list");
    cr_expect(fll.empty());

    constexpr size_t fll_2_size = 2342;
    ForwardLinkedList<long> fll_2(fll_2_size, 777);
    cr_expect(fll_2.length() == fll_2_size);
    cr_expect(fll_2.size() == (sizeof(long) * fll_2_size));
    cr_expect(fll_2.front(val));
    cr_expect_eq(val, 777);
    val = -4;
    cr_expect(fll_2.back(val));
    cr_expect_eq(val, 777);
    cr_expect(fll_2.empty() == false);

    cr_expect(fll_2.clear());
    cr_expect(fll_2.length() == 0);
    cr_expect(fll_2.size() == (sizeof(long) * 0));
    cr_expect(fll_2.empty());
}

Test(linked_list, adding_elements) {
    ForwardLinkedList<long> fll {};

    cr_expect_not(fll.insert(7, 777));
    cr_expect_not(fll.insert(1, 777));
    cr_expect_not(fll.remove(1));
    cr_expect_not(fll.remove(0));
    cr_expect(fll.empty());
    cr_expect(fll.insert(0, 777));
    cr_expect_not(fll.empty());
    cr_expect_not(fll.remove(1));
    cr_expect(fll.remove(0));
    cr_expect(fll.empty());
    cr_expect(fll.insert(0, 777));
    cr_expect_eq(fll.length(), 1);
    cr_expect(fll.insert(1, 777));
    cr_expect(fll.insert(1, 777));
    cr_expect(fll.insert(0, 777));
    cr_expect(fll.insert(4, 778));
    cr_expect_not(fll.insert(6, 778));
    cr_expect_eq(fll.length(), 5);
    cr_expect(fll.remove(1));
    cr_expect_eq(fll.length(), 4);
    cr_expect(fll.remove(0));
    cr_expect(fll.remove(0));
    cr_expect(fll.remove(0));
    cr_expect(fll.remove(0));
    cr_expect_not(fll.remove(0));
}

Test(linked_list, accessors) {
    ForwardLinkedList<long> fll {};
    long val(-342);

    cr_expect_eq(fll.size(), 0);
    cr_expect(fll.insert(0, 1));
    cr_expect_eq(fll.length(), 1);
    cr_expect(fll.insert(1, 2));
    cr_expect(fll.insert(2, 3));
    cr_expect(fll.insert(3, 4));
    cr_expect(fll.insert(4, 5));
    cr_expect(fll.insert(5, 6));
    cr_expect(fll.insert(6, 7));
    cr_expect_eq(fll.size(), sizeof(long) * 7);
    cr_expect(fll.get(0, val));
    cr_expect_eq(val, 1);
    cr_expect(fll.get(6, val));
    cr_expect_eq(val, 7);
    cr_expect_not(fll.get(7, val));
    cr_expect_eq(val, 7);
}
