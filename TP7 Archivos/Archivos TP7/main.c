#include <stdio.h>
#include <stdlib.h>

int main()
{



    FILE* buffer
    buffer = fopen("archivo","ab");

    return 0;
}
void guardarUnDatoEnArchivo(int A)
{
    FILE* buffer
    buffer = fopen("archivo","ab");
    if(buffer==NULL)
    {
        printf("No se pudo abrir \n");
    }
    else
    {
        fwrite(&A,sizeof(int),1,buffer)

        fclose(buffer);
    }
}
void mostrar archivo(int A)
{
    int aux
    FILE* buffer
    buffer = fopen("archivo","ab");
fread()
}
