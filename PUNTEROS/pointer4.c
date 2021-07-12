#include <stdio.h>

int main(){

    int x = 10;
    int* p;
    p = &x;

    printf("Content of p: %lu\n", p);
    printf("Content of x: %d\n", x);
    p = p + 1;
    printf("Content of p: %lu\n", p);
    *p = 15;
    printf("Content of x: %d\n", x);
    int y = *p;
    printf("Content of y: %d\n", y);
    ////////////


    return 0;
}