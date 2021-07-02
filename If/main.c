#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3){
        return num1;
    }else if(num2 > num1 && num2 > num3){
        return num2;
    }

    return num3;
}

void numeroMagico(int numero){
    if(numero==0){
        printf("Adivinaste!!!\n");
    }else{
        printf("FALLASTE\n");
    }
}

void adivina(char palabra[]){
    if(palabra=="hola" || palabra=="facil"){
        printf("SII FACIL!\n");
    }else{
        printf("Esa no es la palabra!\n");
    }
}

int main()
{
    printf("Digite tres numeros\n");

    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    printf("El mayor numero es: %d\n", max(num1, num2, num3));

    printf("Adivina el numero\n");

    int numero;
    scanf("%d", &numero);
    numeroMagico(numero);

    adivina("facil");


    return 0;
}
