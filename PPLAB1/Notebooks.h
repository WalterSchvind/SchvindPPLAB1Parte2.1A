#include "Marcas.h"
#include "Tipo.h"
#include "Cliente.h"
#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

typedef struct
{
int id;
char modelo[20];
int idMarca;
int idTipo;
int idCliente;
float precio;
int isEmpty;
}eNotebook;

#endif // NOTEBOOKS_H_INCLUDED

/** \brief inicializa el vector de notebooks
 *
 * \param vec[] eNotebook vector
 * \param tam int tamaño
 * \return void
 *
 */
void inicializarNotebooks(eNotebook vec[],int tam);
/** \brief busca un lugar libre en el vector
 *
 * \param vec[] eNotebook vector
 * \param tam int tamaño
 * \return int indice del lugar libre
 *
 */
int buscarLibre(eNotebook vec[],int tam);
/** \brief busca una notebooks segun id
 *
 * \param id int id buscado
 * \param vec[] eNotebook vector
 * \param tam int tamaño
 * \return int indice de la notebook encontrada
 *
 */
int buscarNotebook(int id,eNotebook vec[],int tam);
/** \brief  da de alta una notebook en el vector
 *
 * \param id int id de la notebook que va a ser dada de alta
 * \param vec[] eNotebook vector de notebooks
 * \param tam int tamaño de vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tamM int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tamT int tamaño del vector de tipos
 * \return int 1 si pudo dar de alta 0 si no pudo
 *
 */
int altaNotebook(int id,eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC);
/** \brief da de baja una notebook de manera logica
 *
 * \param vec[] eNotebook vector de noteboks
 * \param tam int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tamM int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tamT int tamaño del vector de tipos
 * \return void
 *
 */
void bajaNotebook(eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC);
/** \brief muestra una notebooks del vector
 *
 * \param x eNotebook notebooks que se va a mostrar
 * \param marcas[] eMarca vector de marcas
 * \param tamM int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tamT int tamaño del vector de tipos
 * \return void
 *
 */
void mostrarNotebook(eNotebook x,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC);
/** \brief muestra todas las notebooks del vector
 *
 * \param vec[] eNotebook vector de notebooks
 * \param tam int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tamM int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tamT int tamaño del vector de tipos
 * \return void
 *
 */
void mostrarNotebooks(eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC);
/** \brief muestra notebooks para la estructura de trabajo
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tamNote int tamaño del vector
 * \return void
 *
 */
void mostrarNotebooksParaTrabajo(eNotebook notebooks[], int tamNote);
/** \brief ordena las notebooks
 *
 * \param vec[] eNotebook vector de notebooks
 * \param tamN int vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tamM int tamaño de vector de marcas
 * \return void
 *
 */
void ordenarNotebooks(eNotebook vec[],int tamN,eMarca marcas[],int tamM);
/** \brief menu de modificaciones de notebooks
 *
 * \return int opcion elegida
 *
 */
int menuModificacionesNotebook();
/** \brief modifica segun la eleccion del usuario una notebook del vector
 *
 * \param vec[] eNotebook vector de notebooks
 * \param tam int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tamM int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tamT int tamaño del vector de tipos
 * \return void
 *
 */
void modificarNotebook(eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC);

/** \brief carga la descripcion del modelo de la notebook
 *
 * \param modelo[] char variable donde va a ser cargada la descripcion
 * \param id int id de la notebook cuyo modelo deseamos copiar
 * \param vec[] eNotebook vector de notebooks
 * \param tam int tamaño del vector de notebooks
 * \return void
 *
 */
int cargarDescripcionNotebook(char descripcion[], int id, eNotebook notebooks[], int tamNote);
void hardcodearNotebooks(eNotebook vec[], int cant);
void harcodearClientes(eCliente lista[],int tam);

