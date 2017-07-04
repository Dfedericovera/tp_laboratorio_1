#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[200];
} EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 si pudo agregar la pelicula o 0 si no.
 */
int agregarPelicula(EMovie *movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie *movie, char nombre[]);

#endif // FUNCIONES_H_INCLUDED


FILE* abrirArchivo();
EMovie* cargarPelis(FILE* bin);
void cerrarArchivo(FILE*);
int guardar(EMovie*,FILE*);
void mostrarpelis(EMovie *movie,int i);
void setPeli(EMovie* movie,int index);
int modificar (EMovie* movie);
