//WAP to perform Addition, Subtraction and multiplication of polynomials.
#include<stdio.h>
#include<math.h>
struct poly{					//Structure of a polynomial
    int coeff;
    double expo;
};

void Evaluate(struct poly* p, int n)		//Function To Evaluate Result of a polynomial
{
  double x,res=0;
  printf("Enter the Value of X:");
  scanf("%lf",&x);
  for(int i=0;i<=n;i++)
    res+=(p[i].coeff*pow(x,p[i].expo));
  printf("The Result is:%lf\n",res);

}

void input(struct poly* p,int n1)		//Function To Input the Polynomial
{


    printf("Enter the Polynomial:\n");
    for(int i=n1;i>=0;i--)
    {
        printf("Enter the Coefficient of '(x^%d)':",(n1-i));
        scanf("%d",&p[i].coeff);
        p[i].expo=n1-i;   }
}
void Display(struct poly* p,int n)	//Function to Display the polynomial
{
    for(int i=0;i<=n;i++)
    {
        printf("%d(x^%d)",p[i].coeff,(int)p[i].expo);
        if(i!=n)
        printf("+");
    }
    printf("\n");}
void ADDSUB(struct poly*p1,struct poly*p2,int n1,int n2,int s)//Function to add or subtract 2 //polynomials
{char ch;
  if(n1>n2)
    {
      struct poly sum[n1+1];
      for(int i=n2;i>=0;i--)
      {
        sum[i].coeff=p1[i].coeff+(s*p2[i].coeff);
        sum[i].expo=p1[i].expo;
      }
      for(int i=n2+1;i<=n1;i++)
      {
        sum[i].coeff=p1[i].coeff;
        sum[i].expo=p1[i].expo;
      }
      Display(sum,n1);
      printf("Do You Want to Evaluate?(y/n)");
      scanf("\n");
      scanf("%c",&ch);
      if(ch=='y'|| ch=='Y')
        Evaluate(sum,n1);


    }
    else{
      struct poly sum[n2+1];
      for(int i=n1;i>=0;i--)
      {
        sum[i].coeff=p1[i].coeff+(s*p2[i].coeff);
        sum[i].expo=p1[i].expo;

      }
      for(int i=n1+1;i<=n2;i++)
      {
        sum[i].coeff=p2[i].coeff;
        sum[i].expo=p2[i].expo;
      }
      Display(sum,n2);
      printf("Do You Want to Evaluate?(y/n)");
        scanf("\n");
      scanf("%c",&ch);
      if(ch=='y'|| ch=='Y')
        Evaluate(sum,n2);  }
}
void MUL(struct poly*p1,struct poly*p2,int n1,int n2)//Function to Find Multiplication of 2 //Polynomials
{
  int e,size=p1[0].expo+p2[0].expo;
  char ch;
  struct poly Multi[size+1];
  for(int i=0;i<=size;i++)
  {
    Multi[i].expo=i;
    Multi[i].coeff=0;
  }
  for(int i=n1;i>=0;i--)
  {
    for(int j=n2;j>=0;j--)
    {
      e=p1[i].expo+p2[j].expo;

      Multi[e].coeff+=(p1[i].coeff*p2[j].coeff);


    }
  }
  Display(Multi,size);
  printf("Do You Want to Evaluate?(y/n)\n");

scanf("\n");   scanf("%c",&ch);
  if(ch=='y'|| ch=='Y')
    Evaluate(Multi,size);


}

int main(){
    int n1,n2,ch;
    printf("Enter the degree of 1st polynomial:");
    scanf("%d",&n1);
    printf("Enter the degree of 2nd polynomial:");
    scanf("%d",&n2);
    struct poly p1[n1+1],p2[n2+1];
    input(p1,n1);
    input(p2,n2);
    do{	//Menu for user to Choose From
    printf("Choose:\n1.Display\n2.Add\n3.Subtract\n4.Multiply\n0.Exit\n");
    scanf("%d",&ch);
    switch (ch) {
      case 1:
      printf("Poly 1:");
      Display(p1,n1);
      printf("Poly 2:");
      Display(p2,n2);
      break;
      case 2:
      ADDSUB(p1,p2,n1,n2,1);
      break;
      case 3:
      ADDSUB(p1,p2,n1,n2,-1);
      case 4:
      MUL(p1,p2,n1,n2);
      break;

    }
  }while(ch!=0);
}
