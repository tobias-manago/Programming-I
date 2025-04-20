#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumRandom ();
void tresNumeros ();
int SumarMenoresPositivos();
void tablaFor ();

int main()
{
    srand(time(NULL));
      int Num;                  //randomizador
      Num = NumRandom();
      printf("El numero aleatorio es %d ",Num);

      tresNumeros (); //comparador

      int N, rtnSuma;
      printf(" \n Ingresa N: ");
      scanf("%i", &N);
      rtnSuma = SumarMenoresPositivos(N);
      printf("Este es el return de suma: %i\n", rtnSuma); //sumatoria funcion

      int multiplo;
      printf("Ingrese la tabla de multiplicacion que quisiera ver "); //tabla for
      scanf("%d",&multiplo);
      tablaFor(multiplo);

    int numero1,numero2,opcion;
    printf("presione [1] para sumar [2] para restar [3] para multiplicar y [4] para dividir: ");
    scanf("%d",&opcion);
    if (opcion<=4)
    {
        printf("ingresa el primer numero con el que desea realizar la operacion: ");
        scanf("%i",&numero1);
        printf("ingresa el segundo numero con el que desea realizar la operacion: ");
        scanf("%i",&numero2);
        int* puntOpcion = &opcion;
        calculadora (numero1,numero2,opcion);
    }
    else
    {
        printf("ERROR ingrese un numero del 1 al 4 porfavor ");
    }
    return 0;
}

int NumRandom ()
{
    return rand() %101;
}

void tresNumeros ()
{
    int num1, num2, num3;
    printf("\n ingresa 3 numeros  \n ");
    scanf(" %i", &num1);
    scanf(" %i", &num2);
    scanf(" %i", &num3);
    if (num1>num2 && num1>num3 && num2>num3)
    {
        printf ("el numero mas grande es %i ",num1);
        printf ("el numero mas chico es %i ",num3);
    }
    else if (num2>num1 && num2>num3 && num1>num3)
    {
        printf ("el numero mas grande es %i ",num2);
        printf ("el numero mas chico es %i ",num3);
    }
    else if (num3>num1 && num3>num2 && num2>num1)
    {
        printf ("el numero mas grande es %i ",num3);
        printf ("el numero mas chico es %i ",num1);
    }
    else if (num3>num1 && num3>num2 && num1>num2)
    {
        printf ("el numero mas grande es %i ",num3);
        printf ("el numero mas chico es %i ",num2);
    }
}

int SumarMenoresPositivos(N)
{
    int suma = 0;
    for (int i = 1; i <= N; i++)
    {
        suma += i;
    }
    return suma;
}
void tablaFor(multiplo)
{
    int Resultado;
    for ( int i=1 ; i<11 ; i++ )
    {
        Resultado = multiplo * i;
        printf(" %d x %d = %d \n", multiplo, i, Resultado);
    }
}
void calculadora (int numero1,int numero2,int opcion)
{
    float resultado = 0;
    switch (opcion)
    {
    case 1:
        sumaCalculadora(numero1,numero2,resultado);

        break;
    case 2:
        restaCalculadora(numero1,numero2,resultado);

        break;
    case 3:
        multiplicacionCalculadora(numero1,numero2,resultado);

        break;
    case 4:
        divisionCalculadora (numero1,numero2,resultado);

        break;
    default:
        printf("ERROR ingrese un numero del 1 al 4 porfavor ");
    }
}

void sumaCalculadora (int numero1,int numero2,float resultado)
{
    resultado = numero1 + numero2;
    printf("el resultado de %i + %i = %.2f",numero1,numero2,resultado);

}
void restaCalculadora (int numero1,int numero2,float resultado)
{
    resultado=numero1-numero2;
    printf("el resultado de %i - %i = %.2f",numero1,numero2,resultado);
}
void multiplicacionCalculadora (int numero1,int numero2,float resultado)
{
    resultado=numero1*numero2;
    printf("el resultado de %i * %i = %.2f",numero1,numero2,resultado);
}
void divisionCalculadora (int numero1,int numero2,float resultado)
{
    resultado=numero1/numero2;
    printf("el resultado de %i / %i = %.2f",numero1,numero2,resultado);
}
















