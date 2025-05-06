#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define DIMROWS 3
#define DIMCOLS 3
void cargarMatriz(int M[DIMROWS][DIMCOLS]);
void mostrarMatriz(int M[DIMROWS][DIMCOLS]);
void cargar_la_matriz_con_numeros_random(int M1[DIMROWS][DIMCOLS]);
void mostrarMatriz1(int M1[DIMROWS][DIMCOLS]);
float promedio_Matriz (int M[DIMROWS][DIMCOLS]);
int saber_si_tiene_un_dato(int M[DIMROWS][DIMCOLS],int dato);
int main()

{
    int M [DIMROWS][DIMCOLS] = { {1,2,3},{4,5,6},{7,8,9} };
    M [0][0] = 3 ;      ///en la la fila 0 columna 0 es 3

    int M1 [DIMROWS][DIMCOLS];
    cargarMatriz(M);
    mostrarMatriz(M);
    srand(time(NULL));
    cargar_la_matriz_con_numeros_random(M1);
    mostrarMatriz1(M1);
    sumarMatriz(M);
    promedio_Matriz(M);
    int dado;
    printf("\n que numero desea saber si esta dentro de la matriz: ");
    scanf("%d",&dado);
    int TorF = saber_si_tiene_un_dato(M,dado);
    printf("\n si muestra 1 esta el dato, si muestra 0 no esta: %d",TorF);



    return 0;
}

void cargarMatriz(int M[DIMROWS][DIMCOLS])
{
    for(int i = 0; i < DIMROWS; i++)
    {
        for(int j = 0; j < DIMCOLS; j++)     ///asi podemos recorrer una matriz
        {
            printf("Que numero desea ingresar en la matriz: ");
            scanf("%d",&M[i][j]);
        }
    }
}

void mostrarMatriz(int M[DIMROWS][DIMCOLS])
{
    for(int i = 0; i < DIMROWS; i++)
    {
        printf("\n");
        for(int j = 0; j < DIMCOLS; j++)
        {
            printf("%d,", M[i][j]);
        }
    }
}

void cargar_la_matriz_con_numeros_random(int M1[DIMROWS][DIMCOLS])
{
    for(int i = 0; i < DIMROWS; i++)
    {
        for(int j = 0; j < DIMCOLS; j++)
        {
            M1[i][j]=rand()%101;
        }
    }
}
void mostrarMatriz1(int M1[DIMROWS][DIMCOLS])
{
    printf("\n La matriz de numeros ramdom es ");
    for(int i = 0; i < DIMROWS; i++)
    {
        printf("\n");
        for(int j = 0; j < DIMCOLS; j++)
        {
            printf("%d,", M1[i][j]);
        }
    }
}

void sumarMatriz(int M[DIMROWS][DIMCOLS])
{
    int sumatoria = 0;

    for(int i = 0; i < DIMROWS; i++)
    {
        for(int j = 0; j < DIMCOLS; j++)
        {
            sumatoria=sumatoria+M[i][j];
        }
    }
    printf("\n la sumatoria del arreglo es de: %i",sumatoria);
}

float promedio_Matriz (int M[DIMROWS][DIMCOLS])
{
    int sumatoria = 0;

    float promedio = 0;

    for(int i = 0; i < DIMROWS; i++)
    {
        for(int j = 0; j < DIMCOLS; j++)
        {
            sumatoria=sumatoria+M[i][j];
        }
    }
    int Dim = DIMROWS * DIMCOLS;
    printf("\n %d",Dim);
    promedio = sumatoria / Dim;
    printf("\n el promedio del arreglo es: %.2f", promedio);
}

int saber_si_tiene_un_dato(int M[DIMROWS][DIMCOLS],int dato)
{
    int TorF = 0;

    for(int i = 0; i < DIMROWS; i++)
    {
        for(int j = 0; j < DIMCOLS; j++)
        {
            if(dato == M[i][j])
            {
              TorF = 1 ;
            }
            else
            {
              TorF = 0 ;
            }
        }
    }
    return TorF;
}
int cargarStrings()
{
    char opcion = 's';

     while()
}
