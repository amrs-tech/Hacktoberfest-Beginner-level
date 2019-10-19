#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gcll.h"

void printElement(void *data) {
    printf("%3d ", *(int *) data);
}

int compare(void **a, void **b) {
    int *p1 = (int*) *a;
    int *p2 = (int*) *b;
    int x = *p1;
    int y = *p2;
    return x - y;
}

int main() {
    srand(time(NULL));

    LinkedList *list = GCLL_Create();

    int n = 16;

    for (size_t i = n; i > 0; --i) {
        int *x = (int*) malloc(sizeof(int));
        *x = rand() % 16;
        GCLL_Push(list, GCLL_TAIL, x);
    }

    GCLL_ForEach(list, printElement);
    puts("");
    GCLL_Sort(list, (int (*)(const void *, const void *)) compare);
    GCLL_ForEach(list, printElement);

    GCLL_Destroy(&list, free);
    return 0;
}