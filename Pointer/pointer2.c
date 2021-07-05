#include <stdio.h>

void doSomething(void){
    printf("Hola mundo");
}

int main(){
    int age = 37;

    printf("%p\n", &age);

    int* direccion = &age;

    printf("Direccion: %p\n", direccion);

    *direccion = 25;

    printf("La edad es: %d\n", *direccion);

    int peso;
    int* pPeso = &peso;

    *pPeso = 218;
    printf("El peso es: %d\n", peso);

    puts("--------------");

    int prices[3] = {5, 2, 10};

    printf("El primer valor del arreglo es: %d\n", *prices);
    printf("El segundo valor del arreglo es: %d\n", *(prices+1));
    printf("El tecer valor del arreglo es: %d\n", *(prices+2));

    doSomething();


    return 0;
}

