#include <criterion/internal/test.h>
#include <criterion/internal/assert.h>

#include <dynamic_array.h>


DYNAMIC_ARRAY(int)
DYNAMIC_ARRAY(char)
DYNAMIC_ARRAY(DynamicArray_int)


void testSetup (void) {
    //
}

void testTeardown (void) {
    //
}


TestSuite(dynamic_array, .init = testSetup, .fini = testTeardown);


Test(dynamic_array, create) {
    DynamicArray_int_init(NULL);
    DynamicArray_int_init_2(NULL, 0);
    DynamicArray_int_init_2(NULL, 100);

    DynamicArray_int_deinit(NULL);

    DynamicArray_int da;
    DynamicArray_int_init(&da);
    cr_expect(DynamicArray_int_length(&da) == 0);
    cr_expect(DynamicArray_int_capacity(&da) == 0);

    DynamicArray_int da_2;
    DynamicArray_int_init_2(&da_2, 1999);
    cr_expect(DynamicArray_int_length(&da_2) == 0);
    cr_expect(DynamicArray_int_capacity(&da_2) == 1999);

    DynamicArray_int da_3;
    DynamicArray_int_init_2(&da_3, 0);
    cr_expect(da_3._data != NULL);
    cr_expect(DynamicArray_int_length(&da_3) == 0);
    cr_expect(DynamicArray_int_capacity(&da_3) == 0);

    //DynamicArray_int *val = DynamicArray_int_create_2(1);
    /* DynamicArray_int val; */
    /* DynamicArray_int_init_2(&val, 1); */
    /* val._data[0] = 0; */
    int val = 0;

    DynamicArray_int da_4;
    DynamicArray_int_init_3(&da_4, 777, 0xD503);
    cr_expect(da_4._data != NULL);
    cr_expect(DynamicArray_int_length(&da_4) == 777);
    cr_expect(DynamicArray_int_capacity(&da_4) == 777);
    /* cr_expect(val._data[0] == 0); */
    cr_expect(val == 0);
    cr_expect(DynamicArray_int_get(&da_4, 0, &val) == SUCCESS);
    /* cr_expect(val._data[0] == 0xD503); */
    cr_expect(val == 0xD503);
    cr_expect(DynamicArray_int_get(&da_4, 7, &val) == SUCCESS);
    /* cr_expect(val._data[0] == 0xD503); */
    cr_expect(val == 0xD503);
    cr_expect(DynamicArray_int_get(&da_4, 76, &val) == SUCCESS);
    /* cr_expect(val._data[0] == 0xD503); */
    cr_expect(val == 0xD503);
    cr_expect(DynamicArray_int_get(&da_4, 776, &val) == SUCCESS);
    /* cr_expect(val._data[0] == 0xD503); */
    cr_expect(val == 0xD503);
    cr_expect(DynamicArray_int_get(&da_4, 777, &val) == FAIL);
    cr_expect(DynamicArray_int_get(&da_4, 10873, &val) == FAIL);
    /* cr_expect(val._data[0] == 0xD503); */
    cr_expect(val == 0xD503);

    DynamicArray_int_deinit(&da);
    DynamicArray_int_deinit(&da_2);
    DynamicArray_int_deinit(&da_3);
    DynamicArray_int_deinit(&da_4);

    cr_expect(da._data == NULL);
    cr_expect(da_2._data == NULL);
    cr_expect(da_3._data == NULL);
    cr_expect(da_4._data == NULL);
    cr_expect(da._capacity == 0);
    cr_expect(da._length == 0);


    DynamicArray_int *da_ptr = DynamicArray_int_create();
    cr_expect(da_ptr != NULL);
    cr_expect(da_ptr->_data != NULL);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 101) == SUCCESS);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 102) == SUCCESS);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 103) == SUCCESS);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 104) == SUCCESS);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr) + 1, 104) == FAIL);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 105) == SUCCESS);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 106) == SUCCESS);
    cr_expect(DynamicArray_int_length(da_ptr) == 6);
    cr_expect(DynamicArray_int_capacity(da_ptr) == 6);
    cr_expect(DynamicArray_int_insert(da_ptr, DynamicArray_int_length(da_ptr), 107) == SUCCESS);
    cr_expect(DynamicArray_int_length(da_ptr) == 7);
    cr_expect(DynamicArray_int_capacity(da_ptr) == 14);

    DynamicArray_int *da_ptr_2 = DynamicArray_int_create_2(7);
    cr_expect(DynamicArray_int_length(da_ptr_2) == 0);
    cr_expect(DynamicArray_int_capacity(da_ptr_2) == 7);
    cr_expect(DynamicArray_int_insert(da_ptr_2, DynamicArray_int_length(da_ptr_2), 105) == SUCCESS);
    cr_expect(DynamicArray_int_length(da_ptr_2) == 1);
    cr_expect(DynamicArray_int_capacity(da_ptr_2) == 7);

    DynamicArray_int *da_ptr_3 = DynamicArray_int_create_2(7);
    cr_expect(DynamicArray_int_length(da_ptr_3) == 0);
    cr_expect(DynamicArray_int_capacity(da_ptr_3) == 7);
    cr_expect(DynamicArray_int_insert(da_ptr_3, DynamicArray_int_length(da_ptr_3), 105) == SUCCESS);
    cr_expect(DynamicArray_int_length(da_ptr_3) == 1);
    cr_expect(DynamicArray_int_capacity(da_ptr_3) == 7);

    DynamicArray_int_destroy(&da_ptr);
    DynamicArray_int_destroy(&da_ptr_2);

    DynamicArray_int_deinit(da_ptr_3);
    DynamicArray_int_destroy(&da_ptr_3);

    cr_expect(da_ptr == NULL);
    cr_expect(da_ptr_2 == NULL);
    cr_expect(da_ptr_3 == NULL);

    DynamicArray_int_destroy(&da_ptr);
    DynamicArray_int_destroy(NULL);
}

Test(dynamic_array, insert_remove_elements) {
    int test = 0;
    cr_expect(DynamicArray_int_insert(NULL, 0, 7) == FAIL);
    cr_expect(DynamicArray_int_insert(NULL, 1707, 7) == FAIL);
    cr_expect(DynamicArray_int_remove(NULL, 0, NULL) == FAIL);
    cr_expect(DynamicArray_int_remove(NULL, 1707, &test) == FAIL);

    int val = 'h';
    DynamicArray_int da;
    DynamicArray_int_init(&da);
    cr_expect(DynamicArray_int_length(&da) == 0);
    cr_expect(DynamicArray_int_capacity(&da) == 0);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 0, 'a');
    cr_expect(DynamicArray_int_length(&da) == 1);
    cr_expect(DynamicArray_int_capacity(&da) == 2);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 3, 'b');
    DynamicArray_int_insert(&da, 1, 'b');
    cr_expect(DynamicArray_int_length(&da) == 2, "wrong len");
    cr_expect(DynamicArray_int_capacity(&da) == 2, "wrong cap");
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 2, 'c');
    cr_expect(DynamicArray_int_length(&da) == 3);
    cr_expect(DynamicArray_int_capacity(&da) == 6);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 3, 'd');
    cr_expect(DynamicArray_int_length(&da) == 4);
    cr_expect(DynamicArray_int_capacity(&da) == 6);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 4, 'e');
    cr_expect(DynamicArray_int_length(&da) == 5);
    cr_expect(DynamicArray_int_capacity(&da) == 6);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 5, 'f');
    cr_expect(DynamicArray_int_length(&da) == 6);
    cr_expect(DynamicArray_int_capacity(&da) == 6);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    DynamicArray_int_insert(&da, 6, 'g');
    cr_expect(DynamicArray_int_length(&da) == 7);
    cr_expect(DynamicArray_int_capacity(&da) == 14);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));

    cr_expect(DynamicArray_int_remove(&da, 6, NULL) == SUCCESS);
    cr_expect(DynamicArray_int_length(&da) == 6);
    cr_expect(DynamicArray_int_capacity(&da) == 14);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_remove(&da, 6, &val) == FAIL);
    cr_expect(val == 'h');
    cr_expect(DynamicArray_int_length(&da) == 6);
    cr_expect(DynamicArray_int_capacity(&da) == 14);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_remove(&da, 5, &val) == SUCCESS);
    cr_expect(val == 'f');
    cr_expect(DynamicArray_int_length(&da) == 5);
    cr_expect(DynamicArray_int_capacity(&da) == 14);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_remove(&da, 2, &val) == SUCCESS);
    cr_expect(val == 'c');
    cr_expect(DynamicArray_int_length(&da) == 4);
    cr_expect(DynamicArray_int_capacity(&da) == 14);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_remove(&da, 0, &val) == SUCCESS);
    cr_expect(val == 'a');
    cr_expect(DynamicArray_int_length(&da) == 3);
    cr_expect(DynamicArray_int_capacity(&da) == 5);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_remove(&da, 0, &val) == SUCCESS);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(val == 'b');
    cr_expect(DynamicArray_int_length(&da) == 2);
    cr_expect(DynamicArray_int_capacity(&da) == 5);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_remove(&da, 10, &val) == FAIL);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(val == 'b');
    cr_expect(DynamicArray_int_length(&da) == 2);
    cr_expect(DynamicArray_int_capacity(&da) == 5);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));

    DynamicArray_int_deinit(&da);


    DynamicArray_int da_2;
    DynamicArray_int_init_2(&da_2, 7);
    cr_expect(DynamicArray_int_length(&da_2) == 0);
    cr_expect(DynamicArray_int_capacity(&da_2) == 7);
    cr_expect(DynamicArray_int_size(&da_2) == (DynamicArray_int_capacity(&da_2) * sizeof(da_2._data[0])));
    DynamicArray_int_insert(&da_2, 0, 'e');
    DynamicArray_int_insert(&da_2, 1, 'e');
    DynamicArray_int_insert(&da_2, 2, 'e');
    DynamicArray_int_insert(&da_2, 22, 'e');
    DynamicArray_int_insert(&da_2, 3, 'e');
    cr_expect(DynamicArray_int_length(&da_2) == 4);
    cr_expect(DynamicArray_int_capacity(&da_2) == 7);
    cr_expect(DynamicArray_int_size(&da_2) == (DynamicArray_int_capacity(&da_2) * sizeof(da_2._data[0])));
    DynamicArray_int_insert(&da_2, 4, 'e');
    DynamicArray_int_insert(&da_2, 5, 'e');
    DynamicArray_int_insert(&da_2, 6, 'e');
    DynamicArray_int_insert(&da_2, 7, 'e');
    DynamicArray_int_insert(&da_2, 77, 'e');
    cr_expect(DynamicArray_int_length(&da_2) == 8);
    cr_expect(DynamicArray_int_capacity(&da_2) == 16);
    cr_expect(DynamicArray_int_size(&da_2) == (DynamicArray_int_capacity(&da_2) * sizeof(da_2._data[0])));

    DynamicArray_int_deinit(&da_2);


    DynamicArray_int da_3;
    DynamicArray_int_init_2(&da_3, 0);
    cr_expect(DynamicArray_int_length(&da_3) == 0);
    cr_expect(DynamicArray_int_capacity(&da_3) == 0);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    DynamicArray_int_insert(&da_3, 0, '1');
    DynamicArray_int_insert(&da_3, 1, '2');
    DynamicArray_int_insert(&da_3, 2, '3');
    DynamicArray_int_insert(&da_3, 22, '4');
    DynamicArray_int_insert(&da_3, 3, '4');
    cr_expect(DynamicArray_int_length(&da_3) == 4);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    DynamicArray_int_insert(&da_3, 4, '5');
    cr_expect(DynamicArray_int_length(&da_3) == 5);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    DynamicArray_int_insert(&da_3, 5, '6');
    cr_expect(DynamicArray_int_length(&da_3) == 6);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));


    DynamicArray_int_deinit(&da_3);

    DynamicArray_int row;
    DynamicArray_DynamicArray_int twoDimArr;
    cr_expect(DynamicArray_int_init_3(&row, 2, 7) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_init(&twoDimArr) == SUCCESS);

    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 0, row) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 1, row) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 2, row) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 2, row) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 2, row) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 2, row) == SUCCESS);

    cr_expect(DynamicArray_int_length(&row) == 2);
    cr_expect(DynamicArray_int_capacity(&row) == 2);
    cr_expect(DynamicArray_int_size(&row) == (2 * sizeof(int)));

    cr_expect(DynamicArray_int_insert(&row, 3, 8) == FAIL);
    cr_expect(DynamicArray_int_insert(&row, 2, 8) == SUCCESS);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 7, row) == FAIL);
    cr_expect(DynamicArray_DynamicArray_int_insert(&twoDimArr, 6, row) == SUCCESS);

    cr_expect(DynamicArray_int_length(&row) == 3);
    cr_expect(DynamicArray_int_capacity(&row) == 6);
    cr_expect(DynamicArray_int_size(&row) == (6 * sizeof(int)));
    cr_expect(DynamicArray_DynamicArray_int_length(&twoDimArr) == 7);
    cr_expect(DynamicArray_DynamicArray_int_capacity(&twoDimArr) == 14);
    cr_expect(DynamicArray_DynamicArray_int_size(&twoDimArr) == (14 * sizeof(DynamicArray_DynamicArray_int)));
}

Test(dynamic_array, access) {
    DynamicArray_int da_3;
    DynamicArray_int_init_2(&da_3, 0);

    cr_expect(DynamicArray_int_length(&da_3) == 0);
    cr_expect(DynamicArray_int_capacity(&da_3) == 0);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    DynamicArray_int_insert(&da_3, 0, '1');
    DynamicArray_int_insert(&da_3, 1, '2');
    DynamicArray_int_insert(&da_3, 2, '3');
    DynamicArray_int_insert(&da_3, 22, '4');
    DynamicArray_int_insert(&da_3, 3, '4');
    cr_expect(DynamicArray_int_length(&da_3) == 4);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    DynamicArray_int_insert(&da_3, 4, '6');
    cr_expect(DynamicArray_int_length(&da_3) == 5);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    DynamicArray_int_insert(&da_3, 4, '5');
    cr_expect(DynamicArray_int_length(&da_3) == 6);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));


    int val;

    /// check get function
    cr_expect(DynamicArray_int_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '1');
    cr_expect(DynamicArray_int_get(&da_3, 1, &val) == SUCCESS);
    cr_expect(val == '2');
    cr_expect(DynamicArray_int_get(&da_3, 2, &val) == SUCCESS);
    cr_expect(val == '3');
    cr_expect(DynamicArray_int_get(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '4');
    cr_expect(DynamicArray_int_get(&da_3, 4, &val) == SUCCESS);
    cr_expect(val == '5');
    cr_expect(DynamicArray_int_get(&da_3, 5, &val) == SUCCESS);
    cr_expect(val == '6');
    cr_expect(DynamicArray_int_get(&da_3, 6, &val) == FAIL);
    cr_expect(val == '6');

    /// check set function
    cr_expect(DynamicArray_int_set(&da_3, 4, '9', &val) == SUCCESS);
    cr_expect(val == '5');
    cr_expect(DynamicArray_int_get(&da_3, 4, &val) == SUCCESS);
    cr_expect(val == '9');
    cr_expect(DynamicArray_int_set(&da_3, 5, '8', &val) == SUCCESS);
    cr_expect(val == '6');
    cr_expect(DynamicArray_int_get(&da_3, 5, &val) == SUCCESS);
    cr_expect(val == '8');
    cr_expect(DynamicArray_int_get(&da_3, 6, &val) == FAIL);
    cr_expect(val == '8');
    cr_expect(DynamicArray_int_set(&da_3, 6, '8', &val) == FAIL);
    cr_expect(val == '8');
    cr_expect(DynamicArray_int_get(&da_3, 6, &val) == FAIL);
    cr_expect(val == '8');

    cr_expect(DynamicArray_int_remove(&da_3, 0, NULL) == SUCCESS);
    cr_expect(DynamicArray_int_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '2');
    cr_expect(DynamicArray_int_remove(&da_3, 6, &val) == FAIL);
    cr_expect(val == '2');
    cr_expect(DynamicArray_int_length(&da_3) == 5);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    cr_expect(DynamicArray_int_remove(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '9');
    cr_expect(DynamicArray_int_get(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '8');
    cr_expect(DynamicArray_int_size(&da_3) == (DynamicArray_int_capacity(&da_3) * sizeof(da_3._data[0])));
    cr_expect(DynamicArray_int_remove(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '8');
    cr_expect(DynamicArray_int_get(&da_3, 3, &val) == FAIL);
    cr_expect(val == '8');
    cr_expect(DynamicArray_int_length(&da_3) == 3);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_remove(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '2');
    cr_expect(DynamicArray_int_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '3');
    cr_expect(DynamicArray_int_length(&da_3) == 2);
    cr_expect(DynamicArray_int_capacity(&da_3) == 6);
    cr_expect(DynamicArray_int_remove(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '3');
    cr_expect(DynamicArray_int_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '4');
    cr_expect(DynamicArray_int_length(&da_3) == 1);
    cr_expect(DynamicArray_int_capacity(&da_3) == 3);

    DynamicArray_int_deinit(&da_3);
}

Test(dynamic_array, size_manip) {
    cr_expect(DynamicArray_int_length(NULL) == 0);
    cr_expect(DynamicArray_int_capacity(NULL) == 0);
    cr_expect(DynamicArray_int_size(NULL) == 0);

    cr_expect(DynamicArray_int_resize(NULL, 0) == FAIL);
    cr_expect(DynamicArray_int_resize(NULL, 1707) == FAIL);

    DynamicArray_int da;
    DynamicArray_int_init(&da);
    cr_expect(DynamicArray_int_length(&da) == 0);
    cr_expect(DynamicArray_int_capacity(&da) == 0);
    cr_expect(DynamicArray_int_resize(&da, 2177) == SUCCESS);
    cr_expect(DynamicArray_int_length(&da) == 0);
    cr_expect(DynamicArray_int_capacity(&da) == 2177);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    cr_expect(DynamicArray_int_resize(&da, 2177) == SUCCESS);
    cr_expect(DynamicArray_int_length(&da) == 0);
    cr_expect(DynamicArray_int_capacity(&da) == 2177);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));
    for (size_t i = 0; i < 2176; i++) {
        cr_expect(DynamicArray_int_insert(&da, i, '#') == SUCCESS);
    }
    cr_expect(DynamicArray_int_length(&da) == 2176);
    cr_expect(DynamicArray_int_capacity(&da) == 2177);
    cr_expect(DynamicArray_int_insert(&da, 7, '/') == SUCCESS);
    cr_expect(DynamicArray_int_length(&da) == 2177);
    cr_expect(DynamicArray_int_capacity(&da) == 2177);
    cr_expect(DynamicArray_int_insert(&da, 7, '/') == SUCCESS);
    cr_expect(DynamicArray_int_length(&da) == 2178);
    /// (2178 * 2) == 4356
    cr_expect(DynamicArray_int_capacity(&da) == 4356);

    /// (me->capacity / (MEM_REALLOC_FACTOR + 1)) == (4356 / (2 + 1)) == (1452)
    /// (2178 - 1) > (1452)
    /// (1451) < (1452)
    /// ((2178) - (1451)) == 727
    /// so, remove ((727) - 1) == (726) elements
    for (size_t i = 0; i < 726; i++) {
        cr_expect(DynamicArray_int_remove(&da, i, NULL) == SUCCESS);
    }
    cr_expect(DynamicArray_int_length(&da) == 1452);
    cr_expect(DynamicArray_int_capacity(&da) == 4356);
    cr_expect(DynamicArray_int_remove(&da, 0, NULL) == SUCCESS);    /// remove 727'th element
    cr_expect(DynamicArray_int_length(&da) == 1451);
    cr_expect(DynamicArray_int_capacity(&da) == 1453);
    cr_expect(DynamicArray_int_resize(&da, 20134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 20134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 30134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 20134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 0) == FAIL);
    cr_expect(DynamicArray_int_resize(&da, 920134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 20134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 1451) == FAIL);
    cr_expect(DynamicArray_int_resize(&da, 1452) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 1450) == FAIL);
    cr_expect(DynamicArray_int_resize(&da, 200134) == SUCCESS);
    cr_expect(DynamicArray_int_resize(&da, 20) == FAIL);
    cr_expect(DynamicArray_int_resize(&da, 20134) == SUCCESS);
    cr_expect(DynamicArray_int_length(&da) == 1451);
    cr_expect(DynamicArray_int_capacity(&da) == 20134);
    cr_expect(DynamicArray_int_size(&da) == (DynamicArray_int_capacity(&da) * sizeof(da._data[0])));


    DynamicArray_int da_2;
    DynamicArray_int_init_2(&da_2, 1999);
    cr_expect(DynamicArray_int_length(&da_2) == 0);
    cr_expect(DynamicArray_int_capacity(&da_2) == 1999);

    DynamicArray_int dai_1;
    DynamicArray_char dac_1;

    DynamicArray_int_init_2(&dai_1, 288);
    DynamicArray_char_init_2(&dac_1, 288);

    cr_expect(DynamicArray_int_resize(&dai_1, 1999) == SUCCESS);
    cr_expect(DynamicArray_char_resize(&dac_1, 1999) == SUCCESS);

    cr_expect(DynamicArray_int_capacity(&dai_1) == 1999);
    cr_expect(DynamicArray_char_capacity(&dac_1) == 1999);

    cr_expect(DynamicArray_int_size(&dai_1) == 7996);
    cr_expect(DynamicArray_char_size(&dac_1) == 1999);
}
