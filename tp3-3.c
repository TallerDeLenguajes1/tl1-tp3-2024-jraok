#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5
#define M 12

void cargarMatriz(char **registro);
void limpiarMatriz(char **arreglo);
void liberarMemoria(char **nombres);
void mostrarMatriz(char **registro);

int main(){
    
    char **nombres = (char **)malloc(sizeof(char*)*N);
    for (int i = 0; i < M; i++){
        nombres[i] = (char*)malloc(sizeof(char)*M);
    }
    
    puts("\n\n\t\t\tREGISTRO DINAMICO");
    cargarMatriz(nombres);
    mostrarMatriz(nombres);
    liberarMemoria(nombres);
}

void limpiarMatriz(char **arreglo){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            arreglo[i][j]='\0';
        }
    }
}

void cargarMatriz(char **registro){
    char caracter;
    for (int i = 0; i < N; i++){
        int longitud=0,capacidad = 12;
        fflush(stdin);
        printf("\nIngrese el nombre %d (para terminar presione ENTER):\t",i+1);
        while ((caracter = getchar()) != '\n'){
            if (longitud >= capacidad){
                capacidad++;
                char *aux = (char*)malloc(sizeof(char)* longitud);
                registro[i] = aux;
            }
            registro[i][longitud]=(char)caracter;
            longitud++;
        }
        registro[i][longitud] = '\0';
    }
}

void liberarMemoria(char **nombres){
    for (int i = 0; i < N; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
}

void mostrarMatriz(char **registro){
    puts("\n\t\tNOMBRES INGRESADOS");
    for (int i = 0; i < N; i++)
    {
        printf("\nNombre %d:\t%s",i+1,registro[i]);
    }
}
