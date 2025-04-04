#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M [3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    M [0][0] = 3 ;      ///en la la fila 0 columna 0 es 3

    cargarMatriz(3,3,M[3][3]);


return 0;
}

void cargarMatriz(int DimRows,int DimCols,int M[DimRows][DimCols])
{
    for(int i = 0; i < DimRows; i++)
    {
        for(int j = 0; j < DimCols; j++){    ///asi podemos recorrer una matriz
            printf("Que numero desea ingresar en la matriz: ");
            scanf("%d",&M[DimRows][DimCols]);
    }}
    printf("%d",M);
}
