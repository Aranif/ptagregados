/*
**      Fichero:  cochesPrincipal.c
**        Autor:  Departamento de Ingeniería Telemática
**        Fecha:  01/01/2020
**
**  Descripción:  Contiene función principal del programa
*/

/* Includes del sistema */
#include <stdio.h>

/* Includes de la aplicación */
#include "cochesDatos.h"


/* Definición de constantes */
#define NUM_ARG 1
#define ARG_FICHERO 1

/* Tipos definidos por el usuario */
//Opciones del menú
enum operacion { salir, listar, agregar };

/* Declaración de funciones locales. */

/*
**   Parámetros:  char * fichero Nombre del fichero
**     Devuelve:  void
**  Descripción:  Agrega nuevos datos al fichero
*/
static void hacerAgregar(char *fichero);

/*
**   Parámetros:  char * fichero Nombre del fichero
**     Devuelve:  void
**  Descripción:  Lista los datos contenidos en el fichero
*/
static void hacerListar(char *fichero);

/************************************************************/
int main(int argc, char *argv[])
{
  //Al programa se le pasa el nombre del fichero con el que se va a trabajar
  if ( argc-1 != NUM_ARG )
    {
      printf( "Uso: coches fichero\n" );
    }
  else
    {
      int continuar = VERDADERO;
      while (continuar)
        {
          //El usuario selecciona una opción a realizar
          //Cualquier valor incorrecto hace que se termine el programa
          enum operacion op = salir;
          printf("Operación (%d=listar, %d=agregar):\n", (int) listar, (int) agregar );
          scanf( "%d", (int *) &op );
          switch(op)
            {
            case listar:
              hacerListar( argv[ARG_FICHERO] );
              break;
            case agregar:
              hacerAgregar( argv[ARG_FICHERO] );
              break;
            default:
              continuar = FALSO;
            }
        }
    }

  return 0;
}



/* Definiciones de funciones  */

/************************************************************/
void hacerListar(char *fichero)
{
     
  //Intentamos abrir el fichero en modo "r" y leemos.
  FILE *fich = fopen( fichero, "r" );
  if ( NULL == fich )
    printf( "Error al abrir el fichero \"%s\"\n", fichero );
  else
    {
      datosCoche dato;
      //Leemos 1
      while ( fread( &dato, sizeof(datosCoche), (size_t) 1, fich ) == (size_t) 1 )
        {
          //Imprimimos por salida estándar
          imprimeDatosCoche( dato );
          putchar('\n');
        }
      
      //Cerramos
      if ( EOF == fclose( fich ) )
        printf( "Error al cerrar fichero\n" );
    }
}

/************************************************************/
void hacerAgregar(char *fichero)
{
  datosCoche nuevo;
  //Leemos datos de la entrada estándar
  int error = leeDatosCoche( &nuevo );

  //Si los datos son correctos
  if ( error )
    printf("Error en los datos introducidos\n");
  else
    {
      //Intentamos abrir el fichero en modo "a" y escribimos.
      FILE *fich = fopen( fichero, "a" );
      if ( NULL == fich )
        printf( "Error al abrir el fichero \"%s\"\n", fichero );
      else
        {
          //Escribimos 1
          if ( fwrite( &nuevo, sizeof(nuevo), (size_t) 1, fich ) != (size_t) 1 )
            printf( "Error al escribir en el fichero \"%s\"\n", fichero );

          //Cerramos
          if ( EOF == fclose( fich ) )
            printf( "Error al cerrar fichero\n" );
        }
    }
  
}
/************************************************************/
