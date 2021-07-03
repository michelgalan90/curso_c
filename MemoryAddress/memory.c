#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int edad = 30;
    double peso = 20.56;
    char grado = 'A';

    printf(" Edad: %p\n Peso: %p\n Grado: %p\n", &edad, &peso, &grado);

    return 0;
}
