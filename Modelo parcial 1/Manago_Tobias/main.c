/// Tobias Manago
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define CARRERAS 15

int TiemposCarreras(float TiemposFinales[CARRERAS]);
void FunMejorTiempo(float TiemposCarreras[CARRERAS],int validos,float* PMejorTiempo);
float SumatoriaTiempos(float TiemposCarreras[],int validos);
void FunPromedioTiempos(float TiemposCarreras[],int validos);

int main()
{
    float TiemposFinales [CARRERAS];

    int validos = TiemposCarreras(TiemposFinales);

    float MejorTiempo;
    float* PMejorTiempo = &MejorTiempo;

    FunMejorTiempo(TiemposFinales,validos,PMejorTiempo);
    printf("el mejor tiempo fue %.2f \n",MejorTiempo);
    FunPromedioTiempos(TiemposFinales,validos);

    return 0;
}

int TiemposCarreras(float TiemposFinales[CARRERAS])
{
    int i = 0;
    char opcion = 's';

    while((opcion == 's' || opcion == 'S') && (i < CARRERAS))
    {
        printf("cual fue el tiempo final de tu carrera: ");
        scanf("%f",&TiemposFinales[i]);
        i++;
        printf("¿desea cargar otra carrera mas? [s/n]: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    return i;
}

void FunMejorTiempo(float TiemposCarreras[],int validos,float* PMejorTiempo)
{
    int i = 0;
    *PMejorTiempo = TiemposCarreras[i];
    for(int i = 0; i < validos; i++)
    {
        if (TiemposCarreras[i] < *PMejorTiempo)
        {
            *PMejorTiempo = TiemposCarreras[i];
        }
    }
}
float SumatoriaTiempos(float TiemposCarreras[],int validos)
{
    float sumatoria;

    for(int i = 0 ; i < validos ; i++)
    {
        sumatoria+=TiemposCarreras[i];
    }

    return sumatoria;
}

void FunPromedioTiempos(float Tiemposfinales[],int validos)
{
    float sumatoria = SumatoriaTiempos(Tiemposfinales,validos);
    float promedio = sumatoria / validos;


    printf("el promedio es: %.2f ",promedio);
}

