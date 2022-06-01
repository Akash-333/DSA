#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    int i=0,n,j=0,l,m;
    printf("enter a string :\n");
    gets(str1);
    printf("enter the position from which to start substring:\n");
    scanf("%d",&m);
    printf("enter the length of substring:\n");
    scanf("%d",&n);
    i=m;
    while(str1[i]!='\0'&&n-1>=0)
    {
        str2[i]=str1[i];
        i++;
        n--;
    }
     str2[i]='\0';
    printf("copied characters are:\n");
    puts(str2);
    return 0;


}
