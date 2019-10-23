#include <stdio.h>
#include <stdlib.h>
//binary recursive
int main()
{
    int key;
    int a[] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Hello world!\n");
    printf("\nBinary Search Program Using Recursive Method.\n");

    printf("\nEnter the number to be searched:");
    scanf("%d", &key);
    int result = RBinSearch(a, 0, n-1, key);
    if(result==-1)
        printf("\nElement Not Found!\n");
    else
        printf("\nElement Found at position %d.\n", result + 1);
    return 0;
}

int RBinSearch(int a[], int l, int h, int key)
{
    if(l==h)
    {
        if(key==a[l])
            return l;
        else
            return -1;
    }
    else
    {
        int mid = (l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinSearch(a, l, mid-1, key);
        else if(key>a[mid])
            return RBinSearch(a, mid+1, h, key);
        else
            return -1;
    }
}
