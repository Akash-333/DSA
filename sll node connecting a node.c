#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next,*bottom;
}*first=NULL,*bottom=NULL;
void read_1(int arr1[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d  ",&arr1[i]);
    }
}
void read_2(int arr2[],int m)
{
    int i=0;
    for(i=0;i<m;i++)
    {
        scanf("%d  ",&arr2[i]);
    }
}
void create1(int arr1[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=arr1[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr1[1];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int arr2[],int m)
{
    int i;
    struct Node *t,*last;
    bottom=(struct Node *)malloc(sizeof(struct Node));
    bottom->data=arr2[0];
    bottom->next=NULL;
    last=bottom;
    for(i=1;i<m;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr2[1];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{

    while(p!=0)
    {
        printf("%d->",p->data);
        p=p->next;
    }
}
int main()
{
    int n,m,arr1[100],i=0,arr2[100];
    printf("enter the number of elements in array 1:\n");
    scanf("%d ",&n);
    read_1(arr1,n);
    create1(arr1,n);
    printf("enter the number of elements in array 2:\n");
    scanf("%d ",&n);
    create2(arr2,m);
    for(i=0;i<n;i++)
    {
         read_2(arr2,m);
    }
    printf("the list elements are \n");
    display(first);
    display(bottom);
}

