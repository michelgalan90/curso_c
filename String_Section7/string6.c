#include <stdio.h>
#include <string.h>

int main(){

    char my_str[] = "In this programme otorrinolaringologo we will find the longest word in a string";

    int longest = 0;
    char word[20]; 
    char longestWord[20]; 

    int i = 0, j;
    int flag = 0;

    while(my_str[i]!='\0'){
        if(flag == 0){
            j = 0; 
            flag = 1;
            memset(word, 0, sizeof(word));
        }
        if(my_str[i] != ' ' ){
           
            word[j] = my_str[i]; 
            j++;          

        }else if(my_str[i] == ' '){
            strcat(word, "\0");
            if(strlen(word) > longest){
                longest = strlen(word);
                strcpy(longestWord, word);
            }
            flag = 0;
        }

        i++;
       
    }
    printf("Longest word: %s\n", longestWord);
    printf("Length: %d\n", longest);

    return 0;
}
