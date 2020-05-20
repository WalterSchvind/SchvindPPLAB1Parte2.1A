#include <stdio.h>
#include <stdlib.h>
#include "Notebooks.h"
#include "Servicios.h"
#include "Trabajo.h"
#include "informes.h"


#define TAMN 23
#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMTR 20
#define TAMC 20
int menu();
int main()
{
    int proximoIdN=100;
    int proximoIdT=40000;

    int flagN=0;
    int flagT=0;

    char continuar='s';
    char confirma;


    eNotebook listaN[TAMN];
    eMarca listaM[TAMM]= {{1000,"Compaq",0},{1001,"Asus",0},{1002, "Acer",0},{1003,"HP",0}};
    eTipo listaT[TAMT]= {{5000,"Gamer",0},{5001,"Disenio",0},{5002, "Ultrabook",0},{5003,"Normalita",0}};
    eServicio listaS[TAMS]= {{20000,"Bateria",250,0},{20001,"Antivirus",300,0},{20002,"Actualizacion",400,0},{20003,"Fuente",600,0}};
    eTrabajo listaTr[TAMTR];
    eCliente listaC[TAMC];

    inicializarNotebooks(listaN,TAMN);
    inicializarTrabajo(listaTr,TAMTR);
    inicializarClientes(listaC,TAMC);
    hardcodearNotebooks(listaN,20);
    harcodearClientes(listaC,TAMC);

    proximoIdN+=20;
    flagN=1;
  do
    {
        system("cls");
        switch(menu())
        {
        case 1:

            if(altaNotebook(proximoIdN,listaN,TAMN,listaM,TAMM,listaT,TAMT,listaC,TAMC)==1)
            {
                proximoIdN++;
                flagN=1;
            }
            else
            {
                printf("No se pudo cargar notebook");
            }

            break;

        case 2:
            if(flagN==1)
            {
                modificarNotebook(listaN,TAMN,listaM,TAMM,listaT,TAMT,listaC,TAMC);
            }
            else
            {
                printf("Debe ingresar una notebook antes");
            }

            break;

        case 3:
            if(flagN==1)
            {
                bajaNotebook(listaN,TAMN,listaM,TAMM,listaT,TAMT,listaC,TAMC);
            }
            else
            {
                printf("Debe ingresar una notebook antes");
            }

            break;

        case 4:
            if(flagN==1)
            {
                mostrarNotebooks(listaN,TAMN,listaM,TAMM,listaT,TAMT,listaC,TAMC);
            }
            else
            {
                printf("Debe ingresar una notebook antes");
            }

            break;

        case 5:
            mostrarMarcas(listaM,TAMM);
            break;
        case 6:
            mostrarTipos(listaT,TAMT);
            break;
        case 7:
            mostrarServicios(listaS,TAMS);
            break;
        case 8:
            if(flagN==1)
            {


                if(altaTrabajo(proximoIdT,listaTr,TAMTR,listaN,TAMN,listaS,TAMS)==1)
                {
                    flagT=1;
                    proximoIdT++;
                }
                else
                {
                    printf("No se pudo ingresar trabajo");
                }
            }
            else
            {
                printf("Debe ingresar una notebook antes");
            }
            break;
        case 9:
            if(flagT==1)
            {
                listarTrabajos(listaTr,TAMTR,listaN,TAMN,listaS,TAMS);
            }
            else
            {
                printf("\nDebe ingresar un trabajo antes\n");
            }

            break;
        case 10:
            informar(listaN,TAMN,listaT,TAMT,listaM,TAMM,listaC,TAMC);

        case 11:
            system("cls");
            printf("\n***** Salir *****\n\n ");
            printf("Confirma salida? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                continuar = 'n';
            }
            break;
        default:
            printf("No es una opcion valida.\n");
        }
        system("pause");


    }
    while(continuar == 's');
    return 0;
}
int menu()
{
    int opcion;

    system("cls");


    printf("*****Gestion*****\n\n");
    printf("1.-Alta NoteBook\n");
    printf("2.-Modificar Notebook\n");
    printf("3.-Baja Notebook\n");
    printf("4.-Listar Notebook\n");
    printf("5.-Listar Marcas\n");
    printf("6.-Listar Tipos\n");
    printf("7.-Listar Servicios\n");
    printf("8.-Alta Trabajo\n");
    printf("9.-Listar Trabajo\n");
    printf("10.-Informes\n");
    printf("11.-Salir\n");

    printf("Elija una opcion: " );
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
