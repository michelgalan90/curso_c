#include <stdio.h>


void test1(){
    auto int k;
    printf("k = %d\n", k);
    k = 20;
    printf("k = %d\n", k);
}

void test(){
    auto int var;
    /*cuando la variable es auto que es el por default se destruye de la memoria cuando termina
    la ejecucion de la funcion, el valor inicial es indefinido sino se inicializa. y el lifecycle
    es el mismo de la funcion */
    printf("var = %d\n", var);
    var++;
    printf("var = %d\n", var);
}

int main(){
    test1();
    test();

    return 0;
}