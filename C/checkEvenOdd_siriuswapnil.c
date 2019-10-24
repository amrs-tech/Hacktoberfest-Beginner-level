#include<stdio.h>

void main()
{
    //Ask the user for a number
    int num;
    printf("Enter the number you have to check: \n");
    scanf("%d",&num);
    //Check for even number
    if(num%2==0)
    {
        printf("The number %d is even\n",num);
    }
    //Check for odd number
    else
    {
        printf("The number %d is odd\n",num);
    }
  
}