#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char characterName[] = "Michel";
    char caracter = 'h';
    printf("%c\n", caracter);


    int numero = 5;
    numero = 8;
    int rgbColor = 0xFFEF0D;

    double salario = 25600.23;

    printf("Mi numero favorito es: %d\n", rgbColor);

    float a = 34.565689123;

    printf("%.3f\n", a);

    double radio = 1.5689425;

    printf("El radio es %.2lf\n", radio);

    printf("    /|\n");
    printf("   / |\n");
    printf("  /  |\n");
    printf(" /   |\n");
    printf("/____|\n");

    bool estado = true;

    printf("%f\n", pow(3, 2)); // la potencia de 3 a la 2

    printf("%f\n", sqrt(9)); // el cuadrado de 9

    return 0;
}
