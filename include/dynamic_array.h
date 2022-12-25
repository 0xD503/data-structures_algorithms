#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdio.h>
#include <stddef.h>


#define MEM_REALLOC_FACTOR 2


enum Status_e {
    SUCCESS = 0,
    FAIL = -1
};


typedef enum Status_e Status;


#define DYNAMIC_ARRAY_T(typename, type)                                 \
    typedef struct {                                                    \
        size_t _length;     /* number of elements in a queue */         \
        size_t _capacity;   /* number of buckets for elements in a queue */ \
        type *_data;                                                    \
    } DynamicArray_##type;                                              \
                                                                        \
    void DynamicArray_##type##_init (DynamicArray_##type *me) {         \
        if (me != NULL) {                                               \
            me->_capacity = 0;                                          \
            me->_length = 0;                                            \
            me->_data = malloc(sizeof(me->_data[0]) * me->_capacity);   \
            if (me->_data == NULL) {                                    \
                perror("Failed to construct dynamic array");            \
            }                                                           \
        }                                                               \
    }                                                                   \
                                                                        \
    void DynamicArray_##type##_init_2 (DynamicArray_##type *me, size_t capacity) { \
        if (me != NULL) {                                               \
            me->_capacity = capacity;                                   \
            me->_length = 0;                                            \
            me->_data = malloc(sizeof(me->_data[0]) * me->_capacity);   \
            if (me->_data == NULL) {                                    \
                me->_capacity = 0;                                      \
                perror("Failed to construct dynamic array");            \
            }                                                           \
        }                                                               \
    }                                                                   \
                                                                        \
    void DynamicArray_##type##_init_3 (DynamicArray_##type *me, size_t capacity, type val) { \
        DynamicArray_##type##_init_2(me, capacity);                     \
        memset(me->_data, val, sizeof(me->_data[0]) * capacity);        \
    }                                                                   \
                                                                        \
    void DynamicArray_##type##_deinit (DynamicArray_##type *me) {       \
        if (me != NULL) {                                               \
            if (me->_data != NULL) {                                    \
                free(me->_data);                                        \
                me->_data = NULL;                                       \
            }                                                           \
            me->_capacity = 0;                                          \
            me->_length = 0;                                            \
        }                                                               \
    }                                                                   \
                                                                        \
                                                                        \
    DynamicArray_##type *DynamicArray_##type##_create (void) {          \
        DynamicArray_##type *da = calloc(1, sizeof(*da));               \
        if (da != NULL) {                                               \
            DynamicArray_##type##_init(da);                             \
        }                                                               \
                                                                        \
        return (da);                                                    \
    }                                                                   \
                                                                        \
    DynamicArray_##type *DynamicArray_##type##_create_2 (size_t capacity) { \
        DynamicArray_##type *da = calloc(1, sizeof(*da));               \
        if (da != NULL) {                                               \
            DynamicArray_##type##_init_2(da, capacity);                 \
        }                                                               \
                                                                        \
        return (da);                                                    \
    }                                                                   \
                                                                        \
    void DynamicArray_##type##_destroy (DynamicArray_##type **me) {     \
        if (me != NULL) {                                               \
            DynamicArray_##type##_deinit(*me);                          \
            if (*me != NULL) {                                          \
                free(*me);                                              \
                *me = NULL;                                             \
            }                                                           \
        }                                                               \
    }                                                                   \
                                                                        \
                                                                        \
    Status DynamicArray_##type##_resize (DynamicArray_##type *me, size_t newCap) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (me->_data != NULL)) {                      \
            /* check if new capacity is more than the number of elements in array */ \
            if (newCap > me->_length) {                                 \
                type *temp = (type *) realloc(me->_data, newCap * sizeof(*temp)); \
                if (temp == NULL) {                                     \
                    perror("Failed to reallocate memory");              \
                    goto end;                                           \
                }                                                       \
                me->_data = temp;                                       \
                me->_capacity = newCap;                                 \
                status = SUCCESS;                                       \
            }                                                           \
        }                                                               \
                                                                        \
    end:                                                                \
        return (status);                                                \
    }                                                                   \
                                                                        \
                                                                        \
    void DynamicArray_##type##_init_copy (DynamicArray_##type *me, DynamicArray_##type *src) { \
        if ((me != NULL) && (src != NULL)) {                            \
            DynamicArray_##type##_init_2(me, src->_length);             \
            memcpy(me->_data, src->_data, src->_length);                \
            me->_length = src->_length;                                 \
        }                                                               \
    }                                                                   \
                                                                        \
                                                                        \
    void DynamicArray_##type##_copy (DynamicArray_##type *me, DynamicArray_##type *src) { \
        if ((me != NULL) && (src != NULL)) {                            \
            if (src->_length > me->_length) {                           \
                DynamicArray_##type##_resize(me, src->_length);         \
            }                                                           \
            memcpy(me->_data, src->_data, src->_length);                \
            me->_length = src->_length;                                 \
        }                                                               \
    }                                                                   \
                                                                        \
                                                                        \
    size_t DynamicArray_##type##_length (const DynamicArray_##type *me) { \
        size_t len = 0;                                                 \
                                                                        \
        if (me != NULL) {                                               \
            len = me->_length;                                          \
        }                                                               \
                                                                        \
        return (len);                                                   \
    }                                                                   \
                                                                        \
    size_t DynamicArray_##type##_capacity (const DynamicArray_##type *me) { \
        size_t cap = 0;                                                 \
                                                                        \
        if (me != NULL) {                                               \
            cap = me->_capacity;                                        \
        }                                                               \
                                                                        \
        return (cap);                                                   \
    }                                                                   \
                                                                        \
    size_t DynamicArray_##type##_size (const DynamicArray_##type *me) { \
        size_t size = 0;                                                \
                                                                        \
        if (me != NULL) {                                               \
            size = DynamicArray_##type##_capacity(me) * sizeof(me->_data[0]); \
        }                                                               \
                                                                        \
        return (size);                                                  \
    }                                                                   \
                                                                        \
                                                                        \
    Status DynamicArray_##type##_get (const DynamicArray_##type *me, size_t index, type *dest) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (index < me->_length)) {                    \
            if (dest != NULL) {                                         \
                *dest = me->_data[index];                               \
                status = SUCCESS;                                       \
            }                                                           \
        }                                                               \
                                                                        \
        return (status);                                                \
    }                                                                   \
                                                                        \
    Status DynamicArray_##type##_set (DynamicArray_##type *me, size_t index, type val, type *dest) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (index < me->_length)) {                    \
            if (dest != NULL) {                                         \
                *dest = me->_data[index];                               \
            }                                                           \
            me->_data[index] = val;                                     \
            status = SUCCESS;                                           \
        }                                                               \
                                                                        \
        return (status);                                                \
    }                                                                   \
                                                                        \
                                                                        \
    Status DynamicArray_##type##_insert (DynamicArray_##type *me, size_t index, type val) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (index <= me->_length)) {                   \
            /* check if we have enough memory first */                  \
            if (me->_length >= me->_capacity) {                         \
                size_t newCap = (me->_capacity + 1) * MEM_REALLOC_FACTOR; \
                Status st = DynamicArray_##type##_resize(me, newCap);   \
                if (st != SUCCESS) {                                    \
                    goto end;                                           \
                }                                                       \
            }                                                           \
            memmove(&me->_data[index + 1], &me->_data[index], (me->_length++ - index) * sizeof(me->_data[0])); \
            DynamicArray_##type##_set(me, index, val, NULL);            \
            status = SUCCESS;                                           \
        }                                                               \
                                                                        \
    end:                                                                \
        return (status);                                                \
    }                                                                   \
                                                                        \
    Status DynamicArray_##type##_remove (DynamicArray_##type *me, size_t index, type *dest) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (index < me->_length)) {                    \
            /* put the desired element to container */                  \
            if (dest != NULL) {                                         \
                *dest = me->_data[index];                               \
            }                                                           \
            if ((me->_length - 1) < (me->_capacity / (MEM_REALLOC_FACTOR + 1))) { \
                Status st = DynamicArray_##type##_resize(me, me->_length + 1); \
                if (st != SUCCESS) {                                    \
                    goto end;                                           \
                }                                                       \
            }                                                           \
            memmove(&me->_data[index], &me->_data[index + 1], (me->_length-- - index - 1) * sizeof(me->_data[0])); \
            status = SUCCESS;                                           \
        }                                                               \
                                                                        \
    end:                                                                \
        return (status);                                                \
    }


#endif // __DYNAMIC_ARRAY_H__
