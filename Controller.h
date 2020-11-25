#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


/** \brief Carga los datos de los paises desde el archivo  (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_LoadFromText(char* path , LinkedList* pLista);


/** \brief Lista a las bicicletas
 *
 * \param path char* ruta del archivo
 * \param pLista LinkedList* puntero a la lista
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_ShowBicicletas(LinkedList* pLista);


/** \brief Guarda los datos de las bicis en el archivo (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pLista LinkedList* puntero a la lista
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_saveAsText(char* path, LinkedList* pLista);


#endif // CONTROLLER_H_INCLUDED
