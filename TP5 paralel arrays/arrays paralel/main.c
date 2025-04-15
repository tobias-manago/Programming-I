#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargaArreglosParalelos(int matricula[20], char nombre[20][30]);
void muestraArreglosParalelos(int matricula[20], char nombre[20][30], int validos);
void mostrarNombrePorLegajo(int matricula[20], char nombre[20][30], int validos, int valorBuscado);
int main()
{
    int matricula [20];
    char nombre[20][30];
    int validos = cargaArreglosParalelos(matricula,nombre);
    muestraArreglosParalelos(matricula,nombre,validos);
    int valorBuscado;
    printf("que legajo desea encontrar ? \n");
    scanf("%d",&valorBuscado);
    mostrarNombrePorLegajo(matricula,nombre,validos,valorBuscado);
    ordenarPorNombre(matricula, nombre, validos);
    muestraArreglosParalelos(matricula, nombre, validos);



    return 0;
}

int cargaArreglosParalelos(int matricula[20], char nombre[20][30])
{
    int i = 0;
    char rta = 's';

    while (i < 20 && rta == 's')
    {
        printf("\nIngrese matricula del alumno: ");
        scanf("%d", &matricula[i]);

        fflush(stdin);
        printf("\nIngrese nombre del alumno (hasta 30 caracteres): ");
        gets(nombre[i]); // arreglo de palabras

        i++;

        printf("\n\n¿Desea ingresar los datos de otro alumno? (s/n): ");
        fflush(stdin);
        scanf(" %c", &rta);
    }

    return i;
}
void muestraArreglosParalelos(int matricula[20], char nombre[20][30], int validos)
{
    int i = 0;
    while(i < validos)
    {
        printf("\tMatricula: %d\n", matricula[i]);
        printf("\tNombre:    %s\n", nombre[i]);
        i++;
    }
}
int buscarLegajo(int matricula[20], int validos, int valorBuscado)
{
    int i = 0;

    while (i < validos)
    {
        if (matricula[i] == valorBuscado)
        {
            return i;
        }
        i++;
    }

    return -1;
}
void mostrarNombrePorLegajo(int matricula[20], char nombre[20][30], int validos, int valorBuscado)
{
    int posicion = buscarLegajo(matricula,validos,valorBuscado);

    if (posicion != -1)
    {
        printf("El nombre correspondiente al legajo %d es: ", valorBuscado);
        puts(nombre[posicion]);
    }
    else
    {
        printf("Legajo %d no encontrado.\n", valorBuscado);
    }
}
void ordenarPorNombre(int matricula[20], char nombre[20][30], int validos) {
    int i, j, min;
    char auxNombre[30];
    int auxMatricula;

    for (i = 0; i < validos - 1; i++) {
        min = i;
        for (j = i + 1; j < validos; j++) {
            if (strcmp(nombre[j], nombre[min]) < 0) {
                min = j;
            }
        }

        // Intercambiar nombres
        strcpy(auxNombre, nombre[i]);
        strcpy(nombre[i], nombre[min]);
        strcpy(nombre[min], auxNombre);

        // Intercambiar matrículas
        auxMatricula = matricula[i];
        matricula[i] = matricula[min];
        matricula[min] = auxMatricula;
    }
}

