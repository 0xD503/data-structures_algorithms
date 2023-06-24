#include <criterion/criterion.h>

#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(sequence_if, .init = setUp, .fini = tearDown);


template<typename T>
void testSequenceIf(SequenceInterface<T> *seq) {
    //
}


Test(sequence_if, dynamic_array) {
    //
}

Test(sequence_if, linked_list) {
    //
}

Test(sequence_if, deque) {
    //
}
