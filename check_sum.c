#include <stdio.h>
#include <stdlib.h>

void check_sum(int *arr,int sum,int length)
{
    int front = 0;
    int last = length-1;
    while(1)
    {
		  if(front>=last)
		  {
                printf("No elements found\n");
                break;
		  }
		  if(arr[front]+arr[last] == sum)
          {
                printf("Sum of %d,%d = %d",arr[front],arr[last],sum);
                break;
          }
		   else if(arr[front]+arr[last] > sum)
		   {
                last--;
		   }
		   else
		   {
                front++;
		   }
    }
}

int main()
{
    int arr[6]={1,7,9,11,15,17};
    int length = sizeof(arr)/sizeof(int);
    int sum = 18;
    check_sum(arr,sum,length);
}
