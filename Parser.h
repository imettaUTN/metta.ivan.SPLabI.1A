#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


/** \brief Analiza y parsea los datos de los paises desde el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return exito [1] si hubo error, [0] si no hubo error
 *
 */
int parser_BiciFromText(FILE* pFile , LinkedList* pLista);


#endif // PARSER_H_INCLUDED
