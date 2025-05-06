#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila Km;
    inicpila(&Km);
    CargarPilaKm(&Km);


    return 0;
}
void CargarPilaKm(Pila* Km)
{
    char opcion = 's';
    char control = 'c';
    while(control == 's'|| control == 'S')
    {
    while(opcion == 's' || opcion == 'S')
    {
        printf("cuantos kilometros hizo en el tramo ?: \n");
        leer(Km);
        printf("desea cargar otro tramo ? [S/N]: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    apilar(Km, -1);
    printf("\ndesea cargar un dia mas ? [S/N]: ");
    fflush(stdin);
    scanf("%c",&control);
}
}
