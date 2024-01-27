#include <criterion/criterion.h>

#include "hash_table.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(test_hash_table, .init = setUp, .fini = tearDown);


template<typename T>
void test_hash_table(HashTable<T> *ht, size_t numOfElems) {
    cr_assert_not_null(ht);

    //
}


Test(test_hash_table, long) {
    HashTable<long> ht_1{};

    test_hash_table<long>(&ht_1, 0);
}
