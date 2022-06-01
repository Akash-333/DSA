#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void create()
{
    struct Node *newnode,*temp;
    temp=head;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter the element\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==0)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
int search()
{
    int i=1,n;
    printf("enter the element to be searched\n");
    scanf("%d",&n);
    struct Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            printf("the element %d  is present at position:%d",n,i);
            return 0;
        }
        temp=temp->next;
        i++;
    }
    printf("element not found\n");
    return 0;
}
void nth_node()
{
    int i=1,n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    struct Node *temp,*prevnode;
    if(n>length())
    {
        printf("invalid value of n\n");
    }
    /*if(n==1)
    {
        temp=head;
        printf("the node value is:",temp->data);
    }*/
    else
    {
        temp=head;
        while(i<=n)
        {
             printf("the node value is:",temp->data);
             temp=temp->next;
        }
    }
}
int main()
{
    head=0;
    int choice,pos;
    printf("enter choice\n");
    while(1)
    {
        printf("\n 1.create\n 2.search\n 3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:search();
            break;
            case 3:exit(0);
            break;
        }

    }



}

