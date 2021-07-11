#include <stdio.h>


void test1(){
    auto int k;
    printf("k = %d\n", k);
    k = 20;
    printf("k = %d\n", k);
}

void test(){
    static int var;
    /* se mantiene en memoria durante todo el ciclo de vida del programa pero el 
    scope sigue siendo local, solo puedo usarla dentro de esta funcion...pero mantendra
    en todo tiempo su valor en memoria. no se destruye cuando termina la llamada a la funcion.
    */
    /*siempre son inicializadas en cero las variables static si no se inicializan*/
   
    printf("var = %d\n", var);
    var++;
    printf("var = %d\n", var);
}

int main(){
  //  test1();
    test();    
    test();    
    test();    

    return 0;
}