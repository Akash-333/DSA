#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 25

struct stack
{
    int num[SIZE];
    int top;
};
typedef struct stack STACK;

//function prototypes.
void push(STACK *s, int data);
int pop(STACK *s);
void reversenumber(STACK *s,int);

int main()
{
    int n;
    STACK s;
    s.top = -1;
    scanf("%d",&n);
    reversenumber(&s,n);
    return 0;
}

void push(STACK *s, int data)
{
    if(s->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top ++;
        s->num[s->top] = data;
    }
}

int pop(STACK *s)
{
    int data;
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        data = s->num[s->top];
        s->top--;
        return data;
    }
}

void reversenumber(STACK *s,int n)
{
    int  m, rem, factor=1, rev=0;
    m=n;
    while(n)
    {
        rem = n%10;
        push(s, rem);
        n = n/10;
    }
    while(s->top != -1)
    {
        rev = rev + factor * pop(s);
        factor = factor *10;
    }
    if(rev == m)
        printf("%d is a palindrome number\n", m);
    else
        printf("%d is not a palindrome number\n", m);
}
