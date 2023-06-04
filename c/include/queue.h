#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>
#include <stdint.h>


#define DATA_TYPE char
#define MEM_REALLOC_FACTOR 2
//#define


enum Status_e {
    SUCCESS = 0,
    FAIL = -1
};


struct Queue_s {
    DATA_TYPE *data;
    size_t length;      /// number of elements in a queue
    size_t capacity;    /// number of buckets for elements in a queue
    size_t head;
    size_t tail;
};


typedef struct Queue_s Queue;
typedef enum Status_e Status;


void Queue_init (Queue *me);
void Queue_init_2 (Queue *me, size_t capacity);
void Queue_deinit (Queue *me);

size_t Queue_length (const Queue *me);
size_t Queue_capacity (const Queue *me);
Status Queue_resize (Queue *me, size_t newCap);

Status Queue_add (Queue *me, DATA_TYPE val);
Status Queue_remove (Queue *me, DATA_TYPE *dest);

Status Queue_read(const Queue *me, DATA_TYPE *dest);


#endif // QUEUE_H_
