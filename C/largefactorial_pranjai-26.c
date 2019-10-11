#include<stdio.h>
int main()
{
	int t;   \\Number of test cases.
	scanf("%d",&t);
	while(t--)
	{
		int n,k=0,c,i,j,temp;
		scanf("%d",&n);   //Number whose factorial has to be calculated.
		int a[17000]={0};
		for(i=n;i>0;i=i/10)
		{
			a[k]=i%10;  //Storing that number in an array in reverse order.   
			k++;
		}
		for(i=2;i<n;i++)
		{
			c=0;
			for(j=0;j<17000;j++)
			{
				temp=(a[j]*i+c); //Calculating factorial
				a[j]=temp%10;
				c=temp/10;
			}
		}
		for(i=17000-1;i>=0;i--)
		{
			if(a[i]!=0)
				break;
		}
		for(j=i;j>=0;j--)
			printf("%d",a[j]);  //Printing answer in reverse order as we stored number in reverse order.
		printf("\n");
	}
	return 0;
}

		

