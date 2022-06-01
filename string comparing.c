#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,len1=0,len2=0,same=0;
    char str1[100],str2[100];
    printf("enter first string:\n");
    gets(str1);
    printf("enter second string:\n");
    gets(str2);
    len1=strlen(str1);
    len2=strlen(str2);
    if(len1==len2)
    {
        while(i<len1)
        {
            if(str1[i]==str2[i])

                i++;
                else break;

        }
        if(i==len1)
        {
            same=1;
            printf("two strings are same\n");
        }
    }
    if(len1!=len2)
    {
        printf("two strings are not same\n");
    }
    if(same==0)
    {
        if(str1[i]>str2[i])
        {
            printf("first string is greater then second\n");
        }
        else if(str1[i]<str2[i])
        {
            printf("second string is greater then first\n");
        }
    }
    return 0;
}
