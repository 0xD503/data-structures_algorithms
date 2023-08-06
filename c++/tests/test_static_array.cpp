#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

#include "static_array.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}

TestSuite(static_array, .init = setUp, .fini = tearDown);


template<typename T, size_t length_>
void test_static_array (StaticArray<T, length_>& sa, bool filled = false) {
    T val = 1;
    cr_expect_eq(sa.length(), length_);

    if (filled) {
        cr_expect(sa.front(val));
        cr_expect_eq(val, 19);
        cr_expect(sa.back(val));
        cr_expect_eq(val, 19);
        for (size_t i(0); i < sa.length(); i++) {
            val = 1;
            cr_expect(sa.get(i, val));
            cr_expect_eq(val, 19);
        }
    }

    for (size_t i(0); i < sa.length(); i++) {
        cr_expect(sa.set(i, static_cast<T>(i + 1)));
    }
    val = 100;
    cr_expect(sa.front(val));
    cr_expect_eq(val, 1);
    cr_expect(sa.back(val));
    cr_expect_eq(val, static_cast<T>(sa.length()));
    for (size_t i(0); i < sa.length(); i++) {
        val = 100;
        cr_expect(sa.get(i, val));
        cr_expect_eq(val, static_cast<T>(i + 1));
    }

    for (size_t i(0); i < sa.length() / 2; i++) {
        cr_expect(sa.swap(i, sa.length() - 1 - i));
    }
    for (size_t i(sa.length()); i > 0; i--) {
        val = 100;
        cr_expect(sa.get(i - 1, val));
        cr_expect_eq(val, static_cast<T>(sa.length() - i + 1));
    }

    sa.fill(-1);
    for (size_t i(0); i < sa.length(); i++) {
        val = 1;
        cr_expect(sa.get(i, val));
        cr_expect_eq(val, -1);
    }

    const T *arr = sa.data();
    cr_expect_not_null(arr);
    sa.fill(-7);
    for (size_t i(0); i < sa.length(); i++) {
        cr_expect_eq(arr[i], -7);
    }
}


Test(static_array, test) {
    StaticArray<long, 7> sa_1;
    test_static_array<long, 7>(sa_1);

    StaticArray<long, 7> sa_2(19);
    test_static_array<long, 7>(sa_2);

    StaticArray<char, 17> sa_3(19);
    test_static_array<char, 17>(sa_3);

    //StaticArray<char, 0> sa_4(101);
    //test_static_array<char, 0>(sa_4);
}
