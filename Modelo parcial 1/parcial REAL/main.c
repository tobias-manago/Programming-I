#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipo que respeta el enunciado
Pila cargarpilas(Pila A, Pila* B);
int EncontrarElMenor(Pila* A);
int ordenarArreglo(Pila* A,int arreglo[],int dim);
void mostrarArreglo(int arreglo[],int validos);

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

    printf("\nMostrando pila A (despues de la busqueda del menor):\n");
    mostrar(&A);

    printf("el menor es: %d",menor);

    int arreglo[10];

    int validos = ordenarArreglo(&A,arreglo,10);

    mostrarArreglo(arreglo,validos);
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

        if(dato > 0 && dato % 3 == 0)
        {
            apilar(B, desapilar(&Aux));
        }
        else if(dato > 0)
        {
            apilar(&A, desapilar(&Aux));
        }
        else
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
    inicpila(&Aux);
    inicpila(&Basura);

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
        if (tope(&Aux) == menor)
        {
            apilar(&Basura, desapilar(&Aux));
        }
        apilar(A,desapilar(&Aux));
    }
    return menor;
}
int ordenarArreglo(Pila* A,int arreglo[],int dim)
{
    int i = 0;
    while((!pilavacia(A)) && (i < dim))
    {
        arreglo[i] = EncontrarElMenor(A);
        i++;
    }
    return i;
}
void mostrarArreglo(int arreglo[], int validos)
{
    printf("\n[");
    for(int i = 0; i < validos; i++)
    {
        printf("%d", arreglo[i]);
        if(i < validos - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

