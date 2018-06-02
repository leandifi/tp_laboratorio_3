#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    EMovie* peliculas;
    FILE* binario;
    int i,contador=0;
    if((binario=fopen("peliculas.dat","r+b"))==NULL)
    {
        if((binario=fopen("peliculas.dat","w+b"))==NULL)
        {
            printf("Hubo un error procesando el archivo. Reinicie.");
            exit(1);
        }
        fwrite(&contador,sizeof(int),1,binario);
        rewind(binario);
    }
    fread(&contador,sizeof(int),1,binario);
    char seguir='s';
    int opcion;
        if((peliculas=(EMovie*)malloc(sizeof(EMovie)*(contador+5)))==NULL)
        {
            printf("Error ubicando memoria");
            exit(1);
        }

    fread(peliculas,sizeof(EMovie),contador,binario);

    while(seguir=='s')
    {
        opcion=0;
        if(contador==0)
        {
            printf("///EL BINARIO SE CARGARA UNA VEZ QUE SE SALGA DEL PROGRAMA, contador:%d///\n",contador);
            printf("1- Agregar pelicula\n");
            printf("5- Salir\nSu opcion: ");

            scanf("%d",&opcion);
            fflush(stdin);
            while(opcion!=1 && opcion!=5)
            {
                printf("Error, reingrese: ");
                scanf("%d",&opcion);
                fflush(stdin);
            }
        }
        else
        {
            printf("///EL BINARIO SE CARGARA UNA VEZ QUE SE SALGA DEL PROGRAMA, contador:%d///\n",contador);
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Salir\nSu opcion: ");

            scanf("%d",&opcion);
            fflush(stdin);
            while(opcion<1 && opcion>5)
            {
                printf("Error, reingrese: ");
                scanf("%d",&opcion);
                fflush(stdin);
            }
        }
        switch(opcion)
        {
        case 1:
            if(agregarPelicula(&peliculas,contador)==1)
            {
                contador++;
                rewind(binario);
                if(fwrite(&contador,sizeof(int),1,binario)!=1)
                {
                    printf("Error al escribir el archivo.");
                }
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(borrarPelicula(peliculas,contador)==1)
            {
                contador--;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(modificarPelicula(peliculas,contador)==0)
            {
                printf("No se pudo encontrar la película.");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            generarPagina(peliculas,contador);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            for(i=0; i<contador || contador==0; i++)
            {
                rewind(binario);
                if(fwrite(&contador,sizeof(int),1,binario)!=1)
                {
                    printf("Error al escribir en el archivo\n");
                    return 0;
                }
                fseek(binario,0L,SEEK_END);
                if(fwrite(peliculas+i,sizeof(EMovie),contador,binario)!=contador)
                {
                    printf("Error al escribir en el archivo\n");
                    return 0;
                }
                if(contador==0)
                {
                    break;
                }
            }
            fclose(binario);
            free(peliculas);
            break;
        }
    }

    return 0;
}
