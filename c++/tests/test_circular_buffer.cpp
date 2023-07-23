#include "criterion/criterion.h"

#include "circular_buffer.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(circularBuffer, .init = setUp, .fini = tearDown);


Test(circularBuffer, test) {
    // CircularBuffer<char, 1> circBuff_1;
    CircularBuffer<char> circBuff_1(5);

    cr_expect(circBuff_1.empty());
    cr_expect_eq(circBuff_1.length(), 0);
    cr_expect_eq(circBuff_1.maxLength(), 5);
}
