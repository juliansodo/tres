#include "Actor.h"
#define MAX_ELENCO 20
typedef struct
{
    int idPelicula;
    int idActor;
    float valorContrato;
}Elenco;

void Elenco_inicializarElencos(Elenco*, int);
int Elenco_altaElenco(Elenco*, int , Actor*, int, Pelicula*, int, Genero*, int );
void Elenco_listarElencos(Elenco*, int, Pelicula*, int, Actor*, int, Genero*, int);
void Elenco_listarElenco(Elenco*, int);
int Elenco_BuscarIndiceVacio(Elenco*, int );
int Elenco_buscarDuplicados(Elenco[], int , int , int );
