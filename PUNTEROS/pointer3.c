#include <stdio.h>

int main(){

    int* p;
    float* f;
    double* d;
    int** k;
    char* c;

    printf("%lu %lu %lu %lu %lu\n", sizeof(p), sizeof(f), sizeof(d), sizeof(k), sizeof(c));
    /*el tamano del puntero siempre sera dependiente del sistema operativo, si es de 64bits 
    entonces los punteros tendra 8 bytes que es 64 bits y si el SO es de 32 bits entonces los
    punteros tendran 4 bytes siempre no importa el tipo, todos los punteros de punteros y 
    punteros de tipos de datos tendran el mismo tamano de bytes en memoria.
    las variables normales si tendran distintos tamanos dependiendo de cual sea.*/
    printf("%lu %lu %lu %lu %lu\n", sizeof(*p), sizeof(*f), sizeof(*d), sizeof(**k), sizeof(*c));


    return 0;
}