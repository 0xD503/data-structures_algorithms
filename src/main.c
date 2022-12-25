#include <stdio.h>

#include "dynamic_array.h"
//#include "queue.h"


/* DYNAMIC_ARRAY_T(DynamicArray_int, int) */
/* DYNAMIC_ARRAY_T(DynamicArray_char, char) */
DYNAMIC_ARRAY_T(int)
DYNAMIC_ARRAY_T(char)


int main (int argc, char *argv[]) {
    int status = -1;

    DynamicArray_int dynArr;
    DynamicArray_char dynArr_char;
    dynArr._length = 3;
    dynArr._capacity = 100;
    dynArr._data = NULL;

    DynamicArray_int_init(&dynArr);
    DynamicArray_char_init(&dynArr_char);

    printf("Size of dynArr_int->data:  %zu\n", sizeof(dynArr._data[0]));
    printf("Size of dynArr_char->data: %zu\n", sizeof(dynArr_char._data[0]));
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
