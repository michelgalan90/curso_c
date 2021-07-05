#include <stdio.h>

int main(){

    unsigned char a = 255;
    a += 1;

    printf("a: %u\n", a);

    unsigned short s = 65535;
    s += 5;
    printf("s: %u\n", s);

    return 0;
}