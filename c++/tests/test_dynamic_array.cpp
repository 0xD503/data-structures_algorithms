#include <criterion/criterion.h>

#include "dynamic_array.hpp"

#include <limits>
#include <iostream>


using std::clog;
using std::endl;


void testSetup (void) {
    //
}

void testTeardown (void) {
    //
}


TestSuite(dynamic_array, .init = testSetup, .fini = testTeardown);


Test(dynamic_array, create) {
    DynamicArray<int> vec;
    cr_expect(vec.empty(), "Expected empty array");
    cr_expect(vec.length() == 0, "Expected empty array");
    cr_expect(vec.capacity() == 0, "Expected empty array with 0 capacity");
    cr_expect(vec.size() == 0, "Expected empty array with 0 size");
    cr_expect_not(vec.clear(), "Expected fail on clearing an empty array");

    DynamicArray<int> vec_2(5);
    cr_expect(vec_2.empty(), "Expected empty array");
    cr_expect(vec_2.length() == 0, "Expected empty array");
    cr_expect(vec_2.capacity() == 5, "Expected array with 5 buckets");
    cr_expect(vec_2.size() == (sizeof(int) * 5), "Expected empty array with the size of (5 * int)");
    cr_expect(vec_2.clear(), "Expected success on clearing non-empty array");

    DynamicArray<int> vec_2_filled(5, 7);
    cr_expect_not(vec_2_filled.empty(), "Expected non-empty array");
    cr_expect(vec_2_filled.length() == 5, "Expected non-empty array");
    cr_expect(vec_2_filled.capacity() == 5, "Expected array with 5 buckets");
    cr_expect_eq(vec_2_filled.size(), sizeof(int) * 5, "Expected empty array with the size of (5 * int)");
    cr_expect(vec_2_filled.clear(), "Expected success on clearing non-empty array");

    DynamicArray<int> vec_3(std::numeric_limits<size_t>::max());
    cr_expect_null(vec_3.data());
    cr_expect(vec_3.empty(), "Expected empty array");
    cr_expect(vec_3.length() == 0, "Expected empty array");
    cr_expect(vec_3.capacity() == 0, "Expected empty array with 0 capacity");
    cr_expect(vec_3.size() == 0, "Expected empty array with 0 size");
    cr_expect_not(vec_3.clear(), "Expected fail on clearing an empty array");
}

Test(dynamic_array, adding_alements) {
    DynamicArray<int> vec;
    cr_expect(vec.insert(0, 7));
    cr_expect(vec.insert(0, 6));
    cr_expect(vec.insert(0, 5));
    cr_expect(vec.insert(0, 4));
    cr_expect(vec.insert(0, 3));
    cr_expect(vec.insert(0, 2));
    cr_expect(vec.insert(0, 9));
    cr_expect(vec.insert(6, 8));
    cr_expect(vec.capacity() == 14);
    cr_expect(vec.length() == 8);

    DynamicArray<int> vec_2(7);
    cr_expect(vec_2.insert(0, 1));
    cr_expect_not(vec_2.insert(2, 3));
    cr_expect(vec_2.length() == 1);
    cr_expect(vec_2.capacity() == 7);

    // DynamicArray<int> vec_3(9999999997, 0xFF);
    // cr_expect_not(vec_3.empty());
    // cr_expect_not(vec_3.append(7));
}

Test(dynamic_array, removing_elements) {
    DynamicArray<int> vec_2(7);
    int val(-791);
    //int testVal = -1;
    cr_expect(vec_2.insert(0, 1));
    cr_expect_not(vec_2.insert(2, 3));
    cr_expect(vec_2.insert(1, 7));
    cr_expect(vec_2.insert(2, 2));
    cr_expect(vec_2.remove(1));
    cr_expect(vec_2.get(1, val));
    cr_expect(val == 2);
    cr_expect(vec_2.insert(1, 2));
    cr_expect(vec_2.insert(3, 4));
    cr_expect(vec_2.length() == 4);
    cr_expect(vec_2.capacity() == 7);
    cr_expect(vec_2.insert(4, 5));
    cr_expect(vec_2.insert(5, 17));
    cr_expect(vec_2.insert(5, 6));
    cr_expect(vec_2.length() == 7);
    cr_expect(vec_2.capacity() == 7);
    cr_expect(vec_2.insert(7, 8));
    cr_expect(vec_2.length() == 8);
    cr_expect(vec_2.capacity() == 16);
    cr_expect(vec_2.remove(5));
    cr_expect(vec_2.length() == 7);
    cr_expect(vec_2.capacity() == 16);
    cr_expect(vec_2.remove(5));
    cr_expect(vec_2.remove(5));
    cr_expect_not(vec_2.remove(5));
    cr_expect(vec_2.get(4, val));
    cr_expect(val == 5);
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect_not(vec_2.remove(0));
    cr_expect(vec_2.length() == 0);
    cr_expect(vec_2.capacity() == 2);
}

Test(dynamic_array, accessors) {
    DynamicArray<int> vec;
    int val(-791);
    const int *cPtr = reinterpret_cast<int *>(0xDEADBEEF);
    int *ptr = reinterpret_cast<int *>(0xDEADBEEF);

    cr_expect_null(vec.data());
    cr_expect(vec.length() == 0);
    cr_expect(vec.capacity() == 0);
    cr_expect(vec.insert(0, 7));
    cr_expect(vec.get(0, val));
    cr_expect(val == 7);
    cr_expect(vec.length() == 1);
    cr_expect(vec.capacity() == 2);
    cPtr = vec.data();
    val = *cPtr;
    cr_expect_eq(val, 7);
    //cr_assert_not_null(cPtr);
    cr_expect(vec.insert(0, 6));
    cr_expect(vec.get(0, val));
    cr_expect(val == 6);
    cr_expect(vec.length() == 2);
    cr_expect(vec.capacity() == 2);
    cr_expect(vec.insert(0, 5));
    cr_expect(vec.get(0, val));
    cr_expect(val == 5);
    cr_expect(vec.length() == 3);
    cr_expect(vec.capacity() == 6);
    cr_expect(vec.insert(0, 4));
    cr_expect(vec.get(0, val));
    cr_expect(val == 4);
    cr_expect(vec.insert(0, 3));
    cr_expect(vec.get(0, val));
    cr_expect(val == 3);
    cr_expect(vec.insert(0, 2));
    cr_expect(vec.get(0, val));
    cr_expect(val == 2);
    cr_expect(vec.insert(6, 9));
    cr_expect(vec.insert(6, 8));
    cr_expect(vec.get(0, val));
    cr_expect(val == 2);
    cr_expect(vec.get(1, val));
    cr_expect(val == 3);
    cr_expect(vec.get(2, val));
    cr_expect(val == 4);
    cr_expect(vec.get(3, val));
    cr_expect(val == 5);
    cr_expect(vec.get(4, val));
    cr_expect(val == 6);
    cr_expect(vec.get(5, val));
    cr_expect(val == 7);
    cr_expect(vec.get(6, val));
    cr_expect(val == 8);
    cr_expect(vec.set(6, 800));
    cr_expect(vec.get(6, val));
    cr_expect(val == 800);
    cr_expect(vec.get(7, val));
    cr_expect(val == 9);
    cr_expect(vec.length() == 8);
    cr_expect(vec.capacity() == 14);
    ptr = vec.data();
    cr_assert_not_null(ptr);
    *ptr = 19;
    cr_expect(vec.front(val));
    cr_expect_eq(val, 19);
    cr_expect(vec.back(val));
    cr_expect_eq(val, 9);
    cr_expect_not(vec.set(16, 800));
}

Test(dynamic_array, reserving_space) {
    DynamicArray<int> vec;
    DynamicArray<int> vec_2(90);
    cr_expect(vec.capacity() == 0);
    cr_expect(vec_2.capacity() == 90);

    cr_expect_not(vec.resize(std::numeric_limits<size_t>::max()));
    cr_expect(vec.resize(17));
    cr_expect(vec_2.resize(19));
    cr_expect(vec.capacity() == 17);
    cr_expect(vec_2.capacity() == 19);

    cr_expect_not(vec.insert(3, 3));
    cr_expect(vec.insert(0, 3));
    cr_expect(vec.insert(1, 33));
    cr_expect(vec.length() == 2);
    cr_expect(vec.size() == (sizeof(int) * vec.capacity()));
    cr_expect(vec.capacity() == 17);

    cr_expect(vec.fit());
    cr_expect_not(vec.fit());
    cr_expect(vec.length() == 2);
    cr_expect(vec.size() == (sizeof(int) * vec.capacity()));
    cr_expect(vec.capacity() == 2);
}
