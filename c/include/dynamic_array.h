#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


#define MEM_REALLOC_FACTOR 2


#define DYNAMIC_ARRAY_T(type)                   \
    typedef struct {                            \
        size_t _length;                         \
        size_t _capacity;                       \
        type *_data;                            \
    } DynamicArray_##type;

#define DYNAMIC_ARRAY_INIT(type)                                        \
    Status DynamicArray_##type##_init (DynamicArray_##type *me) {       \
        Status status = FAIL;                                           \
                                                                        \
        if (me != NULL) {                                               \
            me->_capacity = 0;                                          \
            me->_length = 0;                                            \
            me->_data = malloc(sizeof(me->_data[0]) * me->_capacity);   \
            if (me->_data == NULL) {                                    \
                perror("Failed to construct dynamic array");            \
                goto end;                                               \
            }                                                           \
            status = SUCCESS;                                           \
        }                                                               \
                                                                        \
    end:                                                                \
        return (status);                                                \
    }

#define DYNAMIC_ARRAY_INIT_2(type)                                      \
    Status DynamicArray_##type##_init_2 (DynamicArray_##type *me, size_t capacity) { \
        Status status = FAIL;                                           \
                                                                        \
        if (me != NULL) {                                               \
            me->_capacity = capacity;                                   \
            me->_length = 0;                                            \
            me->_data = malloc(sizeof(me->_data[0]) * me->_capacity);   \
            if (me->_data == NULL) {                                    \
                me->_capacity = 0;                                      \
                perror("Failed to construct dynamic array");            \
                goto end;                                               \
            }                                                           \
            status = SUCCESS;                                           \
        }                                                               \
                                                                        \
    end:                                                                \
        return (status);                                                \
    }

#define DYNAMIC_ARRAY_INIT_3(type)                                      \
    Status DynamicArray_##type##_init_3 (DynamicArray_##type *me, size_t length, type val) { \
        Status status;                                                  \
                                                                        \
        status = DynamicArray_##type##_init_2(me, length);            \
        if (status == SUCCESS) {                                        \
            for (size_t i = 0; i < _capacity; i++) {                     \
                me->_data[i] = val;                                     \
            }                                                           \
            me->_length = length;                                     \
        }                                                               \
                                                                        \
        return (status);                                                \
    }

#define DYNAMIC_ARRAY_DEINIT(type)                                      \
    void DynamicArray_##type##_deinit (DynamicArray_##type *me) {       \
        if (me != NULL) {                                               \
            if (me->_data != NULL) {                                    \
                free(me->_data);                                        \
                me->_data = NULL;                                       \
            }                                                           \
            me->_capacity = 0;                                          \
            me->_length = 0;                                            \
        }                                                               \
    }

#define DYNAMIC_ARRAY_CREATE(type)                                      \
    DynamicArray_##type *DynamicArray_##type##_create (void) {          \
        DynamicArray_##type *da = calloc(1, sizeof(*da));               \
        if (da != NULL) {                                               \
            DynamicArray_##type##_init(da);                             \
        }                                                               \
                                                                        \
        return (da);                                                    \
    }

#define DYNAMIC_ARRAY_CREATE_2(type)                                    \
    DynamicArray_##type *DynamicArray_##type##_create_2 (size_t capacity) { \
        DynamicArray_##type *da = calloc(1, sizeof(*da));               \
        if (da != NULL) {                                               \
            DynamicArray_##type##_init_2(da, capacity);                 \
        }                                                               \
                                                                        \
        return (da);                                                    \
    }

#define DYNAMIC_ARRAY_DESTROY(type)                                     \
    void DynamicArray_##type##_destroy (DynamicArray_##type **me) {     \
        if (me != NULL) {                                               \
            DynamicArray_##type##_deinit(*me);                          \
            if (*me != NULL) {                                          \
                free(*me);                                              \
                *me = NULL;                                             \
            }                                                           \
        }                                                               \
    }

#define DYNAMIC_ARRAY_RESIZE(type)                                      \
    Status DynamicArray_##type##_resize (DynamicArray_##type *me, size_t newCap) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (me->_data != NULL)) {                      \
            /* check if new capacity is more than the number of elements in array */ \
            if ((newCap >= me->_length) && (newCap != me->_capacity)) {                                 \
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
    }

#define DYNAMIC_ARRAY_COPY(type)                                        \
    Status DynamicArray_##type##_copy (DynamicArray_##type *me, DynamicArray_##type *src) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (src != NULL)) {                            \
            /* Resize destination array if necessary  */                \
            if (src->_length > me->_length) {                           \
                DynamicArray_##type##_resize(me, src->_length);         \
            }                                                           \
            /* Copy values from src array to dest  */                   \
            for (size_t i = 0; i < src->_length; i++) {                 \
                me->_data[i] = src->_data[i];                           \
            }                                                           \
            me->_length = src->_length;                                 \
            status = SUCCESS;                                           \
        }                                                               \
                                                                        \
        return (status);                                                \
    }

#define DYNAMIC_ARRAY_INIT_COPY(type)                                   \
    Status DynamicArray_##type##_init_copy (DynamicArray_##type *me, DynamicArray_##type *src) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (src != NULL)) {                            \
            DynamicArray_##type##_init_2(me, src->_length);             \
            DynamicArray_##type##_copy(me, src);                        \
            me->_length = src->_length;                                 \
        }                                                               \
                                                                        \
        return (status);                                                \
    }

#define DYNAMIC_ARRAY_LENGTH(type)                                      \
    size_t DynamicArray_##type##_length (const DynamicArray_##type *me) { \
        size_t len = 0;                                                 \
                                                                        \
        if (me != NULL) {                                               \
            len = me->_length;                                          \
        }                                                               \
                                                                        \
        return (len);                                                   \
    }

#define DYNAMIC_ARRAY_CAPACITY(type)                                    \
    size_t DynamicArray_##type##_capacity (const DynamicArray_##type *me) { \
        size_t cap = 0;                                                 \
                                                                        \
        if (me != NULL) {                                               \
            cap = me->_capacity;                                        \
        }                                                               \
                                                                        \
        return (cap);                                                   \
    }

#define DYNAMIC_ARRAY_SIZE(type)                                        \
    size_t DynamicArray_##type##_size (const DynamicArray_##type *me) { \
        size_t size = 0;                                                \
                                                                        \
        if (me != NULL) {                                               \
            size = DynamicArray_##type##_capacity(me) * sizeof(me->_data[0]); \
        }                                                               \
                                                                        \
        return (size);                                                  \
    }

#define DYNAMIC_ARRAY_GET(type)                                         \
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
    }

/**
 * Set array's element to a new value and save old in <dest> if present
 **/
#define DYNAMIC_ARRAY_SET(type)                                         \
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
    }

#define DYNAMIC_ARRAY_INSERT(type)                                      \
    Status DynamicArray_##type##_insert (DynamicArray_##type *me, size_t index, type val) { \
        Status status = FAIL;                                           \
                                                                        \
        if ((me != NULL) && (index <= me->_length)) {                   \
            /* check if we have enough memory front */                  \
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
    }

#define DYNAMIC_ARRAY_REMOVE(type)                                      \
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



#define DYNAMIC_ARRAY(type)                     \
    DYNAMIC_ARRAY_T(type)                       \
    DYNAMIC_ARRAY_INIT(type)                    \
    DYNAMIC_ARRAY_INIT_2(type)                  \
    DYNAMIC_ARRAY_INIT_3(type)                  \
    DYNAMIC_ARRAY_DEINIT(type)                  \
    DYNAMIC_ARRAY_CREATE(type)                  \
    DYNAMIC_ARRAY_CREATE_2(type)                \
    DYNAMIC_ARRAY_DESTROY(type)                 \
    DYNAMIC_ARRAY_RESIZE(type)                  \
    DYNAMIC_ARRAY_COPY(type)                    \
    DYNAMIC_ARRAY_INIT_COPY(type)               \
    DYNAMIC_ARRAY_LENGTH(type)                  \
    DYNAMIC_ARRAY_CAPACITY(type)                \
    DYNAMIC_ARRAY_SIZE(type)                    \
    DYNAMIC_ARRAY_GET(type)                     \
    DYNAMIC_ARRAY_SET(type)                     \
    DYNAMIC_ARRAY_INSERT(type)                  \
    DYNAMIC_ARRAY_REMOVE(type)


#endif // __DYNAMIC_ARRAY_H__
