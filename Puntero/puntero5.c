#include <stdio.h>

int main()
{
    int a = 1025;
    int* p;
    p = &a;

    printf("Tamano del entero es: %d\n", sizeof(int));
    printf("Address p= %d, valor= %d\n", p, *p);
    printf("Address p+1= %d, valor= %d\n", p+1, *(p+1));

    char* p1;
    p1 = (char*) p;


    printf("Tamano del char es %d\n", sizeof(char));
    printf("address p1= %d, valor= %d\n", p1, *p1);
    printf("address p1+1= %d, valor= %d\n", p1+1, *(p1+1));
 
    return 0;
}
