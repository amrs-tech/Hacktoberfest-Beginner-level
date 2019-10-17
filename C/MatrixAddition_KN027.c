#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,a[50][50],b[50][50],c[50][50],r1,r2,c1,c2;
	clrscr();
	printf("Enter the row & column size of matrix 1:");
	scanf("%d %d",&r1,&c1);
	printf("Enter the row & column size of matrix 2:");
	scanf("%d %d",&r2,&c2);
	printf("\nEnter matrix1\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter matrix2\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}                         //accepting matrix 1,2
	printf("Entered matrices:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d \t",b[i][j]);
		}
		printf("\n");
	}                            //displaying in matrix format

	if(r1==r2 && c1==c2)
	{
		printf("Addition possible. Added matrix is displayed below\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d \t",c[i][j]);
			}
			printf("\n");
		}

	}
	else
		printf("Addition of entered matrices is not possible");
return 0;
}
