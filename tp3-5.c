#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define M 12

void cargarMatriz(char **registro, int cantidad);
void limpiarMatriz(char **arreglo, int cantidad);
void liberarMemoria(char **nombres, int cantidad);
void mostrarMatriz(char **registro, int cantidad);

int main(){

    int cantidad=0;
    do{
        printf("\n\t\tIngrese la cantidad de nombres:\t");
        scanf("%d",&cantidad);
        if (cantidad <= 0){
            printf("\n\t\t----Valor invalido----\t");   
        }
    } while (cantidad <= 0);
    
    char **nombres = (char **)malloc(sizeof(char*)*cantidad);
    for (int i = 0; i < M; i++){
        nombres[i] = (char*)malloc(sizeof(char)*M);
    }
    
    puts("\n\n\t\t\tREGISTRO DINAMICO");
    cargarMatriz(nombres, cantidad);
    mostrarMatriz(nombres, cantidad);
    liberarMemoria(nombres, cantidad);

    return 0;
}

void limpiarMatriz(char **arreglo, int cantidad){
    for (int i = 0; i < cantidad; i++){
        for (int j = 0; j < M; j++){
            arreglo[i][j]='\0';
        }
    }
}

void cargarMatriz(char **registro, int cantidad){
    limpiarMatriz(registro, cantidad);
    char caracter;
    for (int i = 0; i < cantidad; i++){
        int longitud=0, capacidad = 12;
        fflush(stdin);
        printf("\nIngrese el nombre %d (para terminar presione ENTER):\t",i+1);
        while ((caracter = getchar()) != '\n'){
            if (longitud >= capacidad){
                capacidad++;
                char *aux = (char*)realloc(registro[i],sizeof(char)* capacidad);
                registro[i] = aux;
            }
            registro[i][longitud]=(char)caracter;
            longitud++;
        }
        registro[i][longitud] = '\0';
    }
}

void liberarMemoria(char **nombres, int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
}

void mostrarMatriz(char **registro, int cantidad){
    puts("\n\t\t\tNOMBRES INGRESADOS");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nNombre %d:\t%s",i+1,registro[i]);
    }
    printf("\n\n");
}
