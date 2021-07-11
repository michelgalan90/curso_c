#include <stdio.h>


void test(){
    extern int gVar;
    /* si la variable global esta antes de cualquier funcion arriba antes de ser usada...
    no hay problemas de compilacion, pero si esta debajo de una funcion donde se usa como este caso
    la tenemos debajo de la funcion test() entonces en tiempo de compilacion se queja porque no
    sabe que es la variable gVar para esto se usa la palabras reservada extern para hacerle saber
    al compilar que mas adelante se sabra el valor de gVar y que compile sin miedo */

    printf("gVar = %d\n", gVar);
    gVar = 20;

}
int gVar; // variable global -por default es 0

int main(){
    printf("gVar = %d\n", gVar);
    gVar = 10;

    test();
    printf("gVar = %d\n", gVar);




    return 0;
}