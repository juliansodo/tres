
#define MAX_PELICULAS 10
typedef struct
{
    int codigo;
    char descripcion[51];
    float duracion;
    int idGenero;
}Pelicula;

void hardcodearPelicula(Pelicula*, int);
