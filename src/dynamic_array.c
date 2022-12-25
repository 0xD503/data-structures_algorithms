#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* void DynamicArray_init (DynamicArray *me) { */
/*     if (me != NULL) { */
/*         me->_capacity = 0; */
/*         me->_length = 0; */
/*         me->_data = malloc(sizeof(me->_data[0]) * me->_capacity); */
/*         if (me->_data == NULL) { */
/*             perror("Failed to construct dynamic array"); */
/*         } */
/*     } */
/* } */

/* void DynamicArray_init_2 (DynamicArray *me, size_t capacity) { */
/*     if (me != NULL) { */
/*         me->_capacity = capacity; */
/*         me->_length = 0; */
/*         me->_data = malloc(sizeof(me->_data[0]) * me->_capacity); */
/*         if (me->_data == NULL) { */
/*             me->_capacity = 0; */
/*             perror("Failed to construct dynamic array"); */
/*         } */
/*     } */
/* } */

/* void DynamicArray_init_3 (DynamicArray *me, size_t capacity, DATA_TYPE val) { */
/*     DynamicArray_init_2(me, capacity); */
/*     memset(me->_data, val, sizeof(me->_data[0]) * capacity); */
/* } */

/* void DynamicArray_deinit (DynamicArray *me) { */
/*     if (me != NULL) { */
/*         if (me->_data != NULL) { */
/*             free(me->_data); */
/*             me->_data = NULL; */
/*         } */
/*         me->_capacity = 0; */
/*         me->_length = 0; */
/*     } */
/* } */


/* DynamicArray *DynamicArray_create (void) { */
/*     DynamicArray *da = calloc(1, sizeof(*da)); */
/*     if (da != NULL) { */
/*         DynamicArray_init(da); */
/*     } */

/*     return (da); */
/* } */

/* DynamicArray *DynamicArray_create_2 (size_t capacity) { */
/*     DynamicArray *da = calloc(1, sizeof(*da)); */
/*     if (da != NULL) { */
/*         DynamicArray_init_2(da, capacity); */
/*     } */

/*     return (da); */
/* } */

/* void DynamicArray_destroy (DynamicArray **me) { */
/*     if (me != NULL) { */
/*         DynamicArray_deinit(*me); */
/*         if (*me != NULL) { */
/*             free(*me); */
/*             *me = NULL; */
/*         } */
/*     } */
/* } */


/* void DynamicArray_init_copy (DynamicArray *me, DynamicArray *src) { */
/*     if ((me != NULL) && (src != NULL)) { */
/*         DynamicArray_init_2(me, src->_length); */
/*         memcpy(me->_data, src->_data, src->_length); */
/*         me->_length = src->_length; */
/*     } */
/* } */


/* void DynamicArray_copy (DynamicArray *me, DynamicArray *src) { */
/*     if ((me != NULL) && (src != NULL)) { */
/*         if (src->_length > me->_length) { */
/*             DynamicArray_resize(me, src->_length); */
/*         } */
/*         memcpy(me->_data, src->_data, src->_length); */
/*         me->_length = src->_length; */
/*     } */
/* } */


/* size_t DynamicArray_length (const DynamicArray *me) { */
/*     size_t len = 0; */

/*     if (me != NULL) { */
/*         len = me->_length; */
/*     } */

/*     return (len); */
/* } */

/* size_t DynamicArray_capacity (const DynamicArray *me) { */
/*     size_t cap = 0; */

/*     if (me != NULL) { */
/*         cap = me->_capacity; */
/*     } */

/*     return (cap); */
/* } */

/* size_t DynamicArray_size (const DynamicArray *me) { */
/*     size_t size = 0; */

/*     if (me != NULL) { */
/*         size = DynamicArray_capacity(me) * sizeof(me->_data[0]); */
/*     } */

/*     return (size); */
/* } */


/* Status DynamicArray_resize (DynamicArray *me, size_t newCap) { */
/*     Status status = FAIL; */

/*     if ((me != NULL) && (me->_data != NULL)) { */
/*         /// check if new capacity is more than the number of elements in array */
/*         if (newCap > me->_length) { */
/*             DATA_TYPE *temp = (DATA_TYPE *) realloc(me->_data, newCap * sizeof(*temp)); */
/*             if (temp == NULL) { */
/*                 perror("Failed to reallocate memory"); */
/*                 goto end; */
/*             } */
/*             me->_data = temp; */
/*             me->_capacity = newCap; */
/*             status = SUCCESS; */
/*         } */
/*     } */

/* end: */
/*     return (status); */
/* } */


/* Status DynamicArray_get (const DynamicArray *me, size_t index, DATA_TYPE *dest) { */
/*     Status status = FAIL; */

/*     if ((me != NULL) && (index < me->_length)) { */
/*         if (dest != NULL) { */
/*             *dest = me->_data[index]; */
/*             status = SUCCESS; */
/*         } */
/*     } */

/*     return (status); */
/* } */

/* Status DynamicArray_set (DynamicArray *me, size_t index, DATA_TYPE val, DATA_TYPE *dest) { */
/*     Status status = FAIL; */

/*     if ((me != NULL) && (index < me->_length)) { */
/*         if (dest != NULL) { */
/*             *dest = me->_data[index]; */
/*         } */
/*         me->_data[index] = val; */
/*         status = SUCCESS; */
/*     } */

/*     return (status); */
/* } */


/* Status DynamicArray_insert (DynamicArray *me, size_t index, DATA_TYPE val) { */
/*     Status status = FAIL; */

/*     if ((me != NULL) && (index <= me->_length)) { */
/*         /// check if we have enough memory first */
/*         if (me->_length >= me->_capacity) { */
/*             size_t newCap = (me->_capacity + 1) * MEM_REALLOC_FACTOR; */
/*             Status st = DynamicArray_resize(me, newCap); */
/*             if (st != SUCCESS) { */
/*                 goto end; */
/*             } */
/*         } */
/*         memmove(&me->_data[index + 1], &me->_data[index], (me->_length++ - index) * sizeof(me->_data[0])); */
/*         DynamicArray_set(me, index, val, NULL); */
/*         status = SUCCESS; */
/*     } */

/* end: */
/*     return (status); */
/* } */

/* Status DynamicArray_remove (DynamicArray *me, size_t index, DATA_TYPE *dest) { */
/*     Status status = FAIL; */

/*     if ((me != NULL) && (index < me->_length)) { */
/*         /// put the desired element to container */
/*         if (dest != NULL) { */
/*             *dest = me->_data[index]; */
/*         } */
/*         if ((me->_length - 1) < (me->_capacity / (MEM_REALLOC_FACTOR + 1))) { */
/*             Status st = DynamicArray_resize(me, me->_length + 1); */
/*             if (st != SUCCESS) { */
/*                 goto end; */
/*             } */
/*         } */
/*         memmove(&me->_data[index], &me->_data[index + 1], (me->_length-- - index - 1) * sizeof(me->_data[0])); */
/*         status = SUCCESS; */
/*     } */

/* end: */
/*     return (status); */
/* } */
