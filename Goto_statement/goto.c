#include <stdio.h>

int main(){

    char fruta[] = "Manzana";
    int contador = 5;

    f:{
        printf("La fruta es: %s", fruta);
    }

    printf("------------");


    if(contador > 0){
        contador--;
        goto f;
       
    }   


    return 0;
}