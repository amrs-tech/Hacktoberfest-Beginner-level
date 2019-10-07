#include"stdio.h"
#include"conio.h"
int main()
{
    int Size,i,j,list[10],smallest,current,walker;
    printf("Enter the number of elements & elements\n");
    scanf("%d",&Size);
    for(j=0;j<Size;j++)
            scanf("%d",&list[j]);
    printf("Before Sort:\n");
        for(j=0;j<Size;j++)
            printf("%d\t",list[j]);
        for(i = 0;i<Size-1;i++)
        {
            smallest = i;
            walker = smallest + 1;
            while(walker <= Size)
            {
                if(list[walker] < list[smallest])
                    smallest = walker;
                walker++;
            }
            current = list[i];
            list[i] = list[smallest];
            list[smallest] = current;
        }

        printf("\nAfter Sort:\n");
        for(j=0;j<Size;j++)
            printf("%d\t",list[j]);

}
