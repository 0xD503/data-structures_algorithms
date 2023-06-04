#include "queue.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void Queue_init (Queue *me) {
    const size_t initCap = 0;
    me->data = calloc(initCap, sizeof(DATA_TYPE));
    if (me->data != NULL) {
        me->capacity = initCap;
        me->head = me->tail = 0;
        me->length = me->head - me->tail;
    }
    else {
        perror("Failed to construct queue");
    }
}

void Queue_init_2 (Queue *me, size_t capacity) {
    me->data = calloc(capacity, sizeof(DATA_TYPE));
    if (me != NULL) {
        me->capacity = capacity;
        me->head = me->tail = 0;
        me->length = me->head - me->tail;
    }
    else {
        perror("Failed to construct queue");
    }
}

void Queue_deinit (Queue *me) {
    if (me != NULL) {
        free(me);
        me = NULL;
    }
    me->capacity = 0;
    me->head = me->tail = 0;
    me->length = me->head - me->tail;
}


size_t Queue_length (const Queue *me) {
    return (me->length);
}

size_t Queue_capacity (const Queue *me) {
    return (me->capacity);
}

Status Queue_resize (Queue *me, size_t newCap) {
    Status status = FAIL;

    if (me != NULL) {
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

Status Queue_add (Queue *me, DATA_TYPE val) {
    Status status = FAIL;

    if (me != NULL) {
        if (me->length >= me->capacity) {
            size_t newCap = (me->capacity + 1) * MEM_REALLOC_FACTOR;
            Status st = Queue_resize(me, newCap);
            if (st != SUCCESS) {
                goto end;
            }
        }
        me->data[me->length++] = val;
        status = SUCCESS;
    }

end:
    return (status);
}

/* Status Queue_remove (Queue *me, DATA_TYPE *dest) { */
/*     Status status = FAIL; */

/*     if (me != NULL) { */
/*         if (me->length > 0) { */
/*             /\* if (dest != NULL) { *\/ */
/*             /\*     *dest = me->data[me->length]; *\/ */
/*             /\* } *\/ */
/*             /\* if (--me->length < (me->capacity / (MEM_REALLOC_FACTOR + 1))) { *\/ */
/*             /\*     Status st = Queue_resize(me, me->length + 1); *\/ */
/*             /\*     if (st != SUCCESS) { *\/ */
/*             /\*         goto end; *\/ */
/*             /\*     } *\/ */
/*             /\* } *\/ */
/*             /\* status = SUCCESS; *\/ */
/*         } */
/*     } */

/* end: */
/*     return (status); */
/* } */
