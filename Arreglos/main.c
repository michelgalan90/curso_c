#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[] = {4, 2, 5, 89, 6, 45, 32};
    numeros[1] = 560;

    printf("%d\n", numeros[1]);

    int numeros2[10];

    numeros2[1] = 15;
    numeros2[5] = 42;

    printf("%d", numeros2[5]);

    const int TAMANO = 5;
    int numeros3[TAMANO];

    int prices[5] = {1, 2, 3, 4, 5};
    prices[0] = 10;
    prices[1] = 25;
    prices[4] = -50;

    return 0;
}
