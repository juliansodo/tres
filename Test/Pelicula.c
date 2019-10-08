#include "Pelicula.h"
void hardcodearPelicula(Pelicula ListadoPeliculas[], int MAX)
{
    int i;
    int codigos[4] = {1,2,3,4};
    char descripciones[4][51] = {"Bastardos sin gloria", "Mama", "500 dias", "Juego del miedo"};
    float duraciones[4] = {63.5, 121.3, 69.1, 93.7};
    int idGeneros[4] = {1,2,3,4};
    for(i = 0; i<4; i++)
    {
//        ListadoPeliculas.codigo = codigos[i];
        strcpy(ListadoPeliculas[i].descripcion , descripciones[i]);
        ListadoPeliculas[i].duracion = duraciones[i];
        ListadoPeliculas[i].idGenero = idGeneros[i];
    }
}
