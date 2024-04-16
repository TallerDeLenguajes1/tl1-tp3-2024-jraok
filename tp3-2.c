#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5
#define M 12

void cargarMatriz(int matriz[N][M]);
void mostrarMatriz(int matriz[N][M]);
void promediar(int matriz[N][M], float promedios[N]);
void mejorVenta(int matriz[N][M]);

int main(){
    srand(time(NULL));
    puts("\n\t\t\t----REGISTRO PRODUCCION----\n");
    int matriz[N][M];
    float anuales[N];
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    promediar(matriz,anuales);
    mejorVenta(matriz);
    return 0;
}


void cargarMatriz(int matriz[N][M]){

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matriz[i][j] = 40000 + rand()%10000;
        }
    }

}

void mostrarMatriz(int matriz[N][M]){

    printf("Registro de produccion de los ultimos anios:\n");

    for (int i = 0; i < N; i++)
    {
        printf("\nANIO %d\n",2019+i);
        for (int j = 0; j < M; j++)
        {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
}

void promediar(int matriz[N][M], float promedios[N]){
    for (int i = 0; i < N; i++){
        promedios[i] = 0;
    }
    
    puts("\n\t\t\t----Promedio de ganancias por anio----");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
        {
            promedios[i] += matriz[i][j] / 12;
        }
        printf("\nPromedio de %d: $%.3f",2019+i,promedios[i]);
    }
    
}

void mejorVenta(int matriz[N][M]){
    char meses[12][12]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};

    puts("\n\n\t\t\t----Mejores meses de ventas----");

    for (int i = 0; i < N; i++){
        int m = 0, c = 0;
        for (int j = 0; j < M; j++){
            if (matriz[i][j]>c){
                c = matriz[i][j];
                m = j;
            }
        }
        printf("\nEl mejor mes del %d es %s con %d ventas",2019+i,meses[m],c);
        
    }
    
}

