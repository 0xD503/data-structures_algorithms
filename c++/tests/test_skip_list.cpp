#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

#include "skip_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}

TestSuite(skip_list, .init = setUp, .fini = tearDown);


template<typename T>
void test_skip_list(SkipList<T> *sl, size_t initLen, size_t maxHeight) {
    cr_assert_not_null(sl);
    cr_assert_eq(sl->length(), initLen);

    T val(-1);

    if (initLen == 0) {
        cr_expect(sl->empty());
        cr_expect_eq(sl->length(), 0);
        cr_expect_eq(sl->getHeight(), 0);
        cr_expect_not(sl->clear());
        cr_expect(sl->empty());
        cr_expect_eq(sl->length(), 0);
        cr_expect_eq(sl->getHeight(), 0);
    }
    else {
        cr_expect_not(sl->empty());
        cr_expect_neq(sl->length(), 0);
        cr_expect_leq(sl->getHeight(), maxHeight);
        cr_expect(sl->clear());
        cr_expect(sl->empty());
        cr_expect_eq(sl->length(), 0);
        cr_expect_eq(sl->getHeight(), 0);
    }

    /// set methods
    val = 575;
    cr_expect(sl->insert(val));
    cr_expect_eq(sl->length(), initLen + 1);

    cr_expect(sl->insert(val));
    cr_expect_eq(sl->length(), initLen + 1);

    cr_expect(sl->insert(val + 1));
    cr_expect_eq(sl->length(), initLen + 2);


    cr_expect(sl->remove(val));
    cr_expect_eq(sl->length(), initLen + 1);

    cr_expect_not(sl->remove(val));
    cr_expect_eq(sl->length(), initLen + 1);

    cr_expect(sl->remove(val + 1));
    cr_expect_eq(sl->length(), initLen);

    cr_expect_not(sl->remove(val + 1));
    cr_expect_eq(sl->length(), initLen);

    /// sorted set methods
    T hasVal(832);
    T hasntVal(832314);
    cr_assert_neq(hasVal, hasntVal);
    cr_assert(sl->insert(hasVal));
    //sl->insert(hasVal);
    sl->remove(hasntVal);

    // cr_expect(sl->find(hasVal, val));
    // cr_expect_eq(val, hasVal);

    // cr_expect(sl->find(hasntVal, val));
    // cr_expect_neq(val, hasntVal);
    // cr_expect_eq(val, hasVal);

    /// other
    cr_expect_leq(sl->getHeight(), maxHeight);
}


Test(skip_list, test) {
    //SkipList<int> sklst_1;
    constexpr size_t height_2 = 4;
    SkipList<int, height_2> sklst_2{};

    test_skip_list<int>(&sklst_2, 0, height_2);
}
