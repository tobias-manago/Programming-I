#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int legajo;
    char nombre_apellido[30];
    int edad;
    char rango; // m ó p (Maestro/Padawan)
    int id_planeta; // puede ser 1, 2, 3 o 4
} StJedi;

///structs

void cargar_jedi(StJedi* jedi);
void cargar_jedis();
void mostrar_jedi(StJedi jedi);
void mostrar_jedis();
int Legajo_repetido(int Legajo_buscado);
void cantidad_en_planeta(int planeta_buscado);
void mostrar_arreglo_jedis(StJedi jedi[],int validos);
void intercambiar_jedis(StJedi* a, StJedi* b);
int buscar_pos_min_legajo(StJedi arr[], int desde, int validos);
void ordenar_jedis_por_legajo(StJedi arr[], int validos);
int contarRegistros(int edad);

///prototipados

int main()
{
    int planetaBuscado;
    int edadBuscada;

    //cargar_jedis();
    /*mostrar_jedis();
    printf("\ningrese el numero del planeta que desea crear el arreglo de jedis: ");
    scanf("%i",&planeta_buscado);
    cantidad_en_planeta(planetaBuscado);*/
    printf("elije una edad para saber la cantidad de jedis con esa edad: ");
    scanf(" %i",&edadBuscada);
    int tamanio = contarRegistros(edadBuscada);
    printf("la cantidad de jedis con esa edad es de [%i]",tamanio);

    return 0;
}

void cargar_jedi(StJedi* jedi)
{
    int Rta;
    do
    {
        printf("\ncual es el legajo del jedi: ");
        scanf(" %i",&jedi->legajo);
        Rta = Legajo_repetido(jedi->legajo);
        if(Rta == 1)
            printf("\nese legajo ya existe, porfavor ingrese otro ");
    }
    while(Rta == 1);

    printf("\ncual es el nombre y apellido del mismo: ");
    fflush(stdin);
    gets(jedi->nombre_apellido);

    printf("\ncual es la edad del jedi: ");
    scanf(" %i",&jedi->edad);

    do
    {
        printf("\nque rango es el jedi [M/P]: ");
        fflush(stdin);
        scanf(" %c",&jedi->rango);
        if(jedi->rango != 'M' || 'P' || 'm' || 'p')
            printf("ingrese un rango valido");
    }
    while(jedi->rango != 'M' || 'P' || 'm' || 'p');

    printf("\nde que planeta proviene el jedi, ingrese el numero correspondiente: ");
    scanf("%i",&jedi->id_planeta);
}

void cargar_jedis()
{
    StJedi jedi;

    char opcion = 's';

    FILE* buffer;

    buffer = fopen("ArchivoJedis","ab");

    if(buffer == NULL)
    {
        printf("algo salio mal :(");
    }
    else
    {
        while(opcion == 's' || opcion == 'S')
        {
            cargar_jedi(&jedi);

            fwrite(&jedi,sizeof(StJedi),1,buffer);

            printf("\ndesea seguir cargando jedis [s/n]: ");
            fflush(stdin);
            scanf(" %c",&opcion);
        }
        fclose(buffer);
    }
}

void mostrar_jedi(StJedi jedi)
{
    printf("\n-----------------------------------------------\n");
    printf("\nLegajo del jedi: %i ",jedi.legajo);

    printf("\nEl jedi se llama: ");
    puts(jedi.nombre_apellido);

    printf("la edad del jedi es: %i ",jedi.edad);

    printf("\nEl jedi tiene el rango de: %s ",(jedi.rango == 'M' || jedi.rango == 'm') ? "Maestro" : "Padawan");

    printf("\nProviene del planeta %i",jedi.id_planeta);
    printf("\n-----------------------------------------------\n");
}

void mostrar_jedis()
{
    StJedi jedi;

    FILE* buffer;

    buffer = fopen("ArchivoJedis","rb");

    if(buffer == NULL)
    {
        printf("algo salio mal :(");
    }
    else
    {
        printf("\n**************** Archivos de Jedis ***************************\n");
        while(fread(&jedi,sizeof(StJedi),1,buffer) > 0)
        {
            printf("\n**************** Mostrando Jedi ******************************\n");
            mostrar_jedi(jedi);
        }
    }
    fclose(buffer);
}
int Legajo_repetido(int Legajo_buscado)
{
    StJedi jedi;

    int TorF;

    int flag = 0;

    FILE* buffer;
    buffer = fopen("ArchivoJedis","rb");

    while(fread(&jedi,sizeof(StJedi),1,buffer) > 0 && flag == 0)
    {
        if(Legajo_buscado == jedi.legajo)
        {
            TorF = 1;
            flag = 1;
        }
        else
            TorF = 0;
    }

    fclose(buffer);

    return TorF;
}
void cantidad_en_planeta(int planeta_buscado)
{
    FILE* buffer;
    buffer = fopen("ArchivoJedis","r+b");

    StJedi jedi;

    StJedi arrJedisXPlaneta[100];

    int i = 0;

    if(buffer==NULL)
    {
        printf("Algo fallo :(");
    }
    else
    {
        while(fread(&jedi,sizeof(StJedi),1,buffer) > 0)
        {
            if(planeta_buscado == jedi.id_planeta)
            {
                arrJedisXPlaneta[i] = jedi;
                i++;
            }
        }
    }

    ordenar_jedis_por_legajo(arrJedisXPlaneta, i); ///acá ordeno el arreglo

    printf("\n**************** Arreglo de Jedis ***************************\n");

    mostrar_arreglo_jedis(arrJedisXPlaneta,i);

    printf("\n**************** Arreglo del planeta %i ************************\n",planeta_buscado);

fclose(buffer);
}
void mostrar_arreglo_jedis(StJedi jedi[],int validos)
{
    for(int i = 0;i<validos;i++)
    {
        mostrar_jedi(jedi[i]);
    }
}
void intercambiar_jedis(StJedi* a, StJedi* b)
{
    StJedi aux = *a;
    *a = *b;
    *b = aux;
}
int buscar_pos_min_legajo(StJedi arr[], int desde, int validos)
{
    int posMin = desde;
    for(int j = desde + 1; j < validos; j++)
    {
        if(arr[j].legajo < arr[posMin].legajo)
        {
            posMin = j;
        }
    }
    return posMin;
}
void ordenar_jedis_por_legajo(StJedi arr[], int validos)
{
    for(int i = 0; i < validos - 1; i++)
    {
        int posMin = buscar_pos_min_legajo(arr, i, validos);
        if(posMin != i)
        {
            intercambiar_jedis(&arr[i], &arr[posMin]);
        }
    }
}
int contarRegistros(int edad)
{
    StJedi jedi;

    FILE* buffer;
    buffer = fopen("ArchivoJedis","rb");
    int tamanio = 0;

    if(buffer == NULL)
    {
        printf("No se pudo abrir \n");
    }
    else
    {
        fseek(buffer, 0 ,SEEK_END);

        tamanio = (ftell(buffer)) / (sizeof(StJedi));

        fclose(buffer);
    }
    return tamanio;
}
