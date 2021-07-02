#include <stdio.h>
#include <stdlib.h>

int main()
{
    char status = 'g';

    switch(status){
        case 'A': printf("Buena calificacion");
        break;
        case 'B': printf("OK");
        break;
        case 'C': printf("FACIL");
        break;
        default: printf("NOOOO!");
    }


    switch(5){
        case 2: {
            int c = 2+2;
            printf("%d", c);

        }
        break;
        case 10: {
            printf("El numero es 10");
        }
        break;
        default: {
            printf("No coincide ningun numero");
        }
    }
    return 0;
}
