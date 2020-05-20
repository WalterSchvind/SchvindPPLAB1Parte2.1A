#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;//comienza en 1000
    char descripcion[20];
    int isEmpty;

}eMarca;


#endif // MARCAS_H_INCLUDED
/** \brief inicializa el vector de marca
 *
 * \param vec[] eMarca vector
 * \param tam int tamaño
 * \return void
 *
 */
void inicializarMarcas(eMarca vec[],int tam);
/** \brief busca lugar libre en el vector de marcas
 *
 * \param vec[] eMarca vector
 * \param tam int tamaño
 * \return int indice del lugar libre
 *
 */
int buscarLibreMarca(eMarca vec[],int tam);
/** \brief busca marca por id en el vector de marcas
 *
 * \param id int id de la marca
 * \param vec[] eMarca vector
 * \param tam int tamaño
 * \return int indice de la marca encontrada o -1 si no encontro nada
 *
 */
int buscarMarca(int id,eMarca vec[],int tam);
/** \brief carga una marca al vector de marcas
 *
 * \param id int id con el que va a ser cargada la marca
 * \param vec[] eMarca vector
 * \param tam int tamaño
 * \return int 0 si no pudo cargar y 1 si pudo cargar
 *
 */
int altaMarca(int id,eMarca vec[],int tam);
/** \brief carga la descripcion una marca del vector
 *
 * \param descripcion[] char variable donde va a ser cargada la descripcion
 * \param id int id de la marca
 * \param vec[] eMarca vector
 * \param tam int tamaño
 * \return void
 *
 */
void cargarDescripcionMarca(char descripcion[],int id,eMarca vec[],int tam);
/** \brief muestra una marca del vector
 *
 * \param x eMarca marca que se va a mostrar
 * \return void
 *
 */
void mostrarMarca(eMarca x);
/** \brief muestra todas las marcas del vector
 *
 * \param marcas[] eMarca vector
 * \param tam int tamaño
 * \return void
 *
 */
void mostrarMarcas(eMarca marcas[],int tam);
/** \brief menu de marcas
 *
 * \param vec[] eMarca vector
 * \param tam int tamaño
 * \return int id de la marca elegida
 *
 */
int menuMarcas(eMarca vec[],int tam);
