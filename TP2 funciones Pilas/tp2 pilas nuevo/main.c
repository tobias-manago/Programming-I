#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void cargar_pila1(Pila* pilin);
void cambiar_de_pila (Pila* A, Pila* B);
int main()
{
    Pila* pilin;
    inicpila(&pilin);                ///funcion para cargar pilas
    cargar_pila(&pilin);

    Pila* A, B;
    inicpila(&A);
    inicpila(&B);
    cargar_pila1(&A);
    cambiar_de_pila(&A,&B);             ///funcion para pasar los elementos de pila A a B
    printf("esta es la pila A");
    mostrar(&A);
    printf("esta es la pila B");
    mostrar(&B);
    return 0;
}
void cargar_pila (Pila* pilin)
{
    char opcion = 's';
    while (opcion == 's' || opcion == 'S')
    {
        leer(&pilin);
        printf("desea seguir s/n \n");                 //punto 1
        fflush(stdin);
        scanf("%c",&opcion);
    }
    mostrar(&pilin);
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
int encontrarElMenor (pilin)
{
    int menor ;
    while(!pilavacia (pilin))
    {

    }

}
