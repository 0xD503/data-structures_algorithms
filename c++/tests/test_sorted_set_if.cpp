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
void test_sorted_set_if(SortedSetInterface<T> *ss, size_t length, T& prevVal, T& maxVal) {
    cr_assert_not_null(ss);
    cr_assert_neq(prevVal, maxVal);

    //T val(-1);
    size_t index_1(SIZE_MAX), index_2(SIZE_MAX);

    cr_expect_eq(ss->length(), length);

    cr_expect(ss->contains(prevVal));
    cr_expect(ss->contains(maxVal));

    /// sorted array has no values higher than max value
    cr_expect_not(ss->contains(maxVal + 1));

    cr_expect(ss->find(prevVal, index_1));
    cr_expect(ss->find(maxVal, index_2));
    cr_expect_gt(index_2, index_1);
    cr_expect_eq(index_2, index_1 + 1);

    cr_expect(ss->find(prevVal, index_2));
    cr_expect(ss->find(maxVal, index_1));
    cr_expect_gt(index_1, index_2);
    cr_expect_eq(index_1, index_2 + 1);
}


Test(test_sorted_set_if, skip_list) {
    SkipList<long> sl_1{};

    long prevVal = 7;
    long maxVal = 8;
    //test_sorted_set_if<long>(&sl_1, 0, 7, 8);
    test_sorted_set_if<long>(&sl_1, 0, prevVal, maxVal);
}
