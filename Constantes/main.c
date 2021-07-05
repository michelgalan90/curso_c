#include <stdio.h>
#include <stdlib.h>

#define EDAD 35 // declarando constante - otra manera

int main()
{
    const int FAV_NUM = 5;
    printf("%d\n", FAV_NUM);
    //num = 8;

    printf("%i\n", FAV_NUM);

    printf("La constante EDAD: %d", EDAD);
    return 0;
}
