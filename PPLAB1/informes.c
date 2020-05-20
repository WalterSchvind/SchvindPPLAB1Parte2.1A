#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "Notebooks.h"
#include "Servicios.h"
#include "Trabajo.h"
#include "informes.h"
int menuInformes()
{
    int opcion;

    system("cls");


    printf("1.-Mostrar notebooks de un tipo\n");
    printf("2.-Mostrar notebooks de una marca\n");
    printf("3.-Mostrar notebooks mas baratas\n");
    printf("4.-Mostrar notebooks por marca\n");
    printf("5.-Mostrar notebooks por tipo y marca\n");
    printf("7.-Salir\n");

    printf("Elija una opcion: " );
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
void informar(eNotebook vec[],int tam,eTipo tipos[],int tamT,eMarca marcas[],int tamM,eCliente clientes[],int tamC)
{
    char seguirI='s';
    char confirma;

    do
    {

        switch(menuInformes())
        {
        case 1:
            informarNotebooksDeUnTipo(vec,tam,tipos,tamT,marcas,tamM,clientes,tamC);


            break;
        case 2:
            informarNotebooksDeUnaMarca(vec,tam,tipos,tamT,marcas,tamM,clientes,tamC);

            break;
        case 3:
            notebookMasBarata(vec,tam,tipos,tamT,marcas,tamM,clientes,tamC);

            break;
        case 4:
                mostrarNotebooksPorMarca(vec,tam,tipos,tamT,marcas,tamM,clientes,tamC);
            break;
        case 5:mostrarNotebooksPorMarcaYTipo(vec,tam,tipos,tamT,marcas,tamM,clientes,tamC);
            break;
        case 6:
            printf("Confirma Salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if (confirma=='s')
            {
                seguirI='n';
            }
            break;


        }
        system("pause");
    }
    while(seguirI=='s');


}
void informarNotebooksDeUnTipo(eNotebook vec[],int tam,eTipo tipos[],int tamT,eMarca marcas[],int tamM,eCliente clientes[],int tamC)
{
    int flag=0;
    int id;


    id=menuTipos(tipos,tamT);

    system("cls");


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0&&vec[i].idTipo==id)
        {
           mostrarNotebook(vec[i],marcas,tamM,tipos,tamT,clientes,tamC);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("Error no hay notebooks que mostrar\n");
    }
}
void informarNotebooksDeUnaMarca(eNotebook vec[],int tam,eTipo tipos[],int tamT,eMarca marcas[],int tamM,eCliente clientes[],int tamC)
{
    int flag=0;
    int id;


    id=menuMarcas(marcas,tamM);

    system("cls");


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0&&vec[i].idMarca==id)
        {
           mostrarNotebook(vec[i],marcas,tamM,tipos,tamT,clientes,tamC);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("Error no hay notebooks que mostrar\n");
    }
}
void notebookMasBarata(eNotebook vec[],int tam,eTipo tipos[],int tamT,eMarca marcas[],int tamM,eCliente clientes[],int tamC)
{
    float masBarata;
    int flag=0;


    for(int i=0;i<tam;i++)
    {
        if((vec[i].precio>masBarata||flag==0)&&flag==0)
        {
            masBarata=vec[i].precio;
            flag=1;
        }
    }
    printf("El precio mas Barato :$%.2f",masBarata);

    for(int i=0;i<tam;i++)
    {
        if(vec[i].precio==masBarata)
        {
            printf("--%s\n",vec[i].modelo);
        }
    }
}
void mostrarNotebooksPorMarca(eNotebook vec[],int tam,eTipo tipos[],int tamT,eMarca marcas[],int tamM,eCliente clientes[],int tamC)
{
      for(int i=0; i<tamM; i++)
    {
        printf("***%s***\n",marcas[i].descripcion);
        for(int j=0; j<tam; j++)
        {
            if(vec[j].isEmpty==0&&vec[j].idMarca==i+1)
            {
                mostrarNotebook(vec[j],marcas,tamM,tipos,tamT,clientes,tamC);
            }
        }
    }

}
void mostrarNotebooksPorMarcaYTipo(eNotebook vec[],int tam,eTipo tipos[],int tamT,eMarca marcas[],int tamM,eCliente clientes[],int tamC)
{
    int idMarca;
    int idTipo;
    idMarca=menuMarcas(marcas,tamM);
    idTipo=menuTipos(tipos,tamT);

    for(int i=0;i<tam;i++)
    {
        if(vec[i].idMarca==idMarca&&vec[i].idTipo==idTipo)
        {
            mostrarNotebook(vec[i],marcas,tamM,tipos,tamT,clientes,tamC);
        }
    }
}
