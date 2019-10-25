/**
 * @author Michael Pacheco
 * @date 2019/10/16
 *
 * This file contains the definition of a Generic Linked List Abstract Data Type.
 * This ADT can storage <b>any</b> possible data type in C - <em>including user defined types</em>.
 * */

#ifndef GENERIC_LINKED_LIST_GCLL_H
#define GENERIC_LINKED_LIST_GCLL_H


#include <limits.h>
#include <stddef.h>
#include <stdbool.h>

#define GCLL_HEAD (UINT_MAX - 1)     ///< Flag used to insert/remove data from head (left)
#define GCLL_TAIL (UINT_MAX)          ///< Flag used to insert/remove data from tail (right)
#define GCLL_OK 1                     ///< Flag used to indicate operation success
#define GCLL_ERROR 0                  ///< Flag used to indicate operation failure

struct LinkedList;
struct Cell;
typedef struct LinkedList LinkedList;
typedef struct Cell Cell;

/**
 * This structure stores pointer for the head and the tail of the list, also it's size.
 * */
struct LinkedList {
    Cell *head;    ///< A pointer for the head cell.
    Cell *tail;    ///< A pointer for the tail cell.
    size_t size;   ///< The current number of stored elements.
};


/**
 * This structure stores information about the data that will be stored into the list.
 * */
struct Cell {
    void* data;          ///< A pointer to the data.
    Cell *next;          ///< A pointer to the next cell.
    Cell *prev;          ///< A pointer to the previous cell.
};


/**
 * Create an empty list.
 * @return A pointer to an empty list. If memory allocation fails it returns NULL.
 * */
LinkedList* GCLL_Create ();


/**
 * Clear the list and deallocate the memory. Set the pointer to NULL for security purpose.
 * @param pplist a address of a pointer to a list.
 * @param cleanup a pointer to a function that will be called for each data stored in the given list.
 * */
void GCLL_Destroy(LinkedList **pplist, void (*cleanup)(void *));


/**
 * Insert a data into the given list.
 * @param list the list in which the data will be inserted.
 * @param pos the position in which the data will be inserted.
 *        Use the GCLL_HEAD to insert into the list head (left) and GCLL_TAIL to insert into the list tail (right).
 * @retval GCLL_OK if success
 * @retval GCLL_ERROR if failure
 * */
unsigned GCLL_Push(LinkedList *list, unsigned pos, void *data);


/**
 * Remove data into the given list.
 * @param list the list in which the data will be removed.
 * @param pos the position in which the data will be removed.
 *        Use the GCLL_HEAD to remove into the list head (left) and GCLL_TAIL to insert into the list tail (right).
 * @param data a pointer that will receive the removed data from the list.
 * @retval GCLL_OK if success.
 * @retval GCLL_ERROR if failure.
 * */
unsigned GCLL_Pop(LinkedList *list, unsigned pos, void **data);


/**
 * Retrieve a data into the given list.
 * @param list the list in which the data will be retrieved.
 * @param pos the position in which the data will be retrieved.
 *        Use the GCLL_HEAD to get the list head (left) and GCLL_TAIL to get the list tail (right).
 * @param data address of a pointer that will receive the data of the removed element from the list.
 * @retval GCLL_OK if success.
 * @retval GCLL_ERROR if failure.
 * */
unsigned GCLL_Get(const LinkedList *list, unsigned pos, void **data);


/**
 * Check if the given list is empty.
 * @param list the list to check.
 * @return true if the list is empty, false otherwise.
 * */
bool GCLL_IsEmpty(const LinkedList *list);


/**
 * Sort the given list using quick sort.
 * @param list the list to be sorted.
 * @param compare a pointer to a function used to decide which data comes before and after.
 *        This function must return -1 if x must come before y. 1 if x must come after y. 0 if whatever.
 * @return the same pointer as @param list.
 * */
unsigned GCLL_Sort(LinkedList *list, int (*compare)(const void *, const void *));


/**
 * Call a given function passing each element in the list.
 * @param list the list to be iterated.
 * @param f a pointer to a function that will be called for each element in the list.
 * */
// TODO pass index to f
void GCLL_ForEach(const LinkedList *list, void (*f)(void *data));


/**
 * Returns the number of elements in the list.
 * @param list the list to check size.
 * @return the number of elements of the list.
 * */
size_t GCLL_GetSize(const LinkedList *list);

#endif //GENERIC_LINKED_LIST_GCLL_H
