#include "linked_list.h"


struct LinkedListNode_s {
    LIST_NODE_DATA_TYPE data;
    struct LinkedListNode_s *previous, *next;
};

struct LinkedList_s {
    struct LinkedListNode_s dummyNode;
    //struct LinkedListNode_s head, tail;
    size_t length;
}


typedef struct LinkedList_s LinkedList;


void construct (LinkedList *me) {
    me->dummyNode.next = &me->dummyNode;
    me->dummyNode.previous = &me->dummyNode;
    me->length = 0;
}

void destruct (LinkedList *me) {
    /// delete
    /// and
    me->length = 0;
}


LIST_NODE_DATA_TYPE get (const size_t i) {
    //
}

bool set (const size_t i, const LIST_NODE_DATA_TYPE data) {
    //
}


bool add (const size_t i, const LIST_NODE_DATA_TYPE data) {
    //
}

bool remove (const size_t i) {
    //
}
