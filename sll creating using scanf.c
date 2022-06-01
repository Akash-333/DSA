#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;
void read(int arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void create(int arr[],int n)

{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
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
int main()
{
    int n,arr[100];
    printf("enter the number of elements:\n");
    scanf("%d ",&n);
    //printf("\n");
    //printf("enter array elements\n");
    read(arr,n);
    create(arr,n);
    printf("the list elements are \n");
    display(first);

}
