#include <stdio.h>
#include <string.h>

typedef struct{
    char usuario[9];
    char f_actual[9];
    char programa[16];
    char numero[20];
} Telefono;

typedef struct{
    char usuario[31];
    char f_actual[9];
    char programa[16];
    long cod_cli;
    char ape1_cli[21];
    char ape2_cli[21];
    char nom_cli[31];
    Telefono* telefono;
} Clientes;

int main(){
    char json[200];

    char telefonos[200];

    char usuario[31];
    char f_actual[9];
    char programa[16];
    long cod_cli;
    char nom_cli[21];
    char ape1_cli[21];
    char ape2_cli[21];
   // char numTelefono[20];

    int cantidadTelefono;

    printf("Introduzca el usuario del cliente: \n");
    scanf("%s", usuario);

    printf("Introduzca el f_actual del cliente: \n");
    scanf("%s", f_actual);

    printf("Introduzca el programa del cliente: \n");
    scanf("%s", programa);

    printf("Introduzca el codigo del cliente en formato Numerico: \n");
    scanf("%ld", &cod_cli);

    printf("Introduzca su nombre: \n");
    scanf("%s", nom_cli);

   // printf("Su nombre es: %s", nombre);
    printf("Introduzca su primer apellido: \n");
    scanf("%s", ape1_cli);

    printf("Introduzca su segundo apellido: \n");
    scanf("%s", ape2_cli);

    printf("Introduzca cuantos No. telefono tiene: \n");
    scanf("%d", &cantidadTelefono);

    

    if(cantidadTelefono >= 1){
        char tele[150];
            for(int contador = 0; contador < cantidadTelefono; contador++){
                printf("Digite el telefono %d\n", contador + 1 );
                scanf("%s", tele);
                
                if(contador == 0){
                    strcat(telefonos, "[");
                    strcat(telefonos, "\"");
                    strcat(telefonos, tele);
                    strcat(telefonos, "\"");
                }
                
                if(contador>0){
                
                    strcat(telefonos, ",");
                    strcat(telefonos, "\"");
                    strcat(telefonos, tele);
                    strcat(telefonos, "\""); 
                    
                }
            }
        strcat(telefonos, "]");
    }
        

    printf("-------------------------\n");
  //  printf("%s\n", telefonos);

     sprintf(json,"{\"usuario\":\"%s\",\"f_actual\":\"%s\", \"programa\":\"%s\", \"cod_cli\":%ld, \"nom_cli\":\"%s\", \"ape1_cli\":\"%s\", \"ape2_cli\":\"%s\", \"telefonos\":%s}", usuario, f_actual, programa, cod_cli, nom_cli, ape1_cli, ape2_cli, telefonos);

    printf("%s\n", json);

  
    /* Escribiendo el archivo json. */
   
    FILE* jsonFile = fopen("cliente.json", "w");
    
    fprintf(jsonFile, json );

    fclose(jsonFile);


    /* -----------------Leyendo JSON---------------*/


 
    return 0;
}