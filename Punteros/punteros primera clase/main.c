#include <stdio.h>
#include <stdlib.h>
#include "../../../../../../../Downloads/Librerias/pila.h"
void intercambioPorReferencia (int* p1, int* p2);

int main()
{
    int a = 1;
    int* p = &a;

    printf("imprimo direccion de memoria de (p) %p \n", p);
    printf("imprimo dato apuntado %d \n", *p);
    printf("imprimo direccion de memoria de (p) %p \n", &p);
    printf("imprimo direccion de memoria de (a) %p \n", &a);

    *p=2;  ///de esta manera puedo modificar el valor de una variable mediante un puntero

    /// por referencia implica que trabajo con las direcciones de memoria (punteros)
    /// en cambio si trabajo por copia implica que desde el main ingreso la variable directamente

    printf("%d",a);
     int* p1, p2;

    intercambioPorReferencia(&p1, &p2);

    Pila* A;
    inicpila(&A);

    cargarPila(&A);


    return 0;
}

void intercambioPorReferencia (int* p1, int* p2)
{


}

void cargarPila (Pila* A)
{

                                                          /// no es necesario poner el &
}
