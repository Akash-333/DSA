#include <stdio.h>
struct student {
    char firstName[50];
    int roll;
    float marks;
} s[20];

int main() {
    int i;
    printf("Enter information of students:\n");


    for (i = 0; i < 2; i++) {
        s[i].roll = i + 1;
        printf("\nFor roll number%d,\n", s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("Displaying Information:\n\n");

    for (i = 0; i < 2; i++) {
        printf("\nRoll number: %d\n", i + 1);
        printf("First name: ");
        puts(s[i].firstName);
        printf("Marks: %.1f", s[i].marks);
    }


    printf("\n\n");
    printf("Displaying Information of student who topped in exam:\n\n");
       for(i = 0; i < 2; i++);
        int max,n;
        max=s[0].marks;
        if (s[i].marks>max)
        max=s[i].marks;
        n=i;
        printf("\nRoll number: %d\n", n );
        printf("First name: ",s[n].firstName);
        puts(s[n].firstName);
        printf("Marks: %.1f", s[n].marks);
        printf("\n");


    return 0;
        }
