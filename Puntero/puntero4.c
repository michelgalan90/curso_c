#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* 1 byte es 8 bits...un integer son 32 bits es decir 4 bytes */
    
    int a = 10;
    int *p;

    p = &a;

    // Pointer Arithmetic
    printf("p address: %p\n", p);
    printf("valor en p address: %d\n", *p);
    printf("size of integer is %d bytes\n", sizeof(int));
    /* El int a ocupa 4 bytes en memoria, por lo tanto al ejecutar
    p(direccion de a) + 1 queremos la direccion en memoria que le sigue a la de p, 
    que esta apuntando realmente a la direccion de a, pero como a es un int y ocupa 4 bytes
    la siguiente direccion sera 4 valores despues de la direccion de a...
    Ej.  p(&a) =  0xffffcbf4
        p(&a)+1 = 0xffffcbf8
        p(&a) =   -13324
        p(&a)+1 = -13320

     */
    printf("p+1 address: %p\n", p+1); // aca lo incrementa en 4 bytes porque el int ocupa 4
    printf("valor en p+1 address: %d\n", *(p+1) ); // aca lo incrementa en 4 bytes

    printf("p+2 address: %p\n", p+2); // aca lo incremento en 8 bytes



    return 0;
}
