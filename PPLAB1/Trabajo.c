#include "Trabajo.h"
#include "Validaciones.h"
#include "Servicios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>



void inicializarTrabajo(eTrabajo vec[], int tamS)
{
    for(int i=0; i<tamS; i++)
    {
        vec[i].isEmpty =1;
    }
}
int buscarLibreTrabajo(eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int altaTrabajo(int proximoId,eTrabajo vec[], int tam,eNotebook notebooks[], int tamN, eServicio servicios[], int tamS)
{
    int todoOk=0;
    int indice= buscarLibreTrabajo(vec,tam);
    int id;
    int existeIdNote;
    eTrabajo auxiliar;

    system("cls");

    printf("\n***** Alta Trabajo *****\n");
    if(indice == -1)
    {
        printf("\nSistema Completo\n");
    }
    else
    {

        auxiliar.id=proximoId;
        mostrarNotebooksParaTrabajo(notebooks,tamN);
        utn_getEntero(&id,3,"\nIngrese el id de notebook: ","\n Id ingresado no es valido!! \n\n",100,999);
        existeIdNote=buscarNotebook(id,notebooks,tamN);

        if(existeIdNote == -1)
        {
            printf("\n\n ESE ID NO EXISTE.");

        }
        else
        {
            auxiliar.idNotebook=id;

            mostrarServicios(servicios,tamS);
            utn_getEntero(&auxiliar.idServicio,3,"\nElija una opcion: ","\n  Opcion ingresada no es valida! \n\n",20000,20003);

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxiliar.fecha.dia, &auxiliar.fecha.mes, &auxiliar.fecha.anio);


            auxiliar.isEmpty=0;
            vec[indice]=auxiliar;
            todoOk=1;
        }
    }
    return todoOk;
}
void listarTrabajo(eTrabajo trabajo, eNotebook notebooks[], int tamN,eServicio servicios[], int tamS)
{
    char nombreNotebook[20];
    char nombreServicio[20];

    cargarDescripcionNotebook(nombreNotebook,trabajo.idNotebook,notebooks, tamN);
    cargarDescripcionServicio(nombreServicio,trabajo.idServicio,servicios,tamS);
    printf("  %d     %-10s      %-15s     %02d/%02d/%d    \n",trabajo.id,nombreNotebook,nombreServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);

}
void listarTrabajos(eTrabajo vec[], int tam,eNotebook notebooks[],int tamN, eServicio servicios[], int tamS)
{
    int flag=0;
    system("cls");


    system("cls");
    printf("\n              ***** Listado de Trabajos *****\n");
    printf("   Id       Notebook          Servicio            Fecha     \n");

    for(int i=0; i<tamN; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            listarTrabajo(vec[i],notebooks,tamN,servicios,tamS);
            flag=1;

        }
    }
    if(flag==0)
    {
        printf("\n   No hay trabajo que mostrar\n\n");
    }
}


