#include "Sistema.h"
#include "Actor.h"
#include "Elenco.h"
#include "Genero.h"
#include "Pelicula.h"


void gestionarActores(Actor*, int );
void gestionarElencos(Elenco*, int );
int main()
{
    Pelicula ListadoPeliculas[MAX_PELICULAS];
    Genero ListadoGeneros[MAX_GENERO];
    Actor ListadoActores[MAX_ACTOR];
    Elenco ListadoElencos[MAX_ELENCO];
    int opcionGestion;
    int opcionMenu;

    do
    {
        printf("\t\t\n------Menu------");
        printf("\n1-Gestionar Actores\n2-GestionarElencos\n3-Salir");
        scanf("%d", &opcionGestion);
        switch(opcionGestion)
        {
        case 1:
            gestionarActores(ListadoActores, MAX_ACTOR);
            break;
        case 2:
            gestionarElencos(ListadoElencos, MAX_ELENCO);
            break;
        }

    }
    while(opcionGestion != 3);

    return 0;
}



void gestionarElencos(Elenco listadoElencos[], int MAX )
{
    printf("\n1-Generar un elenco\n2-Listar Elencos\n3-Baja de actor\n4-ListarActores\n5-Salir");

}

void gestionarActores(Actor listadoActores[], int MAX)
{
    int opcionMenu;
    int auxiliar;
    do
    {
        printf("\n1-Ingresar un actor\n2-Modificar un actor\n3-Baja de actor\n4-ListarActores\n5-Salir");
        scanf("%d", opcionMenu);

        switch(opcionMenu)
        {
        case 1:
            Actor_altaActor(listadoActores, MAX);
            break;
        case 2:
            auxiliar = Actor_modificarActor(listadoActores, MAX);
            break;
        case 3:
            auxiliar = Actor_bajarActor(listadoActores, MAX);
            break;
        case 4:
            Actor_listarActores(listadoActores, MAX);
            break;
        }
    }
    while(opcionMenu !=5);
}
