#include <stdio.h>

int edad = 25; // variable global

int incrementAge(); // prototype function

int main(){

    /*las variables globales son static por default pero las que estan dentro de una funcion no
    para hcaer una variable de una funcion static se usa la palabra static */
    printf("La edad es: %d\n", edad);

    edad = 12;
    printf("La edad ahora es: %d\n", edad);

    printf("----------***----------\n");
    printf("La edad es: %d\n", incrementAge());
    printf("La edad es: %d\n", incrementAge());
    printf("La edad es: %d\n", incrementAge());


    return 0;
}

int incrementAge(){
    int age = 0; // variable local
    age++;

    static int age2 = 0; // variable static mantiene su estado cada vez que ejecuto la funcion
    age2++;
    
    return age2;
}