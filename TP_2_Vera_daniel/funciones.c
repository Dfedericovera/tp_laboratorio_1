#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define V 20

int obtenerEspacioLibre(EPersona lista[])
{
    int i,espacioLibre;
    for(i=0;i<V;i++)
    {
        if(lista[i].estado==0)
        {
            espacioLibre=i;
        }
    }
    return espacioLibre;
}
void inicializarEstado(EPersona lista[])
{
    int i;
    for(i=0;i<V;i++)
    {
        lista[i].estado=0;
    }
}
int buscarPorDni(EPersona lista[], int dni)
{
    int i,indiceDNI;
    for(i=0; i<V; i++)
    {
        if(lista[i].dni==dni)
        {
            indiceDNI=i;
            return indiceDNI;
        }

    }

    return 0;
}

void ordenarPorNombre(EPersona lista[])
{
    int i,j;
    EPersona auxlista;
    for(i=0;i<V-1;i++)
    {
        for(j=i+1;j<V;j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                auxlista=lista[i];
                lista[i]=lista[j];
                lista[j]=auxlista;
            }
        }
    }
}
