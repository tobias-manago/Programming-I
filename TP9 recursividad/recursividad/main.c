#include <stdio.h>
#include <stdlib.h>
int factorial(int x);
int main()
{
    int numero;

    printf("Ingrese un numero entero no negativo: ");
    scanf("%i", &numero);

    if (numero < 0) {
        printf("El factorial no está definido para numeros negativos.\n");
    } else {
        printf("El factorial de %d es: %i\n", numero, factorial(numero));
    }

    return 0;
}
int factorial(int x)
{
    int rta;
    if(x == 0)
    {
        rta = 1;  //conclusion trivial
    }
    else
    {
        rta = x * factorial(x-1);
    }
    return rta;
}
