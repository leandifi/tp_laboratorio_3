#include "funciones.h"
int agregarPelicula(void* moviep,int i)
{
    EMovie** movie;
    movie=moviep;
    if((i+1)%5==0)
    {
        if((*movie=realloc(*movie,sizeof(EMovie)*(i+5)))==NULL)
        {
            printf("Error ubicando memoria");
            return 0;
        }
    }
    printf("Ingrese titulo de la pelicula: ");
    gets((*movie+i)->titulo);
    printf("Ingrese genero: ");
    gets((*movie+i)->genero);
    printf("Ingrese descripcion: ");
    gets((*movie+i)->descripcion);
    printf("Ingrese puntaje (1-10): ");
    scanf("%d",&(*movie+i)->puntaje);
    fflush(stdin);
    while((*movie+i)->puntaje<1 || (*movie+i)->puntaje>10)
    {
        printf("Error, reingrese: ");
        scanf("%d",&(*movie+i)->puntaje);
        fflush(stdin);
    }
    printf("Ingrese duracion: ");
    scanf("%d",&(*movie+i)->duracion);
    fflush(stdin);
    while((*movie+i)->duracion<=0)
    {
        printf("Error, reingrese: ");
        scanf("%d",&(*movie+i)->duracion);
        fflush(stdin);
    }
    printf("Ingrese link de la imagen: ");
    gets((*movie+i)->linkImagen);

    /*fseek(binario,0L,SEEK_END);
    if(fwrite(movie+i,sizeof(EMovie),1,binario)!=1)
    {
        printf("Error al escribir en el archivo\n");
        return 0;
    }*/
    return 1;
}

int borrarPelicula(EMovie* movie,int cant)
{
    int i;
    char opcion[20];
    printf("pelicula: ");
    for(i=0; i<cant; i++)
    {
        printf("\n%s",(movie+i)->titulo);
    }
    printf("\nEscriba el titulo de la pelicula que desea borrar: ");
    gets(opcion);
    fflush(stdin);
    for(i=0; i<cant; i++)
    {
        if(strcmp(opcion,(movie+i)->titulo)==0)
        {
            *(movie+i)=*(movie+cant-1);
            return 1;
        }
    }
    printf("\nNo se pudo encontrar la película.");
    return 0;
}

int modificarPelicula(EMovie* movie, int cant)
{
    int i,dato;
    char opcion[20];
    printf("pelicula: ");
    for(i=0; i<cant; i++)
    {
        printf("\n%s",(movie+i)->titulo);
    }
    printf("\nEscriba el titulo de la pelicula que desea modificar: ");
    gets(opcion);
    for(i=0; i<cant; i++)
    {
        if(strcmp(opcion,(movie+i)->titulo)==0)
        {
            printf("\nModificar (1)Titulo(2)Genero(3)Duracion(4)Descripcion(5)Puntaje(6)Imagen: ");
            scanf("%d",&dato);
            fflush(stdin);
            switch(dato)
            {
            case 1:
                printf("\nIngrese nuevo titulo: ");
                gets((movie+i)->titulo);
                break;
            case 2:
                printf("\nIngrese nuevo genero: ");
                gets((movie+i)->genero);
                break;
            case 3:
                printf("\nIngrese nueva duracion: ");
                scanf("%d",&(movie+i)->duracion);
                fflush(stdin);
                while((movie+i)->duracion<=0)
                {
                    printf("Error, reingrese: ");
                    scanf("%d",&(movie+i)->duracion);
                    fflush(stdin);
                }
                break;
            case 4:
                printf("\nIngrese nueva descripcion: ");
                gets((movie+i)->descripcion);
                break;
            case 5:
                printf("\nIngrese nuevo puntaje: ");
                scanf("%d",&(movie+i)->puntaje);
                fflush(stdin);
                while((movie+i)->puntaje<1 && (movie+i)->puntaje>10)
                {
                    printf("Error, reingrese: ");
                    scanf("%d",&(movie+i)->puntaje);
                    fflush(stdin);
                }
                break;
            case 6:
                printf("\nIngrese nuevo titulo: ");
                gets((movie+i)->linkImagen);
                break;
            }
            return 1;
        }
    }
    return 0;
}

void generarPagina(EMovie* peliculas,int cont)
{
    FILE* html;
    char nombre[25];
    char ruta[50]= {"template/"};
    printf("Ingrese el nombre del archivo: ");
    gets(nombre);
    strcat(nombre,".html");
    strcat(ruta,nombre);
    html=fopen(ruta,"w");
    fprintf(html,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
    int i;
    for(i=0; i<cont; i++)
    {
        fprintf(html,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt='404'></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d</li></ul><p>%s<p></article>",(peliculas+i)->linkImagen,(peliculas+i)->titulo,(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion,(peliculas+i)->descripcion);
    }
    fprintf(html,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
    fclose(html);
}
