#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define ARCH	"./bin.dat"
int cantpelis=0;
int reservado=0;

void generarPagina(EMovie* movie, char nombre[])
{

    int i;
    FILE* html;
    if(cantpelis!=0)
    {
        if ((html=fopen(nombre,"w+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        for(i=0; i<cantpelis; i++)
        {
            fprintf(html,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head><body>\n    <div class='container'>\n        <div class='row'>\n\n		\n			<!-- Repetir esto para cada pelicula -->\n            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n				<ul>\n					<li>Genero:%s</li>\n					<li>Puntaje:%d</li>\n					<li>Duracion:%d</li>				</ul>\n                <p>%s</p>\n            </article>\n			<!-- Repetir esto para cada pelicula -->\n\n\n        </div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n",(movie+i)->linkImagen,(movie+i)->titulo,(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion,(movie+i)->descripcion);
        }
        printf("\nHecho!-_-'\n");
    }
    else
    {
        printf("\nNo existen peliculas en memoria.\n");
    }
}

/** \brief Agrega una pelicula
 *
 * \param
 * \param
 * \return retorna 1 si pudo agregar la pelicula o 0 si no.
 *
 */
void constructor (EMovie* movie)
{
    EMovie* auxmovie=NULL;
    auxmovie = (EMovie*)realloc(movie,sizeof(EMovie)*cantpelis+10);
    reservado = cantpelis+10;
    if(auxmovie != NULL)
    {
        movie = auxmovie;
    }
    else
    {
        printf("No hay lugar en memoria");
        exit(0);
    }
}
int agregarPelicula(EMovie* movie)
{
    int auxreturn=0;
    if(cantpelis==reservado)
    {
        constructor(movie);
    }
    setPeli(movie,cantpelis);
    cantpelis++;
    mostrarpelis(movie,cantpelis-1);
    auxreturn=1;
    return auxreturn;
}
void setPeli(EMovie* movie,int index)
{
    if(movie!=NULL)
    {
        printf("\nIngrese titulo: ");
        fflush(stdin);
        gets(movie[index].titulo);
        printf("Ingrese genero: ");
        fflush(stdin);
        gets(movie[index].genero);
        printf("Ingrese duracion: ");
        scanf("%d",&movie[index].duracion);
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(movie[index].descripcion);
        printf("ingrese puntaje: ");
        scanf("%d",&movie[index].puntaje);
        printf("Ingrese Link de imagen: ");
        fflush(stdin);
        gets(movie[index].linkImagen);
    }
}



void cerrarArchivo(FILE *bin)
{
    if((fclose(bin))== -1)
    {
        printf("\nNo se pudo cerrar el archivo correctamente");
    }
}
FILE* abrirArchivo()
{
    FILE* pbin;
    if ((pbin=fopen(ARCH,"rb+"))==NULL)
    {
        if ((pbin=fopen(ARCH,"wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }
    return pbin;
}
EMovie* cargarPelis(FILE* bin)
{
    EMovie* movie;
    int cant;
    cant = fread(&cantpelis,sizeof(int),1,bin);
    if(cantpelis>0)
    {
        movie = (EMovie*)malloc(sizeof(EMovie)*cantpelis+10);
        reservado = cantpelis+10;
        if(movie == NULL)
        {
            printf("NO QUEDA MEMORIA");
            exit(0);
        }
        while(!feof(bin))
        {
            cant = fread(movie,sizeof(EMovie),cantpelis,bin);
            if(cant!=cantpelis)
            {
                if(feof(bin))
                {
                    printf("cantidad de peliculas: %d\n",cantpelis);
                }
                else
                {
                    printf("No leyo el ultimo registro");
                    exit(0);
                }
            }
        }
    }
    else
    {
        movie = (EMovie*)malloc(sizeof(EMovie)*10);
        reservado=10;
        if(movie == NULL)
        {
            printf("No hay lugar en memoria.");
            exit(0);
        }
        printf("No existe ninguna pelicula guardada\n");
    }
    return movie;
}

void mostrarpelis(EMovie *movie,int i)
{
    if(i>=0)
    {
        printf("\n-->%s\n-->%s\n-->%d\n--%s\n-->%d\n-->%s\n\n\n",(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->descripcion,(movie+i)->puntaje,(movie+i)->linkImagen);
    }
}

int borrarPelicula(EMovie *movie)
{
    int i,j,auxretur=0;
    char auxtitulo[50];
    if(cantpelis!=0)
    {
        printf("\nIngrese titulo: ");
        fflush(stdin);
        gets(auxtitulo);
        for(i=0; i<cantpelis; i++)
        {
            strlwr((movie+i)->titulo);
            strlwr(auxtitulo);
            if(!stricmp((movie+i)->titulo,auxtitulo))
            {
                mostrarpelis(movie,i);
                for(j=i; j<cantpelis; j++)
                {
                    movie[j]=movie[j+1];
                }
                cantpelis--;
                printf("\nSe borro la pelicula\n");

                auxretur=1;
                break;
            }
        }
    }
    else
    {
        auxretur=-1;
    }

    return auxretur;
}

int guardar(EMovie *movie, FILE* bin)
{
    int auxreturn=0;
    int cant;
    fseek(bin, 0L, SEEK_SET);

    cant=fwrite(&cantpelis,sizeof(int),1,bin);
    if(cant!=1)
    {
        if(feof(bin))
        {
            printf("No se pudo guardar el archivo");
            auxreturn=1;
        }
    }
    cant=fwrite(movie,sizeof(EMovie),cantpelis,bin);
    if(cant!=cantpelis)//puede ir !=????
    {
        if(feof(bin))
        {
            printf("No se pudo guardar el archivo");
            auxreturn=1;
        }
    }
    return auxreturn;
}

int modificar (EMovie* movie)
{
    int i,auxretur = 0;
    char auxtitulo[50];
    if(cantpelis!=0)
    {
        printf("\nIngrese titulo de la pelicula a modificar: ");
        fflush(stdin);
        gets(auxtitulo);
        for(i=0; i<cantpelis; i++)
        {
            strlwr((movie+i)->titulo);
            strlwr(auxtitulo);

            if(!stricmp((movie+i)->titulo,auxtitulo))
            {
                printf("-----Pelicula encontrada\n");
                mostrarpelis(movie,i);
                setPeli(movie,i);
                printf("\nSe modifico la pelicula correctamente\n");
                auxretur = 1;
                break;
            }
        }
    }

    return auxretur;
}
