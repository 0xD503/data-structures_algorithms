#ifndef __SET_H__
#define __SET_H__

//


#define TYPENAME char


enum ContStatus_e {
    OK = 0,
    FAILED = -1,
    NOT_ENOUGH_MEM = -2
};


/*
 * Set is sorted container of unique elements
 **/
struct Set_s {
    //
};


typedef struct Set_s Set;
typedef enum ContStatus_e ContStatus;


ContStatus find (Set *me, TYPENAME *dest);

/*
 * Adds <elem> to set <me>
 *
 * Return values:
 *   ContStatus_e::OK - element was succesfully added to the set
 *   ContStatus_e::FAILED - element wasn't added to the set because it already contains
 *   ContStatus_e::NOT_ENOUGH_MEM - not enough memory
 */
ContStatus add (Set *me, TYPENAME elem);

/*
 * Removes <elem> from set <me>
 *
 * Return values:
 *   ContStatus_e::OK - element was succesfully removed from the set
 *   ContStatus_e::FAILED - element wasn't removed because it isn't in the set
 */
ContStatus remove (Set *me, TYPENAME elem);


#endif // __SET_H__
