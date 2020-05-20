#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;

}eTipo;


#endif // TIPO_H_INCLUDED
/** \brief inicializa el vector de tipos
 *
 * \param vec[] eTipo vector de tipos
 * \param tam int tamaño del vector
 * \return void
 *
 */
void inicializarTipos(eTipo vec[],int tam);

/** \brief busca lugar libre en el vector de tipos
 *
 * \param vec[] eTipo vector de tipos
 * \param tam int tamaño
 * \return int indice del lugar libre
 *
 */
int buscarLibreTipo(eTipo vec[],int tam);

/** \brief busca un tipo segun id
 *
 * \param id int id buscado
 * \param vec[] eTipo vector de tipos
 * \param tam int tamaño
 * \return int indice del tipo encontrado o -1 si no encontro nada
 *
 */
int buscarTipo(int id,eTipo vec[],int tam);

/** \brief  da de alta un nuevo tipo en el vector
 *
 * \param id int id del vector de tipos
 * \param vec[] eTipo vector de tipos
 * \param tam int tamaño del vector
 * \return int 1 si pudo 0 si no pudp
 *
 */
int altaTipo(int id,eTipo vec[],int tam);

/** \brief da de baja un elemento del vector de tipos
 *
 * \param vec[] eTipo vector
 * \param tam int tamaño del vector
 * \return void
 *
 */
void bajaTipo(eTipo vec[],int tam);

/** \brief carga la descripcion de uno de los elementos del vector
 *
 * \param descripcion[] char variable donde va a ser cargada la descripcio
 * \param id int id del tipo que deseamos cargar la descripcion
 * \param vec[] eTipo vector
 * \param tam int tamaño
 * \return void
 *
 */
void cargarDescripcionTipo(char descripcion[],int id,eTipo vec[],int tam);

/** \brief muestra un tipo del vector
 *
 * \param x eTipo tipo a ser mostrado
 * \return void
 *
 */
void mostrarTipo(eTipo x);

/** \brief muestra todos los elementos del vector
 *
 * \param vec[] eTipo vector
 * \param tam int tamaño
 * \return void
 *
 */
void mostrarTipos(eTipo vec[],int tam);

/** \brief menu de tipos
 *
 * \param vec[] eTipo vector
 * \param tam int tamaño
 * \return int eleccion del usuario
 *
 */
int menuTipos(eTipo vec[],int tam);
