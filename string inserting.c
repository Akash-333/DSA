#include<stdio.h>
int main()
{
    char txt[100],ins[100],str[100];
    int i=0,n,j=0,k=0;
    printf("enter the main string :\n");
    gets(txt);
    printf("enter a string to be inserted:\n");
    gets(str);
    printf("enter the position from where to insert the string:\n");
    scanf("%d",&n);
    while(txt[i]!='\0')
    {
        if(i==n)
        {
            while(str[k]!='\0')
            {
                ins[j]=str[k];
                j++;
                k++;
            }
        }
        else
        {
            ins[j]=txt[i];
            j++;

        }
        i++;
    }
    ins[j]='\0';
    printf("final string is:\n");
    puts(ins);
    return 0;
}
