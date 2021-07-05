#include <stdio.h>
#include <string.h>

struct telefono{
    char marca[20];
    char modelo[10];
} samsung, telefonos[3];
// samsung es una variable global de tipo struct telefono

struct persona{
    int edad;
    char nombre[15];
    char apellido[20];
} michel, mirel;

int main(){

    strcpy(samsung.marca, "Samsung");
    strcpy(samsung.modelo, "Note10");

    struct telefono iphone; // variable local de tipo struct telefono

    strcpy(iphone.marca, "iPhone");
    strcpy(iphone.modelo, "X");

    strcpy(telefonos[0].marca, "Xiaomi");
    strcpy(telefonos[0].modelo, "Redmi 10");

    //podemos inicializar unba struct en tiempo de declaracion

    struct telefono lg = {"LG", "V35"};

    printf("El telefono lg: %s\n", lg.modelo);

    puts("----*******************---------\n");

    struct persona pollito;
    strcpy(pollito.nombre, "Pollito");
    strcpy(pollito.apellido, "Poderoso");
    pollito.edad = 20;

    printf("El %s %s tiene %d anios\n", pollito.nombre, pollito.apellido, pollito.edad);
   
    strcpy(michel.nombre, "Michel");
    strcpy(mirel.nombre, "Mirel");
    michel.edad = 20;
    mirel.edad = 15;

    printf("%s tiene %d anos y %s tiene %d anos...facil\n", mirel.nombre, mirel.edad, 
                                                            michel.nombre, michel.edad);

    struct persona maida = {60, "Maida", "Blanco"};

    printf("%s %s tiene %d anos de edad\n", maida.nombre, maida.apellido, maida.edad);

    return 0;
}