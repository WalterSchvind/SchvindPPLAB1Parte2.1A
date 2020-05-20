#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED
/** \brief funcion que devuelve validado un numero flotante
 *
 * \param puntero float
 * \param intentos
 * \param mensaje
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return retorna 0 si todo salio bien, sino -1 si hubo algun error
 *
 */
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

/** \brief consigue un flotante
 *
 * \param puntero flotante
 * \return retorna 0 si todo salio bien, sino -1 si hubo algun error
 *
 */
int getFloat(float*pAux);


/** \brief funcion para saber si lo ingresado es float o no
 *
 * \param puntero auxiliar char
 * \return retorna 0 si todo salio bien, sino -1 si hubo algun error
 *
 */
int isFloat(char* pAux);


/** \brief funcion que me devuelve una cadena de caracteres validada
 *
 * \param puntero char
 * \param limite
 * \param intentos
 * \param mensaje
 * \param mensaje error
 * \return devuelve 0 si todo ok, sino -1 si hubo error
 *
 */
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

/** \brief consigue una cadena de caracter
 *
 * \param puntero char auxiliar
 * \param limite
 * \return 0 si todo ok, -1 si hubo un error
 *
 */
int getCadena(char* pAux, int limit);


/** \brief funcion para saber si lo ingresado es char o no
 *
 * \param char string
 * \return 0 si todo ok, -1 si hubo error
 *
 */
int isChar(char str[]);


/** \brief funcion que devuelve validado un numero entero
 *
 * \param puntero int
 * \param intentos
 * \param mensaje
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return
 *
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

/** \brief consigue un entero
 *
 * \param puntero entero
 * \return retorna 0 si todo salio bien, sino -1 si hubo algun error
 *
 */
int getInt(int* pAux);


/** \brief funcion para saber si lo ingresado es entero o no
 *
 * \param puntero auxiliar char
 * \return retorna 0 si todo salio bien, sino -1 si hubo algun error
 *
 */
int isInt(char *pAux);

