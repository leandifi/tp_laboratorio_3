#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
}EMovie;

/**
 *  Agrega una pelicula a la memoria dinámica
 *  @param puntero a un array de estructuras EMovie
 *  @param numero entero con la cantidad de estructuras del array
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(void* moviep,int i);

/**
 *  Borra una pelicula de la memoria dinámica
 *  @param puntero a un array de estructuras EMovie
 *  @param numero entero con la cantidad de estructuras del array
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie, int cant);

/**
 *  Modifica una pelicula de la memoria dinámica
 *  @param puntero a un array de estructuras EMovie
 *  @param numero entero con la cantidad de estructuras del array
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modificarPelicula(EMovie* movie, int cant);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en la memoria dinámica
 *  @param puntero a un array de estructuras EMovie
 *  @param numero entero con la cantidad de estructuras del array
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* peliculas,int cont);


#endif // FUNCIONES_H_INCLUDED
