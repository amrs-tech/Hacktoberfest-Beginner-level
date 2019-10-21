#include<stdio.h>
#include<stdlib.h>
#define MAX 30
char stack[MAX], postfix[100];
int top=-1;
void infixTopostfix(char[]);
int GetPriority(char);
int Isalnum(char);
void push(char[],char);
char pop(char[]);
int main()
{
    char ch[100];
    printf("Enter The Infix Expression : ");
    gets(ch);
    infixTopostfix(ch);
    printf("Postfix Expression : ");
    puts(postfix);
    printf("\n");
    return 0;
}
void infixTopostfix(char ch[])
{
    int i=0,j=0;
    char temp;
    while(ch[i] != '\0')
    {
        if(Isalnum(ch[i]))
        {
            postfix[j]=ch[i];
            j++;
            i++;
        }
        else if(ch[i]=='(')
        {
            push(stack,ch[i]);
            i++;
        }
        else if(ch[i]==')')
        {
            while((top!=-1) && (stack[top]!='('))
            {
                postfix[j]=pop(stack);
                j++; 
            }
            if(top==-1)
            {
                printf("\nIncorrect Expression..!!\n");
                return;
            }
            temp=pop(stack);
            i++;
        }
        else if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='%')
        {
            while((top!=-1) && (GetPriority(stack[top]) >= GetPriority(ch[i])) && (stack[top]!='('))
            {
                postfix[j] = pop(stack);
                j++;
            }
            push(stack,ch[i]);
            i++;
        }
        else
        {
           printf("Incorrect Expression..!!!");
           return;
        }
        
    }
    while((top!=-1) && (stack[top]!='('))
    {
        postfix[j]=pop(stack);
        j++;
    }
    postfix[j]='\0';
}
int GetPriority(char ch)
{
    if(ch=='*' || ch=='/' || ch=='%')
    {
        return 1;
    }
    else if(ch=='+' || ch=='-')
    {
        return 0;
    }
}
void push(char stack[], char ch)
{
     if(top==MAX-1)
     {
         printf("Stack Overflow..!!!");
     }
     else
     {
         top++;
         stack[top]=ch;
     }
}
char pop(char stack[])
{
    char temp;
    if(top==-1)
    {
        printf("Stack Underflow..!!");
        return 0;
    }
    else
    {
        temp = stack[top];
        top--;
    }
    return temp;
}
int Isalnum(char ch)
{
    if((ch>=65 && ch<=98) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57))
        return 1;
    else
        return 0;
} 
