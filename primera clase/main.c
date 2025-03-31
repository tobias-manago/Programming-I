#include <stdio.h>
#include <stdlib.h>
//Poner el nombre de la funcion para que el programa sepa que existe, si se pone primero la funcion, el programa tardaria en arrancar
void imprimirSaludo();
void sumarDosNumerosSinRetorno (int NumA, int NumB);
int sumarDosnumerosConRetorno(int NumA, int NumB);
int main()
{
    int NumA, NumB;

    printf("Ingrese dos numeros enteros \n");
    scanf("%d",&NumA);
    scanf("%d",&NumB);

    int resultado;
    resultado = sumarDosnumerosConRetorno(NumA, NumB);

    printf("El resultado es %d ",resultado);

    imprimirSaludo(); //invocacion de la funcion
    sumarDosNumerosSinRetorno ( NumA, NumB);


    return 0;
}

void imprimirSaludo()  //funcion
{
    printf("Hola \n");
}
void sumarDosNumerosSinRetorno (int NumA, int NumB)
{
    int suma = NumA + NumB;
    printf("El resultado es %d \n",suma);

}

 int sumarDosnumerosConRetorno (int NumA, int NumB){
 int suma= NumA + NumB;
 return suma;

}

