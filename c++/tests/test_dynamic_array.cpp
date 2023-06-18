#include <criterion/criterion.h>

#include "dynamic_array.hpp"

#include <iostream>


using std::clog;
using std::endl;


void testSetup (void) {
    //
}

void testTeardown (void) {
    //
}


TestSuite(list_if, .init = testSetup, .fini = testTeardown);
TestSuite(dynamic_array, .init = testSetup, .fini = testTeardown);


Test(list_if, list_if) {
    //
}


Test(dynamic_array, create) {
    DynamicArray<int> vec;
    cr_expect(vec.length() == 0, "Expected empty array");
    cr_expect(vec.capacity() == 0, "Expected empty array with 0 capacity");
    cr_expect(vec.size() == 0, "Expected empty array with 0 size");
    cr_expect(vec.clear() == true, "Expected success on clearing array");

    DynamicArray<int> vec_2(5);
    cr_expect(vec_2.length() == 0, "Expected empty array");
    cr_expect(vec_2.capacity() == 5, "Expected array with 5 buckets");
    cr_expect(vec_2.size() == (sizeof(int) * 5), "Expected empty array with the size of (5 * int)");
    cr_expect(vec.clear() == true, "Expected success on clearing array");
}

Test(dynamic_array, adding_alements) {
    DynamicArray<int> vec;
    cr_expect(vec.add(0, 7));
    cr_expect(vec.add(0, 6));
    cr_expect(vec.add(0, 5));
    cr_expect(vec.add(0, 4));
    cr_expect(vec.add(0, 3));
    cr_expect(vec.add(0, 2));
    cr_expect(vec.add(0, 9));
    cr_expect(vec.add(6, 8));
    cr_expect(vec.capacity() == 14);
    cr_expect(vec.length() == 8);

    DynamicArray<int> vec_2(7);
    cr_expect(vec_2.add(0, 1));
    cr_expect(!vec_2.add(2, 3));
    cr_expect(vec_2.length() == 1);
    cr_expect(vec_2.capacity() == 7);
}

Test(dynamic_array, removing_elements) {
    DynamicArray<int> vec_2(7);
    int val(-791);
    //int testVal = -1;
    cr_expect(vec_2.add(0, 1));
    cr_expect(not vec_2.add(2, 3));
    cr_expect(vec_2.add(1, 7));
    cr_expect(vec_2.add(2, 2));
    cr_expect(vec_2.remove(1));
    cr_expect(vec_2.get(1, val) == true);
    cr_expect(val == 2);
    cr_expect(vec_2.add(1, 2));
    cr_expect(vec_2.add(3, 4));
    cr_expect(vec_2.length() == 4);
    cr_expect(vec_2.capacity() == 7);
    cr_expect(vec_2.add(4, 5));
    cr_expect(vec_2.add(5, 17));
    cr_expect(vec_2.add(5, 6));
    cr_expect(vec_2.length() == 7);
    cr_expect(vec_2.capacity() == 7);
    cr_expect(vec_2.add(7, 8));
    cr_expect(vec_2.length() == 8);
    cr_expect(vec_2.capacity() == 16);
    cr_expect(vec_2.remove(5));
    cr_expect(vec_2.length() == 7);
    cr_expect(vec_2.capacity() == 16);
    cr_expect(vec_2.remove(5));
    cr_expect(vec_2.remove(5));
    cr_expect(not vec_2.remove(5));
    cr_expect(vec_2.get(4, val) == true);
    cr_expect(val == 5);
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(vec_2.remove(0));
    cr_expect(!vec_2.remove(0));
    cr_expect(vec_2.length() == 0);
    cr_expect(vec_2.capacity() == 2);
}

Test(dynamic_array, accessors) {
    DynamicArray<int> vec;
    int val(-791);

    cr_expect(vec.length() == 0);
    cr_expect(vec.capacity() == 0);
    cr_expect(vec.add(0, 7));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 7);
    cr_expect(vec.length() == 1);
    cr_expect(vec.capacity() == 2);
    cr_expect(vec.add(0, 6));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 6);
    cr_expect(vec.length() == 2);
    cr_expect(vec.capacity() == 2);
    cr_expect(vec.add(0, 5));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 5);
    cr_expect(vec.length() == 3);
    cr_expect(vec.capacity() == 6);
    cr_expect(vec.add(0, 4));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 4);
    cr_expect(vec.add(0, 3));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 3);
    cr_expect(vec.add(0, 2));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 2);
    cr_expect(vec.add(6, 9));
    cr_expect(vec.add(6, 8));
    cr_expect(vec.get(0, val) == true);
    cr_expect(val == 2);
    cr_expect(vec.get(1, val) == true);
    cr_expect(val == 3);
    cr_expect(vec.get(2, val) == true);
    cr_expect(val == 4);
    cr_expect(vec.get(3, val) == true);
    cr_expect(val == 5);
    cr_expect(vec.get(4, val) == true);
    cr_expect(val == 6);
    cr_expect(vec.get(5, val) == true);
    cr_expect(val == 7);
    cr_expect(vec.get(6, val) == true);
    cr_expect(val == 8);
    cr_expect(vec.set(6, 800));
    cr_expect(vec.get(6, val) == true);
    cr_expect(val == 800);
    cr_expect(vec.get(7, val) == true);
    cr_expect(val == 9);
    cr_expect(vec.length() == 8);
    cr_expect(vec.capacity() == 14);
    cr_expect(vec.first() == 2);
    cr_expect(vec.last() == 9);
    cr_expect(!vec.set(16, 800));
}

Test(dynamic_array, reserving_space) {
    DynamicArray<int> vec;
    DynamicArray<int> vec_2(90);
    cr_expect(vec.capacity() == 0);
    cr_expect(vec_2.capacity() == 90);

    cr_expect(vec.resize(17));
    cr_expect(vec_2.resize(19));
    cr_expect(vec.capacity() == 17);
    cr_expect(vec_2.capacity() == 19);

    cr_expect(!vec.add(3, 3));
    cr_expect(vec.add(0, 3));
    cr_expect(vec.add(1, 33));
    cr_expect(vec.length() == 2);
    cr_expect(vec.size() == (sizeof(int) * vec.capacity()));
    cr_expect(vec.capacity() == 17);

    cr_expect(vec.fit());
    cr_expect(vec.length() == 2);
    cr_expect(vec.size() == (sizeof(int) * vec.capacity()));
    cr_expect(vec.capacity() == 2);
}
