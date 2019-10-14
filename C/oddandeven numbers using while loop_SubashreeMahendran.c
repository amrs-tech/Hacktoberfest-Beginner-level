include<stdio.h>
#include<conio.h>
void main()
{
 int n,last;
 clrscr();

 printf("\n Enter Last Number : ");
 scanf("%d",&last);

 //While Loop

 //Code For Even Number List
 printf("\n Even Number List :\n ");

 n=2;
 while(n<=last)
 {
  printf(" %d",n);
  n=n+2;
 }

 //Code For Odd Number List
 printf("\n\n Odd Number List :\n ");

 n=1;
 while(n<=last)
 {
  printf(" %d",n);
  n=n+2;
 }

 getch();

}