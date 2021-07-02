#include <stdio.h>
#include <stdlib.h>

void saludo(){
    printf("Hola primo, facil verdad??? jajajja\n");
}

void saludito(char nombre[]){
    printf("Hola %s, mmm, si bien facil jejejejje.\n", nombre);
}

int suma(int a, int b){
    return a + b;
}

double impuesto(double salario); /* prototype de la funcion impuesto para poder usarla dentro del main
 cuando la funcion esta debajo del main se utiliza la firma del metodo arriba para que el main sepa que tipos va retornar...
si no pongo esta firma arriba del main me tira un error*/

int main()
{
    char nombre[] = "Pollito";
    saludo();
    saludito(nombre);

    saludito("Facil");

    printf("La suma de 3 y 5 es: %d\n", suma(3, 5));

    printf("El impuesto de 28000 es %lf\n", impuesto(28000.0));

    return 0;
}

double impuesto(double salario){
    return salario * 0.28;
}


