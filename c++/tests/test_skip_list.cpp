#include <criterion/criterion.h>

#include "skip_list.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}

TestSuite(skip_list, .init = setUp, .fini = tearDown);


Test(skip_list, test) {
    SkipList<int> sklst_1;
    SkipList<int> sklst_2{};
}
