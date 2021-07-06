//Directivas de Preprocesador y Variables

#include <stdio.h> // Libreria
/*
#include <string.h>
#include <math.h>
#include <stdlib.h> 
*/

#define PI 3.1416 //Symbolic constants, los macro no llevan ;

int y = 5; //Variable global

int main(){
	int x = 10; // Variable local
	
	int suma = 0;
	
	suma = PI + x;
	
	printf("La suma es: %i", suma);
	
	return 0;
}


