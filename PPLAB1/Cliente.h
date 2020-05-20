
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
int id;
char nombre[25];
char sexo;
int isEmpty;

}eCliente;


#endif // CLIENTE_H_INCLUDED

void inicializarClientes(eCliente vec[],int tam);
int buscarLibreCliente(eCliente vec[],int tam);
int altaCliente(int id,eCliente vec[],int tam);
void listarClientes(eCliente vec[],int tam);
void cargarNombreClientes(char nombre[],int id,eCliente vec[],int tam);
