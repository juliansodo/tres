#include "Genero.h"
void hardcodearGenero(Genero ListadoGeneros[], int MAX)
{
    int i;
    int ids[4] = {1,2,3,4};
    char descripciones[4][51] = {"Accion", "Terror", "Romance", "Suspenso"};
    for(i = 0; i<MAX; i++)
    {
        ListadoGeneros[i].id = ids[i];
        strcpy(ListadoGeneros[i].descripcion , descripciones[i]);
    }
}
