#include <stdio.h>
#include <stdlib.h>

int main()
{
    int indice = 12;

    while(indice != 0){
        printf("EL indice es %i\n", indice);
        indice--;

    }

    int ruta = 30;
    while(ruta < 1000){
        printf("La ruta es %i\n", ruta);
        ruta += 90;
    }

    int facil = -9;
    do{
        printf("El numero magico es: %d\n", facil);
        facil++;
    }while(facil < 5);

    return 0;
}
