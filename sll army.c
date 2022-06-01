#include<stdio.h><stdlib.h>


struct Node
{
    int height;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *node;




node getnode()
{
    node t;
    int n;
    t=(node*)malloc(sizeof(struct Node));
if(t==NULL)
{
    printf("memory not allocated\n");
}
    scanf("%d",&t->height);
    t->next=NULL;
    t->prev=NULL;
return t;
}



node insrear(head)
{
    node n,cur;
    n=getnode();
    cur=head;
if(head==NULL)
{
    return n;
}
while(cur->next!=NULL)
{
    cur=cur->next;
}
    cur->next=n;
    n->prev=cur;
return head;
}


void select(node head)
{
    node c=head;
    int a[100],i=0,k=0;
if(head->height<=150)
{
    a[i]=head->height;
    i++;
}
    c=c->next;
while(c->next!=NULL)
{
    if(c->height>c->prev->height &&   c->height<c->next->height)
{
    a[i]=c->height;
    i++;
}
c=c->next;
}
if(c->height>=150)
{
    a[i]=head->height;
    i++;
}
if(i==0)
{
    printf("No candidates are eligible\n");
}
else{
for(k=0;k<i;k++)
{
    printf("%d ",a[k]);
}
}
    printf("\n%d",i);
}






main()
{
int n,i;
node head=NULL;
//printf("Enter the number of candidates\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
head=insrear(head);
}
select(head);

}

