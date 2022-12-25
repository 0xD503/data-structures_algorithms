#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stddef.h>


#define DATA_TYPE long
#define MEM_REALLOC_FACTOR 2


enum Status_e {
    SUCCESS = 0,
    FAIL = -1
};


struct DynamicArray_s {
    DATA_TYPE *_data;
    size_t _length;      /// number of elements in a queue
    size_t _capacity;    /// number of buckets for elements in a queue
};


typedef struct DynamicArray_s DynamicArray;
typedef enum Status_e Status;


void DynamicArray_init (DynamicArray *me);
void DynamicArray_init_2 (DynamicArray *me, size_t capacity);
void DynamicArray_init_3 (DynamicArray *me, size_t capacity, DATA_TYPE val);
void DynamicArray_deinit (DynamicArray *me);

/// fabrics
DynamicArray *DynamicArray_create (void);
DynamicArray *DynamicArray_create_2 (size_t capacity);
void DynamicArray_destroy (DynamicArray **me);

/// copy/move constructors
void DynamicArray_init_copy (DynamicArray *me, DynamicArray *src);

/// copy/move operators
void DynamicArray_copy (DynamicArray *me, DynamicArray *src);

size_t DynamicArray_length (const DynamicArray *me);
size_t DynamicArray_capacity (const DynamicArray *me);
size_t DynamicArray_size (const DynamicArray *me);

Status DynamicArray_resize (DynamicArray *me, size_t newCap);

Status DynamicArray_insert (DynamicArray *me, size_t index, DATA_TYPE val);
Status DynamicArray_remove (DynamicArray *me, size_t index, DATA_TYPE *dest);

Status DynamicArray_get (const DynamicArray *me, size_t index, DATA_TYPE *dest);
Status DynamicArray_set (DynamicArray *me, size_t index, DATA_TYPE val, DATA_TYPE *dest);


#endif // __DYNAMIC_ARRAY_H__
