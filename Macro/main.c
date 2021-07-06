#include <stdio.h>

#define POWER(x) ((x) * (x)) // MACRO
#define IMPUESTO(a) ((a) + (a))

int main(){

    printf("%u\n", POWER(3));

    printf("El impuesto de 250 es: %u", IMPUESTO(250));
    return 0;
}