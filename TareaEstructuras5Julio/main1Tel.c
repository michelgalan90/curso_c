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
    int cod_cli;
    char ape1_cli[21];
    char ape2_cli[21];
    char nom_cli[31];
    Telefono* telefono;
} Cliente;

typedef struct{
  
    char fecha[30];
    double consumo;
    double facturado;
} Consumo;

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

void fillJson(char* usuario, char* f_actual, char* programa, int* cod_cli,
        char* nom_cli, char* ape1_cli, char* ape2_cli, Telefono* telefono){

    printf("Introduzca el usuario del cliente: \n");
    scanf("%s", usuario);

    printf("Introduzca el f_actual del cliente: \n");
    scanf("%s", f_actual);

    printf("Introduzca el programa del cliente: \n");
    scanf("%s", programa);

    printf("Introduzca el codigo del cliente en formato Numerico: \n");
    scanf("%d", cod_cli);

    printf("Introduzca su nombre: \n");
    scanf("%s", nom_cli);

    printf("Introduzca su primer apellido: \n");
    scanf("%s", ape1_cli);

    printf("Introduzca su segundo apellido: \n");
    scanf("%s", ape2_cli);

    printf("Introduzca su numero de telefono: \n");
    scanf("%s", telefono->numero);
    
}

void calcularConsumo(Consumo* consu, int cantidad);
void fabricarJsonFactura(Consumo* consumos, int cantidad, char* json);

int main(){

  
    char json[200];
    Telefono* telefono = (Telefono*) malloc(sizeof(Telefono));

    char usuario[31];
    char f_actual[9];
    char programa[16];
    int cod_cli;
    char nom_cli[21];
    char ape1_cli[21];
    char ape2_cli[21];  

    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));

    cliente->telefono = telefono;
   
    fillJson(usuario, f_actual, programa, &cod_cli, nom_cli, ape1_cli, ape2_cli, telefono);

   // printf("-------------------------\n");

    
    sprintf(json,"{\"usuario\":\"%s\",\"f_actual\":\"%s\", \"programa\":\"%s\", \"cod_cli\":%ld, \"nom_cli\":\"%s\", \"ape1_cli\":\"%s\", \"ape2_cli\":\"%s\", \"telefono\":\"%s\"}", usuario, f_actual, programa, cod_cli, nom_cli, ape1_cli, ape2_cli, telefono->numero);

    //printf("%s\n", json);

   // printf("-------------------------\n");

   
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
            sprintf( cliente->usuario ,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
                   
            i++;
          //strcpy(cliente.usuario, facil);
        }
        else if(jsoneq(JSON_STRING, &t[i], "f_actual") == 0){
           // char* f_ac;
               /* We may use strndup() to fetch string value */
            sprintf(cliente->f_actual ,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
          //  strcpy(cliente.f_actual, f_ac);
        }  
        else if(jsoneq(JSON_STRING, &t[i], "programa") == 0){
          //  char* program;
               /* We may use strndup() to fetch string value */
            sprintf(cliente->programa, "%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
           // strcpy(cliente.programa, program);
        }   
        else if(jsoneq(JSON_STRING, &t[i], "cod_cli") == 0){
            
            char cod[30];

               /* We may use strndup() to fetch string value */
            sprintf( cod ,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;   
           // printf("%s\n", cod);

            int codigo = atoi(cod);   

            //printf("%d\n", codigo);  
            cliente->cod_cli = codigo;

        } 
        else if(jsoneq(JSON_STRING, &t[i], "nom_cli") == 0){
               /* We may use strndup() to fetch string value */
            sprintf( cliente->nom_cli,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        }  
        else if(jsoneq(JSON_STRING, &t[i], "ape1_cli") == 0){
               /* We may use strndup() to fetch string value */
            sprintf( cliente->ape1_cli,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        } 
        else if(jsoneq(JSON_STRING, &t[i], "ape2_cli") == 0){
               /* We may use strndup() to fetch string value */
            sprintf( cliente->ape2_cli,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        }  
         else if(jsoneq(JSON_STRING, &t[i], "telefono") == 0){
               /* We may use strndup() to fetch string value */
            sprintf( cliente->telefono->numero,"%.*s", t[i + 1].end - t[i + 1].start,
                    JSON_STRING + t[i + 1].start);
            i++;
        }  
 
    }

    //DARLE FORMATO IMPRESION DATOS DEL CLIENTE
    printf("\nEstos son los datos del cliente: \n");
    printf("Usuario: %-10s\tF_actual: %-10s\tPrograma: %-10s\tCodigo_Cliente:%d\t\nNombre: %s\t Primer_Apellido: %s\t Segundo_Apellido: %s\nTelefono: %s\n", cliente->usuario, cliente->f_actual, cliente->programa, cliente->cod_cli, cliente->nom_cli, cliente->ape1_cli, cliente->ape2_cli, cliente->telefono->numero);
      
    printf("******************************************************\n");
    printf("******************************************************\n");

    int consumos = 0;
    printf("Digite cuantos meses desea facturar: \n");
    scanf("%d", &consumos);

    Consumo* pConsumo = (Consumo*) malloc(consumos * sizeof(Consumo));

    for(int i = 0 ; i < consumos; i++){
        printf("Digite fecha del %d mes (yyyy-mm-dd): ", i+1);
        scanf(" %s", (pConsumo+i)->fecha);
        printf("Digite el consumo en kWh del mes %d: ", i+1);
        scanf(" %lf", &(pConsumo+i)->consumo);
    }

    calcularConsumo(pConsumo, consumos);

    char* jsonConsumos = (char*) malloc(500);

    fabricarJsonFactura(pConsumo, consumos, jsonConsumos);
   // printf("\n%s", jsonConsumos);

    //escribiendo json de consumos
    FILE* consumosJsonFile = fopen("consumos.json", "w");
    
    fprintf(consumosJsonFile, jsonConsumos);

    fclose(consumosJsonFile);
    printf("**********************************");
    printf("**********************************\n");
    printf("Datos de consumo mensuales: \n");

    for(int k =0; k < consumos; k++){
        printf("Factura %d\t", k+1);
        printf("Fecha: %s\t", (pConsumo+k)->fecha);
        printf("Consumo: %lf\t", (pConsumo+k)->consumo);
        printf("Facturado: %lf\t\n", (pConsumo+k)->facturado);
    }

    return 0;
}

void fabricarJsonFactura(Consumo* consumos, int cantidad, char* json){
           char* jsonTemp = (char*) malloc(500);
               strcat(jsonTemp, "{");
               strcat(jsonTemp, "\"");
               strcat(jsonTemp, "factura1");                  
               strcat(jsonTemp, "\":");   

            for(int contador = 0; contador < cantidad; contador++){

                char* consumoString = (char*) malloc(30);
                snprintf(consumoString, 30, "%lf", (consumos+contador)->consumo);
                char* facturadoString = (char*) malloc(50);
                snprintf(facturadoString, 50, "%lf", (consumos+contador)->facturado);


                strcat(jsonTemp, "{\"");
                strcat(jsonTemp, "fecha\":\"");
                strcat(jsonTemp, (consumos+contador)->fecha);
                strcat(jsonTemp, "\", \"consumo\":\"");
                strcat(jsonTemp, consumoString);
                strcat(jsonTemp, "\", \"facturado\":\"");                
                strcat(jsonTemp, facturadoString);
                strcat(jsonTemp, "\"}");

                if(contador<cantidad-1){
                    char* facil = (char*) malloc(20);
                    sprintf(facil, "%d", contador+2);
                    strcat(jsonTemp, ",\"factura");
                    strcat(jsonTemp, facil);
                    strcat(jsonTemp, "\":");

                }
                if(contador==cantidad-1){
                    strcat(jsonTemp, "}");
                }

                // printf("\n%s\n", jsonTemp);
                 
                 free(consumoString);
                 free(facturadoString);
            }
            memcpy(json, jsonTemp, 500);
            free(jsonTemp);
       
}

void calcularConsumo(Consumo* consu, int cantidad){
    for(int i = 0; i < cantidad; i++){
        
        double consumo = (consu+i)->consumo;

        double cargoFijo = 0.0;
        double cargoEnergia = 0.0;

        if(consumo<101){
            cargoFijo = 37.95;
        }else if(consumo > 100){
            cargoFijo = 137.25;
        }

        if(consumo > 1 && consumo <= 200){
            cargoEnergia = consumo * 4.44;
        }else if(consumo > 200 && consumo <= 300){
            double consumoFacil = 200* 4.44;
            double tarifaProv = consumo - 200;
            double tarifaEner = tarifaProv * 6.97;
            cargoEnergia = consumoFacil + tarifaEner;
        }else if(consumo > 300 && consumo <= 700){
            double consumoFacil = 200 * 4.44;
            double consumoFacilDosTres = 100 * 6.97;
            double tempo = consumo - 300;
            double consumoFacilTresSiete = tempo * 10.86;
            cargoEnergia = consumoFacil + consumoFacilDosTres + consumoFacilTresSiete;
        }

        double consumoPotente = cargoFijo + cargoEnergia;
        (consu+i)->facturado = consumoPotente;
    }
}