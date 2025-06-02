#include <stdio.h>
#include <stdlib.h>
void showArray(int A[], int validosA);
int loadArrays(int A[], int dimension);
void pasarPares(int A[],int* ArrDin, int validosA);
int contarPares(int A[], int validosA);
int crearArregloDin(int validosAdin,int A[], int validosA);
int main()
{
///2A

    int A[5];
    int validosA=loadArrays(A,50);
    /*
    showArray(A,validosA);
    int cantPares=contarPares(A,validosA);
    int* ArrDin= (int*)malloc(sizeof(int)* cantPares);
    pasarPares(A, ArrDin, validosA);
    showArray(ArrDin, cantPares);
    */
///2B
    int cantPares=contarPares(A,validosA);
    int* ArrDin2=crearArregloDin(cantPares, A, validosA);
    showArray(ArrDin2, cantPares);
    return 0;
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
int contarPares(int A[], int validosA)
{
    int contador=0;
    for (int i=0; i<validosA;i++)
{
    if(A[i]%2==0)
        {
            contador++;
        }
    }
    return contador;
}
int crearArregloDin(int validosAdin,int A[], int validosA)
{
    int* ArrayDin = (int*)malloc(sizeof(int)*validosAdin);
    pasarPares(A, ArrayDin, validosA);
    return ArrayDin;
}
void pasarPares(int A[],int* ArrayDin, int validosA)
{
    int j=0;
    for(int i=0; i<validosA;i++){
    if(A[i]%2==0)
        {
            ArrayDin[j]=A[i];
            j++;
        }
    }
}
