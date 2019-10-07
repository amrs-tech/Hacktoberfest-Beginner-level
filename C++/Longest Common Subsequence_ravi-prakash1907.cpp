//Longest Common Subsequence
//Author: Ravi Prakash (https://github.com/ravi-prakash1907)

//Longest Common Sub-sequence  (LCS)

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

  char b[20][20];
  char c[20][20];  //c[m+1][n+1]
  char *seq;
  int index = 0;


void fillSeq(char *y, int m, int n)
{
   while(b[m][n] != ' ')
   {
     switch(b[m][n])
     {
       case '\\':  seq[index++] = y[n-1];
		   m--;
		   n--;
		   break;

       case '|':   m--;
		   break;

       case '-':   n--;
		   break;

       default:    break;
     }
   }
}

void printLCS(char *x, char *y, int row, int col)
{
  cout<<"------------------\n\nLCS:\t"
      <<"{   ";
  fillSeq(y, row-1, col-1);
  for (int i = index-1; i > -1; i--) {
    cout<<seq[i]<<"   ";
  }
  cout<<"}";
}

void printTable(char *x, char *y, int row, int col)
{
  clrscr();
  cout<<"\nThe graph for given Sequences:\n\n";

  cout<<"\tY\t";
  for(int i=0; i<col; i++)
    cout<<y[i]<<"\t";
  cout<<endl<<endl;

  for (i = 0; i < row; i++) {
    if(i==0)
      cout<<"X\t";
    else
      cout<<x[i-1]<<"\t";

    for (int j = 0; j < col; j++) {
      cout<<c[i][j]<<b[i][j]<<"\t";
    }
    cout<<endl<<endl;
  }
  printLCS(x, y, row, col);
}

void LCS(char *x, char *y){
  int m, n;
  m = strlen(x);
  n = strlen(y);
  seq = new char[n];

  for(int i=0; i<m+1; i++)
  {
    c[i][0] = '0';
    b[i][0] = ' ';
  }
  for(int j=0; j<n+1; j++)
  {
    c[0][j] = '0';
    b[0][j] = ' ';
  }

  for(i=1; i<m+1; i++)
    for(j=1; j<n+1; j++)
    {
      if(x[i-1] == y[j-1]){
	c[i][j]=c[i-1][j-1] + 1;
	b[i][j] = '\\';
      }
      else if(c[i-1][j] >= c[i][j-1]){
	c[i][j]=c[i-1][j];
	b[i][j] = '|';
      }
      else{
	c[i][j]=c[i][j-1];
	b[i][j] = '-';
      }
    }
    printTable(x, y, m+1, n+1);

}

void main()
{
  clrscr();
   int m, n;
   char y[10], x[10];
   cout<<"\nEnter the array \'X\' and \'Y\': \n\n";
   gets(x);
   gets(y);

   LCS(x, y);

  getch();
}
