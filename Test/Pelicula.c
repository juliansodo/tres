#include "Pelicula.h"
void hardcodearPelicula(Pelicula ListadoPeliculas[], int MAX)
{
    int i;
    //Inicializo todos los codigos en -1
    for(i = 0; i < MAX; i++)
    {
        ListadoPeliculas[i].codigo = -1;
    }
    int codigos[4] = {0,1,2,3};
    char descripciones[4][51] = {"Bastardos sin gloria", "La noche de los lapices", "500 dias", "Juego del miedo"};
    float duraciones[4] = {63.5, 121.3, 69.1, 93.7};
    int idGeneros[4] = {1,2,3,4};
    for(i = 0; i<4; i++)
    {
        ListadoPeliculas[i].codigo = codigos[i];
        strcpy(ListadoPeliculas[i].descripcion , descripciones[i]);
        ListadoPeliculas[i].duracion = duraciones[i];
        ListadoPeliculas[i].idGenero = idGeneros[i];
    }
}

void listarPeliculas(Pelicula ListadoPeliculas[], int MAX_Peliculas, Genero ListadoGenero[], int MAX_Generos)
{
    int i,j;
    for(i = 0; i<MAX_Peliculas; i++)
    {
        if(ListadoPeliculas[i].codigo != -1)
        {
            printf("\n------------- ID: %d -------------\n", ListadoPeliculas[i].codigo);
            printf("Nombre: %s\n", ListadoPeliculas[i].descripcion);
            printf("Duracion: %f minutos\n", ListadoPeliculas[i].duracion);
            for(j=0; j<MAX_Generos;j++)
            {
                if(ListadoGenero[j].id == ListadoPeliculas[i].idGenero)
                {
                     printf("Genero: %s\n", ListadoGenero[j].descripcion);
                }
            }
            printf("\n-------------------------------\n");
        }
    }
}

void listarPeliculaXId(Pelicula ListadoPeliculas[], int MAX_Peliculas, Genero ListadoGenero[], int MAX_Generos, int codigoPelicula)
{
    int j;
    printf("\n------------- ID: %d -------------\n", ListadoPeliculas[codigoPelicula].codigo);
    printf("Nombre: %s\n", ListadoPeliculas[codigoPelicula].descripcion);
    printf("Duracion: %3.2f minutos\n", ListadoPeliculas[codigoPelicula].duracion);
    for(j=0; j<MAX_Generos;j++)
    {
        if(ListadoGenero[j].id == ListadoPeliculas[codigoPelicula].idGenero)
        {
             printf("Genero: %s\n", ListadoGenero[j].descripcion);
        }
    }
    printf("\n-------------------------------\n");
}


int Pelicula_buscarIndicePorID(Pelicula listadoPeliculas[], int MAX, int indice)
{
    int i;
    int retorno = -1;
    for(i = 0; i<MAX; i++)
    {
        if(indice == listadoPeliculas[i].codigo)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
