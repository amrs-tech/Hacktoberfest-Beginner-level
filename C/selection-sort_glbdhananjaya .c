#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 5

void selection_sort(int[]);

int main() {
    int arr_sort[MAX_SIZE], i;

    printf("Simple Selection Sort Example - Functions and Array\n");
    printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++)
        scanf("%d", &arr_sort[i]);

    printf("\nYour Data   :");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("\t%d", arr_sort[i]);
    }

    selection_sort(arr_sort);
    getch();

}

void selection_sort(int fn_arr[]) {
    int i, j, a, t, p;

    for (i = 0; i < MAX_SIZE; i++) {
        p = i;
        for (j = i; j < MAX_SIZE; j++) {
            if (fn_arr[p] > fn_arr[j])
                p = j;
        }

        if (p != 1) {
            //Swapping Values
            t = fn_arr[i];
            fn_arr[i] = fn_arr[p];
            fn_arr[p] = t;
        }
        printf("\nIteration %d : ", i);
        for (a = 0; a < MAX_SIZE; a++) {
            printf("\t%d", fn_arr[a]);
        }
    }

    printf("\n\nSorted Data :");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("\t%d", fn_arr[i]);
    }
}
