
#include "Actor.h"

void Actor_inicializarActores(Actor listadoActores[], int MAX)
{
    int i;
    int codigos[4] = {0,1,2,3};
    char nombres[4][51] = {"Leonardo", "Joseph", "Leigh", "Leonardo"};
    char apellidos[4][51] = {"Dicaprio", "Gordon", "Whannel", "Sbaraglia"};
    char sexos[4] = {'M','M','M', 'M'};
    for(i = 0; i<MAX; i++)
    {
        listadoActores[i].isEmpty = 1;
    }
    for(i = 0; i < 4 ; i++)
    {
        listadoActores[i].codigo = codigos[i];
        strcpy(listadoActores[i].nombre , nombres[i]);
        strcpy(listadoActores[i].apellido ,apellidos[i]);
        listadoActores[i].sexo = sexos[i];
        listadoActores[i].isEmpty = 0;
    }
}

int Actor_buscarIndicePorID(Actor listadoActores[], int MAX, int indice)
{
    int i;
    int retorno = -1;
    for(i = 0; i<MAX; i++)
    {
        if(listadoActores[i].isEmpty == 0)
        {
            if(indice == listadoActores[i].codigo)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}

int Actor_altaActor(Actor listadoActores[], int MAX)
{
    int posicionVacia = Actor_encontrarPosicionVacia(listadoActores, MAX);
    int retorno = -1;
    char nombre[51];
    if(posicionVacia != -1)
    {
        printf("%d \n", posicionVacia);
        int codigo = posicionVacia;
        char nombre[51];
        char apellido[51];
        char sexo;
        fflush(stdin);
        do
        {
            printf("\nIngrese el nombre del actor(Maximo 51 caracteres): ");
            gets(nombre);
        }while(strlen(nombre) > 51);

        fflush(stdin);
        do
        {
            printf("\nIngrese el apellido del actor(Maximo 51 caracteres): ");
            gets(apellido);
        }while(strlen(apellido) > 51);

        do
        {
            printf("\nIngrese el sexo del actor(valido solo M(masculino) o F(femenino): ");
            fflush(stdin);
            scanf("%c", &sexo);
        }while(toupper(sexo) != 'M' && toupper(sexo) !='F');
        strcpy(listadoActores[posicionVacia].nombre , toupper(nombre));
        strcpy(listadoActores[posicionVacia].apellido , toupper(apellido));
        listadoActores[posicionVacia].sexo = toupper(sexo);
        listadoActores[posicionVacia].isEmpty = 0;
        listadoActores[posicionVacia].codigo = codigo;
        printf("\nSe dio de alta un nuevo actor. La información es: \n");
        Actor_listarActor(listadoActores,posicionVacia);
    }
}
int Actor_bajarActor(Actor listadoActores[], int MAX)
{
    int indice;
    int encontroPosicion;
    int retorno;
    printf("Ingrese el ID del actor que desea bajar: ");
    scanf("%d", &indice);
    encontroPosicion = Actor_buscarIndicePorID(listadoActores,MAX,indice);
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
    printf("Ingrese el ID del actor que desea modificar: ");
    scanf("%d", &indice);
    encontroPosicion = Actor_buscarIndicePorID(listadoActores, MAX, indice);
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
    Actor * auxListadoActores;
    auxListadoActores = listadoActores;
    for(i=0;i<MAX;i++)
    {
        if(auxListadoActores[i].isEmpty == 0)
        {
            Actor_listarActor(auxListadoActores,i);
        }
    }

}

void Actor_listarActoresOrdenados(Actor listadoActores[], int MAX)
{
    int i;
    Actor * auxListadoActores;
    auxListadoActores = listadoActores;
    auxListadoActores = Actor_ordenarXNombreYApellido(auxListadoActores, MAX);
    for(i=0;i<MAX;i++)
    {
        if(auxListadoActores[i].isEmpty == 0)
        {
            Actor_listarActor(auxListadoActores,i);
        }
    }

}
void Actor_listarActor(Actor listadoActores[], int indice)
{

    printf("\n-------ID:%d--------", listadoActores[indice].codigo);
    printf("\nNombre: %s", listadoActores[indice].nombre);
    printf("\nApellido: %s", listadoActores[indice].apellido);
    printf("\nSexo: %c", listadoActores[indice].sexo);
    printf("\n-------------------\n");
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
            break;
        }
    }
    return retorno;
}


void setNombre(Actor listadoActores[], int indice)
{

    char nombre[51];
    printf("\nIngrese el nuevo nombre:");
    fflush(stdin);
    gets(nombre);
    strcpy(listadoActores[indice].nombre, toupper(nombre));
}

void setApellido(Actor listadoActores[], int indice)
{
    char apellido[51];
    printf("\nIngrese el nuevo nombre:");
    fflush(stdin);
    gets(apellido);
    strcpy(listadoActores[indice].apellido, toupper(apellido));
}

void setSexo(Actor listadoActores[], int indice)
{
    char sexo;
    printf("\nIngrese el nuevo nombre:");
    fflush(stdin);
    scanf("%c", &sexo);
    listadoActores[indice].sexo = toupper(sexo);
}

Actor* Actor_ordenarXNombreYApellido(Actor listadoActores[], int MAX)
{
    int i,j;
    Actor* auxListadoActores = listadoActores;
    Actor auxActor;
    for(i = 0; i < MAX; i++)
    {
        for(j = i+1; j < MAX+1; j++)
        {
            if(auxListadoActores[i].isEmpty == 0 && auxListadoActores[j].isEmpty == 0)
            {
                if(strcmp(auxListadoActores[i].nombre, auxListadoActores[j].nombre) >0)
                {
                   // printf("%d ---- %d \n", auxListadoActores[i].codigo, auxListadoActores[j].codigo); //control de datos
                    auxActor = auxListadoActores[i];
                    auxListadoActores[i] = auxListadoActores[j];
                    auxListadoActores[j] = auxActor;
                }
                else if(strcmp(auxListadoActores[i].nombre, auxListadoActores[j].nombre) == 0)
                {
                    if(strcmp(auxListadoActores[i].apellido, auxListadoActores[j].apellido) >0)
                    {
                        auxActor = auxListadoActores[i];
                        auxListadoActores[i] = auxListadoActores[j];
                        auxListadoActores[j] = auxActor;
                    }
                }
            }
        }
    }

    return auxListadoActores;

}

