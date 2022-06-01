#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    int i=0,n;
    printf("enter a string :\n");
    gets(str1);
    printf("enter the number of characters to be copied :\n");
    scanf("%d",&n);
    i=0;
    while(str1[i]!='\0' && i<n)
    {
        str2[i]=str1[i];
        i++;
    }
    str2[i]='\0';
    printf("copied characters are:\n");
    puts(str2);
    return 0;


}
