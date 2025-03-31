#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A [10];
    int validos = loadArrays(A,10);
    apilarArray(A,validos)


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
        scanf(" %c", &opcion);
    }
}
void apilarArray (int A [],int validos)
{
    for (int i = 0 ; i<validos ; i++)
    {

    }

}
