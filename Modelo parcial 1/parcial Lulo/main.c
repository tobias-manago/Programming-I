#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
#define FILAS 4
#define COLUMNAS 5
///constantes
int cargarArray(int arreglo[],int dim);
void mostrarArray(int validos,int arreglo[]);
void parOimpar(int validos,int arreglo[],int* pares,int* impares);
int sumatoriaArreglo(int arreglo[],int validos);
void pasarDeArregloaPila(int arreglo[],Pila* A,int validos);
void cargarMatrizRandom(int Matriz[FILAS][COLUMNAS]);
///prototipados


int main()
{
    ///punto 1
    int arreglo[50];
    int validos = cargarArray(arreglo,50);
    mostrarArray(validos,arreglo);
    ///punto 2
    int pares = 0;
    int impares = 0;
    parOimpar(validos,arreglo,&pares,&impares);
    printf("\nhay [%d] numeros pares, y [%d] numeros impares",pares,impares);
    ///punto 3
    int sumatoria = 0;
    sumatoria = sumatoriaArreglo(arreglo,validos);
    printf("\nla sumatoria es de : %d",sumatoria);
    ///punto 4
    Pila A;
    inicpila(&A);
    pasarDeArregloaPila(arreglo,&A,validos);
    mostrar(&A);
    ///punto 5
    int M1[FILAS][COLUMNAS];
    srand(time(NULL));
    cargar_la_matriz_con_numeros_random(M1);
    mostrarMatriz1(M1);



    return 0;
}
int cargarArray(int arreglo[],int dim)      ///funcion Punto 1
{
    int validos = 0;

    char opcion = 's';

    while((opcion == 's' || opcion == 'S') && validos < dim)
    {
        printf("ingrese un numero : ");
        scanf("%d",&arreglo[validos]);

        printf("deseas seguir cargando el arreglo [S/N]: ");
        fflush(stdin);
        scanf(" %c",&opcion);
        validos++;
    }
    return validos;
}
void mostrarArray(int validos,int arreglo[])
{
    printf("\n[");
    for(int i = 0;i<validos;i++)
    {
        printf("%d",arreglo[i]);
        if (i < validos - 1)
        {
            printf("|");
        }
    }
    printf("]");
}
void parOimpar(int validos,int arreglo[],int* pares,int* impares)///funcion 2
{
    for(int i = 0;i<validos;i++)
    {
        if(arreglo[i]%2 == 0)
        {
            (*pares)++;
        }
        else
        {
            (*impares)++;
        }
    }
}
int sumatoriaArreglo(int arreglo[],int validos)///funcion 3
{
    int sumatoria = 0;
    for(int i = 0;i<validos;i++)
    {
        if(arreglo[i] >= 10 && arreglo[i] <= 20)
        {
            sumatoria = sumatoria + arreglo[i];
        }
    }
    return sumatoria;
}
void pasarDeArregloaPila(int arreglo[],Pila* A,int validos)
{
    for(int i=0;i<validos && i<10;i++)
    {
        apilar(A,arreglo[i]);
    }
}
void cargar_la_matriz_con_numeros_random(int M1[FILAS][COLUMNAS])
{
    for(int i = 0; i < FILAS; i++)
    {
        for(int j = 0; j < COLUMNAS; j++)
        {
            M1[i][j]=rand()%101;
        }
    }
}
void mostrarMatriz1(int M1[FILAS][COLUMNAS])
{
    printf("\n La matriz de numeros ramdom es ");
    for(int i = 0; i < FILAS; i++)
    {
        printf("\n");
        for(int j = 0; j < COLUMNAS; j++)
        {
            printf("%d,", M1[i][j]);
        }
    }
}
