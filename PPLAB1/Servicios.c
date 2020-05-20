#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "Servicios.h"

void inicializarServicios(eServicio vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}
int buscarLibreServicio(eServicio vec[],int tam)
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
int buscarServicio(int id,eServicio vec[],int tam)
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
int altaServicio(int id,eServicio vec[],int tam)
{
    int sePudo=0;
    int indice=buscarLibreServicio(vec,tam);

    eServicio auxServicio;


    auxServicio.id=id;
    printf("Ingrese nombre del servicio: ");
    fflush(stdin);
    scanf("%s",auxServicio.descripcion);

    printf("Ingrese precio del servicio: ");
    scanf("%f",&auxServicio.precio);

    auxServicio.isEmpty=0;

    if(indice!=-1)
    {
        vec[indice]=auxServicio;
        sePudo=1;
    }

    return sePudo;
}
void bajaServicio(eServicio vec[],int tam)
{
    int id;
    char confirma;

    system("cls");

    id = menuServicios(vec,tam);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            system("cls");
            mostrarServicio(vec[i]);

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
void cargarDescripcionServicio(char descripcion[],int id,eServicio vec[],int tamS)
{
    for(int i=0; i<tamS; i++)
    {
        if(vec[i].id==id)
        {
            strcpy(descripcion,vec[i].descripcion);
        }
    }

}
int cargarPrecioDeServicio(float*  mostrarPrecio,int id, eServicio vec[], int tamS )
{
   int todoOk = 0;

   for(int i=0;i<tamS;i++)
   {
       if(vec[i].id == id)
       {
          *  mostrarPrecio = vec[i].precio;
           todoOk=1;
       }
   }
   return todoOk;
}
void mostrarServicio(eServicio x)
{
    printf("%d.-%s $%f\n",x.id,x.descripcion,x.precio);
}
void mostrarServicios(eServicio vec[],int tam)
{
    system("cls");
    printf("ID.-Servicio Precio\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarServicio(vec[i]);
        }
    }
}
int menuServicios(eServicio vec[],int tam)
{
    int opcion=0;
    system("cls");

    printf("***SERVICIOS***\n\n");
    mostrarServicios(vec,tam);

    printf("Elija el id del Servicio:");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
