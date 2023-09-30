#include <criterion/criterion.h>

#include "skip_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(test_set_interface, .init = setUp, .fini = tearDown);


template<typename T>
void test_set_if(SetInterface<T> *set, size_t length = 0) {
    cr_assert_not_null(set);

    T val(6);

    cr_assert_not(set->contains(val));
    cr_assert_eq(set->length(), length);


    cr_expect(set->insert(val));
    cr_expect_eq(set->length(), length + 1);
    cr_expect(set->contains(val));

    cr_expect(set->insert(val));
    cr_expect_eq(set->length(), length + 1);

    cr_expect_not(set->contains(val + 1));
    cr_expect(set->insert(val + 1));
    cr_expect_eq(set->length(), length + 2);
    cr_expect(set->contains(val + 1));


    cr_expect(set->contains(val));
    cr_expect(set->remove(val));
    cr_expect_eq(set->length(), length + 1);
    cr_expect_not(set->contains(val));

    cr_expect_not(set->remove(val));
    cr_expect_eq(set->length(), length + 1);

    cr_expect(set->remove(val + 1));
    cr_expect_eq(set->length(), length);

    cr_expect_not(set->remove(val + 1));
    cr_expect_eq(set->length(), length);
}


Test(test_set_interface, skip_list) {
    SkipList<long, 4> sl_1{};

    test_set_if<long>(&sl_1, 0);
    //test_set_if<SkipList<long, 4>>(&sl_1, 0);
}
