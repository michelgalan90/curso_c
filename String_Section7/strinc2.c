#include <stdio.h>

int main(){

    char str[80];

    printf("Enter your name: ");
    scanf("%[A-Za-z ]", str); // tipo de regex //el espacio luego de z permite un espacio en la entrada
    printf("Welcome, %s\n", str);

    char oracion[100];

    printf("Diga una oracion: \n");
    scanf("%[^l]", oracion); // dejara de leer el bufer cuando entre una l

    printf("La oracion dice: %s\n", oracion);
   
    char orac[100];

    printf("JEJEJE ahora otra oracion: ");
    scanf("%[^P]", orac); // dejara de leer cuando entre una P
    printf("DIGITASTE: %s", orac);

    return 0;
}