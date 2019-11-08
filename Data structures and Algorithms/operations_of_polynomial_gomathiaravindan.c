#include<stdio.h>
#include<stdlib.h>
struct node
{
    int power;
    int coeff;
    struct node* next;
};

struct node* temp1=NULL;
struct node* temp2=NULL;
struct node* temp3=NULL;
struct node* last4=NULL;
struct node* first4=NULL;
struct node* newnode1=NULL;
struct node* first1=NULL;
struct node* last1=NULL;
struct node* first2=NULL;
struct node* last2=NULL;
struct node* first3=NULL;
struct node* last3=NULL;
struct node* m=NULL;
struct node* n=NULL;
struct node* temp4=NULL;
struct node* newnode3=NULL;

struct node* createnode1(int x,int y)
{
    newnode1=(struct node*)malloc(sizeof(struct node));
    newnode1->power=x;
    newnode1->coeff=y;
    newnode1->next=NULL;
    return newnode1;
}
void insert1()
{
    int x,y,a;
    do
    {
    printf("Enter the degree and coefficient\n");
    scanf("%d%d",&x,&y);
    newnode1=createnode1(x,y);
    if(first1==NULL&&last1==NULL)
    {
        first1=newnode1;
        last1=newnode1;
    }
    else
    {
         last1->next=newnode1;
         last1=newnode1;
    }
    printf("To continue press 1\tTo exit press 0\n");
    scanf("%d",&a);
    }
    while(a!=0);
    sort1(first1);
}

void insert2()
    {
    int w,z,a;
    do
    {
    printf("Enter the degree and coefficient\n");
    scanf("%d%d",&w,&z);
    newnode1=createnode1(w,z);
    if(first2==NULL&&last2==NULL)
    {
        first2=newnode1;
        last2=newnode1;

    }
    else
    {
         last2->next=newnode1;
         last2->next=newnode1;
         last2=newnode1;
    }
    printf("To continue press 1\tTo exit press 0\n");
    scanf("%d",&a);
    }
    while(a==1);
    sort2(first2);
}

void add()
{
   int g=0;
   temp1=first1;
   temp2=first2;
   while(temp1!=NULL&&temp2!=NULL)
   {
    temp3=createnode1(0,0);
    if(temp1->power==temp2->power)
   {
    temp3->coeff=temp1->coeff+temp2->coeff;
    temp3->power=temp1->power;
    if(g!=0)
    last3->next=temp3;
    else
    first3=temp3;
    last3=temp3;
    g++;
    temp1=temp1->next;
    temp2=temp2->next;
    }
   else if(temp1->power>temp2->power)
   {
    temp3->coeff=temp1->coeff;
    temp3->power=temp1->power;
    if(g!=0)
    last3->next=temp3;
    else
    first3=temp3;
    last3=temp3;
    g++;
    temp1=temp1->next;
   }
   else
   {
    temp3->coeff=temp2->coeff;
    temp3->power=temp2->power;
    if(g!=0)
    last3->next=temp3;
    else
    first3=temp3;
    last3=temp3;
    g++;
    temp2=temp2->next;
    }
   }
   while(temp2==NULL&&temp1!=NULL)
   {
       temp3=createnode1(0,0);
       temp3->power=temp1->power;
       temp3->coeff=temp1->coeff;
       if(g!=0)
        last3->next=temp3;
       else
        first3=temp3;
        last3=temp3;
        g++;
        temp1=temp1->next;

   }
   while(temp1==NULL&&temp2!=NULL)
   {
       temp3=createnode1(0,0);
       temp3->power=temp2->power;
       temp3->coeff=temp2->coeff;
       if(g!=0)
        last3->next=temp3;
       else
        first3=temp3;
        last3=temp3;
        g++;
        temp2=temp2->next;

   }
   }

void sort1()
{
    temp4=first1;
    while(temp4!=NULL)
        {
            temp1=temp4;
            while(temp1!=NULL)
            {
                if(temp1->power>temp4->power)
                {
                    m=temp1->power;
                    temp1->power=temp4->power;
                    temp4->power=m;
                    n=temp1->coeff;
                    temp1->coeff=temp4->coeff;
                    temp4->coeff=n;

                }

                temp1=temp1->next;
             }
             temp4=temp4->next;
        }
        temp1=first1;
        while(temp1->next)
        {
            if(temp1->power==temp1->next->power)
              {
            temp1->coeff=temp1->coeff+temp1->next->coeff;
            temp1->next=temp1->next->next;
            }
             else
            temp1=temp1->next;
        }

}
void sort2()
{
     temp4=first2;
    while(temp4!=NULL)
        {
            temp1=temp4;
            while(temp1!=NULL)
            {
                if(temp1->power>temp4->power)
                {
                    m=temp1->power;
                    temp1->power=temp4->power;
                    temp4->power=m;
                    n=temp1->coeff;
                    temp1->coeff=temp4->coeff;
                    temp4->coeff=n;

                }
                temp1=temp1->next;
             }
             temp4=temp4->next;
        }
        temp1=first2;
        while(temp1->next)
        {
            if(temp1->power==temp1->next->power)
              {
            temp1->coeff=temp1->coeff+temp1->next->coeff;
            temp1->next=temp1->next->next;
            }
             else
            temp1=temp1->next;
        }
}
void sort3()
{
        temp4=first4;
        while(temp4->next)
        {
            if(temp4->power==temp4->next->power)
              {
            temp4->coeff=temp4->coeff+temp4->next->coeff;
            temp4->next=temp4->next->next;
            }
             else
            temp4=temp4->next;
        }
}
void multiply()
{
    temp1=first1;
    temp2=first2;
    int g=0;
    while(temp1!=NULL)
    {
        while(temp2!=NULL)
        {
           temp4=createnode1(0,0);
           temp4->power=temp1->power+temp2->power;
           temp4->coeff=temp1->coeff*temp2->coeff;
           if(g!=0)
            last4->next=temp4;
            else
                first4=temp4;
                last4=temp4;
                g++;
                temp2=temp2->next;
        }
         if(temp2==NULL)
                temp2=first2;
          temp1=temp1->next;
        }
        temp4=first4;
        sort3(first4);
}

void display()
{
    int x;
    printf("\nEnter the choice\n");
    printf("\n1.Entered polynomial\n2.Added polynomial\n3.Multipyed polynomial\n");
    scanf("%d",&x);
    if(x==1)
    {
     int x;
    printf("\n1st Sorted polynomial\n");
    temp1=first1;
    while(temp1!=NULL)
    {
        printf(" %dx^%d",temp1->coeff,temp1->power);
        temp1=temp1->next;
        if(temp1!=NULL)
            printf("+");
    }
    printf("\n");
    printf("\n2nd sorted polynomial\n");
    temp2=first2;
  while(temp2!=NULL)
    {
        printf(" %dx^%d",temp2->coeff,temp2->power);
        temp2=temp2->next;
        if(temp2!=NULL)
            printf("+");
    }
        printf("\n");
    }
    else if(x==2)
    {
        printf("\nAdded polynomial\n");
        temp3=first3;
    while(temp3!=NULL)
    {
        printf(" %dx^%d",temp3->coeff,temp3->power);
        temp3=temp3->next;
        if(temp3!=NULL)
            printf("+");
    }
            printf("\n");
    }
    else
    {
        printf("\nMultplyied poloynomial\n");
        temp4=first4;
     while(temp4!=NULL)
    {
        printf(" %dx^%d",temp4->coeff,temp4->power);
        temp4=temp4->next;
        if(temp4!=NULL)
            printf("+");
    }
            printf("\n");
    }

}
void main()
{

    int f,b;
    while(1)
    {
    printf("\n1.insertpolynomial 1\n2.insertpolynomial 2\n3.Add\n4.multiply\n5.display\n6.exit\n");
    scanf("%d",&f);
    switch(f)
    {

       case 1:
              insert1();
              break;
       case 2:
              insert2();
              break;
        case 3:
              add();
              break;

        case 4:
              multiply();
              break;
       case 5:
              display();
              break;
       case 6:
             exit(0);
             break;

             }
}
}

	
	
	

