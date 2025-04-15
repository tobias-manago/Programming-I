#include <stdio.h>
#include <stdlib.h>

int cargaArreglosParalelos(int matricula[20], char nombre[20][30]);
void muestraArreglosParalelos(int matricula[20], char nombre[20][30], int validos);

int main()
{
    int matricula [20];
    char nombre[20][30];
    int validos = cargaArreglosParalelos(matricula,nombre);
    muestraArreglosParalelos(matricula,nombre,validos);
    int valorBuscado;
    printf("que legajo desea encontrar ? \n");
    scanf("%d",&valorBuscado);
    int pos = buscarLegajo(matricula, validos,valorBuscado);
if (pos != -1) {
    printf("Legajo encontrado en la posicion: %d \n", pos);
} else {
    printf("Legajo no encontrado.\n");
}


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
int buscarLegajo(int matricula[20], int validos, int valorBuscado) {
    int i = 0;

    while (i < validos) {
        if (matricula[i] == valorBuscado) {
            return i; // Retorna la posición donde se encontró el legajo
        }
        i++;
    }

    return -1; // Si no se encuentra, retorna -1
}

