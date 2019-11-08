#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int* arr;
    int top;
} Stack;
Stack* stack_initialize(int);
void stack_push(Stack*, int);
void stack_pop(Stack*);
int stack_is_empty(Stack*);
int stack_peek(Stack*);

void stack_destroy(Stack*);

void convert_infix_to_postfix(const char*, char*);

int main()
{
    char source_infix[2000];
    char target_postfix[2000];
    int number_of_inputs = 0;
    scanf("%d", &number_of_inputs);

    for(int counter = 0; counter < number_of_inputs; ++ counter)
    {
        scanf("%s", source_infix);
        convert_infix_to_postfix(source_infix, target_postfix);
        printf("%s\n", target_postfix);
    }
    return 0;
}


Stack* stack_initialize(int s)
{
    Stack *t = (Stack *)malloc(sizeof(Stack));
    t->arr = (int *)malloc(s*sizeof(int));
    t->top = -1;
    return t;
}


void stack_push(Stack* s, int x)
{
    s->arr[++(s->top)] = x;
}

void stack_pop(Stack* s)
{
    (s->top)--;
}

int stack_peek(Stack*s)
{
    return s->arr[s->top];
}

void stack_destroy(Stack* s)
{
    free(s->arr);
    free(s);
}



int infix_prec(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/' || ch == '%')
        return 3;
    if(ch == '^')
        return 6;
    if(ch == '(' || ch == '{' || ch == '[')
        return 9;
    if(ch == ')' || ch == '}' || ch == ']')
        return 0;
    return 8;
}

int stack_prec(char ch)
{
    if(ch == '+' || ch == '-')
        return 2;
    if(ch == '*' || ch == '/' || ch == '%')
        return 4;
    if(ch == '^')
        return 5;
    if(ch == '(' || ch == '{' || ch == '[')
        return 0;
    if(ch == '#')
        return -1;
    return 7;
}

void convert_infix_to_postfix(const char* infix, char *postfix)
{
    Stack *stack = stack_initialize(2000);
    int top = -1;
    char ch;
    int j = 0;
    char waste;
    stack_push(stack, '#');
    for(int i=0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        while(infix_prec(ch) < stack_prec(stack_peek(stack)))
        {
            postfix[j++] = stack_peek(stack);
            stack_pop(stack);
        }
        if(infix_prec(ch) != stack_prec(stack_peek(stack)))
            stack_push(stack, ch);
        else
           { waste = stack_peek(stack);
            stack_pop(stack);}

    }
    while(stack_peek(stack) != '#')
    {
        postfix[j++] = stack_peek(stack);
        stack_pop(stack);
    }
    postfix[j] = '\0';
}

