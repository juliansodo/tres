#include "Sistema.h"
#define MAX_ACTOR 20

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    int isEmpty;
}Actor;

void Actor_inicializarActores(Actor *, int);
int Actor_altaActor(Actor[], int);
int Actor_bajarActor(Actor[], int);
int Actor_modificarActor(Actor[], int);
void Actor_listarActores(Actor[], int);
void Actor_listarActor(Actor[], int);
void setNombre(Actor*, int);
void setApellido(Actor*, int);
void setSexo(Actor*, int);
int Actor_encontrarPosicionVacia(Actor*, int);

