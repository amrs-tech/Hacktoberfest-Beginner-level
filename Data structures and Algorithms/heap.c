#include<stdio.h>
void read_array(int * array, int n)
{
  for(i=0;i<n;i++)
  {
    scanf("%d",&array[i]);
   }
 }
 void display_array(int * array, int n)
 {
  for(i=0;i<n;i++)
	{
			printf("%d",array[i]);
		}
	}
	void swap(int *a , int *b)
	{
			temp=*a;
			*a=*b;
			*b=temp;
		}
		void heapify(int * array, int n, int position)
		{
			int i=position;
			int j=2*i;
			int flag=0;
			while(j<=n && !flag)
			{
				if(j<n && array[j+1]>array[j])
				{
					++j;
				}
				if(array[j]>array[i])
				{
						swap(&array[j],&array[i];
						i=j;
						j=2*i;
				}
				else
				{
					flag=1;
				}
			}
			void insert(int* array , int n)
			{
					for(int i=n/2;i>=1;i--);
					{
							heapify(array,n,i)
					}
				}
			void delete_max(int *array, int n)
			{
					int max;
					max=array[1];
					array[1]=array[n];
					n--;
					heapify(array,n);
					return max;
				}
				int main()
				{
						#define MAX 100
						int array[MAX];
						printf("enter the number of elements");
						int n;
						scanf("%d",&n);
						read_array(array,n);
						display_array(arrray,n);
						insert(array,n);
						printf("after heapifying\n");
						display_array(array,n);
						printf("the deleted element is %d\n",delete_max(array,n);
						printf("after deletion");
						display_array(array,n);
					}
		
			
