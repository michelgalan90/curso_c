#include <stdio.h>

void doWork(int a, int b, int c, int* suma, int* mayor){
    *suma = a + b + c;
    if(a>b && a>c) *mayor = a;
    if(b>a && b>c) *mayor = b;
    if(c>a && c>b) *mayor = c;
}

int main(){
    int suma;
    int mayor;

    doWork(2000, 6, 30, &suma, &mayor);

    printf("La suma es: %d, y el mayor es: %d\n", suma, mayor);
    return 0;
}