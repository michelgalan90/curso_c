#include <stdio.h>

int main(){
    int x = 300;
    char* k;
    int* p;

    k = (char*) &x;
    p = &x;

    printf("%d  %d\n", *p, *k);

    k = k+1;
    printf("k+1 = %d\n", *k);

    return 0;
}