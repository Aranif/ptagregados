/*
**      Fichero:  pruebaListaSimple.c
**        Autor:  Departamento de Ingeniería Telemática (trajano.us.es)
**        Fecha:  2016/01/08
**
**  Descripción:  Pruebas de una lista simplemente enlazada 
*/

/* Includes del sistema */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Includes de la aplicación */
#include "listaSimple.h"

/* Constantes */
#define TAMLISTA    10


int main()
{
  NODO * paux    = NULL;  
  NODO * primero = NULL;
  
  /*
   Bucle para la creación de una lista de TAMLISTA elementos 
  for ( i = 0; i < TAMLISTA; i++)
    {
      paux = creaNodo(i*2);
      if (NULL != paux)
        enlaza(paux, &primero);
    }
  */

  
  char *cad = (char*)malloc(MAXLONG*sizeof(char));
  if(cad != NULL){
    /* If you write END it 
    ** does not make the loop
    */
    while(strcmp(cad, "END") != 0){
      
      printf("Introduzca un valor: "); 
      scanf(" %20s", cad);
      
      while(getchar() != '\n');
      
      if(strcmp(cad, "END") != 0){
	paux = creaNodo(cad);
	enlaza(paux, &primero);
      }
    }//END WHILE
    
  }
  
  

  /* Recorre la lista imprimiendo el contenido */
  imprimeLista(primero);

  /* Búsqueda de un elemento */
  printf("\nIntroduzca valor a buscar: ");
  scanf("%20s", cad);
  getchar();       /* Delete '\n' */
  paux = buscaElemento(primero, cad);
  if (NULL != paux)
    printf("valor %s encontrado\n", cad);
  else
    printf("valor %s no encontrado\n", cad);
  free(cad);

  /* Borro el segundo elemento de la lista */
  printf("\nVoy a borrar el segundo elemento de la lista\n");
  printf("Pulse INTRO para continuar");
  getchar();
  /* If the list is empty, 
  ** we will get a "core" 
  ** when trying to access 
  ** the address that does not exist. 
  ** That is why we have to 
  ** check before entering the function
  */
  if(primero != NULL && primero->sig != NULL){
  borra(&(primero->sig));
  }
  
  printf("Así queda la lista\n");
  imprimeLista(primero);

  /* Borro el primero */
  printf("\nVoy a borrar el primer elemento de la lista\n");
  printf("Pulse INTRO para continuar");
  getchar();
  
  if(primero != NULL){
    borra (&primero);
  }
  
  printf("Así queda la lista\n");
  imprimeLista(primero);

  /* Recorre la lista para borrarla */
  if(primero != NULL){
  borraLista(&primero);
  }
  
  printf("\nBorro la lista completa:\n");
  printf("Pulse INTRO para continuar");
  getchar();
  imprimeLista(primero);

  return 0;
}
