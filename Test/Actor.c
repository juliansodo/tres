
#include "Actor.h"

void Actor_inicializarActores(Actor listadoActores[], int MAX)
{
    int i;
    for(i = 0; i<MAX; i++)
    {
        listadoActores[i].isEmpty = 1;
    }
}
int Actor_altaActor(Actor listadoActores[], int MAX)
{
    int posicionVacia = Actor_encontrarPosicionVacia(listadoActores, MAX);
    int retorno = -1;
    char nombre[51];
    if(posicionVacia != -1)
    {
        int codigo = posicionVacia;
        char nombre[51];
        char apellido[51];
        char sexo;

        do
        {
            printf("\nIngrese el nombre del actor(Maximo 51 caracteres)");
            gets(nombre);
        }while(strlen(nombre) > 51);


        do
        {
            printf("\nIngrese el apellido del actor(Maximo 51 caracteres)");
            gets(apellido);
        }while(strlen(apellido) > 51);

        do
        {
            printf("\nIngrese el sexo del actor(valido solo M(masculino) o F(femenino) ");
            fflush(stdin);
            scanf("%c", sexo);
        }while(toupper(sexo) != 'M' && toupper(sexo) !='F');

        strcpy(listadoActores[posicionVacia].nombre , nombre);
        strcpy(listadoActores[posicionVacia].apellido , apellido);
        listadoActores[posicionVacia].sexo = sexo;
        listadoActores[posicionVacia].isEmpty = 0;
        listadoActores[posicionVacia].codigo = codigo;

    }
}
int Actor_bajarActor(Actor listadoActores[], int MAX)
{
    int indice;
    int encontroPosicion;
    int retorno;
    printf("Ingrese el ID del actor que desea bajar");
    scanf("%d", indice);
    encontroPosicion = indice;
    if(encontroPosicion != -1)
    {
        listadoActores[encontroPosicion].isEmpty = 1;
        printf("Se dio de baja el actor.");
        retorno = 0;
    }
    else
    {
        printf("\nNo se puede bajar al actor porque no se encontro el ID especificado");
        retorno = -1;
    }
    return retorno;
}
int Actor_modificarActor(Actor listadoActores[], int MAX)
{
    int indice;
    int encontroPosicion;
    int retorno = -1;
    int opcionEdicion;
    printf("Ingrese el ID del actor que desea modificar");
    scanf("%d", indice);
    encontroPosicion = indice;
    if(encontroPosicion != -1)
    {
        do
        {
            printf("\n1-Modificar nombre\n2-Modificar Apellido\n3-Modificar sexo\n4-Salir de modificacion\nSeleccionar: ");
            scanf("%d", &opcionEdicion);
            switch(opcionEdicion)
            {
                case 1: setNombre(listadoActores, encontroPosicion); break;
                case 2: setApellido(listadoActores, encontroPosicion); break;
                case 3: setSexo(listadoActores, encontroPosicion); break;
            }
        }while(opcionEdicion !=4);
    }
    else
    {
        printf("\nEl ID especificado no existe.");

    }
    return retorno;
}
void Actor_listarActores(Actor listadoActores[], int MAX)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(listadoActores[i].isEmpty == 0)
        {
            Actor_listarActor(listadoActores, i);
        }
    }
}

void Actor_listarActor(Actor listadoActores[], int indice)
{
    printf("\n\t\t\t-------ID:%d--------", listadoActores[indice].codigo);
    printf("\nNombre: %s", listadoActores[indice].nombre);
    printf("\nApellido: %s", listadoActores[indice].apellido);
    printf("\nSexo: %c", listadoActores[indice].sexo);
}
int Actor_encontrarPosicionVacia(Actor listadoActores[], int MAX)
{
    int retorno = -1;
    int i;
    for(i = 0; i<MAX; i++)
    {
        if(listadoActores[i].isEmpty == 1)
        {
            retorno = i;
        }
    }
    return retorno;
}


void setNombre(Actor listadoActores[], int indice)
{
    char nombre[51];
    printf("\nIngrese el nuevo nombre:");
    gets(nombre);
    strcpy(listadoActores[indice].nombre, nombre);
}

void setApellido(Actor listadoActores[], int indice)
{
    char apellido[51];
    printf("\nIngrese el nuevo nombre:");
    gets(apellido);
    strcpy(listadoActores[indice].apellido, apellido);
}

void setSexo(Actor listadoActores[], int indice)
{
    char sexo;
    printf("\nIngrese el nuevo nombre:");
    fflush(stdin);
    scanf("%c", sexo);
    listadoActores[indice].sexo = sexo;
}

