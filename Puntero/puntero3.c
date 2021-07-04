#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a; //declarando variable de tipo int
    int *p; // declarando puntero de tipo int

   // printf("%p", *p);

    a = 10;
    p = &a; // &a = Direccion de a en memoria
    printf("a: %d\n", a);

    *p = 12; // dereferencing asignando un valor nuevo a la direccion en memoria al que apunta

    printf("p: %p\n", p);
    printf("*p: %d\n", *p);
    printf("a: %d\n", a);
    printf("&a: %p\n", &a);

    int b = 25;
    *p = b; 

    printf("------------\n");
    printf("p: %p\n", p);
    printf("*p: %d\n", *p);
    printf("a: %d\n", a);
    printf("&a: %p\n", &a);
    
    printf("------------\n");
    p = &b;
    *p = 9; // cambio valor de b usando dereferencing
    b = 53; // cambio el valor normalmente y se ve reflejado cuando utilice *p

    printf("p: %p\n", p);
    printf("*p: %d\n", *p);
    printf("a: %d\n", a);
    printf("&a: %p\n", &a);
    printf("b: %d\n", b);
    printf("&b: %p\n", &b);

    return 0;
}
