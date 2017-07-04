#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define ARCH	"./bin.dat"


int main()
{
    char seguir='s',nombre [20];
    int opcion=0,aux;
    FILE *bin=NULL;
    EMovie *movie=NULL;
    bin = abrirArchivo();
    movie=cargarPelis(bin);
    system("pause");
    system("cls");
    while(seguir=='s')
    {
        printf("\t|-----------TP3 PELICULAS--------------|\n");
        printf("\t|------------Vera Daniel---------------|\n");
        printf("\t|---------------1H---------------------|\n\n");
        printf("\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar \n4- Generar pagina web\n5- Salir\n ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            if(!agregarPelicula(movie))
            {
                printf("\nError al escribir el archivo\n");
            }
            break;
        case 2:
            aux=borrarPelicula(movie);
            if(!aux)
            {
                printf("\nNo se encontro la pelicula\n");
            }
            else if(aux==-1)
            {
                printf("\nNo existen peliculas en memoria\n");
            }
            break;
        case 3:
            if(!modificar(movie))
            {
                printf("\nNo existe ninguna pelicula\n");
            }
            break;
        case 4:
            printf("\ningrese nombre de la pagina: ");
            scanf("%s",nombre);
            strcat(nombre,".html");
            generarPagina(movie,nombre);
            break;
        case 5:
            if(guardar(movie,bin))
            {
                printf("\nProblemas al escribir el archivo\n");
            }
            seguir = 'n';
            break;
        default:
            printf("\n Opcion incorrecta.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    cerrarArchivo(bin);
    return 0;
}
