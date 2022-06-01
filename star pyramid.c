#include<stdio.h>

int main() {
   char ch='#';
   int n;
   scanf("%d",&n);
   int i, j, no_of_spaces = n-1, spaceCount;

   for (i = 1; i <= n; i++) {
      for (spaceCount = no_of_spaces; spaceCount >= 1; spaceCount--) {
         printf("  ");
      }

      for (j = 1; j <= i; j++) {
         printf("%2c",ch);
      }

      printf("\n");
      no_of_spaces--;
   }
   return 0;
}
