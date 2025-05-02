#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipo que respeta el enunciado
Pila cargarpilas(Pila A, Pila* B);

int master()
{
    Pila A;
    Pila* P;
    Pila B;
    P = &B;

    inicpila(&A);
    inicpila(&B);

    A = cargarpilas(A, P); // Recibe A por copia, B por referencia, retorna A modificada

    printf("\nMostrando pila A (pasada por copia):\n");
    mostrar(&A);

    printf("\nMostrando pila B (pasada por referencia):\n");
    mostrar(&B);

    return 0;
}

Pila cargarpilas(Pila A, Pila* B)
{
    char opcion = 's';

    while(opcion == 's' || opcion == 'S')
    {
        Pila Aux;
        inicpila(&Aux);
        leer(&Aux);

        int dato = tope(&Aux);

        if(dato > 0 && dato % 3 == 0) // positivo y múltiplo de 3
        {
            apilar(B, desapilar(&Aux));
        }
        else if(dato > 0) // positivo pero no múltiplo de 3
        {
            apilar(&A, desapilar(&Aux));
        }
        else // negativo
        {
            printf("Sólo se pueden ingresar números positivos.\n");
        }

        printf("¿Desea seguir cargando datos? [s/n]: ");
        fflush(stdin);
        scanf(" %c", &opcion);
    }

    return A;
}
