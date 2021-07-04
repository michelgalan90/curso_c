#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *pA = &a;

    printf("Address Memory a: %p\n", &a);
    printf("Address Memory pA: %p\n", pA);

    printf("Valor de a: %d\n", a);
    printf("Valor Dereferencing pA: %d\n", *pA);

    //Cambio valor de la variable a usando dereferencing del puntero

    *pA = 25*2;

    //imprimo nuevamente los valores tanto de a 
    //como del puntero que almacena la direccion en memoria de a

    printf("Valor de a: %d\n", a);
    printf("Valor Dereferencing pA: %d\n", *pA);

    //imprimiendo el memory address del puntero...y de la variable a

    printf("MemoryAddress del puntero: %p\n", &pA); 
    printf("MemoryAddress de variable a: %p\n", &a); 
    
    return 0;
}
