/*
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
    
    */

    /* sprintf(json,"{\"usuario\":\"%s\",\"f_actual\":\"%s\", \"programa\":\"%s\", \"cod_cli\":%ld, \"nom_cli\":\"%s\", \"ape1_cli\":\"%s\", \"ape2_cli\":\"%s\", \"telefonos\":%s}", usuario, f_actual, programa, cod_cli, nom_cli, ape1_cli, ape2_cli, telefonos);*/