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
      printf("\n");
      printf("\n");
      printf("\n");

}
void insert_beginning()
{
    struct Node *temp,*newnode;
    temp=head;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter the value to be inserted at beginning\n");
    scanf("%d",&newnode->data);
    newnode->next=temp; //newnode->next=head;
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
    struct Node *newnode,*temp;
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
        printf("enter the element to be inserted\n");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void del_beg()
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=head;
        head=temp->next;
        free(temp);
    }
}
void del_end()
{
    struct Node *temp,*prevnode;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            head=0;
        }
        else
        {
            prevnode->next=NULL;
        }
        free(temp);
    }

}
void del_specific()
{
    int i=1,pos;
    struct Node *temp,*prevnode;
    printf("enter the position of the node to be deleted\n");
    scanf("%d",&pos);
    if(pos>length())
    {
        printf("invalid position\n");
    }
    if(pos==1)
    {
        head=head->next;
        free(temp);
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            prevnode=temp;
             temp=temp->next;
            i++;
        }
        prevnode->next=temp->next;
        free(temp);
    }
}
void rev()
{
    struct Node *prev,*cur,*nxt;
    prev=NULL;
    cur=nxt=head;
    while(nxt!=NULL)
    {
        nxt=nxt->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    head=prev;
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
int nth_node()
{
    int i=1,n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    struct Node *temp;
    temp=head;
    if(n>length() || n==0)
    {
        printf("invalid value of n\n");
        return 0;
    }
    if(n==1)
    {
        temp=head;
        printf("the node value is:%d\n",temp->data);
    }
    else
    {
        temp=head;
        while(i<n)
        {
             temp=temp->next;
             i++;
        }
        printf("the node value is:%d\n",temp->data);
        //return 0;
    }
}

int main()
{
    head=0;
    int choice,len;
    printf("enter choice\n");
    while(1)
    {
        printf(" \n 1.create\n 2.display\n 3.inserting at beginning\n 4.inserting at end\n 5.length of list\n 6.inserting at specific position\n 7.delete beginning\n 8.delete end\n 9.delete specific\n 10.reversing the list\n 11.searching\n 12.nth node\n 13.exit\n");
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
            case 7:del_beg();
            break;
            case 8:del_end();
            break;
            case 9:del_specific();
            break;
            case 10:rev();
            break;
            case 11: search();
            break;
            case 12:nth_node();
            break;
            case 13:exit(0);
            break;
        }

    }
}
