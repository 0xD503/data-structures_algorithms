#include <stdio.h>

#include "dynamic_array.h"
//#include "queue.h"


int main (int argc, char *argv[]) {
    int status = -1;

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

    DynamicArray da_3;
    DynamicArray_init_2(&da_3, 0);

    DynamicArray_insert(&da_3, 0, '1');
    DynamicArray_insert(&da_3, 1, '2');
    DynamicArray_insert(&da_3, 2, '3');
    DynamicArray_insert(&da_3, 3, '4');
    DynamicArray_insert(&da_3, 4, '6');
    DynamicArray_insert(&da_3, 4, '5');

    DATA_TYPE val;

    /// check set function
    DynamicArray_set(&da_3, 4, '9', &val);
    DynamicArray_set(&da_3, 5, '8', &val);

    DynamicArray_remove(&da_3, 0, NULL);
    DynamicArray_remove(&da_3, 3, &val);
    //printf("Value: %d\n\n", val);
    //if (val == '9');
    DynamicArray_get(&da_3, 3, &val);
    //printf("Value: %d\n\n", val);
    //if (val == '8');


    status = 0;

    return (status);
}
