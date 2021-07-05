#include <stdio.h>

int main(int argc, char *argv[])
{
    int numberOfArguments = argc;

    char* argument1 = argv[0];
   // char* argument2 = argv[1];

    printf("Number of arguments: %d", numberOfArguments);
    
    for (int i = 0; i < numberOfArguments; i++)
    {
        printf("%s%\n", argv[i]);
    }
    
   // printf("Argument 2 is the command line argument: %s", argument2);


    return 0;
}
