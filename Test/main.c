#include "Elenco.h"

void gestionarActores(Actor*, int );
void gestionarElencos(Elenco*, int, Pelicula*, int, Actor*, int, Genero*, int);
int main()
{
    Pelicula ListadoPeliculas[MAX_PELICULAS];
    Genero ListadoGeneros[MAX_GENERO];
    Actor ListadoActores[MAX_ACTOR];
    Elenco ListadoElencos[MAX_ELENCO];
    hardcodearPelicula(ListadoPeliculas, MAX_PELICULAS);
    hardcodearGenero(ListadoGeneros, MAX_GENERO);
    Elenco_inicializarElencos(ListadoElencos, MAX_ELENCO);
    Actor_inicializarActores(ListadoActores, MAX_ACTOR);
    int opcionGestion;
    int opcionMenu;

    do
    {
        printf("\t\t\n------Menu------");
        printf("\n1-Gestionar Actores\n2-GestionarElencos\n3-Salir\nElegir: ");
        scanf("%d", &opcionGestion);
        switch(opcionGestion)
        {
        case 1:
            gestionarActores(ListadoActores, MAX_ACTOR);
            break;
        case 2:
            gestionarElencos(ListadoElencos, MAX_ELENCO, ListadoPeliculas, MAX_PELICULAS, ListadoActores, MAX_ACTOR, ListadoGeneros, MAX_GENERO);
            break;
        }

    }
    while(opcionGestion != 3);

    return 0;
}

void gestionarElencos(Elenco listadoElencos[], int MAX_Elencos, Pelicula listadoPeliculas[], int MAX_Peliculas, Actor listadoActores[], int MAX_Actores, Genero listadoGeneros[], int MAX_Generos )
{
    char opcionMenu;
    int auxiliar;
    do
    {
        printf("\nA)Generar un elenco\nB)Listar elencos\nC)Salir\nD)Listar Elencos\nElegir: ");
        fflush(stdin);
        scanf("%c", &opcionMenu);
        switch(tolower(opcionMenu))
        {
        case 'a':
            auxiliar = Elenco_altaElenco(listadoElencos, MAX_Elencos, listadoActores, MAX_Actores, listadoPeliculas , MAX_Peliculas, listadoGeneros, MAX_Generos);
            if(auxiliar == -1)
            {
                printf("\nNo se puede crear un actor porque no hay espacio.");
            }
            break;
        case 'b':
            Elenco_listarElencos(listadoElencos, MAX_Elencos, listadoPeliculas, MAX_Peliculas, listadoActores, MAX_Actores, listadoGeneros, MAX_Generos);
            break;
        case 'd':
                    listarElenco(listadoElencos, MAX_Elencos);

            break;
        default: continue;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while(opcionMenu !='c');
}

void gestionarActores(Actor listadoActores[], int MAX)
{
    int auxiliar;
    char opcionMenu;
    do
    {
        printf("\nA)Ingresar un actor\nB)Modificar un actor\nC)Baja de actor\nD)ListarActores\nE)Salir\nElegir: ");
        fflush(stdin);
        //scanf("%c", &opcionMenu);
        opcionMenu = getchar();
        switch(tolower(opcionMenu))
        {
        case 'a':
            auxiliar = Actor_altaActor(listadoActores, MAX);
            if(auxiliar == -1)
            {
                printf("\nNo se puede crear un actor porque no hay espacio.");
            }
            break;
        case 'b':
            auxiliar = Actor_modificarActor(listadoActores, MAX);
            break;
        case 'c':
            auxiliar = Actor_bajarActor(listadoActores, MAX);
            break;
        case 'd':
            Actor_listarActoresOrdenados(listadoActores, MAX);
            break;
        default: continue;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while(opcionMenu !='e');
}
