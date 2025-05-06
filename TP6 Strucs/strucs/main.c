#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
char nombreYapellido[50];
int matricula;
char genero;
float nota;
}StAlumno;
int main()
{
    StAlumno alumnos[10];
    int validos = cargarArregloAlumnos(alumnos,10);
    mostrarArregloAlumnos(alumnos,validos);


    return 0;
}
StAlumno cargarunAlumnoSinParametro ()
{
   StAlumno alumnos;

   printf("\nIngrese un nombre para el alumno\n");
   fflush(stdin);
   gets(alumnos.nombreYapellido);  // o: scanf("%s", &A.nombreYapellido);  PERO NO CONVIENE PARA NOMBRES Y APELLIDOS

    printf("\nIngrese un legajo para el alumno\n");
    scanf("%i", &alumnos.matricula);

    printf("\n Ingrese una nota para el alumno\n");
    scanf("%f", &alumnos.nota);

    return alumnos;
}
int cargarArregloAlumnos (StAlumno alumnos[], int dimension)
{
    int i=0;
    char opcion ='s';

    while (opcion=='s' && i<dimension)
    {
        alumnos[i]= cargarunAlumnoSinParametro();
        i++;

        printf("\nQuiere seguir cargando datos? presione s/n\n ");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    return i;
}
void mostrarunAlumno (StAlumno alumnos)
{
    printf("\n----------------------------------------------------------\n");
    printf("Nombre y apellido del alumno:    %s\n", alumnos.nombreYapellido);
    printf("Nota del alumno:                 %.2f\n", alumnos.nota);
    printf("Legajo del alumno:               %i\n", alumnos.matricula);
    printf("\n----------------------------------------------------------\n");

}
void mostrarArregloAlumnos(StAlumno alumnos[], int validos)
{
    int i;

    for(i=0; i<validos; i++)
    {
        printf("\n**************** Arreglo de alumnos ***************************\n");
        printf("\n**************** Mostrando alumno Nro %i **********************\n", i+1);
        mostrarunAlumno(alumnos[i]);
    }
}
