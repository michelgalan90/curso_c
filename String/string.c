#include <string.h>
#include <stdio.h>

int main(){
    char nombre[] = "Michelito";

    printf("El nombre es: %s\n",nombre);

    printf("La longitud del nombre es: %d\n", strlen(nombre)); // me devuelve la longitud de un string

    strcpy(nombre, "Mirelito"); // sustituir string dentro de otro

    printf("El nombre ahora es: %s\n", nombre);

    strcat(nombre, " Michelito"); // append string

    printf("Ahora los nombres son: %s\n", nombre);

    char tito[100];


    sprintf(tito, "Hola pollito %s %i", "pollito", 25);

    printf("%s", tito);

    return 0;
}