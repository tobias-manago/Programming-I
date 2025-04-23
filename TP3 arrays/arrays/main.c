#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipos de funciones
int loadArrays(int A[], int dimension);
void showArray(int A[], int validosA);
Pila desapilarArray(int A[], int validosA);
int plusArray (int A[],int validosA);
float loadArraysF (float F[], int dimension);
void showArrayF(float F[], int validosF);
float plusArrayF (float F[],int validosF);
int loadArraysC(char C[], int dimension);
int contieneCaracter(char C[], int dimension, char elementoBuscado);
void insertarOrdenado(char C[], int* validos, char nuevoChar);
int main()
{
    int A[10];
    int validosA = loadArrays(A, 10);
    printf("Cantidad de elementos cargados: %i\n", validosA);

    showArray(A, validosA);

    int rtnplusArray = plusArray(A,validosA);
    printf("el resultado de la suma de los elementos del arreglo es : %d",rtnplusArray);


    Pila Pa;
    inicpila(&Pa);
    Pa = desapilarArray(A,validosA);
    mostrar(&Pa);



    /*
    float F[100];

    int validosF = loadArraysF(F,100);

    showArrayF(F,validosF);

    float rtnplusArrayF = plusArrayF(F,validosF);
    printf("el resultado de la suma de los elementos del arreglo float es : %.2f \n",rtnplusArrayF);
    */


    char C[50];
    char elementoBuscado;
    int validosC = loadArraysC(C,50);
    printf("que elemento desea encontrar: ");
    scanf(" %c",&elementoBuscado);
    int RtncontieneCaracter = contieneCaracter(C,50,elementoBuscado);
    if (RtncontieneCaracter = 1)
    {
        printf("el elemento buscado se encuentra en el arreglo de caracteres ");
    }
    else
    {
        printf("el elemento buscado no se encuentra en el arreglo de caracteres ");
    }

    char nuevoChar;
    printf("\nque dato desea ingresar en el arreglo de caracteres ?: ");
    fflush(stdin);
    scanf("%c",&nuevoChar);
    insertarOrdenado(C,validosC,nuevoChar);

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

        printf("Desea seguir cargando el arreglo [s/n]: ");
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

Pila desapilarArray(int A[], int validosA)
{
    Pila pilita;
    inicpila(&pilita);

    for (int i = 0; i < validosA; i++)
    {
        apilar(&pilita,A[i]);
    }
    return pilita;
}

float loadArraysF (float F[], int dimension)
{
    char opcion = 's';
    int i = 0;
    while ((opcion == 's' || opcion == 'S') && i < dimension)
    {
        printf("Ingresa un numero : ");
        scanf("%f", &F[i]);
        i++;

        printf("Desea seguir cargando el arreglo de flotantes [s/n]: ");
        fflush(stdin);
        scanf(" %c", &opcion);
    }

    return i;
}
void showArrayF(float F[], int validosF)
{
    printf("Contenido del arreglo float: [ ");
    for (int i = 0; i < validosF; i++)
    {
        printf("%.2f", F[i]);
        if (i < validosF - 1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}
float plusArrayF (float F[],int validosF)
{
    float suma = 0;

    for (int i = 0 ; i<validosF ; i++)
    {
        suma+=F[i];
    }
    return suma;
}
int loadArraysC(char C[], int dimension)
{
    char opcion = 's';
    int i = 0;
    while ((opcion == 's' || opcion == 'S') && i < dimension)
    {
        printf(" Ingresa las letras que quieras : ");
        scanf(" %c",&C[i]);
        i++;

        printf("Desea seguir cargando el arreglo de caracteres [s/n]: ");
        fflush(stdin);
        scanf(" %c", &opcion); // Espacio antes de %c para ignorar el salto de línea
    }
    return i;
}
int contieneCaracter(char C[], int dimension, char elementoBuscado)
{
    for (int i = 0; i < dimension; i++)
    {
        if (C[i] == elementoBuscado)
        {
            return 1;
        }
    }
    return 0;
}
// Inserta un carácter manteniendo el orden alfabético
void insertarOrdenado(char C[], int* validosC, char nuevoChar)
{
    int i = *validosC - 1;
    while (i >= 0 && C[i] > nuevoChar)
    {
        C[i + 1] = C[i];
        i--;
    }
    C[i + 1] = nuevoChar;
    (*validosC)++;
}

// Devuelve el carácter máximo del arreglo
char maxCaracter(char C[], int validos)
{
    char max = C[0];
    for (int i = 1; i < validos; i++)
    {
        if (C[i] > max)
            max = C[i];
    }
    return max;
}

// Devuelve 1 si el arreglo es capicúa, 0 si no lo es
int esCapicua(int A[], int validos)
{
    for (int i = 0; i < validos / 2; i++)
    {
        if (A[i] != A[validos - 1 - i])
            return 0;
    }
    return 1;
}

// Invierte el arreglo sin usar auxiliar
void invertirArreglo(int A[], int validos)
{
    for (int i = 0; i < validos / 2; i++)
    {
        int aux = A[i];
        A[i] = A[validos - 1 - i];
        A[validos - 1 - i] = aux;
    }
}

// Ordenamiento por selección
void ordenarSeleccion(int A[], int validos)
{
    for (int i = 0; i < validos - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < validos; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

// Ordenamiento por inserción
void ordenarInsercion(int A[], int validos)
{
    for (int i = 1; i < validos; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Intercala dos arreglos de chars ordenados en uno nuevo, también ordenado
int intercalarArreglos(char A[], int validosA, char B[], int validosB, char C[])
{
    int i = 0, j = 0, k = 0;
    while (i < validosA && j < validosB)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while (i < validosA) C[k++] = A[i++];
    while (j < validosB) C[k++] = B[j++];
    return k; // Retorna la cantidad de elementos en C
}

// Genera vector acumulativo como {1,6,12,19,27}
void generarAcumulado(int A[], int validos, int resultado[])
{
    int suma = 0;
    for (int i = 0; i < validos; i++)
    {
        suma += A[i];
        resultado[i] = suma;
    }
}
