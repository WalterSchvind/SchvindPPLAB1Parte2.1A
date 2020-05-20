#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "Marcas.h"

void inicializarMarcas(eMarca vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}
int buscarLibreMarca(eMarca vec[],int tam)
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
int buscarMarca(int id,eMarca vec[],int tam)
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
int altaMarca(int id,eMarca vec[],int tam)
{
    int sePudo=0;
    int indice=buscarLibreMarca(vec,tam);

    eMarca auxMarca;


    auxMarca.id=id;
    printf("Ingrese marca: ");
    scanf("%s",auxMarca.descripcion);
    auxMarca.isEmpty=0;

    if(indice!=-1)
    {
        vec[indice]=auxMarca;
        sePudo=1;
    }

    return sePudo;
}
void bajaMarca(eMarca vec[],int tam)
{
    int id;
    char confirma;

    system("cls");

    id = menuMarcas(vec,tam);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            system("cls");
            mostrarMarca(vec[i]);

            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {
                vec[i].isEmpty=1;
                printf("La notebook se dio de baja\n");
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
void cargarDescripcionMarca(char descripcion[],int id,eMarca vec[],int tam)
{


    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            strcpy(descripcion,vec[i].descripcion);
        }
    }


}
void mostrarMarca(eMarca x)
{
    printf("%d.-%s\n",x.id,x.descripcion);

}
void mostrarMarcas(eMarca marcas[],int tam)
{
    system("cls");
    printf("***MARCAS***\n\n");
    printf("ID.-Marca\n");
    for(int i=0;i<tam;i++)
    {
        if(marcas[i].isEmpty==0)
        {
            mostrarMarca(marcas[i]);
        }
    }
}
int menuMarcas(eMarca vec[],int tam)
{
    int opcion=0;
    system("cls");

    mostrarMarcas(vec,tam);
    printf("Elija el id de la marca:");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
