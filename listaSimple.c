/*
**      Fichero:  listaSimple.c
**        Autor:  Departamento de Ingeniería Telemática (trajano.us.es)
**        Fecha:  2016/01/08
**
**  Descripción:  Funciones para el manejo de una lista simplemente enlazada 
*/

/* Includes del sistema */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Includes de la aplicación */
#include "listaSimple.h"

/* Definiciones de funciones  */

/*
**   Parámetros:  int i  - Valor del campo de info
**     Devuelve:  NODO * - Nuevo nodo creado (NULL en caso de error)
**
**  Descripción:  Crea un nuevo nodo
*/
NODO *creaNodo (char *cadena)
{
  NODO *p = (NODO *) malloc(sizeof(NODO));
  if (NULL != p)
    {
      /* Tengo que asignar memoria dentro del nodo
      ** tengo que usar strcpy para igualarlas
      ** comprobar que se hace bien la reserva
      */
      /* Valores iniciales de los campos */
      p->cad = (char *)malloc((strlen(cadena)+1) * sizeof(char));
      if(p->cad != NULL){
	strcpy(p->cad, cadena);
      }
      p->sig = NULL;
    }

  return p;
}


/*
**   Parámetros:  NODO * p   - Nodo a enlazar
**                NODO ** pp - Dirección del puntero al primero o del 
**                  puntero sig del nodo anterior (puntero que apuntará
**                  al nuevo nodo)
                                                                                                                             **   Devuelve:    void
**
**  Descripción:  Enlaza un nuevo nodo
*/
void enlaza(NODO *p, NODO **pp)
{
  /* if (NULL != p) */
  /*   { */
  /*     p->sig = *pp; */
  /*     *pp = p; */
  /*   } */
 if (*pp == NULL) {
        *pp = p; /* Si la lista está vacía, el nuevo nodo es el primero */
    } else {
   NODO * paux = *pp; // nodo actual
        while (paux->sig != NULL) {
            paux = paux->sig; /* Recorre hasta el último nodo */
        }
        paux->sig = p; /* Inserta el nodo al final */
    } 
}


/*
**   Parámetros:  NODO ** pp - Dirección del puntero al primero o del 
**                  puntero sig del nodo anterior (puntero con la 
**                  dirección del nodo a borrar)
**   Devuelve:    void
**
**  Descripción:  Borra un nodo
*/
void borra (NODO **pp)
{
  // ESTÁ VACIA LA LISTA
  NODO *paux = *pp;

  if (paux != NULL)
    {
      *pp = paux->sig;
      if(paux->cad != NULL)
	{
	  free(paux->cad);
	}
      free(paux);
      
    }
  
}


/*
**   Parámetros:  NODO * p - Dirección del primer nodo que se va a imprimir
**   Devuelve:    void
**
**  Descripción:  Imprime por salida estándar los nodos de una lista
*/
void imprimeLista (NODO * p)
{
  printf("Info\n");
  while (NULL != p)
    {
      
      printf("%s\n", p->cad);
      p=p->sig;
      
    }
}


/*
**   Parámetros:  NODO ** pp - Dirección del puntero al primero o del 
**                  puntero sig del nodo anterior (puntero con la 
**                  dirección del primer nodo a borrar)
**   Devuelve:    void
**
**  Descripción:  Borra todos los nodos de una lista.
*/
void borraLista (NODO **pp)
{
  NODO *paux = NULL;
 
  while (NULL != *pp)
    {
      paux= *pp;
      *pp = paux->sig;
      free(paux->cad);
      free(paux);
      
    }
}

/*
**   Parámetros:  NODO * prim  - Nodo primero desde el que buscar
**                int    valor - Valor del campo info buscado
**     Devuelve:  NODO * - Dirección del nodo o NULL si no existe.
**
**  Descripción:  Busca un nodo con un valor en el campo info determinado
*/
NODO *buscaElemento (NODO *prim, char *encont)
{
  int encontrado = 0;
  while (NULL != prim && !encontrado)
    {
      if ((strcmp(prim->cad, encont)) == 0)
	encontrado = 1;
      else
	prim = prim->sig;
    }
  return prim;
}
