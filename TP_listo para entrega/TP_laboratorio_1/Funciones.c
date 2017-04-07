#include "funciones.h"

float pedirNumero()
    {
        float numero;
        printf("ingrese numero\n");
        scanf("%f", &numero);
        return numero;
    }

    void mostrarNumero(float num)
{
    printf("El numero es: %.2f\n", num);
    return 0;
}

long long int calcularFactorial(float num)
{
    long long int factorial = 1;
    int i;
    float aux;
    aux=num-(int) num;
    if (aux==0)
    {
        for(i=1; i<=num; i++)
        {
            factorial = factorial * i;
        }

    }
    else
    {
        printf("El numero a factoriar debe ser Entero.");

    }
    return factorial;
}
