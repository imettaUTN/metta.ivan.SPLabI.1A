#include <stdio.h>
#include <stdlib.h>
#include "Bicicleta.h"
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

eBicicleta* Bicicleta_new()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));

}

eBicicleta* Bicicleta_newParametros(char* id_bici, char* nombre, char* tipo, char* tiempo)
{
    eBicicleta* pBici = NULL;
    pBici = Bicicleta_new();

    if(id_bici != NULL && nombre != NULL && tipo != NULL && tiempo != NULL)
    {

        if(Bicicleta_SetId(pBici, atoi(id_bici)) == -1 || Bicicleta_SetNombre(pBici, nombre) == -1 || Bicicleta_SetTipo(pBici,tipo) == -1 || Bicicleta_SetTiempo(pBici, atof(tiempo)) == -1)
        {
            Bicicleta_borrar(pBici);
            pBici = NULL;
        }
        else
        {
            Bicicleta_SetId(pBici, atoi(id_bici));
            Bicicleta_SetNombre(pBici, nombre);
            Bicicleta_SetTipo(pBici, tipo);
            Bicicleta_SetTiempo(pBici, atof(tiempo));
        }
    }
    return pBici;
}


void Bicicleta_borrar(eBicicleta* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int Bicicleta_SetId(eBicicleta* this, int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
        {
            this->id_bike = id;
            retorno = 1;
        }
return retorno;
}

int Bicicleta_GetId(eBicicleta* this, int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
        {
            *id = this->id_bike;
            retorno = 1;
        }

return retorno;
}

int Bicicleta_SetNombre(eBicicleta* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
return retorno;
}

int Bicicleta_GetNombre(eBicicleta* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}

int Bicicleta_SetTipo(eBicicleta* this, char* tipo)
{
    int retorno = 0;
    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo, tipo);
        retorno = 1;
    }
    return retorno;
}

int Bicicleta_GetTipo(eBicicleta* this, char* tipo)
{
    int retorno = 0;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        retorno = 1;
    }

    return retorno;
}

int Bicicleta_SetTiempo(eBicicleta* this, int tiempo)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->tiempo = tiempo;
        retorno = 1;
    }

    return retorno;
}

int Bicicleta_GetTiempo(eBicicleta* this, int* tiempo)
{
    int retorno = 0;
    if(this != NULL)
        {
            *tiempo = this->tiempo;
            retorno = 1;
        }
return retorno;
}


int ShowBici(LinkedList* pList, int index)
{
    int auxId;
    char auxNombre[128];
    char auxTipo[10];
    int auxTiempo;
    int error = TRUE;

    eBicicleta* pBici;

    if(pList != NULL && index >= 0)
    {
        pBici = ll_get(pList, index);

        Bicicleta_GetId(pBici, &auxId);
        Bicicleta_GetNombre(pBici, auxNombre);
        Bicicleta_GetTipo(pBici, auxTipo);
        Bicicleta_GetTiempo(pBici, &auxTiempo);

        printf("%-5d \t%-50s %-10s \t%-5d\n", auxId, auxNombre, auxTipo, auxTiempo);

        error = FALSE;
    }
    else if(error)
    {
        printf("Error\n");
    }

    return error;
}


int bicicleta_getTiempoRandom(void)
{
    int aleatorio;
    aleatorio = rand()%(71)+50;

    return aleatorio;
}

void* bicicleta_setTiempoRandom(void* bici)
{
     eBicicleta * pBici = NULL;
    if(bici != NULL)
    {
        pBici = (eBicicleta*)bici;
      Bicicleta_SetTiempo(pBici, bicicleta_getTiempoRandom());
    }

    return pBici;
}

int bicicleta_filtrarPorTipo(void* bici, char * tipo)
{
    int cumple = FALSE;
    eBicicleta* pBici;

    if(bici != NULL && tipo != NULL)
    {
        pBici = (eBicicleta*) bici;
        cumple = (strcmp(pBici->tipo,tipo) ==0);
    }
    return cumple;
}

int bicicleta_ordenarPorTipoTiempo(void * elemA, void * elemB)
{
    eBicicleta * bici1 = (eBicicleta *) elemA;
    eBicicleta * bici2 = (eBicicleta *) elemB;

    //si el tipo es igual , comparo por tiempo
    if(strcmp(bici1->tipo,bici2->tipo) == 0)
    {
        return bici1->tiempo -bici2->tiempo;
    }
    //comparo por tipo
    return strcmp(bici1->tipo,bici2->tipo);
}
