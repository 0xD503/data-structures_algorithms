#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stddef.h>


#define DATA_TYPE long
#define MEM_REALLOC_FACTOR 2
//#define


enum Status_e {
    SUCCESS = 0,
    FAIL = -1
};


struct DynamicArray_s {
    DATA_TYPE *data;
    size_t length;      /// number of elements in a queue
    size_t capacity;    /// number of buckets for elements in a queue
};


typedef struct DynamicArray_s DynamicArray;
typedef enum Status_e Status;


void DynamicArray_init (DynamicArray *me);
void DynamicArray_init_2 (DynamicArray *me, size_t capacity);
void DynamicArray_deinit (DynamicArray *me);

size_t DynamicArray_length (const DynamicArray *me);
size_t DynamicArray_capacity (const DynamicArray *me);
size_t DynamicArray_size (const DynamicArray *me);

Status DynamicArray_resize (DynamicArray *me, size_t newCap);

Status DynamicArray_insert (DynamicArray *me, size_t index, DATA_TYPE val);
Status DynamicArray_remove (DynamicArray *me, size_t index, DATA_TYPE *dest);
/* Status DynamicArray_push_back (DynamicArray *me, DATA_TYPE val); */
/* Status DynamicArray_ (DynamicArray *me, DATA_TYPE *dest); */

/* /// begin/end - iterators */
/* /// first/last, front/back - value, reference */
/* Status DynamicArray_front (const DynamicArray *me, DATA_TYPE *dest); */
/* Status DynamicArray_back (const DynamicArray *me, DATA_TYPE *dest); */
Status DynamicArray_get (const DynamicArray *me, size_t index, DATA_TYPE *dest);
Status DynamicArray_set (DynamicArray *me, size_t index, DATA_TYPE val, DATA_TYPE *dest);


#endif // __DYNAMIC_ARRAY_H__
