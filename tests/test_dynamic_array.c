#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

#include <dynamic_array.h>
#include <stddef.h>
#include <stdio.h>


void testSetup (void) {
    //
}

void testTeardown (void) {
    //
}


TestSuite(dynamic_array, .init = testSetup, .fini = testTeardown);


Test(dynamic_array, create) {
    DynamicArray da;
    DynamicArray_init(&da);
    cr_expect(DynamicArray_length(&da) == 0);
    cr_expect(DynamicArray_capacity(&da) == 0);

    DynamicArray da_2;
    DynamicArray_init_2(&da_2, 1999);
    cr_expect(DynamicArray_length(&da_2) == 0);
    cr_expect(DynamicArray_capacity(&da_2) == 1999);

    DynamicArray da_3;
    DynamicArray_init_2(&da_3, 0);
    cr_expect(da_3.data != NULL);
    cr_expect(DynamicArray_length(&da_3) == 0);
    cr_expect(DynamicArray_capacity(&da_3) == 0);

    DynamicArray_deinit(&da);
    DynamicArray_deinit(&da_2);
    DynamicArray_deinit(&da_3);
    cr_expect(da.data == NULL);
    cr_expect(da_2.data == NULL);
    cr_expect(da_3.data == NULL);
    cr_expect(da.capacity == 0);
    cr_expect(da.length == 0);

    DynamicArray_init(NULL);
    DynamicArray_init_2(NULL, 0);
    DynamicArray_init_2(NULL, 100);

    DynamicArray_deinit(NULL);
}

Test(dynamic_array, insert_remove_elements) {
    DATA_TYPE val = 'h';
    DynamicArray da;
    DynamicArray_init(&da);
    cr_expect(DynamicArray_length(&da) == 0);
    cr_expect(DynamicArray_capacity(&da) == 0);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 0, 'a');
    cr_expect(DynamicArray_length(&da) == 1);
    cr_expect(DynamicArray_capacity(&da) == 2);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 3, 'b');
    DynamicArray_insert(&da, 1, 'b');
    cr_expect(DynamicArray_length(&da) == 2, "wrong len");
    cr_expect(DynamicArray_capacity(&da) == 2, "wrong cap");
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 2, 'c');
    cr_expect(DynamicArray_length(&da) == 3);
    cr_expect(DynamicArray_capacity(&da) == 6);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 3, 'd');
    cr_expect(DynamicArray_length(&da) == 4);
    cr_expect(DynamicArray_capacity(&da) == 6);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 4, 'e');
    cr_expect(DynamicArray_length(&da) == 5);
    cr_expect(DynamicArray_capacity(&da) == 6);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 5, 'f');
    cr_expect(DynamicArray_length(&da) == 6);
    cr_expect(DynamicArray_capacity(&da) == 6);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    DynamicArray_insert(&da, 6, 'g');
    cr_expect(DynamicArray_length(&da) == 7);
    cr_expect(DynamicArray_capacity(&da) == 14);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));

    cr_expect(DynamicArray_remove(&da, 6, NULL) == SUCCESS);
    cr_expect(DynamicArray_length(&da) == 6);
    cr_expect(DynamicArray_capacity(&da) == 14);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_remove(&da, 6, &val) == FAIL);
    cr_expect(val == 'h');
    cr_expect(DynamicArray_length(&da) == 6);
    cr_expect(DynamicArray_capacity(&da) == 14);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_remove(&da, 5, &val) == SUCCESS);
    cr_expect(val == 'f');
    cr_expect(DynamicArray_length(&da) == 5);
    cr_expect(DynamicArray_capacity(&da) == 14);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_remove(&da, 2, &val) == SUCCESS);
    cr_expect(val == 'c');
    cr_expect(DynamicArray_length(&da) == 4);
    cr_expect(DynamicArray_capacity(&da) == 14);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_remove(&da, 0, &val) == SUCCESS);
    cr_expect(val == 'a');
    cr_expect(DynamicArray_length(&da) == 3);
    cr_expect(DynamicArray_capacity(&da) == 5);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_remove(&da, 0, &val) == SUCCESS);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(val == 'b');
    cr_expect(DynamicArray_length(&da) == 2);
    cr_expect(DynamicArray_capacity(&da) == 5);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_remove(&da, 10, &val) == FAIL);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));
    cr_expect(val == 'b');
    cr_expect(DynamicArray_length(&da) == 2);
    cr_expect(DynamicArray_capacity(&da) == 5);
    cr_expect(DynamicArray_size(&da) == (DynamicArray_capacity(&da) * sizeof(da.data[0])));

    DynamicArray_deinit(&da);


    DynamicArray da_2;
    DynamicArray_init_2(&da_2, 7);
    cr_expect(DynamicArray_length(&da_2) == 0);
    cr_expect(DynamicArray_capacity(&da_2) == 7);
    cr_expect(DynamicArray_size(&da_2) == (DynamicArray_capacity(&da_2) * sizeof(da_2.data[0])));
    DynamicArray_insert(&da_2, 0, 'e');
    DynamicArray_insert(&da_2, 1, 'e');
    DynamicArray_insert(&da_2, 2, 'e');
    DynamicArray_insert(&da_2, 22, 'e');
    DynamicArray_insert(&da_2, 3, 'e');
    cr_expect(DynamicArray_length(&da_2) == 4);
    cr_expect(DynamicArray_capacity(&da_2) == 7);
    cr_expect(DynamicArray_size(&da_2) == (DynamicArray_capacity(&da_2) * sizeof(da_2.data[0])));
    DynamicArray_insert(&da_2, 4, 'e');
    DynamicArray_insert(&da_2, 5, 'e');
    DynamicArray_insert(&da_2, 6, 'e');
    DynamicArray_insert(&da_2, 7, 'e');
    DynamicArray_insert(&da_2, 77, 'e');
    cr_expect(DynamicArray_length(&da_2) == 8);
    cr_expect(DynamicArray_capacity(&da_2) == 16);
    cr_expect(DynamicArray_size(&da_2) == (DynamicArray_capacity(&da_2) * sizeof(da_2.data[0])));

    DynamicArray_deinit(&da_2);


    DynamicArray da_3;
    DynamicArray_init_2(&da_3, 0);
    cr_expect(DynamicArray_length(&da_3) == 0);
    cr_expect(DynamicArray_capacity(&da_3) == 0);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));
    DynamicArray_insert(&da_3, 0, '1');
    DynamicArray_insert(&da_3, 1, '2');
    DynamicArray_insert(&da_3, 2, '3');
    DynamicArray_insert(&da_3, 22, '4');
    DynamicArray_insert(&da_3, 3, '4');
    cr_expect(DynamicArray_length(&da_3) == 4);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));
    DynamicArray_insert(&da_3, 4, '5');
    cr_expect(DynamicArray_length(&da_3) == 5);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));
    DynamicArray_insert(&da_3, 5, '6');
    cr_expect(DynamicArray_length(&da_3) == 6);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));


    DynamicArray_deinit(&da_3);
}

Test(dynamic_array, access) {
    DynamicArray da_3;
    DynamicArray_init_2(&da_3, 0);

    cr_expect(DynamicArray_length(&da_3) == 0);
    cr_expect(DynamicArray_capacity(&da_3) == 0);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));
    DynamicArray_insert(&da_3, 0, '1');
    DynamicArray_insert(&da_3, 1, '2');
    DynamicArray_insert(&da_3, 2, '3');
    DynamicArray_insert(&da_3, 22, '4');
    DynamicArray_insert(&da_3, 3, '4');
    cr_expect(DynamicArray_length(&da_3) == 4);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));
    DynamicArray_insert(&da_3, 4, '6');
    cr_expect(DynamicArray_length(&da_3) == 5);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));
    DynamicArray_insert(&da_3, 4, '5');
    cr_expect(DynamicArray_length(&da_3) == 6);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_size(&da_3) == (DynamicArray_capacity(&da_3) * sizeof(da_3.data[0])));


    DATA_TYPE val;

    /// check get function
    cr_expect(DynamicArray_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '1');
    cr_expect(DynamicArray_get(&da_3, 1, &val) == SUCCESS);
    cr_expect(val == '2');
    cr_expect(DynamicArray_get(&da_3, 2, &val) == SUCCESS);
    cr_expect(val == '3');
    cr_expect(DynamicArray_get(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '4');
    cr_expect(DynamicArray_get(&da_3, 4, &val) == SUCCESS);
    cr_expect(val == '5');
    cr_expect(DynamicArray_get(&da_3, 5, &val) == SUCCESS);
    cr_expect(val == '6');
    cr_expect(DynamicArray_get(&da_3, 6, &val) == FAIL);
    cr_expect(val == '6');

    /// check set function
    cr_expect(DynamicArray_set(&da_3, 4, '9', &val) == SUCCESS);
    cr_expect(val == '5');
    cr_expect(DynamicArray_get(&da_3, 4, &val) == SUCCESS);
    cr_expect(val == '9');
    cr_expect(DynamicArray_set(&da_3, 5, '8', &val) == SUCCESS);
    cr_expect(val == '6');
    cr_expect(DynamicArray_get(&da_3, 5, &val) == SUCCESS);
    cr_expect(val == '8');
    cr_expect(DynamicArray_get(&da_3, 6, &val) == FAIL);
    cr_expect(val == '8');
    cr_expect(DynamicArray_set(&da_3, 6, '8', &val) == FAIL);
    cr_expect(val == '8');
    cr_expect(DynamicArray_get(&da_3, 6, &val) == FAIL);
    cr_expect(val == '8');

    cr_expect(DynamicArray_remove(&da_3, 0, NULL) == SUCCESS);
    cr_expect(DynamicArray_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '2');
    cr_expect(DynamicArray_remove(&da_3, 6, &val) == FAIL);
    cr_expect(val == '2');
    cr_expect(DynamicArray_length(&da_3) == 5);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_remove(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '9');
    cr_expect(DynamicArray_get(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '8');
    cr_expect(DynamicArray_remove(&da_3, 3, &val) == SUCCESS);
    cr_expect(val == '8');
    cr_expect(DynamicArray_get(&da_3, 3, &val) == FAIL);
    cr_expect(val == '8');
    cr_expect(DynamicArray_length(&da_3) == 3);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_remove(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '2');
    cr_expect(DynamicArray_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '3');
    cr_expect(DynamicArray_length(&da_3) == 2);
    cr_expect(DynamicArray_capacity(&da_3) == 6);
    cr_expect(DynamicArray_remove(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '3');
    cr_expect(DynamicArray_get(&da_3, 0, &val) == SUCCESS);
    cr_expect(val == '4');
    cr_expect(DynamicArray_length(&da_3) == 1);
    cr_expect(DynamicArray_capacity(&da_3) == 3);

    DynamicArray_deinit(&da_3);
}

Test(dynamic_array, size_manip) {
    DynamicArray da;
    DynamicArray_init(&da);
    cr_expect(DynamicArray_length(&da) == 0);
    cr_expect(DynamicArray_capacity(&da) == 0);
    cr_expect(DynamicArray_resize(&da, 2177) == SUCCESS);
    cr_expect(DynamicArray_length(&da) == 0);
    cr_expect(DynamicArray_capacity(&da) == 2177);
    for (size_t i = 0; i < 2176; i++) {
        cr_expect(DynamicArray_insert(&da, i, '#') == SUCCESS);
    }
    cr_expect(DynamicArray_length(&da) == 2176);
    cr_expect(DynamicArray_capacity(&da) == 2177);
    cr_expect(DynamicArray_insert(&da, 7, '/') == SUCCESS);
    cr_expect(DynamicArray_length(&da) == 2177);
    cr_expect(DynamicArray_capacity(&da) == 2177);
    cr_expect(DynamicArray_insert(&da, 7, '/') == SUCCESS);
    cr_expect(DynamicArray_length(&da) == 2178);
    /// (2178 * 2) == 4356
    cr_expect(DynamicArray_capacity(&da) == 4356);

    /// (me->capacity / (MEM_REALLOC_FACTOR + 1)) == (4356 / (2 + 1)) == (1452)
    /// (2178 - 1) > (1452)
    /// (1451) < (1452)
    /// ((2178) - (1451)) == 727
    /// so, remove ((727) - 1) == (726) elements
    for (size_t i = 0; i < 726; i++) {
        cr_expect(DynamicArray_remove(&da, i, NULL) == SUCCESS);
    }
    cr_expect(DynamicArray_length(&da) == 1452);
    cr_expect(DynamicArray_capacity(&da) == 4356);
    cr_expect(DynamicArray_remove(&da, 0, NULL) == SUCCESS);    /// remove 727'th
    cr_expect(DynamicArray_length(&da) == 1451);
    cr_expect(DynamicArray_capacity(&da) == 1453);


    DynamicArray da_2;
    DynamicArray_init_2(&da_2, 1999);
    cr_expect(DynamicArray_length(&da_2) == 0);
    cr_expect(DynamicArray_capacity(&da_2) == 1999);
}
