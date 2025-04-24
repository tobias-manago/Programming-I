#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarDatos(Pila* A, Pila* B);

int main()
{
    Pila A;
    Pila B;

    inicpila(&A);
    inicpila(&B);

    cargarDatos(&A, &B); // A por copia, B por referencia

    printf("\nMostrando pila A (desde main, pasada por copia):\n");
    mostrar(&A); // Esta estará vacía, como se espera

    printf("\nMostrando pila B (pasada por referencia):\n");
    mostrar(&B);

    return 0;
}

void cargarDatos(Pila* A, Pila* B)
{
    char opcion = 's';

    while(opcion == 's' || opcion == 'S')
    {
        Pila Aux;
        inicpila(&Aux);
        leer(&Aux);

        int valor = tope(&Aux);

        if (valor >= 0)
        {
            apilar(&A, desapilar(&Aux)); // Va a pila A (por copia)
        }
        else if (valor % 3 == 0)
        {
            apilar(B, desapilar(&Aux)); // Va a pila B (referencia)
        }
        else
        {
          printf("Solo se permiten números positivos.\n");
        }

        printf("¿Desea seguir cargando datos? [s/n]: ");
        fflush(stdin);
        scanf(" %c", &opcion);
    }

    printf("\nMostrando pila A (desde la función, pasada por copia):\n");
    mostrar(&A); // Mostrar acá para verificar el uso aunque no persista
}
