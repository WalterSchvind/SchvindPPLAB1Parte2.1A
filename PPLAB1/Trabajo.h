#include "Notebooks.h"
#include "Servicios.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
   int dia;
   int mes;
   int anio;
}eFecha;
typedef struct
{
    int id;// (autoincremental)
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED
/** \brief Inicializa todos los elementos del vector trabajo
 *
 * \param vec[] eTrabajo el vector a ser inicializado
 * \param tam int el tamaño del vector
 * \return void
 *
 */
void inicializarTrabajo(eTrabajo vec[],int tam);
/** \brief Busca lugares libres en el vector de trabajos
 *
 * \param vec[] eTrabajo el vector
 * \param tam int tamaño del vector
 * \return int devuelve el indice del lugar vacio
 *
 */
int buscarLibreTrabajo(eTrabajo vec[], int tam);
/** \brief carga un trabajo en el vector de trabajos
 *
 * \param proximoId int id con el que va a ser cargado el trabajo
 * \param vec[] eTrabajo el vector de trabajos
 * \param tam int tamaño del vector
 * \param notebooks[] eNotebook vector de notebooks
 * \param tamN int tamaño del vector de notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tamS int tamaño del vector de servicios
 * \return int devuelve 1 si se cargo el trabajo y 0 si hubo error
 *
 */
int altaTrabajo(int proximoId,eTrabajo vec[], int tam,eNotebook notebooks[], int tamN, eServicio servicios[], int tamS);

/** \brief muestra 1 trabajo del vector de trabajos
 *
 * \param trabajo eTrabajo el trabajo que queremos mostrar
 * \param notebooks[] eNotebook vector de notebooks
 * \param tamN int tamaño del vector notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tamS int tamaño del vector de servicio
 * \return void
 *
 */
void listarTrabajo(eTrabajo trabajo, eNotebook notebooks[], int tamN,eServicio servicios[], int tamS);
/** \brief muestra todos los trabajos del vector de trabajos
 *
\param trabajo eTrabajo el trabajo que queremos mostrar
 * \param notebooks[] eNotebook vector de notebooks
 * \param tamN int tamaño del vector notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tamS int tamaño del vector de servicio
 * \return void
 *
 */
void listarTrabajos(eTrabajo vec[], int tam,eNotebook notebooks[],int tamN, eServicio servicios[], int tamS);
