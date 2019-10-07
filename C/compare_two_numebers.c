// this code can compare two numbers
#include <stdio.h>
int main()
{
    float a,b;
    scanf("%f%f",&a,&b); //input two space seperated numbers
    
    // comparing two numbers
    if(a>b)
    {
        printf("bigger number is %f",a);
    }
    else if(a<b)
    {
        printf("bigger number is %f",b);
    }
    else if(a==b)
    {
        printf("Both numbers are equal");
    }    
    return 0;
}