#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipos de funciones
int loadArrays(int A[], int dimension);
void showArray(int A[], int validosA);
int plusArray (int A[],int validosA);
int main()
{
    int A[10];
    int validosA = loadArrays(A, 10);
    printf("Cantidad de elementos cargados: %i\n", validosA);

    showArray(A, validosA);

    int rtnplusArray = plusArray(A,validosA);
    printf("el resultado de la suma de los elementos del arreglo es : %d",rtnplusArray);

    desapilarArray(A,validosA);
    return 0;
}

int loadArrays(int A[], int dimension)
{
    char opcion = 's';
    int i = 0;
    while ((opcion == 's' || opcion == 'S') && i < dimension)
    {
        printf("Ingresa un numero entero: ");
        scanf("%d", &A[i]);
        i++; // i es la cantidad de números válidos cargados en el array

        printf("Desea seguir cargando [s/n]: ");
        fflush(stdin);
        scanf(" %c", &opcion); // Espacio antes de %c para ignorar el salto de línea
    }
    return i;
}

void showArray(int A[], int validosA)
{
    printf("Contenido del arreglo: [ ");
    for (int i = 0; i < validosA; i++)
    {
        printf("%d", A[i]);
        if (i < validosA - 1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}
int plusArray (int A[],int validosA)
{
    int suma = 0;

    for (int i = 0 ; i<validosA ; i++)
    {
        suma+=A[i];
    }
    return suma;
}

void desapilarArray(int A[], int validosA)
{
    Pila pilita;
    inicpila(&pilita);

    for (int i = 0; i < validosA; i++)
    {
        apilar(&pilita,A[i]);
    }
    mostrar(&pilita);
}


