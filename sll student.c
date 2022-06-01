#include<stdio.h>
#include<stdlib.h>
struct Student
{
    char name[20];
    char sub[15];
    int marks,roll;
    struct Student *next;
};
typedef struct Student *Node;
Node head=NULL;
void create()
{
    Node temp,newnode;
    temp=head;
    newnode=(Node*)malloc(sizeof(Node));
    printf("\n name\n roll_num\n subject\n marks\n");
    scanf("%s %d %s %d",newnode->name,&newnode->roll,newnode->sub,&newnode->marks);
    newnode->next=NULL;
    if(head==NULL)
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
    Node temp;
    if(head==NULL)
    {
        printf("nothing to print\n");
    }
    else
    {
    temp=head;
    while(temp!=NULL)
    {
        printf("name:%s \t roll_number:%d \t subject:%s \t marks:%d \n",temp->name,temp->roll,temp->sub,temp->marks);
        temp=temp->next;
    }
    }
    printf("\n");
    printf("\n");
    printf("\n");
}
int main()
{
    head=0;
    int choice;
    printf("enter choice\n");
    while(1)
    {
        printf("\n 1. create\t 2.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:display();
            break;
        }
    }
}



