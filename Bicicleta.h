#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id_bike;
    char nombre[128];
    char tipo[10];
    int tiempo;
}eBicicleta;


/** \brief Guarda espacio en memoria para una bici
 *
 * \return Puntero al espacio guardado
 *
 */
eBicicleta* Bicicleta_new();


/** \brief Carga los nuevos parametros de bicicleta
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param tipoStr char*
 * \param tiempo char*
 * \return nueva bicicleta
 *
 */
eBicicleta* Bicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempo);

/** \brief
 *  setea el id de la bici id
 * \param this eBicicleta* puntero a la bici
 * \param id int id bici
 * \return int error?
 *
 */
int Bicicleta_SetId(eBicicleta* this, int id);

/** \brief
 * setea el nombre de la bici
 * \param this eBicicleta* puntero a la bici
 * \param nombre char* nombre
 * \return int error ? 0,1
 *
 */
int Bicicleta_SetNombre(eBicicleta* this, char * nombre);

/** \brief
 * Setea el tipo de bici
 * \param this eBicicleta* puntero a la bici
 * \param tipo char* tipo
 * \return int error? 0,1
 *
 */
int Bicicleta_SetTipo(eBicicleta* this, char* tipo);

/** \brief
 *  setea el tiempo
 * \param this eBicicleta*
 * \param tiempo int tiempo
 * \return int error? 0,1
 *
 */
int Bicicleta_setTiempo(eBicicleta* this, int tiempo);

/** \brief
 * Libera memoria del puntero a l bici
 * \param this eBicicleta* puntero a la bici
 * \return void
 *
 */
void Bicicleta_borrar(eBicicleta* this);


/** \brief Asigna el id
 *
 * \param this eBicicleta*
 * \param id int*
 * \return int error [1] si hubo error, [0] si no hubo error
 *
 */
int Bicicleta_GetId(eBicicleta* this, int* id);

/** \brief
 * obtiene el nombre
 * \param this eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int Bicicleta_GetNombre(eBicicleta* this, char* nombre);

int Bicicleta_GetTipo(eBicicleta* this, char* tipo);

int Bicicleta_GetTiempo(eBicicleta* this, int* tiempo);

/** \brief
 * Muestra una bicicleta
 * \param pList LinkedList*
 * \param index int
 * \return int
 *
 */
int ShowBici(LinkedList* pList, int index);

/** \brief
 * Obtiene el tiempo random entre 50 y 120 min
 * \param void
 * \return int
 *
 */
int bicicleta_getTiempoRandom(void);

/** \brief
 * setea el tiempo random
 * \param bici void*
 * \return void*
 *
 */
void* bicicleta_setTiempoRandom(void* bici);

/** \brief
 * Filtra una bicicleta para un tipo dado
 * \param bici void* puntoero a la bici
 * \param tipo char* tipo a filtrar
 * \return int error?
 *
 */
int bicicleta_filtrarPorTipo(void* bici, char * tipo);

/** \brief
 *  Ordena la bici por tiempo y tipo
 * \param elemA void* puntero a bici
 * \param elemB void* punntero a bici
 * \return int error?
 *
 */
int bicicleta_ordenarPorTipoTiempo(void * elemA, void * elemB);
#endif // BICICLETA_H_INCLUDED
