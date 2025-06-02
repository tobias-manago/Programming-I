#include <stdio.h>
#include <stdlib.h>
typedef struct{
 int idPelicula;
 char nombre[50];
 int anio;
 char genero[10];
 char actores[3][50];
 int calificacion;
 int estado;
} stPelicula;
///strucs
stPelicula cargar_pelicula();
///prototipados
int main()
{


    return 0;
}

stPelicula cargar_pelicula(stPelicula* pelicula)
{
    pelicula.idPelicula + 1;
    printf("cual es el nombre de la pelicula ");
    gets(pelicula.nombre);
    return pelicula
}
