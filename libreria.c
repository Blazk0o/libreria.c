#include <stdio.h> //fgets, print
#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#define LEN 1024

typedef struct Lista { //declaramos una lista con puntero next
		char cadena[LEN];
		struct Lista *next;
}Lista;

Lista *lista=NULL;

int head (int N){ //creamos la funcion head
	
	int i;       //contador de bucle
	char buffer[LEN];  //declaramos buffer LEN vale 1024
	
	
	for (i=0; i<N; i++){
    		if (fgets(buffer,LEN,stdin)==NULL) // Removed semicolon here
        		break; //rompe el programa
    		strtok(buffer, "\n");
    		fputs(buffer,stdout);  //fputs muestra por pantalla el contenido del buffer
		}
	return 0; //ejecucion acabada con exito
	}

void insertFinal(char caracter[LEN]){ //metodo de insertar final de lista
	
	Lista *nodo = malloc(sizeof(Lista)); //reserva de memoria
    if (nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nodo->cadena, caracter);//copia la cadena en caracter
    nodo->next = NULL;

    Lista *aux = lista;
    if (aux == NULL) {
        lista = nodo;
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = nodo;
    }
}

void insertaOrdenado(char caracter[LEN]){ //metodo de ordenacion en una lista
	
	Lista *nodo; // Puntero al nuevo nodo a insertar
	Lista *aux; // Puntero auxiliar para recorrer la lista
	Lista *aux2; // Puntero auxiliar para mantener el nodo anterior en la lista
	nodo=malloc(sizeof (Lista)); // Reserva de memoria para el nuevo nodo
	strcpy(nodo->cadena,caracter); // Copia la cadena de entrada en el nuevo nodo
	nodo->next=NULL; // Inicializa el puntero al siguiente nodo como NULL
	if (lista==NULL) // Si la lista está vacía
		lista=nodo; // Inserta el nuevo nodo en la lista
	else{ // Si la lista no está vacía
		aux=lista; 
		if(strlen(nodo->cadena) > strlen(lista->cadena)){ 
		// Si la longitud de la cadena del nuevo nodo es mayor que la del primer nodo de la lista
				nodo->next=lista; // El nuevo nodo apunta al primer nodo de la lista
				lista=nodo; // El nuevo nodo se convierte en el primer nodo de la lista
		}
		else{ // Si la longitud de la cadena del nuevo nodo no es mayor que la del primer nodo de la lista
			aux=lista;
			aux2=NULL;
			while (aux != NULL && strlen(nodo->cadena) <= strlen(aux->cadena)){ 
	// Recorre la lista hasta encontrar un nodo cuya cadena es más corta que la del nuevo nodo, o hasta llegar al final de la lista
				aux2=aux;
				aux=aux->next;
			}
			if (aux2 == NULL){ // Si no se ha encontrado ningún nodo con una cadena más corta
				nodo->next = lista; // El nuevo nodo apunta al primer nodo de la lista
				lista = nodo; // El nuevo nodo se convierte en el primer nodo de la lista
			} else { // Si se ha encontrado un nodo con una cadena más corta
				nodo->next = aux; // El nuevo nodo apunta al nodo encontrado
				aux2->next = nodo; // El nodo anterior al nodo encontrado apunta al nuevo nodo
			}
		}
	}
}



void mostrar(void){ //metodo de mostrar
	Lista *aux;
	Lista *aux2;
	
	
	
	while(aux !=NULL){ //muestra todas las lineas hasta llegar a vacio
		aux2=aux;
		printf("%s", aux->cadena);
		aux=aux->next;
		free(aux2);
		}
	}
int tail(int N){ //metodo tail 
	
	int contL=0; // Contador para el número total de líneas leídas
    	int contP=0; // Contador para el número de líneas impresas
   	char buffer[LEN]; // Búfer para almacenar temporalmente cada línea leída
  	Lista *aux; // Puntero auxiliar para recorrer la lista
  	Lista *aux2; // Puntero auxiliar para liberar la memoria de los nodos
	
	
	
	while(fgets(buffer,LEN,stdin)){ //lee el buffer hasta llegar a fin del fichero
		
		if (feof(stdin))
			break;
		insertFinal(buffer);
		contL++;
		
		}
		
		ini=contL - N;
		if (contL<N){
			mostrar();
			}
		else{
			aux=lista;
			while(aux !=NULL){
				aux2=aux;
				contP++;
				if (contP>ini)
					printf("%s",aux->cadena);
				aux=aux->next;
				free(aux2);
				}//saca los ultimos n elementos
			
			}
		return 0; //ejecucion acabada con exito	
	}

int longlines(int N){
    int contL=0; // Contador para el número total de líneas leídas
    int contP=0; // Contador para el número de líneas impresas
    char buffer[LEN]; // Búfer para almacenar temporalmente cada línea leída
    Lista *aux; // Puntero auxiliar para recorrer la lista
    Lista *aux2; // Puntero auxiliar para liberar la memoria de los nodos

    // Leer líneas de la entrada estándar hasta el final del archivo
    while(fgets(buffer,LEN,stdin)){
        if (feof(stdin))
            break;
        // Insertar cada línea en la lista en un orden determinado por la longitud de la línea
        insertaOrdenado(buffer);
        contL++;
    }
    
    // Si el número total de líneas leídas es menor que N, imprimir todas las líneas
    if(contL < N){
        mostrar();
    }
    else{
        aux=lista;
        // Recorrer la lista e imprimir las N líneas más largas
        while(aux !=NULL){
            aux2=aux;
            contP++;
            if(contP<=N)
                printf("%s",aux->cadena);
            aux=aux->next;
            // Liberar la memoria del nodo después de imprimirlo
            free(aux2);
        }
    }
    return 0; // Devolver 0 para indicar que la función se ha ejecutado correctamente
}

