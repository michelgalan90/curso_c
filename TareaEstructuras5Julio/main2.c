#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jsmn.h"
#define SIZE 300

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
} Cliente;

int cantidadTel;

/*
agregar un contador que mida por 2 o 3 meses la corriente en kilowatts
ano/mes/dia formato fecha
tener 2 o tres meses*/

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
  if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
      strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
    return 0;
  }
  return -1;
}

void fillJson(char* usuario, char* f_actual, char* programa, long* cod_cli,
        char* nom_cli, char* ape1_cli, char* ape2_cli, char* telefonos){

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

    printf("Introduzca su primer apellido: \n");
    scanf("%s", ape1_cli);

    printf("Introduzca su segundo apellido: \n");
    scanf("%s", ape2_cli);

    printf("Introduzca cuantos No. telefono tiene: \n");
    scanf("%d", &cantidadTel);

    if(cantidadTel >= 1){
            char tele[300];
                for(int contador = 0; contador < cantidadTel; contador++){
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

    //return cantidadTel;
        
 //   return cantidadTel;
}

/*
void fillPhone(char* telefonos, int cantidadTelefono){
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
}*/


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

   // int cantidadTelefono;

  //  cantidadTelefono = fillJson(usuario, f_actual, programa, &cod_cli, nom_cli, ape1_cli, ape2_cli);
    fillJson(usuario, f_actual, programa, &cod_cli, nom_cli, ape1_cli, ape2_cli, telefonos);

    Telefono* teles;

    Cliente cliente;


   // cliente.telefono = teles;
   /*  if(cantidadTelefono >= 1){
            char tele[300];
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
     */
  //  fillPhone(telefonos, cantidadTelefono);
           

    printf("-------------------------\n");

    
    sprintf(json,"{\"usuario\":\"%s\",\"f_actual\":\"%s\", \"programa\":\"%s\", \"cod_cli\":%ld, \"nom_cli\":\"%s\", \"ape1_cli\":\"%s\", \"ape2_cli\":\"%s\", \"telefonos\":%s}", usuario, f_actual, programa, cod_cli, nom_cli, ape1_cli, ape2_cli, telefonos);

    printf("%s\n", json);

    printf("-------------------------\n");

   
    FILE* jsonFile = fopen("cliente.json", "w");
    
    fprintf(jsonFile, json);

    fclose(jsonFile);


    /* -----------------Leyendo JSON---------------*/

    char* filename = "cliente.json";
    FILE* fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: no se pudo abrir el archivo %s", filename);
        return 1;
    }

    char JSON_STRING[SIZE];
    
    fgets(JSON_STRING, SIZE, fp);

  
    jsmn_parser parser;
    jsmntok_t t[120];
    jsmn_init(&parser);

    int resultado = jsmn_parse(&parser, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));
   
    if(resultado < 0){
        printf("Failed to parse JSON: %d\n", resultado);
        return 1;
    }
    if(resultado < 1 || t[0].type != JSMN_OBJECT){
        printf("Object expected\n");
        return 1;
    }
    
    
    int i;

    for (i = 1; i < resultado; i++) {
        if (jsoneq(JSON_STRING, &t[i], "usuario") == 0) {
            /* We may use strndup() to fetch string value */
          //  char* facil;
            printf("usuario: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
          //strcpy(cliente.usuario, facil);
        }
        else if(jsoneq(JSON_STRING, &t[i], "f_actual") == 0){
           // char* f_ac;
               /* We may use strndup() to fetch string value */
            printf("f_actual: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
          //  strcpy(cliente.f_actual, f_ac);
        }  
        else if(jsoneq(JSON_STRING, &t[i], "programa") == 0){
          //  char* program;
               /* We may use strndup() to fetch string value */
            printf("programa: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
           // strcpy(cliente.programa, program);
        }   
        else if(jsoneq(JSON_STRING, &t[i], "cod_cli") == 0){
          //  char* codigo;
               /* We may use strndup() to fetch string value */
            printf("cod_cli: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;

            
           // long vOut = strtol(codigo,NULL,10);
          //  cliente.cod_cli = vOut;
         

        } 
        else if(jsoneq(JSON_STRING, &t[i], "nom_cli") == 0){
               /* We may use strndup() to fetch string value */
            printf("nom_cli: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        }  
        else if(jsoneq(JSON_STRING, &t[i], "ape1_cli") == 0){
               /* We may use strndup() to fetch string value */
            printf("ape1_cli: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        } 
        else if(jsoneq(JSON_STRING, &t[i], "ape2_cli") == 0){
               /* We may use strndup() to fetch string value */
            printf("ape2_cli: %.*s\n", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        }  

           
        else if (jsoneq(JSON_STRING, &t[i], "telefonos") == 0) {
                int j;
                printf("telefonos:\n");
                if (t[i + 1].type != JSMN_ARRAY) {
                    continue; /* We expect groups to be an array of strings */
                }
                for (j = 0; j < t[i + 1].size; j++) {
                    jsmntok_t *g = &t[i + j + 2];
                    printf("        * %.*s\n", g->end - g->start, JSON_STRING + g->start);
                }
            i += t[i + 1].size + 1;
        }
    }

  //  printf("---------------");
  //  printf("%s%ld", cliente.usuario, cliente.cod_cli);
    // system("pause");
    return 0;
}