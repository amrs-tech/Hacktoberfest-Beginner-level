#include<stdio.h>

void main()
{   
    int n,r;
    int sum=0;
    printf("Enter A Number:");   //Ask User for Number
    scanf("%d",&n);
    while(n>0)
    {
        r=n%10;             //Finding digits one by one
        sum+=r;             //Perform Sum of Digits
        n/=10;              //Dividing Numbers one by one
    }
    printf("\nThe Sum of digits of %d is %d",n,sum);        //Printing the sum
  
}