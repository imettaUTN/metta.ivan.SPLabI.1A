#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicleta.h"
#include "Parser.h"
#include "Controller.h"
#include <string.h>
#define TRUE 1
#define FALSE 0
int controller_LoadFromText(char* path , LinkedList* pList)
{
    int todoOk = 0;
    FILE * f = fopen(path,"r");

    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
        return todoOk;
    }
    todoOk = parser_BiciFromText(f,pList);
    fclose(f);
    printf("Carga de datos exitosa \n");
    return todoOk;
}


int controller_ShowBicicletas(LinkedList* pList)
{
    int allOk = TRUE;

    eBicicleta* pBici;


	if(pList != NULL)
	{
	    system("cls");
		printf("\n ID \tNombre Dueño \t       Tipo   \tTiempo \n\n");
		for(int i = 0; i < ll_len(pList); i++)
		{
			pBici = ll_get(pList, i);
			if(pBici != NULL)
            {
                ShowBici(pList, i);
                allOk = 0;
            }
		}
	}
	else if(allOk)
	{
		printf("No hay paises cargados en la lista.\n");
	}

    return allOk;
}


/** \brief Guarda los datos de los paises en el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_saveAsText(char* path, LinkedList* pList)
{
    int auxId;
	char auxNombre[128];
	char auxTipo[10];
	int auxTiempo;
	FILE* pFile;
	int error = TRUE;
	eBicicleta* pBici;

	if(pList != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			error = FALSE;
			for(int i = 0; i < ll_len(pList); i++)
			{
				pBici = ll_get(pList, i);

                Bicicleta_GetId(pBici, &auxId);
                Bicicleta_GetNombre(pBici, auxNombre);
                Bicicleta_GetTipo(pBici, auxTipo);
                Bicicleta_GetTiempo(pBici, &auxTiempo);

                fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxNombre, auxTipo, auxTiempo);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(error)
        {
            printf("Error\n");
        }
	}

    return error;
}
