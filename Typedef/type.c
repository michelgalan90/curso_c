#include <stdio.h>

typedef int NUMBER;
typedef enum {monday, tuesday, wednesday, thursday, friday, saturday, sunday} WEEKDAY;

int main(){

    NUMBER one = 1;
    NUMBER two = 2;

    printf("El numero es : %d\n", one);

    WEEKDAY dia = monday;

    if(dia == monday){
        printf("Hoy es lunes");
    }else{
        puts("Hoy no es lunes");
    }

    return 0;
}