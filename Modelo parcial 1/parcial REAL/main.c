#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipo que respeta el enunciado
Pila cargarpilas(Pila A, Pila* B);
int EncontrarElMenor(Pila* A);
void arregloOrdenado(int arreglo[],int dim,Pila* A);

int main()
{
    Pila A;
    Pila B;

    inicpila(&A);
    inicpila(&B);

    A = cargarpilas(A, &B); // Recibe A por copia, B por referencia, retorna A modificada

    printf("\nMostrando pila A (pasada por copia):\n");
    mostrar(&A);

    printf("\nMostrando pila B (pasada por referencia):\n");
    mostrar(&B);

    int menor = EncontrarElMenor(&A);

    int arreglo[10];
    arregloOrdenado(arreglo, 10, &A);
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
int EncontrarElMenor(Pila* A)
{
    Pila Aux;
    Pila Basura;
    inicpila(&Basura);
    inicpila(&Aux);
    int menor;
    menor = tope(A);
    while(!pilavacia(A))
    {
        if(menor>tope(A))
        {
            menor = tope(A);
        }
        apilar(&Aux, desapilar(A));
    }
    while(!pilavacia(&Aux))
    {
        if(menor == tope(&Aux) )
        {
            apilar(&Basura, desapilar(&Aux));
        }
        apilar(A, desapilar(&Aux));
    }
    return menor;
}

void arregloOrdenado(int arreglo[],int dim,Pila* A)
{
    int validos = 0;
    for(int i = 0; i<dim ; i++)
    {
        arreglo[i] = EncontrarElMenor(&A);
    }
    printf("Contenido del arreglo: [ ");
   for (int i = 0; i < validos; i++)
    {
        printf("%d", arreglo[i]);
        if (i < validos - 1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}
