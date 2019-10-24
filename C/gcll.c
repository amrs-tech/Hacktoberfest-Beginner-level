/**
 * @author Michael Pacheco
 * @date 2019/10/16
 *
 * This file contains the implementations of a Generic Linked List Abstract Data Type.
 * This ADT can storage <b>any</b> possible data type in C - <em>including user defined types</em>.
 * */

#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>
#include "gcll.h"

/**
 * Allocate a single cell.
 * @param prev the prev cell.
 * @param next the next cell.
 * @param data the data of new cell.
 * @return a pointer to the new cell.
 * */
static Cell* allocateCell (Cell *prev, Cell *next, void *data);

/**
 * Insert the first element into the list.
 * @param list the list that data will be inserted.
 * @param data the data that will be inserted
 * @retval GCLL_OK if success.
 * @retval GCLL_ERROR if failure
 * */
static unsigned insertFirstElement(LinkedList *list, void *data);

/**
 * Get the cell in a given position.
 * @param list the list that contains the requested cell
 * @param pos the position of the requested cell.
 * Use GCLL_HEAD to retrieve the first cell in the list, GCLL_TAIL to retrieve the last element in the list.
 * If pos doesn't exists in the list a NULL pointer will be returned.
 * @return a pointer to the requested cell.
 * */
static Cell *getCell(const LinkedList *list, unsigned int pos);

LinkedList *GCLL_Create() {
    LinkedList *list;
    if ((list = (LinkedList*) malloc(sizeof(LinkedList))) == NULL)
        return NULL;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void GCLL_Destroy(LinkedList** const pplist, void (*const cleanup)(void *)) {
    LinkedList *const list = *pplist;

    if (!GCLL_IsEmpty(list)) {
        Cell *cell = list->head, *next;
        do {
            next = cell->next;
            if (cleanup)
                cleanup(cell->data);
            free(cell);
            cell = next;
        } while (next);
    }

    free(list);
    *pplist = NULL;
}

unsigned GCLL_Push(LinkedList *list, unsigned pos, void *data) {
    if ((pos != GCLL_HEAD && pos != GCLL_TAIL) && (pos > GCLL_GetSize(list)))
        return GCLL_ERROR;

    if (GCLL_IsEmpty(list))
        return insertFirstElement(list, data);

    if (pos == GCLL_GetSize(list))
        pos = GCLL_TAIL;
    else if (pos == 0)
        pos = GCLL_HEAD;

    Cell *newCell = allocateCell(NULL, NULL, data);
    if (!newCell)
        return GCLL_ERROR;

    switch (pos) {
        case GCLL_HEAD:
            newCell->next = list->head;
            list->head->prev = newCell;
            list->head = newCell;
            break;
        case GCLL_TAIL:
            newCell->prev = list->tail;
            list->tail->next = newCell;
            list->tail = newCell;
            break;
        default: {
            Cell *cell = getCell(list, pos);
            newCell->prev = cell->prev;
            newCell->next = cell;
            cell->prev->next = newCell;
            cell->prev = newCell;
        }
            break;
    }

    list->size++;
    return GCLL_OK;
}

unsigned GCLL_Pop(LinkedList *const list, unsigned pos, void **const data) {
    if (GCLL_IsEmpty(list))
        return GCLL_ERROR;
    if ((pos != GCLL_HEAD && pos != GCLL_TAIL) && (pos >= GCLL_GetSize(list)))
        return GCLL_ERROR;
    if (pos == 0)
        pos = GCLL_HEAD;
    else if (pos == GCLL_GetSize(list) - 1)
        pos = GCLL_TAIL;

    if (GCLL_GetSize(list) == 1) {
        if (data)
            *data = list->head->data;
        free(list->head);
        memset(list, 0, sizeof(LinkedList));
        return GCLL_OK;
    }

    // The cell to be removed
    Cell *cell;

    switch (pos) {
        case GCLL_HEAD:
            cell = list->head;
            list->head = cell->next;
            list->head->prev = NULL;
            break;
        case GCLL_TAIL:
            cell = list->tail;
            list->tail = cell->prev;
            list->tail->next = NULL;
            break;
        default:
            cell = getCell(list, pos);
            Cell *prev = cell->prev;
            Cell *next = cell->next;
            prev->next = next;
            next->prev = prev;
            break;
    }

    if (data)
        *data = cell->data;
    free(cell);
    list->size--;
    return GCLL_OK;
}

inline size_t GCLL_GetSize(const LinkedList *list) {
    return list->size;
}

inline bool GCLL_IsEmpty(const LinkedList *list) {
#ifdef GCLL_DEBUG
    if (list->size == 0)
        assert((size_t)(list->head == list->tail) &
               (size_t)(list->head == NULL));
#endif
    return list->size == 0;
}

inline void GCLL_ForEach(const LinkedList *list, void (*const f)(void *)) {
    for (Cell *cell = list->head; cell != NULL; cell = cell->next)
        f(cell->data);
}

unsigned GCLL_Get(const LinkedList *list, unsigned pos, void **const data) {
    Cell *cell;
    if (!(cell = getCell(list, pos)))
        return GCLL_ERROR;
    if (data)
        *data = cell->data;
    return GCLL_OK;
}

void a(Cell *a, Cell *b, int (*compare)(const void *, const void *)) {
    void *temp;
    if (compare(a->data, b->data) > 0) {
        temp = a->data;
        a->data = b->data;
        b->data = temp;
    } else if (compare(a->data, b->data) < 0) {
        temp = b->data;
        b->data = a->data;
        a->data = temp;
    }
}

unsigned GCLL_Sort(LinkedList *list, int (*compare)(const void *, const void *)) {
    void **array = (void**) malloc(sizeof(void *) * GCLL_GetSize(list));
    if (!array)
        return GCLL_ERROR;

    Cell *cell = list->head;
    for (size_t i = 0; i < GCLL_GetSize(list); i++, cell = cell->next)
        array[i] = cell->data;

    qsort(array, GCLL_GetSize(list), sizeof(void *), compare);

    cell = list->head;
    for (size_t i = 0; i < GCLL_GetSize(list); i++, cell = cell->next)
        cell->data = array[i];
    free(array);
    return GCLL_OK;
}

Cell* allocateCell (Cell* const prev, Cell* const next, void* const data) {
    Cell *newCell = (Cell*) malloc(sizeof(Cell));
    if (!newCell)
        return NULL;
    newCell->prev = prev;
    newCell->next = next;
    newCell->data = data;
    return newCell;
}

unsigned insertFirstElement(LinkedList *list, void *data) {
    Cell *newCell = allocateCell(NULL, NULL, data);
    if (!newCell) return GCLL_ERROR;
    list->head = list->tail = newCell;
    list->size = 1;
    return GCLL_OK;
}

Cell *getCell(const LinkedList *list, unsigned int pos) {
    if (pos < 0 || pos >= GCLL_GetSize(list))
        return NULL;

    if (pos == 0)
        pos = GCLL_HEAD;
    else if (pos == GCLL_GetSize(list) - 1)
        pos = GCLL_TAIL;

    switch (pos) {
        case GCLL_HEAD:
            return list->head;
        case GCLL_TAIL:
            return list->tail;
        default:
            break;
    }

    int count = 0;
    Cell *cell;
    for (cell = list->head; cell != NULL && count < pos; cell = cell->next, count++);
    return cell;
}
