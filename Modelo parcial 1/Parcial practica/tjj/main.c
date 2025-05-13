#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
Pila cargarPilas(Pila A, Pila* B, Pila* C);
int main()
{
    Pila A;
    Pila B;
    Pila C;
    inicpila(&A);
    inicpila(&B);
    inicpila(&C);
    A = cargarPilas(A,&B,&C);
    mostrar(&A);

    return 0;
}
Pila cargarPilas(Pila A, Pila* B, Pila* C)
{
    int valor = 0;
    char opcion = 's';
    while(opcion == 's')
    {
        printf("ingrese un numero entero: ");
        scanf("%d",&valor);
        if(valor %10 == 0)
        {
            apilar(&A, valor);
        }
        else if(valor %2 == 0)
        {
            apilar(B, valor);
        }
        else
        {
            apilar(C, valor);
        }

        printf("\ndesea seguir cargando la Pila [S/N]: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    return A;
}
