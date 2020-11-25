#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Bicicleta.h"
#include "Controller.h"
#include <time.h>
#include "Common.h"
#define TRUE 1
#define FALSE 0
int main()
{
    srand (time(NULL));
    int cargueDatosPrimero = FALSE;
    int exit = FALSE;
    int option ;
    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaFiltrada;
    char tipo[10] ;

    if(listaBicicletas == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        return 0;
    }
    option =common_getMenu("1. Cargar archivos\n2. Imprimir lista\n3. Asignar tiempos\n4. Filtrar por tipos\n5. Mostrar posiciones\n6. Guardar posiciones\n7. Salir\n","Opcion invalida. Reingrese",1,7,3);

    do
    {
        switch(option)
        {
        case 1:

            if(controller_LoadFromText("bicicletas.csv", listaBicicletas))
            {
                cargueDatosPrimero = TRUE;
            }
            break;
        case 2:
            if(cargueDatosPrimero)
            {
                controller_ShowBicicletas(listaBicicletas);
            }
            else
            {
                printf("Error. Primero debe cargar la lista.\n");
            }
            break;
        case 3:
            if(cargueDatosPrimero)
            {
                listaBicicletas = ll_map(listaBicicletas,bicicleta_setTiempoRandom);
                controller_ShowBicicletas(listaBicicletas);
            }
            else
            {
                printf("Error. Primero debe cargar la lista.\n");
            }
            break;
        case 4:
            if(cargueDatosPrimero)
            {
                fflush(stdin);
                do
                {
                    printf("Ingrese el tipo a filtar entre : BMX,PLAYERA,MTB,PASEO\n");
                    gets(tipo);
                }
                while((strcmp(tipo,"bmx") ==0 && strcmp(tipo,"BMX") ==0 &&strcmp(tipo,"PLAYERA") ==0 &&strcmp(tipo,"playera") ==0&& strcmp(tipo,"MTB") ==0&& strcmp(tipo,"mtb") ==0 && strcmp(tipo,"PASEO") ==0&& strcmp(tipo,"paseo") ==0 ));
                printf("------------------------------------------------\n");
                listaFiltrada =  ll_filter(listaBicicletas,bicicleta_filtrarPorTipo,tipo);
                controller_saveAsText("TiempoBicicletas.csv", listaFiltrada);
                controller_ShowBicicletas(listaFiltrada);
                printf("**** Las bicicletas fueron filtradas con exito y guardados en -TiempoBicicletas.csv- ****\n\n");
                printf("------------------------------------------------\n");

            }
            else
            {
                printf("Error. Primero debe cargar la lista.\n");
            }
            break;
        case 5:
            if(cargueDatosPrimero)
            {
                //no me acuerdo si el 1 es asc o desc
                if(!ll_sort(listaBicicletas,bicicleta_ordenarPorTipoTiempo,1))
                {
                    printf("Lista ordenada correctamente \n");
                }

            }
            else
            {
                printf("Error. Primero debe cargar la lista.\n");
            }
            break;
        case 6:
            if(cargueDatosPrimero)
            {
                if(!controller_saveAsText("Posiciones.csv", listaBicicletas))
                {
                    printf("Posiciones guardadas correctamente\n");
                }
            }
            else
            {
                printf("Error. Primero debe cargar la lista.\n");
            }
            break;
        case 7:
            printf("El sistema se va a cerrar\n");
            exit = TRUE;
            break;
        }

        if(!exit)
        {
            printf("¿Desea continuar operador? YES 1 NOT 0\n");
            scanf("%d",&exit);
            exit = !exit;
            system("cls");
        }
        if(!exit)
        {
            option =common_getMenu("1. Cargar archivos\n2. Imprimir lista\n3. Asignar tiempos\n4. Filtrar por tipos\n5. Mostrar posiciones\n6. Guardar posiciones\n7. Salir\n","Opcion invalida. Reingrese",1,7,3);
        }

    }
    while(!exit && option != 7 );
// libero la lista de memoria
    ll_deleteLinkedList(listaBicicletas);
    ll_deleteLinkedList(listaFiltrada);
    return 0;
}
