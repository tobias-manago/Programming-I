#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void cargar_pila1(Pila* pilita);
void cambiar_de_pila (Pila* A, Pila* B);
int encontrarElMenor(Pila* pilita);
int main()
{
    Pila* pilita;
    inicpila(&pilita);                ///funcion para cargar pilas
    cargar_pila(&pilita);
/*
    Pila* A, B;
    inicpila(&A);
    inicpila(&B);
    cargar_pila1(&A);
    cambiar_de_pila(&A,&B);             ///funcion para pasar los elementos de pila A a B
    printf("esta es la pila A");
    mostrar(&A);
    printf("esta es la pila B");
    mostrar(&B); */
    Pila* ordenada;
    inicpila(&ordenada);
    int menor = encontrarElMenor(&pilita);
    printf("el menor de la pila es: %i",menor);
    ordenamientoPorIsercion(&ordenada,&pilita);
    printf("la pila ordenada queda queda asi ");
    mostrar(&ordenada);

    return 0;
}
void cargar_pila (Pila* pilita)
{
    char opcion = 's';
    while (opcion == 's' || opcion == 'S')
    {
        leer(&pilita);
        printf("desea seguir s/n \n");                 //punto 1
        fflush(stdin);
        scanf("%c",&opcion);
    }
}
void cambiar_de_pila (Pila* A,Pila* B)
{
    while (!pilavacia(A))
    {
        apilar(B,desapilar(A));
    }
}
void cargar_pila1 (Pila* A)
{
    char opcion = 's';
    while (opcion == 's' || opcion == 'S')
    {
        leer(A);
        printf("desea seguir s/n \n");                 //punto 1
        fflush(stdin);
        scanf("%c",&opcion);
    }
}
int encontrarElMenor(Pila* pilita)
{
    Pila Aux;
    inicpila(&Aux);
    int menor ;
    menor = desapilar(pilita);
    while(!pilavacia (pilita))
    {
        if (tope(pilita)> menor)
        {
            apilar(&Aux,desapilar(pilita));
        }
        else
        {
            apilar(&Aux, menor);
            menor = desapilar(pilita);

            while(!pilavacia(&Aux))
            {
                apilar(pilita,desapilar(&Aux));
            }
        }
        printf("%i",menor);
        return menor;
    }
}

   void ordenamientoPorInsercion (Pila* ordenada,Pila* pilita)
    {
        int menorO;

        while (!pilavacia(pilita))
        {
            menorO = encontrarElMenor(pilita);

            if (menorO<tope(pilita))
            {
                apilar(ordenada, menorO);
            }
        }
    }
