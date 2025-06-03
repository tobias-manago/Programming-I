#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[50];
    int anio;
    char genero[10];
    char actores[3][50];
    int calificacion;
    int estado;
} stPelicula;
///strucs
void cargar_pelicula(stPelicula* pelicula);
void cargar_peliculas();
void mostrar_peliculas();
int nombre_existente(char nombre_pelicula[]);
///prototipados
int main()
{
    cargar_peliculas();
    mostrar_peliculas();

    return 0;
}

void cargar_pelicula(stPelicula* pelicula)
{
    do
    {
        printf("\ncual es el nombre de la pelicula: ");
        fflush(stdin);
        gets(pelicula->nombre);
        if(nombre_existente(pelicula->nombre) == 1)
        {
            printf("\nese nombre ya esta cargado, ingrese otro nombre ");
        }
    }
    while(nombre_existente(pelicula->nombre) == 1);

    printf("\nen que año fue lanzada: ");
    fflush(stdin);
    scanf("%i",&pelicula->anio);

    printf("\nde que genero es la pelicula: ");
    fflush(stdin);
    gets(pelicula->genero);

    printf("\ncuales fueron los 3 actores principales: ");
    for (int i = 0; i < 3; i++)
    {
        printf("Actor %d: ", i + 1);
        fflush(stdin);
        gets(pelicula->actores[i]);
    }

    printf("cual es la calificacion de los criticos: ");
    scanf("%i",&pelicula->calificacion);
}
void cargar_peliculas()
{
    stPelicula pelicula;
    pelicula.id = 0;

    char opcion = 's';

    FILE* buffer;
    buffer = fopen("archivoPeliculas","ab");

    if(buffer==NULL)
    {
        printf("algo salio mal");
    }
    else
    {
        while(opcion == 's')
        {

            cargar_pelicula(&pelicula);
            fwrite(&pelicula,sizeof(stPelicula),1,buffer);
            pelicula.id = pelicula.id + 1;

            printf("\nQuiere seguir cargando peliculas? presione [s/n]: ");
            fflush(stdin);
            scanf("%c", &opcion);

        }
        fclose(buffer);
    }
}
void mostrar_pelicula(stPelicula pelicula)
{
    printf("\n=============================");
    printf("\nID: %d\n", pelicula.id);
    puts(pelicula.nombre);
    printf("Año de lanzamiento: %d\n", pelicula.anio);
    puts(pelicula.genero);

    printf("Actores principales:\n");
    for (int i = 0; i < 3; i++)
    {
        puts(pelicula.actores[i]);
    }

    printf("Calificacion: %d\n", pelicula.calificacion);
    printf("=============================\n");
}
void mostrar_peliculas()
{
    stPelicula pelicula;

    FILE* buffer;
    buffer = fopen("archivoPeliculas","rb");
    if (buffer != NULL)
    {
        while (fread(&pelicula,sizeof(stPelicula),1,buffer) > 0)
        {
            printf("\n**************** Archivos de peliculas *************************\n");
            printf("\n**************** Mostrando pelicula ****************************\n");
            mostrar_pelicula(pelicula);
        }

        fclose(buffer);
    }
    else
        printf("no se abrio");
}
int nombre_existente(char nombre_pelicula[])
{
    FILE* buffer = fopen("archivoPeliculas", "rb");

    stPelicula p;

    if ( buffer == NULL)
    {
        printf("algo salio mal :(");
    }
    else
    {
        while (fread(&p, sizeof(stPelicula), 1, buffer) > 0)
        {
            if (strcmpi(nombre_pelicula,p.nombre) == 0)
            {
                fclose(buffer);
                return 1;
            }
        }
        fclose(buffer);
    }
    return 0;
}
