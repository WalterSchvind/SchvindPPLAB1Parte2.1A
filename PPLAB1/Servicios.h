#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
int id;
char descripcion[25];
float precio;
int isEmpty;

}eServicio;

#endif // SERVICIOS_H_INCLUDED
/** \brief inicializa el vector de servicios
 *
 * \param vec[] eServicio vector
 * \param tam int tamaño
 * \return void
 *
 */
void inicializarServicios(eServicio vec[],int tam);
/** \brief busca un lugar libre en el vector de servicios
 *
 * \param vec[] eServicio vector de servicios
 * \param tam int tamaño del vector de servicios
 * \return int indice del lugar libre
 *
 */
int buscarLibreServicio(eServicio vec[],int tam);
/** \brief busca un servicio por id
 *
 * \param id int id del servicio
 * \param vec[] eServicio vector
 * \param tam int tamaño
 * \return int indice del servicio encotrado o -1 si no encotro
 *
 */
int buscarServicio(int id,eServicio vec[],int tam);
/** \brief da de alta un servicio en el vector
 *
 * \param id int id con el que va a ser cargado el servicio
 * \param vec[] eServicio vector
 * \param tam int tamaño
 * \return int 0 si no pudo y 1 si pudo
 *
 */
int altaServicio(int id,eServicio vec[],int tam);
/** \brief  hace una baja logica a un servicio en el vector
 *
 * \param vec[] eServicio vector
 * \param tam int tamaño
 * \return void
 *
 */
void bajaServicio(eServicio vec[],int tam);
/** \brief carga la descripcion de un servicio del vector
 *
 * \param descripcion[] char variable donde va a ser cargada la descripcion
 * \param id int id del servicio
 * \param vec[] eServicio vector de servicios
 * \param tamS int tamaño
 * \return void
 *
 */
void cargarDescripcionServicio(char descripcion[], int id, eServicio vec[], int tamS);
/** \brief muestra un servicio del vector
 *
 * \param x eServicio servicio a ser mostrado
 * \return void
 *
 */
void mostrarServicio(eServicio x);
/** \brief muestra todos los servicios del vector
 *
 * \param vec[] eServicio vector
 * \param tam int tamaño
 * \return void
 *
 */
void mostrarServicios(eServicio vec[],int tam);
/** \brief menu de servicios
 *
 * \param vec[] eServicio vector
 * \param tam int tamaño
 * \return int eleccion del usuario
 *
 */
int menuServicios(eServicio vec[],int tam);

