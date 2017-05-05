#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define V 20

int main()
{
    EPersona lista [V];
    char seguir='s';
    int opcion=0,espacioLibre;
    int i, dni,indice;
    inicializarEstado(lista);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            espacioLibre=obtenerEspacioLibre(lista);
            if(lista[espacioLibre].estado==0)
            {
                printf("\nIngrese nombre: ");
                scanf("%s",lista[espacioLibre].nombre);
                printf("Ingrese edad: ");
                scanf("%d",&lista[espacioLibre].edad);
                printf("Ingrese dni: ");
                scanf("%d",&lista[espacioLibre].dni);
                for(i=0;i<V;i++)
                {
                    if(espacioLibre!=i)
                    {
                        while(lista[espacioLibre].dni==lista[i].dni)
                        {
                            printf("\n El DNI ya existe!!\n");
                            printf("Ingrese dni: ");
                            scanf("%d",&lista[espacioLibre].dni);

                        }
                    }
                }

                lista[espacioLibre].estado=1;
            }
            else
            {
                printf("No hay espacio libre\n");

            }

            break;
        case 2:
            printf("\n----ingrese el DNI de la persona a borrar: ");
            scanf("%d",&dni);
            indice= buscarPorDni(lista,dni);
            if(lista[indice].dni==dni)
                {
                    lista[indice].estado=0;
                    printf("\n------Borrado Correctamente.-----\n");

                    break;
                }
                else
                printf("\n-----DNI inexistente-----\n");
                break;

        case 3:
            ordenarPorNombre(lista);
            printf("\n\n-----------LISTA ORDENADA POR NOMBRE-----------------\n\n");
            for(i=0;i<V;i++)
            {
                if(lista[i].estado==1)
                printf("\n%s\t%d\t%d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
            }

            break;
        case 4:
            printf("\n\n------------GRAFICO DE EDADES---------------  \n\n");
            for(i=0;i<V;i++)
            {
                if(lista[i].estado==1)
                {
                    if(lista[i].edad<=18)
                {
                    printf("\t\t*\t \t \n");
                }
                else if(lista[i].edad>18&&lista[i].edad<35)
                {
                    printf("\t\t \t*\t \n");
                }
                else
                    printf("\t\t \t \t* \n");
                }

            }
            printf("\t\t<18\t19-35\t>35\n");

            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\nOpcion incorrecta intente de nuevo\n");

        }
    }

    return 0;
}


