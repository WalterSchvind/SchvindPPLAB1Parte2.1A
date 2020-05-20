#include "Notebooks.h"
#include "Validaciones.h"
#include "Servicios.h"
#include "Tipo.h"
#include "Marcas.h"
#include "Trabajo.h"

#include "datos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


void inicializarNotebooks(eNotebook vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}
int buscarLibre(eNotebook vec[],int tam)
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
int buscarNotebook(int id,eNotebook vec[],int tam)
{

    int indice =-1;

    for (int i=0; i<tam; i++)
    {
        if(vec[i].id==id&&vec[i].isEmpty==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int altaNotebook(int id,eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC)
{
    int indice=buscarLibre(vec,tam);
    int sePudoM=-1;
    int sePudoT=-1;
    int sePudoMo;
    int todoOk=0;
    int marca;
    int tipo;
    int cliente;


    eNotebook auxNotebook;

    system("cls");
    auxNotebook.id=id;

    sePudoMo=utn_getCadena(auxNotebook.modelo,20,3,"Ingrese modelo: ","Error. nombre de modelo muy largo\n");

    marca=menuMarcas(marcas,tamM);
    for(int i=0;i<tamM;i++)
    {
        if(marca==marcas[i].id)
        {
            auxNotebook.idMarca=marca;
            sePudoM=0;
            break;
        }
    }

    tipo=menuTipos(tipos,tamM);
    for(int i=0;i<tamT;i++)
    {
        if(tipo==tipos[i].id)
        {
            auxNotebook.idTipo=tipo;
            sePudoT=0;
            break;
        }

    }


    printf("Ingrese precio: ");
    fflush(stdin);
    scanf("%f",&auxNotebook.precio);

    listarClientes(clientes,tamC);
    printf("Ingrese el id del cliente");
    scanf("%d",&cliente);
            auxNotebook.idCliente=cliente;


    auxNotebook.isEmpty=0;

    if(sePudoM==0&&sePudoT==0&&sePudoMo==0)
    {
        vec[indice] = auxNotebook;//Copio al vector el empleado nuevo
        todoOk=1;
    }


    return todoOk;
}
void bajaNotebook(eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC)
{

    int id;
    int indice;
    char confirma;

    system("cls");
    mostrarNotebooks( vec,tam,marcas,tamM,tipos,tamT,clientes,tamC);


    printf("Ingrese  ID: ");
    scanf("%d",&id);

    indice=buscarNotebook(id,vec,tam);

    if(indice==-1)
    {
        printf("La notebook no existe\n");
    }
    else
    {
        system("cls");
        mostrarNotebook(vec[indice],marcas,tamM,tipos,tamT,clientes,tamC);

        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("La notebook se dio de baja\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }
    }
}
void mostrarNotebook(eNotebook x,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC)
{
    char nombreMarca[20];
    char nombreTipo[20];
    char nombreCliente[20];
    cargarDescripcionMarca(nombreMarca,x.idMarca,marcas,tamM);
    cargarDescripcionTipo(nombreTipo,x.idTipo,tipos,tamT);
    cargarNombreClientes(nombreCliente,x.idCliente,clientes,tamC);
    printf("%2d  %10s  %10s    %10s    %.2f    %10s\n",x.id,x.modelo,nombreMarca,nombreTipo,x.precio,nombreCliente);
}
void mostrarNotebooks(eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC)
{
    int flag=0;

    ordenarNotebooks(vec,tam,marcas,tamM);

    printf("ID      Modelo       Marca        Tipo      Precio\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarNotebook(vec[i],marcas,tamM,tipos,tamT,clientes,tamC);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("No hay que mostrar");
    }

}
void ordenarNotebooks(eNotebook vec[],int tamN,eMarca marcas[],int tamM)
{

    eNotebook auxNotebook;
    char auxDescripcionI[20];
    char auxDescripcionJ[20];

    for(int i=0; i<tamN; i++)
    {
        cargarDescripcionMarca(auxDescripcionI,vec[i].idMarca,marcas,tamM);
        for(int j=i+1; j<tamN; j++)
        {
            cargarDescripcionMarca(auxDescripcionJ,vec[j].idMarca,marcas,tamM);
            if(vec[i].isEmpty==0&&vec[j].isEmpty==0)
            {
                    if(strcmp(auxDescripcionI,auxDescripcionJ)>0 || (strcmp(auxDescripcionI,auxDescripcionJ) == 0 && vec[i].precio>vec[j].precio) )
                    {
                        auxNotebook = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxNotebook;
                    }
            }
        }
    }

}
int menuModificacionesNotebook()
{
    int opcion;


    printf("1.-Precio\n");
    printf("2.-Tipo\n");
    printf("Indique que dato desea modificar: ");
    scanf("%d",&opcion);

    return opcion;
}
void modificarNotebook(eNotebook vec[],int tam,eMarca marcas[],int tamM,eTipo tipos[],int tamT,eCliente clientes[],int tamC)
{
    int id;
    int indice;
    int auxTipo;
    float auxPrecio;

    char continuar='s';


    system("cls");
    printf("****Modificar Notebook****\n\n");
    mostrarNotebooks(vec,tam,marcas,tamM,tipos,tamT,clientes,tamC);


    printf("Ingrese  ID: ");
    scanf("%d",&id);

    indice=buscarNotebook(id,vec,tam);

    if(indice==-1)
    {
        printf("La notebook no existe\n");
    }

    else
    {


        do
        {
            system("cls");
            mostrarNotebook(vec[indice],marcas,tamM,tipos,tamT,clientes,tamC);
            switch(menuModificacionesNotebook())
            {
            case 1:
                printf("Ingrese nuevo precio: ");
                scanf("%f",&auxPrecio);
                vec[indice].precio=auxPrecio;
                break;
            case 2:
                auxTipo=menuTipos(tipos,tamT);
                vec[indice].idTipo=auxTipo;


                break;
            default:
                printf("Error.Opcion no valida");
            }


        printf("Desea continuar modificando?(s/n): ");
        fflush(stdin);
        scanf("%c",&continuar);



        }
        while(tolower(continuar)=='s');
    }
}
void mostrarNotebooksParaTrabajo(eNotebook notebooks[], int tamNote)
{


    system("cls");
    printf("***** Listado de Notebooks *****\n");
    printf(" Id          Modelo    \n");

    for(int i=0; i<tamNote; i++)
    {
        if(notebooks[i].isEmpty ==0)
        {
        printf("  %03d   %-15s \n",notebooks[i].id,notebooks[i].modelo);

        }
    }

}
int cargarDescripcionNotebook(char descripcion[], int id, eNotebook notebooks[], int tamNote)
{
    int todoOk= 0;

    for(int i=0; i<tamNote; i++)
    {
        if(notebooks[i].id == id)
        {
            strncpy(descripcion,notebooks[i].modelo,20);
            todoOk= 1;
        }
    }
    return todoOk;
}
void hardcodearNotebooks(eNotebook vec[],int cant)
{
    for(int i=0;i<cant;i++)
    {
        vec[i].id=harcodeIds[i];
        strcpy(vec[i].modelo,modelos[i]);
        vec[i].idTipo=idTipo[i];
        vec[i].idMarca=idMarca[i];
        vec[i].precio=precios[i];
        vec[i].idCliente=clientesId[i];
        vec[i].isEmpty=0;
    }
}
