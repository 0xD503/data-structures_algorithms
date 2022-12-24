#include "dynamic_array.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void DynamicArray_init (DynamicArray *me) {
    if (me != NULL) {
        static const size_t initCap = 0;
        me->data = calloc(initCap, sizeof(DATA_TYPE));
        if (me->data != NULL) {
            me->capacity = initCap;
            me->length = 0;
        }
        else {
            perror("Failed to construct dynamic array");
        }
    }
}

void DynamicArray_init_2 (DynamicArray *me, size_t capacity) {
    if (me != NULL) {
        me->data = calloc(capacity, sizeof(DATA_TYPE));
        if (me->data != NULL) {
            me->capacity = capacity;
            me->length = 0;
        }
        else {
            perror("Failed to construct dynamic array");
        }
    }
}

void DynamicArray_deinit (DynamicArray *me) {
    if (me != NULL) {
        if (me->data != NULL) {
            free(me->data);
            me->data = NULL;
        }
        me->capacity = 0;
        me->length = 0;
    }
}


size_t DynamicArray_length (const DynamicArray *me) {
    size_t len = 0;

    if (me != NULL) {
        len = me->length;
    }

    return (len);
}

size_t DynamicArray_capacity (const DynamicArray *me) {
    size_t cap = 0;

    if (me != NULL) {
        cap = me->capacity;
    }

    return (cap);
}

size_t DynamicArray_size (const DynamicArray *me) {
    size_t size = 0;

    if (me != NULL) {
        size = DynamicArray_capacity(me) * sizeof(me->data[0]);
    }

    return (size);
}


Status DynamicArray_resize (DynamicArray *me, size_t newCap) {
    Status status = FAIL;

    if ((me != NULL) && (me->data != NULL)) {
        /// check if new capacity is more than the number of elements in array
        if (newCap > me->length) {
            DATA_TYPE *temp = (DATA_TYPE *) realloc(me->data, newCap * sizeof(DATA_TYPE));
            if (temp == NULL) {
                perror("Failed to reallocate memory");
                goto end;
            }
            me->data = temp;
            me->capacity = newCap;
            status = SUCCESS;
        }
    }

end:
    return (status);
}


Status DynamicArray_get (const DynamicArray *me, size_t index, DATA_TYPE *dest) {
    Status status = FAIL;

    if ((me != NULL) && (index < me->length)) {
        if (dest != NULL) {
            *dest = me->data[index];
            status = SUCCESS;
        }
    }

    return (status);
}

Status DynamicArray_set (DynamicArray *me, size_t index, DATA_TYPE val, DATA_TYPE *dest) {
    Status status = FAIL;

    if ((me != NULL) && (index < me->length)) {
        if (dest != NULL) {
            *dest = me->data[index];
        }
        me->data[index] = val;
        status = SUCCESS;
    }

    return (status);
}


Status DynamicArray_insert (DynamicArray *me, size_t index, DATA_TYPE val) {
    Status status = FAIL;

    if ((me != NULL) && (index <= me->length)) {
        /// check if we have enough memory first
        if (me->length >= me->capacity) {
            size_t newCap = (me->capacity + 1) * MEM_REALLOC_FACTOR;
            Status st = DynamicArray_resize(me, newCap);
            if (st != SUCCESS) {
                goto end;
            }
        }
        memmove(&me->data[index + 1], &me->data[index], me->length - index);
        me->data[index] = val;
        me->length++;
        status = SUCCESS;
    }

end:
    return (status);
}

Status DynamicArray_remove (DynamicArray *me, size_t index, DATA_TYPE *dest) {
    Status status = FAIL;

    if ((me != NULL) && (index < me->length)) {
        /// put the desired element to container
        if (dest != NULL) {
            *dest = me->data[index];
        }
        if ((me->length - 1) < (me->capacity / (MEM_REALLOC_FACTOR + 1))) {
            Status st = DynamicArray_resize(me, me->length + 1);
            if (st != SUCCESS) {
                goto end;
            }
        }
        memmove(&me->data[index], &me->data[index + 1], me->length-- - index - 1);
        status = SUCCESS;
    }

end:
    return (status);
}
