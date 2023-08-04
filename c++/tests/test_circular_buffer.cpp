#include "criterion/criterion.h"

#include "circular_buffer.hpp"

#include <iostream>


void setUp () {
    //
}

void tearDown () {
    //
}


using std::cout;
using std::endl;

TestSuite(circularBuffer, .init = setUp, .fini = tearDown);


template<typename T>
void test_circular_buffer (CircularBuffer<T>& cb) {
    //cr_expect_not_null
    // CircularBuffer<char> circBuff_1(maxLen);
    size_t maxLen = 5;

    cr_expect(cb.empty());
    cr_expect_eq(cb.length(), 0);
    cr_expect_eq(cb.maxLength(), maxLen);
    cr_expect_not(cb.clear());
    cr_expect_not(cb.isFull());

    maxLen = 3;
    cr_expect(cb.setMaxLength(maxLen));
    cr_expect_eq(cb.maxLength(), maxLen);
    maxLen = 7;
    cr_expect(cb.setMaxLength(maxLen));
    cr_expect_eq(cb.maxLength(), maxLen);

    cr_expect_not(cb.isOverwritable());
    cb.setOverwritability(true);
    cr_expect(cb.isOverwritable());
    cb.setOverwritability(false);
    cr_expect_not(cb.isOverwritable());

    T val(73);
    cr_expect_eq(cb.length(), 0);
    cr_expect_not(cb.get(val));
    cr_expect_eq(val, 73);
    cr_expect(cb.empty());
    cr_expect_eq(cb.length(), 0);
    cr_expect_eq(cb.maxLength(), maxLen);
    cr_expect_not(cb.clear());

    cr_expect(cb.put(84));
    cr_expect_not(cb.empty());
    cr_expect_eq(cb.length(), 1);
    cr_expect_not(cb.isFull());
    cr_expect(cb.get(val));
    cr_expect_eq(val, 84);
    cr_expect_eq(cb.length(), 0);
    cr_expect(cb.empty());
    cr_expect_not(cb.get(val));
    cr_expect_eq(val, 84);

    size_t i;
    for (i = 1; i <= maxLen; i++) {
        cr_expect(cb.put(84 + i));
        cr_expect_not(cb.empty());
        cr_expect_eq(cb.length(), i);
    }
    cr_expect(cb.isFull());
    cr_expect_not(cb.put(8));
    maxLen = 9;
    cr_expect(cb.setMaxLength(maxLen));
    cr_expect_eq(cb.maxLength(), maxLen);
    cr_expect_not(cb.setMaxLength(6));
    cr_expect_not(cb.setMaxLength(1));
    cr_expect_not(cb.setMaxLength(0));
    cr_expect_eq(cb.maxLength(), maxLen);
    cr_expect_not(cb.isFull());
    cr_expect(cb.put(92));
    cr_expect(cb.put(93));
    for (i = maxLen; i-- > 0; ) {
        cr_expect(cb.get(val));
        cout << "CURRRRRRRRRRRR ITERATION: " << i << endl;
        cout << "CURRRRRRRRRRRR val: " << static_cast<long>(val) << endl;
        cout << "CURRRRRRRRRRRR refVal: " << static_cast<long>(84 + maxLen - i) << endl;
        cr_expect_eq(val, 84 + maxLen - i);
        cr_expect_not(cb.isFull());
        cr_expect_eq(cb.length(), i);
    }
    cr_expect(cb.empty());
    cr_expect_not(cb.get(val));
    cr_expect_eq(val, 84 + maxLen);

    cr_expect(cb.put(1));
    cr_expect(cb.put(2));
    cr_expect(cb.put(3));
    cr_expect_not(cb.empty());
    cr_expect(cb.clear());
    cr_expect(cb.empty());

    /// test overwritability
    maxLen = 3;
    cr_expect(cb.setMaxLength(maxLen));
    cr_expect(cb.put(1));
    cr_expect(cb.put(2));
    cr_expect(cb.put(3));
    cr_expect_not(cb.put(4));
    cr_expect(cb.isFull());
    cr_expect_eq(cb.length(), cb.maxLength());

    cr_expect_not(cb.isOverwritable());
    cb.setOverwritability(true);
    cr_expect(cb.isOverwritable());
    cr_expect(cb.isFull());
    //
    // maxLen = 5;
    // cr_expect(cb.setMaxLength(maxLen));
}


Test(circularBuffer, test) {
    constexpr size_t maxLen = 5;

    CircularBuffer<char> circBuff_1(maxLen);
    test_circular_buffer<char>(circBuff_1);
    CircularBuffer<long> circBuff_2(maxLen);
    test_circular_buffer<long>(circBuff_2);
}
