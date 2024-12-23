#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libreria.h"

int main(int argc, char *argv[]){
    // Variables
    int numLines; // Numero de lineas de el programa
    int option; // 1=head, 2=tail, 3=longlines

    // Prueba de parametros minimo 1 maximo 2
    if(argc > 3 || argc < 2) {
        fprintf(stderr,"Error, correct usage: %s option(1: head, 2:tail, 3:longlines) N(optional)\n",argv[0]);
        return 1;
    }

    option = strtol(argv[1], NULL, 10); // selecion de opcion.

    if(argc == 3){
        numLines = strtol(argv[2], NULL, 10); // SI te dan N
        if(numLines <= 0){ // si no te dan N o no es valido, N = 10
            numLines = 10;
        }
    } else { // Valor por defecto.
        numLines = 10;
    }

    // si el argumento no es valido.
    if(option <= 0 || option > 3){
        fprintf(stderr,"Error, invalid option.\n");
        return 1;
    }

    // inicio de la prueba de las tres funciones, y sus salidas de error.
    if(option == 1){
        // head(n) 
        printf("Starting the test for head(n): \n\n");
        if(head(numLines) != 0){
            printf("Error performing head, the file does not exist.\n\n");
            return 1;
        }
    } else if(option == 2){
        // tail(n) 
        printf("\nStarting the test for tail(n): \n\n");
        if(tail(numLines) != 0){
            printf("Error performing tail(n), the file does not exist.\n\n");
            return 1;
        }
    } else if(option == 3){
        // longlines(n) 
        printf("\nStarting the test for longlines(n): \n\n");
        if(longlines(numLines) != 0){
            printf("Error performing longlines(n), the file does not exist.");
            return 1;
        }
    } else {
        return 1;
    }

    // finalizado correctamente
    printf("\nTest successful, end of the test program.\n");
    exit(0);
}

