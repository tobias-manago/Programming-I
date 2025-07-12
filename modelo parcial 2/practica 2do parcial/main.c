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
void dar_de_baja(int id_pelicula);
void modificacion_en_pelis(int id_pelicula);
///prototipados
int main()
{
    cargar_peliculas();
    mostrar_peliculas();

    int id_buscado;
    printf("\nque pelicula desea dar de baja?, ingrese el id: ");
    scanf("%i",&id_buscado);
    dar_de_baja(id_buscado);
    mostrar_peliculas();

    int id_pelicula;
    printf("\nID de la pelicula que deseas modificar: ");
    scanf("%i",&id_pelicula);
    modificacion_en_pelis(id_pelicula);
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

    pelicula->estado = 1;
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
    if(pelicula.estado == 1)
        printf("DISPONIBLE !!!\n");
    else
        printf("no esta disponible :( \n");
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
void dar_de_baja(int id_pelicula)
{
    int flag = 0;
    FILE* buffer = fopen("archivoPeliculas", "r+b");

    stPelicula peli;

    if(buffer)
    {
        while((flag==0) && (fread(&peli,sizeof(stPelicula),1,buffer) > 0))
        {

            if(peli.id == id_pelicula)
            {
                peli.estado = 0;
                fseek(buffer,(-1)*sizeof(stPelicula),SEEK_CUR);
                fwrite(&peli,sizeof(stPelicula),1,buffer);
                flag=1;
            }
        }

        fclose(buffer);
    }
    else
    {
        printf("no se abrio el archivo :( ");
    }
}

void modificacion_en_pelis(int id_pelicula)
{
    FILE* buffer = fopen("archivoPeliculas", "r+b");

    stPelicula peli;

    int opcion ;
    int actores = 0;

    if(buffer)
    {
        while(fread(&peli,sizeof(stPelicula),1,buffer) > 0)
        {
            if(peli.id == id_pelicula)
            {
                mostrar_pelicula(peli);
                do
                {
                    printf("que desea modificar : \n");
                    printf("1. nombre: \n");
                    printf("2. anio: \n");
                    printf("3. genero: \n");
                    printf("4. actores: \n");
                    printf("5. calificacion: \n");
                    printf("0. salir \n");
                    printf("elija una opcion: ");
                    scanf("%i",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        printf("\ningrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(peli.nombre);
                        break;
                    case 2:
                        printf("\ningrese el nuevo año: ");
                        scanf("%d",&peli.anio);
                        break;
                    case 3:
                        printf("\ningrese el nuevo genero: ");
                        fflush(stdin);
                        gets(peli.genero);
                        break;
                    case 4:
                        printf("\nque actor desea modificar [1-2-3]: ");
                        scanf("%i",&actores);
                        if(actores == 1)
                        {
                            printf("\nactor 1: ");
                            gets(peli.actores[0]);
                        }
                        else if(actores == 2)
                            {
                                printf("\nactor 2: ");
                                gets(peli.actores[1]);
                            }
                        else
                        {
                            printf("\nactor 3: ");
                            gets(peli.actores[2]);
                        }
                        break;
                    case 5:
                        printf("\ningrese la nueva calificacion: ");
                        scanf("%d",&peli.calificacion);
                        break;
                    case 0:
                        printf("\nsaliendo de modificaciones... ");
                        break;
                    default:
                        printf("\nopcion no valida");
                        break;
                    }
                }
                while(opcion!=0);
                fwrite(&peli,sizeof(stPelicula),1,buffer);

            }
            else
            {
                printf("\nno se encontro el id buscado");
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("no se abrio el archivo :( ");
    }
}

