#include <stdio.h>
#include <string.h>

typedef struct{
    int edad;
    char nombre[20];
    char apellido[25];
} PERSONA;

struct empleado{
    char nombre[10];
    char apellido[20];
    int edad;
} michel, mirel;

int main(){

    PERSONA michel;
    strcpy(michel.nombre, "Michel");
    strcpy(michel.apellido, "Galan");
    michel.edad = 30;

    printf("%s %s tiene %d anos beibi.\n", michel.nombre, michel.apellido, michel.edad);

    PERSONA mirel = {25, "Mirel", "Galan"};

    printf("%s %s tiene %d anos facil.\n", mirel.nombre, mirel.apellido, mirel.edad);

    return 0;
}