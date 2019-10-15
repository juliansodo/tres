#include "Elenco.h"

void Elenco_inicializarElencos(Elenco listadoElencos[], int MAX_Elencos)
{
    int i;
    for(i = 0; i < MAX_Elencos; i++)
    {
        listadoElencos[i].idActor = -1;
        listadoElencos[i].idPelicula = -1;
        listadoElencos[i].valorContrato = -1;
    }
    int peliculasId[4] =    {0,2,3,1};
    int actoresId[4] =      {0,2,1,3};
    float contratosValor[4] = {24.500, 32.111, 43.143, 54.221};
    for(i = 0; i < 4; i++)
    {
        listadoElencos[i].idActor = peliculasId[i];
        listadoElencos[i].idPelicula = actoresId[i];
        listadoElencos[i].valorContrato = contratosValor[i];
    }

}

int Elenco_altaElenco(Elenco listadoElencos[], int MAX_Elencos, Actor listadoActores[], int MAX_Actores, Pelicula listadoPeliculas[], int MAX_Peliculas, Genero listadoGeneros[], int MAX_Generos)
{
    int retorno = -1;
    int corteControl = -1;
    int hayDuplicidad = -1; // -1 si hay duplicidad, y distinto de 0 si no hay.
    int codigoActor;
    int codigoPelicula;
    float valorContrato;
    int indiceVacio = Elenco_BuscarIndiceVacio(listadoElencos,MAX_Elencos);
    if(indiceVacio != -1)
    {
        do
        {
            printf("Para crear un elenco, indiquenos por favor el codigo del actor que desea incluir: \n"); system("pause"); system("cls");

            Actor_listarActores(listadoActores, MAX_Actores);
            do
            {
                printf("Ingrese el codigo del actor: ");
                scanf("%d", &codigoActor);
                corteControl = Actor_buscarIndicePorID(listadoActores, MAX_Actores, codigoActor);
                printf("\n%d", codigoActor);
            }while(corteControl == -1);
            system("pause");


            printf("Ademas, ahora debera colocar el codigo de la pelicula, la cual quiere, relacionar con ese actor: \n"); system("pause"); system("cls");
            listarPeliculas(listadoPeliculas, MAX_Peliculas, listadoGeneros, MAX_Generos);
            do
            {
                printf("Ingrese el codigo de la pelicula: ");
                scanf("%d", &codigoPelicula);
                corteControl = Pelicula_buscarIndicePorID(listadoPeliculas, MAX_Peliculas, codigoPelicula);
            }while(corteControl == -1);

            printf("Ahora, por favor, escriba el valor del contrato: ");
            scanf("%f", &valorContrato);
            hayDuplicidad = Elenco_buscarDuplicados(listadoElencos,MAX_Elencos, codigoPelicula, codigoActor);
            if(hayDuplicidad == -1)
            {
                printf("\nYa existe una relacion entre esta pelicula y este actor. No pueden hallarse duplicados. Se volverán a pedir los datos.\n");system("pause");system("cls");
            }
        }while(hayDuplicidad == -1);
        retorno = 0;
        listadoElencos[indiceVacio].idActor = codigoActor;
        listadoElencos[indiceVacio].idPelicula = codigoPelicula;
        listadoElencos[indiceVacio].valorContrato = valorContrato;
        listarElenco(listadoElencos, MAX_Elencos);
    }
    else
    {
        printf("\nNo hay espacio, no se pueden crear mas elencos.\n");
    }
    return retorno;
}
void Elenco_listarElencos(Elenco listadoElencos[], int MAX_Elencos, Pelicula listadoPeliculas[], int MAX_Peliculas, Actor listadoActores[], int MAX_Actores, Genero listadoGeneros[], int MAX_Generos)
{
    int iGenero, iPelicula, iActor, iElenco;
    for(iGenero = 0; iGenero < MAX_Generos; iGenero++)
    {
       // printf("\n\t\t\t------------Peliculas de %s ------------\n", listadoGeneros[iGenero].descripcion);
        for(iPelicula = 0; iPelicula < MAX_Peliculas; iPelicula++)
        {
            if(listadoPeliculas[iPelicula].codigo!= -1 && listadoPeliculas[iPelicula].idGenero == listadoGeneros[iGenero].id)
            {
                listarPeliculaXId(listadoPeliculas,MAX_Peliculas,listadoGeneros,MAX_Generos,iPelicula);
                printf("ACTORES:\n");
                for(iElenco = 0; iElenco<MAX_Elencos; iElenco++)
                {
                    if(listadoElencos[iElenco].idActor != -1 && listadoElencos[iElenco].idPelicula == listadoPeliculas[iPelicula].codigo)
                    {
                        Actor_listarActor(listadoActores, listadoElencos[iElenco].idActor);
                    }
                }
            }
        }
    }
}
void listarElenco(Elenco listadoElencos[], int MAX)
{

    for(int iElenco = 0; iElenco<MAX; iElenco++)
    {
        if(listadoElencos[iElenco].idActor != -1)
        {
            printf("\n-----ID:%d-----\n", iElenco);
            printf("\nActor: %d", listadoElencos[iElenco].idActor);
            printf("\nPelicula: %d", listadoElencos[iElenco].idPelicula);
            printf("\nContrato: %f\n\n", listadoElencos[iElenco].valorContrato);
        }
    }
}
int Elenco_BuscarIndiceVacio(Elenco ListadoElencos[], int MAX_Elencos)
{
    int retorno = -1;
    int i;
    for(i = 0; i < MAX_Elencos; i++)
    {
        if(ListadoElencos[i].idActor == -1 && ListadoElencos[i].idPelicula == -1)
        {
            retorno = i;
            break;
        }
    }
}

int Elenco_buscarDuplicados(Elenco listadoElencos[], int MAX_Elenco, int idPelicula, int idActor)
{
    int retorno = 1;
    int i;
    for(i = 0; i<MAX_Elenco; i++)
    {
        if(listadoElencos[i].idActor == idActor && listadoElencos[i].idPelicula == idPelicula)
        {
            retorno = -1;
        }
    }
    return retorno;
}
