#include <stdio.h>
#include <stdint.h>

#include "dynamic_array.h"
#include "dynamic_matrix.h"
//#include "queue.h"


/* DYNAMIC_ARRAY_T(DynamicArray_int, int) */
/* DYNAMIC_ARRAY_T(DynamicArray_char, char) */

/* DYNAMIC_ARRAY(int) */
/* DYNAMIC_ARRAY(char) */

DYNAMIC_ARRAY(int)
DYNAMIC_ARRAY(uint16_t)
DYNAMIC_ARRAY(char)
DYNAMIC_ARRAY(DynamicArray_int)

DYNAMIC_MATRIX(int)


int main (int argc, char *argv[]) {
    int status = -1;

    /* DynamicArray_int dyna; */
    /* DynamicArray_int_init(&dyna); */

    DynamicArray_int dynArr;
    DynamicArray_uint16_t dyna;
    DynamicArray_char dynArr_char;
    dynArr._length = 3;
    dynArr._capacity = 100;
    dynArr._data = NULL;

    DynamicArray_int_init(&dynArr);
    DynamicArray_char_init(&dynArr_char);
    DynamicArray_uint16_t_init_3(&dyna, 77, 0xD503U);

    printf("Size of dynArr_int->data:  %zu\n", sizeof(dynArr._data[0]));
    printf("Size of dynArr_char->data: %zu\n", sizeof(dynArr_char._data[0]));
    printf("\n\n");
    printf("dyna len: %zu\n", DynamicArray_uint16_t_length(&dyna));
    printf("dyna cap: %zu\n", DynamicArray_uint16_t_capacity(&dyna));
    printf("dyna siz: %zu\n", DynamicArray_uint16_t_size(&dyna));


    DynamicArray_int row;
    DynamicArray_int_init_3(&row, 2, 7);
    DynamicArray_DynamicArray_int ddaa;
    DynamicArray_DynamicArray_int_init(&ddaa);

    DynamicArray_DynamicArray_int_insert(&ddaa, 0, row);
    DynamicArray_DynamicArray_int_insert(&ddaa, 1, row);
    DynamicArray_DynamicArray_int_insert(&ddaa, 2, row);
    DynamicArray_DynamicArray_int_insert(&ddaa, 2, row);
    DynamicArray_DynamicArray_int_insert(&ddaa, 2, row);
    DynamicArray_DynamicArray_int_insert(&ddaa, 2, row);

    printf("\n\n");
    printf("row len:  %zu\n", DynamicArray_int_length(&row));
    printf("row cap:  %zu\n", DynamicArray_int_capacity(&row));
    printf("row siz:  %zu\n", DynamicArray_int_size(&row));
    printf("\n\n");
    //printf("roww len: %zu\n", DynamicArray_int_size(&temp));
    printf("dyna len: %zu\n", DynamicArray_DynamicArray_int_length(&ddaa));
    printf("dyna cap: %zu\n", DynamicArray_DynamicArray_int_capacity(&ddaa));
    printf("dyna siz: %zu\n", DynamicArray_DynamicArray_int_size(&ddaa));
    //DynamicArray_Dynamiint dynArr;





    DynamicMatrix_int mat;
    mat._rowsNum = mat._columnsNum = 2;




    /* DynamicArray q; */
    /* DynamicArray_init(&q); */

    /* DynamicArray_insert(&q, 0, 'a'); */
    /* DynamicArray_insert(&q, 1, 'b'); */
    /* DynamicArray_insert(&q, 2, 'c'); */

    /* DynamicArray_deinit(&q); */


    /* DynamicArray q_3; */
    /* DynamicArray_init_2(&q_3, 0); */

    /* DynamicArray_insert(&q_3, 0, '1'); */
    /* DynamicArray_insert(&q_3, 1, '2'); */
    /* DynamicArray_insert(&q_3, 2, '3'); */
    /* DynamicArray_insert(&q_3, 22, '4'); */
    /* DynamicArray_insert(&q_3, 3, '4'); */
    /* DynamicArray_insert(&q_3, 4, '6'); */
    /* DynamicArray_insert(&q_3, 4, '5'); */

    /* DATA_TYPE val; */
    /* for (size_t i = 0; i < 10; i++) { */
    /*     DynamicArray_get(&q_3, i, &val); */
    /*     printf("%c", val); */
    /* } */
    /* printf("\n\n"); */

    /* DynamicArray_deinit(&q_3); */

    /* DynamicArray da_3; */
    /* DynamicArray_init_2(&da_3, 0); */

    /* DynamicArray_insert(&da_3, 0, '1'); */
    /* DynamicArray_insert(&da_3, 1, '2'); */
    /* DynamicArray_insert(&da_3, 2, '3'); */
    /* DynamicArray_insert(&da_3, 3, '4'); */
    /* DynamicArray_insert(&da_3, 4, '6'); */
    /* DynamicArray_insert(&da_3, 4, '5'); */

    /* DATA_TYPE val; */

    /* /// check set function */
    /* DynamicArray_set(&da_3, 4, '9', &val); */
    /* DynamicArray_set(&da_3, 5, '8', &val); */

    /* DynamicArray_remove(&da_3, 0, NULL); */
    /* DynamicArray_remove(&da_3, 3, &val); */
    /* //printf("Value: %d\n\n", val); */
    /* //if (val == '9'); */
    /* DynamicArray_get(&da_3, 3, &val); */
    /* //printf("Value: %d\n\n", val); */
    /* //if (val == '8'); */


    status = 0;

    return (status);
}
