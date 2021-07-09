#include <stdio.h>
#include <string.h>

int main(){

    char str[80] = "Hello World";
    printf("Message is: %s\n", str);

    strcpy(str, "Hola amigo");

    printf("Mensaje: %s\n", str);

    char str1[] = "Hello Candy";
    strcpy(str, str1);

    printf("str: %s\n", str);

    return 0;
}