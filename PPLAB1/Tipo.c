#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "Tipo.h"

void inicializarTipos(eTipo vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}
int buscarLibreTipo(eTipo vec[],int tam)
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
int buscarTipo(int id,eTipo vec[],int tam)
{
    int indice =-1;

    for (int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int altaTipo(int id,eTipo vec[],int tam)
{
    int sePudo=0;
    int indice=buscarLibreTipo(vec,tam);

    eTipo auxTipo;


    auxTipo.id=id;
    printf("Ingrese marca: ");
    scanf("%s",auxTipo.descripcion);
    auxTipo.isEmpty=0;

    if(indice!=-1)
    {
        vec[indice]=auxTipo;
        sePudo=1;
    }

    return sePudo;
}
void bajaTipo(eTipo vec[],int tam)
{
    int id;
    char confirma;

    system("cls");

    id = menuTipos(vec,tam);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            system("cls");
            mostrarTipo(vec[i]);

            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {
                vec[i].isEmpty=1;
                printf("La marca se dio de baja\n");
                break;
            }
            else
            {
                printf("Se cancelo la operacion\n");
                break;
            }
        }
    }
}
void cargarDescripcionTipo(char descripcion[],int id,eTipo vec[],int tam)
{


    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            strcpy(descripcion,vec[i].descripcion);
        }
    }


}
void mostrarTipo(eTipo x)
{
    printf("%d.-%s\n",x.id,x.descripcion);
}
void mostrarTipos(eTipo vec[],int tam)
{
    system("cls");
    printf("***TIPOS***\n\n");
    printf("ID.-Tipo\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarTipo(vec[i]);
        }
    }
}
int menuTipos(eTipo vec[],int tam)
{
    int opcion=0;
    system("cls");


    mostrarTipos(vec,tam);
    printf("Elija el id del Tipo:");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
