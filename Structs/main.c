#include <stdio.h>
#include <stdlib.h>

struct Estudiante{
    char nombre[50];
    char grado[30];
    int edad;
    double altura;
};

struct Telefono{
    char marca[30];
    int anio;
    char modelo[20];

};

int main()
{
    struct Estudiante estudiante1;

    strcpy(estudiante1.nombre, "Michel");
    estudiante1.edad = 30;
    strcpy(estudiante1.grado, "facil");
    estudiante1.altura = 1.68;

    struct Telefono telefono1;

    strcpy(telefono1.marca, "Samsung");
    strcpy(telefono1.modelo, "Note10");
    telefono1.anio = 2010;

    printf("El telefono de Michel es %s %s del ano %d", telefono1.marca, telefono1.modelo, telefono1.anio);

    return 0;
}
