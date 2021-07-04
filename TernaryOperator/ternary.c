#include <stdio.h>

int main(){

    int a,b;
    a = 10;
    b = 5;

    int max;

    if(a>b){
        max = a;
    }else {
        max = b;
    }
    printf("The max number is: %d\n", max);

    int c = 20;
    int d = 45;

    max = c > d ? c : d;

    printf("The max number using ternary is: %d\n", max);

    printf("The size of max: %d", sizeof(max));

    return 0;

}