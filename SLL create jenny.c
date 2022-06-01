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
    printf("enter data\n");
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
void display()
{
    struct Node *temp;
     if(head == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
    temp=head;
    printf("\n printing values\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    }

}
void insert_beginning()
{
    struct Node *temp,*newnode;
    temp=head;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter the value to be inserted at beginning\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insert_end()
{
    struct Node *temp,*newnode;
    temp=head;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter the value to be inserted at the end\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

int length()
{
    int len=0;
    struct Node *temp;
     if(head==NULL)
     {
         return len;
     }
     else
     {
        temp=head;
        while(temp!=NULL)
          {
             temp=temp->next;
             len++;
          }
     }
    return len;
}
void insert_pos()
{
    int pos,i=1;
    struct Node *head,*newnode,*temp;
    printf("enter the position where the element to be entered\n");
    scanf("%d",&pos);
    if(pos>length())
    {
        printf("invalid position\n");
    }
    else
    {
        temp=head;
        newnode=(struct Node*)malloc(sizeof(struct Node));
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        printf("enter the element to be inserted\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int main()
{
    head=0;
    int choice,len;
    printf("enter choice\n");
    while(1)
    {
        printf(" 1.create\n 2.display\n 3.inserting at beginning\n 4.inserting at end\n 5.length of list\n 6.inserting at specific position\n 7.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:insert_beginning();
            break;
            case 4:insert_end();
            break;
            case 5:len=length();
            printf("the length of list is:%d",len);
            break;
            case 6:insert_pos();
            break;
            case 7:exit(0);
            break;
        }

    }
}
