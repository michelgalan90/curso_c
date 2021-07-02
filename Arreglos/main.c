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

    return 0;
}
