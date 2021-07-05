#include <stdio.h>
#include <stdbool.h>

int main(){
    enum gender{male, female};

    enum gender torito = male;
    enum gender vaca = female;

    printf("%d\n", torito);

    enum colors{rojo, azul, verde, amarillo, blanco};
    enum colors carro = rojo;
    enum colors celular = verde;

    bool isGreen = carro == celular;

    return 0;
}