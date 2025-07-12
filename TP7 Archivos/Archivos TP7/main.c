#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombreYapellido[50];
    int edad;
    int anio; ///no puedo usar la ñ para declarar una variable
} StAlumno;

void guardarUnDatoEnArchivo(int A);
void mostrarArchivo(int A);
void cargarunAlumnoSinParametro();
void cargarArchivoAlumnos ();
void mostrarArchivoAlumnos();
int cantidadDeArchivos();
int Pasar_de_archivo_a_arreglo(StAlumno alumnos[],int dim);
///prototipados
int main()
{
    ///punto 1
    int A = 2;
    //guardarUnDatoEnArchivo(A);
    ///punto 2
    //mostrarArchivo(A);
    ///punto 3
    //cargarArchivoAlumnos();
    mostrarArchivoAlumnos();
    int tamanio = cantidadDeArchivos();
    printf("\nLa cantidad de archivos es de : %i ",tamanio);
    ///punto inventado
    StAlumno alumnos[10];
    int validosA = Pasar_de_archivo_a_arreglo(alumnos,10);
    mostrarArregloAlumnos(alumnos,validosA);


    return 0;
}
void guardarUnDatoEnArchivo(int A) ///funcion punto 1
{
    FILE* buffer;
    buffer = fopen("archivo","ab");

    if(buffer == NULL)
    {
        printf("No se pudo abrir \n");
    }
    else
    {
        fwrite(&A,sizeof(int),1,buffer);

        fclose(buffer);
    }
}
void mostrarArchivo(int A)     ///funcion punto 2
{
    FILE* buffer;
    buffer = fopen("archivo","rb");

    if (buffer != NULL)
    {
        fread(&A, sizeof(int), 1, buffer);
        printf("%i", A);
        fclose(buffer);
    }
    else
    {
        printf("\n ERROR ");
    }
}
void cargarunAlumnoSinParametro(StAlumno* alumno)
{
    printf("\nIngrese un legajo para el alumno: ");
    scanf("%i",&alumno->legajo);

    printf("\nIngrese un nombre para el alumno: ");
    fflush(stdin);
    gets(alumno->nombreYapellido);  // o: scanf("%s", &A.nombreYapellido);  PERO NO CONVIENE PARA NOMBRES Y APELLIDOS

    printf("\n Ingrese la edad del alumno: ");
    scanf("%i",&alumno->edad);

    printf("\nIngrese el año que cursa el alumno: ");
    scanf("%i",&alumno->anio);
}
void cargarArchivoAlumnos()
{

    StAlumno alumno;
    char opcion ='s';

    FILE* buffer;
    buffer = fopen("archivoAlumnos","ab");

    if(buffer!=NULL)
    {
        while (opcion=='s')
        {
            cargarunAlumnoSinParametro(&alumno);

            fwrite(&alumno,sizeof(StAlumno),1,buffer);

            printf("\nQuiere seguir cargando datos? presione [s/n]: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }
        fclose(buffer);
    }
    else
        printf("algo fallo :(");

}
void mostrarunAlumno(StAlumno alumno)
{
    printf("\n----------------------------------------------------------\n");
    printf("El nombre del alumno es: ");
    puts(alumno.nombreYapellido);
    printf("anio del alumno:                 %i\n", alumno.anio);
    printf("edad del alumno:                 %i\n", alumno.edad);
    printf("Legajo del alumno:               %i\n", alumno.legajo);
    printf("\n----------------------------------------------------------\n");

}
void mostrarArchivoAlumnos()
{
    StAlumno alumno;

    FILE* buffer;
    buffer = fopen("archivoAlumnos","rb");
    if (buffer != NULL)
    {
        while (fread(&alumno,sizeof(StAlumno),1,buffer) > 0)
        {
            printf("\n**************** Archivos de alumnos ***************************\n");
            printf("\n**************** Mostrando alumno ******************************\n");
            mostrarunAlumno(alumno);
        }

        fclose(buffer);
    }
    else
        printf("no se abrio");

}
int cantidadDeArchivos() ///funcion punto 3
{
    FILE* buffer;
    buffer = fopen("archivoAlumnos","rb");
    int tamanio = 0;

    if(buffer == NULL)
    {
        printf("No se pudo abrir \n");
    }
    else
    {
        fseek(buffer, 0,SEEK_END);

        tamanio = (ftell(buffer)) / (sizeof(StAlumno));

        fclose(buffer);
    }

    return tamanio;
}
int Pasar_de_archivo_a_arreglo(StAlumno alumnos[],int dim)
{
    FILE* buffer;
    buffer = fopen("archivoAlumnos","rb");
    StAlumno alumno;
    int i = 0;
    if(buffer==NULL)
    {
        printf("Algo fallo :(");
    }
    else
    {
        while(fread(&alumno,sizeof(StAlumno),1,buffer) > 0)
        {
            alumnos[i] = alumno;
            i++;
        }
    }
    return i;
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
/*void modificar_entero_Archivo_Buscado(int datoBuscado)
{
    int Aux;
    int flag = 0;
    FILE* buffer= fopen("archivo","r+b");
    if(buffer==NULL)
    {
        printf("algo salio mal :(");
    }
    else
    {
        while(flag == 0 && fread(&Aux,sizeof(int),1,buffer)>0)
        {
            if(Aux==datoBuscado)
            {
                flag = 1;
                fseek(buffer,(-1)*sizeof(int),SEEK_CUR);
                fwrite(&nuevoValor,sizeof(int),1,buffer);
            }
        }
        fclose(buffer);
    }
}
void modificar_entero_Archivo_Sabiendo_posicion()
{
    int Aux;
    int flag = 0;
    FILE* buffer= fopen("archivo","r+b");
    if(buffer==NULL)
    {
        printf("algo salio mal :(");
    }
    else
    {
        fseek(buffer,(posicion-1)*sizeof(int),SEEK_SET);
    }
    fclose(buffer);
}*/
