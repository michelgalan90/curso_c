#include <stdio.h>

int main()
{
    char str[100];
    int i;

    printf("Entre el nombre y la edad: ");
    scanf("%s %d", str, &i);

    printf("\nDigito: Nombre-%s :: Edad-%d", str, i);

    double x;

    printf("\nDigite un numero: ");
    scanf("%lf", &x);

    printf("El cuadrado de ese numero es: %lf", x * x);

    return 0;

}
