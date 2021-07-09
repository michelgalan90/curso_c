#include <stdio.h>
#include <string.h>

int main(){

    char cadena[80];
    printf("Enter a string: ");
    scanf("%[^\n]", cadena); // dejara de leer el buffer cuando de enter

    printf("Digito: %s\n", cadena);

    int i;

    for(i=0; cadena[i] != '\0';i++); // buscando la ultima posicion del string donde esta el '\0 '

    printf("The string length is: %d\n", i);

    i = strlen(cadena); // esto devuelve tambien el tamano del string

    printf("Tamano de la cadena: %d\n", i);

    return 0;
}