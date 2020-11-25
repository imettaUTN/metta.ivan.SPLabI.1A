#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicleta.h"

int parser_BiciFromText(FILE* pFile, LinkedList* pMiLista)
{
	eBicicleta* pBici;
    int error = 0;
	char id[200];
	char nombre[200];
	char tipo[200];
	char tiempo[200];

	if(pFile != NULL && pMiLista != NULL)
	{
	    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo) == 4)
			{
				pBici = Bicicleta_newParametros(id, nombre, tipo, tiempo);

				if(pBici != NULL)
				{
					ll_add(pMiLista, pBici);
					error = 1;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);
	}
return error;
}
