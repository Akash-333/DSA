#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack
{
	int data[SIZE];
	int top;
};
typedef struct stack *STK;

int full(STK );
int empty(STK );
void PUSH(STK ,int );
int POP(STK );
void DISPLAY(STK );

void main()
{
	STK s;
	int ch,num,x;
    s=malloc(sizeof(struct stack));
	s->top=-1;//Initially stack top points to -1

	while(1)
	{
		printf("\n1:PUSH \n2:POP \n3:DISPLAY \n4:EXIT");
		printf("\nEnter any option[1-4]\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter the element to be pushed");
                    scanf("%d",&num);
                    PUSH(s,num);
                    break;
			case 2:x=POP(s);
                    if(x!=-1)
                    {
                        printf("\n%d is popped",x);
                    }
                    break;
			case 3: DISPLAY(s);
                    break;
			case 4:exit(0);
                    break;
		}
	}

}
int full(STK s)
{
	if(s->top==SIZE-1)
		return 1;
	else
		return 0;
}

int empty(STK s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

void PUSH(STK s,int num)
{
	if(full(s))
	{
		printf("\nStack Overflow!!");

	}
	else
    {
        s->top++;
        s->data[s->top]=num;
    }
}

int POP(STK s)
{
	int temp;

	if(empty(s))
	{
		printf("\nStack Underflow");
		return -1;
	}
	else
    {
        temp=s->data[s->top];
        s->top--;
        return temp;
    }
}

void DISPLAY(STK s)
{
	int i;
	if(empty(s))
	{
		printf("\nStack is empty");
	}
	else
    {
        printf("Elements are\n");
        for(i=s->top; i>=0; i--)
        {
            printf("%d\n",s->data[i]);
        }
    }
}

