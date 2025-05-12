#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargarPilaKm(Pila* Km);
int BuscarElMayorTramo(Pila Km);
void mostrarPila(Pila* Km);
void SumatoriaxTramo(Pila Km);

int main()
{
    Pila Km;
    inicpila(&Km);
    CargarPilaKm(&Km);
    int MayorTramo = BuscarElMayorTramo(Km);
    printf("El mayor tramo Fue de :%d \n",MayorTramo);
    mostrarPila(&Km);
    mostrar(&Km);
    return 0;
}
void CargarPilaKm(Pila* Km)
{
    char opcion = 's';
    char control = 's';
    while(control == 's'|| control == 'S')
    {opcion='s';
    while(opcion == 's' || opcion == 'S')
    {
        printf("cuantos kilometros hizo en el tramo ?\n");
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
int BuscarElMayorTramo(Pila Km)
{
    Pila Aux;
    inicpila(&Aux);
    int masGrande = 0;
    masGrande = desapilar(&Km);
    while(!pilavacia(&Km))
    {
        if(masGrande < tope(&Km))
        {
        masGrande = desapilar(&Km);
        }
        else
        {
            apilar(&Aux, desapilar(&Km));
        }
    }
    return masGrande;
}
void mostrarPila(Pila Km)
{
    int Dia = 1;
    Pila Aux;
    inicpila(&Aux);
    while(!pilavacia(Km))
    {
        if(tope(Km) == -1)
        {
        printf("Dia %d: ",Dia);
        Dia++;
        }
        else
        {
        printf("%d Km|",tope(Km));
        }
        apilar(&Aux,desapilar(Km));
    }
    while(pilavacia(&Aux))
    {
        apilar(Km,desapilar(&Aux));
    }
}
/*void SumatoriaxTramo(Pila Km)
{
    int sumatoria = 0;
    while(!pilavacia(Km))
    {

    }
}*/
