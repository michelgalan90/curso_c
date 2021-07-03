#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arreglo[5];

    int *puntero = arreglo;

    int a = 2;

    for( ; puntero < &arreglo[5]; puntero++){
        *puntero = a;
        a = a +2;

    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d", arreglo[i]);
    }
       
    return 0;
}

