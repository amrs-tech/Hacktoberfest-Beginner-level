#include<stdio.h>
void fact();
main()
{
 fact();

}
void fact()
{
 int i,n,p=1;
 scanf("%d",&n);
 i=n;
 do
 {
   p=p*i;
   i--;
 }
 while(i>=1);
  printf("%d",p);

}
