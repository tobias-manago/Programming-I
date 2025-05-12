#include <stdio.h>
#include <stdlib.h>
#include "time.h" //libreria utilizada para la funcion rand
#include "pila.h"

void pilaRandom(Pila* A);
int ParAlArreglo(Pila A,int arr[],int Dim);
int BuscarElMayorArray(int arr[],int validos);
float PromArray(int arr[],int validos);

///prototipados
int main()
{
    ///punto 1
    srand(time(NULL));
    Pila A;
    inicpila(&A);
    pilaRandom(&A);
    printf("La pila de abajo esta cargada con datos aleatorios");
    mostrar(&A); ///muestro la pila cargada con 20 numeros random
    ///punto 2
    int arr[20];
    int validos = ParAlArreglo(A,arr,20);
    printf("el Arreglo de abajo solamente muestra numeros pares ");
    mostrarArr(arr,validos);
    ///punto 3
    int mayor = BuscarElMayorArray(arr,validos);
    printf("\nEl numero mas grande del array es %d ",arr[mayor]);
    ///punto 4
    int suma = 0;
    suma = sumatoria(arr,validos); //hago la sumatoria en otra parte para modularizar bien
    float promedio = PromArray(arr,validos);
    printf("\nel promedio de arreglo es %.2f",promedio);

    int valorASuperar;
    printf("\ningrese un numero para saber si es superior al promedio: ");
    scanf("%d",&valorASuperar);
    int TorF = VoF(promedio,valorASuperar);
    if(TorF == 1)
    {
        printf("\nel valor buscado SI supera al promedio");
    }
    else
    {
        printf("\nel valor buscado NO supera al promedio");
    }
    return 0;
}
void mostrarArr(int arr[],int validos)
{
    printf("\n[");
    for(int i = 0;i<validos;i++)
    {
        printf("%d",arr[i]);
        if(validos -1)
        {
            printf(",");
        }
    }
    printf("]\n");
}
void pilaRandom(Pila* A) ///funcion punto 1
{
    for(int i = 0; i<20; i++)
    {
        apilar(A, rand()%101);
    }
}
int ParAlArreglo(Pila A,int arr[],int Dim)
{
    Pila Aux;
    inicpila(&Aux);
    int i = 0;
    while(!pilavacia(&A) && i < Dim)  ///pongo la dimension para flexibilizar
    {
        if(tope(&A)%2 == 0)
        {
            arr[i] = desapilar(&A);
            i++;
        }
        else
        {
            apilar(&Aux, desapilar(&A));
        }
    }
    return i;
}
int BuscarElMayorArray(int arr[],int validos)
{
   // int pos = -1; //intente hacerlo con pos -1 pero no pude, y preferi hacer que funcione
    int i = 0;
    int mayor = 0;
    for(int i = 0;i<validos ;i++)
    {
        if(arr[i] > mayor)
        {
            mayor = arr[i];
        }
    }
    return i;
}
int sumatoria(int arr[],int validos)
{
    int sumatoria = 0;
    for(int i = 0;i<validos;i++)
    {
        sumatoria = sumatoria + arr[i];
    }
    return sumatoria;
}
float PromArray(int arr[],int validos)
{
    float promedio = 0;
    int suma = sumatoria(arr,validos);

    promedio = suma / validos; //la sumatoria dividido la cantidad de numeros cargados da el promedio

    return promedio;
}
int VoF(int promedio,int valorASuperar)
{
    int VoF;
    if(promedio > valorASuperar)
    {
        VoF = 1;
    }
    else
    {
        VoF = 0;
    }
    return VoF;
}
