//implemented Linear Search using C 
#include<stdio.h>
#include<stdlib.h>

int linear_search(int* a, int n, int c)//linear search function
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i]==c)
			return i;
	}
	return -1;
}

int main()
{
	int n, i, c, b;
	int* a;
	printf("Enter size: ");
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*n);
	printf("Enter elements:-\n");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	printf("Enter element to be found: ");
	scanf("%d",&c);
	if((b = linear_search(a, n, c))>=0)
		printf("Element found at %d\n", b);
	else
		printf("Element not found\n");	
	return 0;
}
