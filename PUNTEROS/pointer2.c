#include <stdio.h>

int main(){
    //se puede declarar un puntero y una variable directamente en la misma linea (int *p, q);
    int* p, *q;
    int **k;
    int x = 100;
    p = &x;
    k = &p;

    /*de esta simple manera puedo acceder a x usando k, porque k -> p -> x utilizando doble asterisko*/

    printf("x: usando **k -> %d\n", **k);
    printf("p pelao: %p\n", p);
    printf("*k : %p\n", *k);
    printf("&k : %p\n", &k);
    **k = 10*2+9;
    printf("**k = x: -> %d\n", **k);

    /////////////////

    int **facil;
    int a;
/*  facil = &a; // warning: assignment to ‘int **’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
    no puedo asignarle a facil la direccion en memoria de a...porque a es un int...
    y facil es un puntero de puntero... las dos asteriskos ** indican que en esa variable puedo
    guardar una direccion en memoria pero de un puntero y debe ser de un puntero del mismo tipo.
*/
    
    return 0;
}