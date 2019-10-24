// this code can print pascals triangle upto any number of rows
#include<stdio.h>
int main()
{
    int rows,k,j,i,coeff;
    scanf("%d",&rows);//input how many number of rows you want in a pascal triangle
    for(i=0;i<rows;i++)
    {
        printf("\n");
        for(j=0;j<rows-1-i;j++)
        {
            printf(" ");
        }
        for(k=0;k<=i;k++)
        {
        if(i==0 || k==0)
        coeff=1;
        else
        coeff=coeff*(i-k+1)/k;//property of pascals triangle
        printf("%d ",coeff);
        }
    }
    return 0;
}
