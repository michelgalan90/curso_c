#include <stdio.h>

int main(int argc, char const *argv[])
{
    int age = 30;
    int * pAge = &age;
    double gpa = 3.4;
    double * pGpa = &gpa;

    char grade = 'A';
    char * pGrade = &grade;


    printf("age's memory address: %p\n", &age);
    printf("%p\n", pGrade);
    printf("pGrade: %c", *pGrade);

    return 0;
}
