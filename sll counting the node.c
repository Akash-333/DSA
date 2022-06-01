#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;
void create(int a[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=0)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}
int count(struct Node *p)
{
    if(p==0)
    {
        return 0;
    }
    else
        return count(p->next)+1;
}
int add(struct Node *p)
{
    int sum=0;
    if(p==0)
    {
        return 0;
    }
    else
    {
        return add(p->next)+p->data;
    }
}
int main()
{
    int a[]={1,2,3,4,5},k,s;
    create(a,5);
    display(first);
    k=count(first);
    printf("\n length is %d",k);
    s=add(first);
    printf("\n sum is %d",s);
    return 0;
}
