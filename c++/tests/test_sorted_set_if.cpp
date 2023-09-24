#include <criterion/criterion.h>

#include "skip_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(test_sorted_set_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_sorted_set_if(SortedSetInterface<T> *ss, size_t length, T& hasVal, T& hasntVal) {
    cr_assert_not_null(ss);
    cr_assert_neq(hasVal, hasntVal);

    T val(-1);

    cr_expect_eq(ss->length(), length);

    cr_expect(ss->find(hasVal, val));
    cr_expect_eq(val, hasVal);

    cr_expect(ss->find(hasntVal, val));
    cr_expect_neq(val, hasntVal);
    cr_expect_eq(val, hasVal);
}


Test(test_sorted_set_if, skip_list) {
    SkipList<long> sl_1{};

    long hasVal = 7;
    long hasntVal = 8;
    //test_sorted_set_if<long>(&sl_1, 0, 7, 8);
    test_sorted_set_if<long>(&sl_1, 0, hasVal, hasntVal);
}
