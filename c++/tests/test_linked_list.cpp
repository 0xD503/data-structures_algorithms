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

TestSuite(linked_list, .init = testSetup, .fini = testTeardown);

Test(linked_list, create) {
    LinkedList<long> ll;
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

    cr_expect(ll_2.clear() == true);
    cr_expect(ll_2.length() == 0);
    cr_expect(ll_2.size() == (sizeof(long) * 0));
    cr_expect(ll_2.empty() == true);
}

Test(linked_list, adding_elements) {
    //
}
