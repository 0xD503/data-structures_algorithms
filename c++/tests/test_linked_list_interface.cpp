#include <criterion/criterion.h>

#include "linked_list.hpp"
#include "forward_linked_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(linked_list_iface, .init = setUp, .fini = tearDown);


template<typename T>
void test_linked_list_interface(LinkedListInterface<T> *lli, size_t initialLen) {
    cr_expect_not_null(lli);

    cr_expect_eq(lli->size(), sizeof(T) * initialLen);
}


Test(linked_list_iface, doubly_linked) {
    LinkedList<long> dll;
    LinkedList<long> dll_2(2, 7);

    test_linked_list_interface<long>(&dll, dll.length());
    test_linked_list_interface<long>(&dll_2, dll_2.length());
}

Test(linked_list_iface, singly_linked) {
    LinkedList<long> sll;
    LinkedList<long> sll_2(2, 7);

    test_linked_list_interface<long>(&sll, sll.length());
    test_linked_list_interface<long>(&sll_2, sll_2.length());
}
