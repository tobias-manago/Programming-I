#include <stdio.h>
#include <stdlib.h>

typedef struct {
int matricula;
char nombre[30];
char genero;
}stAlumnos
int main()
{
    stAlumnos alumnos[10];


    return 0;
}
int cargarArrayAlumnos(stAlumnos alumnos[])
{
    char opcion = 's';
    while(opcion == 's' || opcion == 's')
    {


        printf("desea seguir cargando registros [s/n]: ");
        scanf("%c",opcion);

    }


}
