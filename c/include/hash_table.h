#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "linked_list.h"


#define TYPENAME_1 LinkedList
//#define TYPENAME_2


struct HashTable_s {
    TYPENAME_1 *table;
    size_t length;
};


typedef struct HashTable_s HashTable;


//


#endif // __HASH_TABLE_H__
