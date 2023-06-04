//#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/internal/assert.h>


#include "dynamic_matrix.h"


/* DYNAMIC_MATRIX_T(int) */
/* DYNAMIC_MATRIX_T(char) */


void testSetup (void) {
    //
}

void testTeardown (void) {
    //
}


TestSuite(dynamic_matrix, .init = testSetup, .fini = testTeardown);


Test (dynamic_matrix, create) {
    /* cr_expect(DynamicMatrix_int_init(NULL) == 0); */
    /* cr_expect(DynamicMatrix_char_init(NULL) == 0); */
}
