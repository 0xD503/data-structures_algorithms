#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stddef.h>

#define LIST_NODE_DATA_TYPE char


LIST_NODE_DATA_TYPE get (const size_t i);
bool set (const size_t i, const LIST_NODE_DATA_TYPE data);

bool add (const size_t i, const LIST_NODE_DATA_TYPE data);
bool remove (const size_t i);


#endif // __LINKED_LIST_H__
