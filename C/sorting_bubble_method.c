//Bubble Sort
#include<stdio.h>
void bubble_sort(int a[],int n)
{
	int i,t,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
void main()
{
	int a[5];
	int i;
	printf("Enter elements\n");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);	
	bubble_sort(a,5);
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
}