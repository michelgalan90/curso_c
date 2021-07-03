#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * fpointer = fopen("empleado.txt", "a");
    
    fprintf(fpointer, " eso es bien facil \n");

    fclose(fpointer);
    return 0;
}
