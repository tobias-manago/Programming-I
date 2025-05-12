#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define DIMCOLS 5
#define DIMROWS 5
// Prototipo que respeta el enunciado
Pila cargarpilas(Pila A, Pila* B);
int EncontrarElMenor(Pila* A);
int ordenarArreglo(Pila* A,int arreglo[],int dim);
void mostrarArreglo(int arreglo[],int validos);
int EncontrarDatoDado(int arreglo[],int datoDado, int validos);
void CargarMatrizConArray(int matriz[DIMCOLS][DIMROWS],int arreglo[],int validos);
void mostrarMatriz(int Matriz[DIMROWS][DIMCOLS]);
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

    int arreglo[10];

    int validos = ordenarArreglo(&A,arreglo,10);

    mostrarArreglo(arreglo,validos);

    int datoDado;

    printf("que dato desea encontrar adentro del arreglo: ");
    scanf("%d",&datoDado);

    int Rtn = EncontrarDatoDado(arreglo, datoDado, validos);
    if(Rtn == 1)
    {
        printf("\nel dato buscado esta dentro del arreglo");
    }
    else
    {
        printf("\nel dato buscado NO esta dentro del arreglo");
    }
    int matriz[DIMCOLS][DIMROWS]={0};
    CargarMatrizConArray(matriz,arreglo,validos);
    mostrarMatriz(matriz);

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
    inicpila(&Aux);

    int menor;

    if(!pilavacia(A))
    {
        menor = desapilar(A);
    }
    while(!pilavacia(A))
    {
        if(menor>tope(A))
        {
            apilar(&Aux, menor);
            menor = desapilar(A);
        }
        else
        {
            apilar(&Aux, desapilar(A));
        }
    }

    while (!pilavacia(&Aux))
    {
        apilar(A, desapilar(&Aux));
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
int EncontrarDatoDado(int arreglo[],int datoDado, int validos)
{
    int TorF;

    for(int i=0; i<validos; i++)
    {
        if(datoDado == arreglo[i])
        {
            TorF = 1;
        }
        else
        {
            TorF = 0;

        }
    }
    return TorF;
}
void CargarMatrizConArray(int matriz[DIMCOLS][DIMROWS],int arreglo[],int validos)
{
    int f=0;
    int i=0;
    while(f<DIMROWS && i<validos)
    {
        int c=0;
        while(c<DIMCOLS && i<validos)
        {
            if(arreglo[i] >= 2 && arreglo[i] <= 50)
            {
                matriz[f][c] = arreglo[i];
                c++;
            }
            i++;
        }
        f++;

    }
}
void mostrarMatriz(int Matriz[DIMROWS][DIMCOLS])
{
    for(int i = 0; i < DIMROWS; i++)
    {
        printf("\n");
        for(int j = 0; j < DIMCOLS; j++)
        {
            if(Matriz[i][j] != 0)
            printf("%d,", Matriz[i][j]);
        }
    }
}
