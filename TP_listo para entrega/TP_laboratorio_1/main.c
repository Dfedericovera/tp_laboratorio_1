#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion=0;
    float num1, num2,aux,resultado;
    long long int factorial;

    printf("\n---------Bienvenido a la Calculadora---------\n");
    while(seguir!='n')
    {
        printf("\n1- Ingresar 1er operando (A)\n");
        printf("2- Ingresar 2do operando (B)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("Elija una opcion: \n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            num1=pedirNumero();
            mostrarNumero(num1);
            break;
        case 2:
            num2=pedirNumero();
            mostrarNumero(num2);
            break;
        case 3:
            resultado=num1+num2;
            printf("El resultado de la suma es: %.2f\n", resultado);
            break;
        case 4:
            resultado=num1-num2;
            printf("El resultado de la resta es: %.2f\n", resultado);
            break;
        case 5:
            resultado=num1/num2;
            printf("El resultado de la division es : %.2f\n", resultado);
            break;
        case 6:
            resultado=num1*num2;
            printf("El resultado de la multiplicacion es : %.2f\n", resultado);
            break;
        case 7:
            aux=num1-(int) num1;
            if (aux==0)
            {
                factorial=calcularFactorial(num1);
                printf("El factorial del 1er operando es : %lli\n", factorial );

            }
            else
            {
                printf("El numero a factoriar (A) debe ser Entero\n.");
            }

            break;
        case 8:
            resultado=num1+num2;
            printf("El resultado de la suma es: %.2f\n", resultado);
            resultado=num1-num2;
            printf("El resultado de la resta es: %.2f\n", resultado);
            resultado=num1/num2;
            printf("El resultado de la division es : %.2f\n", resultado);
            resultado=num1*num2;
            printf("El resultado de la multiplicacion es : %.2f\n", resultado);
            aux=num1-(int) num1;
            if (aux==0)
            {
                factorial=calcularFactorial(num1);
                printf("El factorial del 1er operando es : %lli\n", factorial );

            }
            else
            {
                printf("El numero a factoriar (A) debe ser Entero.\n");
            }

            break;
        case 9:
            seguir = 'n';
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
