#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void cargar_pila(Pila* pilin);
void cambiar_de_pila (Pila* A, Pila* B);
int encontrarElMenor (Pila* pilin);
void ordenamientoPorSelecion (Pila* pilin,Pila* ordenada);
int main()
{
    ///funcion para cargar pilas

    Pila* pilin;
    inicpila(&pilin);
    cargar_pila(&pilin);

    ///funcion para cargar pilas y cambiar los datos de una pila a la otra
    /*
    Pila* A, B;
    inicpila(&A);
    inicpila(&B);
    cargar_pila1(&A);
    cambiar_de_pila(&A,&B);
    printf("esta es la pila A");
    mostrar(&A);
    printf("esta es la pila B");
    mostrar(&B);
    */
    Pila* ordenada;
    inicpila(&ordenada);

    ordenamientoPorSelecion(&ordenada,&pilin);
    mostrar(&ordenada);

    return 0;
}
void cargar_pila (Pila* pilin)
{
    char opcion = 's';
    while (opcion == 's' || opcion == 'S')
    {
        leer(pilin);
        printf("desea seguir [s/n]: ");                 ///punto 1
        fflush(stdin);
        scanf(" %c",&opcion);
    }
}
void cambiar_de_pila (Pila* A,Pila* B)
{
    while (!pilavacia(A))
    {
        apilar(B,desapilar(A));
    }
}
/*void cargar_pila1 (Pila* A)
{
    char opcion = 's';
    while (opcion == 's' || opcion == 'S')
    {
        leer(A);
        printf("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c",&opcion);
    }
}*/


int encontrarElMenor (Pila* pilin)
{
    int menor = 0;
    Pila aux;
    inicpila(&aux);
    menor = desapilar(pilin);
          while (!pilavacia (pilin))
    {
        if (tope(pilin)> menor)
        {
            apilar(&aux,desapilar(pilin));
        }
        else
        {
            apilar(&aux, menor);
            menor = desapilar(pilin);
        }

    }
    while (!pilavacia(&aux))
    {
        apilar(pilin,desapilar(&aux));
    }
    return menor ;
}
void ordenamientoPorSelecion (Pila* pilin,Pila* ordenada)
{
    int menor;
    while(!pilavacia(pilin))
    {
        menor = encontrarElMenor(pilin);
        apilar(ordenada, menor);
    }

}
