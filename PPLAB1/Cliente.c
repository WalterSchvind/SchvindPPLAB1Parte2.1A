#include "Cliente.h"
#include "Validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

void inicializarClientes(eCliente vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibreCliente(eCliente vec[],int tam)
{
    int indice =-1;

    for (int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaCliente(int id,eCliente vec[],int tam)
{
    int indice=buscarLibreCliente(vec,tam);
    int sePudoN=-1;
    int sePudoS=-1;

    int todoOk=0;

    eCliente auxCliente;

    system("cls");
    auxCliente.id=id;

    sePudoN=utn_getCadena(auxCliente.nombre,20,3,"Ingrese nombre: ","Error. nombre muy largo\n");

    printf("Ingrese sexo(m/f): ");
    scanf("%c",&auxCliente.sexo);
    if(auxCliente.sexo=='m'||auxCliente.sexo=='f')
    {
        sePudoS=0;
    }



    auxCliente.isEmpty=0;

    if(sePudoN==0&&sePudoS==0)
    {
        vec[indice] = auxCliente;
        todoOk=1;
    }


    return todoOk;
}
void listarClientes(eCliente vec[],int tam)
{
    system("cls");
    printf("ID  Nombre Sexo\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            printf("%d %s %c\n",vec[i].id,vec[i].nombre,vec[i].sexo);
        }
    }
}
void cargarNombreClientes(char nombre[],int id,eCliente vec[],int tam)
{
     for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            strcpy(nombre,vec[i].nombre);
        }
    }

}
void harcodearClientes(eCliente lista[],int tam)
{
    int clientesId[]={10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    char clientesNombres[][20]={"Walter","Federico","Ana","Maria","Pedro","Juana","Esteban","Nahuel","Andrea","Fernando","Fernanda","Ivan","Ibana","Juan","Andrez","Matias","Agustina","Agustin","Carlos","Fernando","Miguel"};
    char sexos[] = {'m','m','f','f','m','f','m','m','f','m','f','m','f','m','m','m','f','m','m','m','m'};
    for(int i=0;i<tam;i++)
    {
        lista[i].id=clientesId[i];
        strcpy(lista[i].nombre,clientesNombres[i]);
        lista[i].sexo=sexos[i];
        lista[i].isEmpty=0;

    }
}

