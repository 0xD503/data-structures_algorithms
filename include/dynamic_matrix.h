#ifndef __DYNAMIC_MATRIX_H__
#define __DYNAMIC_MATRIX_H__

#include "dynamic_array.h"


#define DYNAMIC_MATRIX_T(type)                      \
    typedef struct {                                \
        size_t _rowsNum, _columnsNum;               \
        DynamicArray_DynamicArray_##type _mat;      \
    } DynamicMatrix_##type;

#define DYNAMIC_MATRIX_INIT(type)                                   \
    int DynamicMatrix_##type##_init (DynamicMatrix_##type *me) {    \
        int status = FAIL;                                          \
                                                                    \
        if (me != NULL) {                                           \
            me->_rowsNum = 0;                                       \
            me->_columnsNum = 0;                                    \
            /* DynamicArray_int(me->_mat); */     \
        }                                                           \
                                                                    \
    end:                                                            \
        return (status);                                            \
    }



#define DYNAMIC_MATRIX(type)                        \
    DYNAMIC_MATRIX_T(type)

/* #define DYNAMIC_MATRIX_T(type)                                      \ */
/*     typedef struct {                                                \ */
/*         /\* DYNAMIC_ARRAY_T(type) *\/                                                     \ */
/*     } DynamicMatrix_##type;                                         \ */
/*                                                                     \ */
/*     int DynamicMatrix_##type##_init (DynamicMatrix_##type *me) {    \ */
/*         int status = -1;                                            \ */
/*                                                                     \ */
/*         if (me != NULL) {                                           \ */
/*                                                                     \ */
/*         }                                                           \ */
/*                                                                     \ */
/*         return (status);                                            \ */
/*     }                                                               \ */

//struct DynamicMatrix {
    //DynamicArray *matrix;
    //size_t rows;
    //size_t columns;
    //size_t maxRows;
    //size_t maxColumns;
//};


#endif // __DYNAMIC_MATRIX_H__
