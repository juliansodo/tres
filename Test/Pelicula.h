#include "Genero.h"
#define MAX_PELICULAS 10

typedef struct
{
    int codigo;
    char descripcion[51];
    float duracion;
    int idGenero;
}Pelicula;

void hardcodearPelicula(Pelicula*, int);
void listarPeliculas(Pelicula[], int, Genero[], int);
void listarPeliculaXId(Pelicula[], int , Genero [], int , int );
int Pelicula_buscarIndicePorID(Pelicula*, int , int );
