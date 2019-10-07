// program to search for an element in a sorted (increasing)  array with binary search algorithm
// Input provided at command prompt by user
// Time Complexity is O(logn)

#include<stdio.h>

int binarysearch (int size, int arr[size], int e) 
{ 
	int l = 0, r = size-1;
	while (l <= r) 
	{ 
		int m = (l + r)/2; 
		 
		if (arr[m] == e) 
			return m; 

		if (arr[m] < e) 
			l = m + 1; 

		else
			r = m - 1;
	       	
	} 

	return -1; 
} 

int main() 
{ 
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);	

	int array[n];
	printf("Enter the elements of array: ");
	for( int i=0 ; i<n ; i++)
		scanf("%d", array+i);

	int element;
	printf("Enter the element you want to search for: ");
	scanf("%d", &element);

	int index = binarysearch(n,array,element);
	if(index == -1)
		printf("Element is not present in array.\n");
	else
		printf("Element is present at index %d\n", index); 
	return 0; 
} 
