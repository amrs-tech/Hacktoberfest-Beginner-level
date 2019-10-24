/* C program to print the following pattern:
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *               */


#include <stdio.h>
int main()
{
    int i, space, rows, k=0;
    printf("Enter number of rows: ");// Input for number of vertical rows
    scanf("%d",&rows);
    for(i=1; i<=rows; ++i, k=0)// loop for number of rows
    {
        for(space=1; space<=rows-i; ++space)// Loop for number of columns
        {
            printf("  ");
        }
        while(k != 2*i-1)//Loop for spacin between to consecutive symbols
        {
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    
    return 0;
}
