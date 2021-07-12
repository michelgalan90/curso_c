#include <stdio.h>

int main(){
    int var = 5;
    int* p;
    float* k;
    double* d;

    printf("%p\n", &var);
    p = &var;
    printf("%d\n", var);
    *p = 10;
    
    printf("%d\n", var);
    *p = *p + 1;
    printf("%d\n", var);

    //printf("%lu", &var);



    return 0;
}