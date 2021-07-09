#include <stdio.h>
#include <string.h>

int main(){

    char first[80] = "zebra";
    char second[80] = "zebra";

  //  strcpy(second, first);
  //  printf("%s", second);

  //  strcat(first, " ");
  //  strcat(first, second);
  //  printf("%s", first);
    int i;
    i = strcmp(first, second); // comparar string lexicamente a ver cual va antes en el alfabeto
    if(i==0){
        printf("Both are exactly equal\n");
    }else if(i<0){
        printf("%s comes first\n", first);
    }else{
        printf("%s comes first\n", second);
    }

    return 0;
}