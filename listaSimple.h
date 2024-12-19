/*
**      Fichero:  listaSimple.h
**        Autor:  Departamento de Ingeniería Telemática (trajano.us.es)
**        Fecha:  2016/01/08
**
**  Descripción:  Funciones para el manejo de una lista simplemente enlazada 
*/

#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#define MAXLONG 20

/* Tipos definidos por el usuario */
typedef struct nodo {
  char           *cad;
  struct nodo * sig;
} NODO;

/* Declaración de funciones exportadas */

/*
**   Parámetros:  int i  - Valor del campo de info
**     Devuelve:  NODO * - Nuevo nodo creado (NULL en caso de error)
**
**  Descripción:  Crea un nuevo nodo
*/
NODO *creaNodo (char * cadena);

/*
**   Parámetros:  NODO * p   - Nodo a enlazar
**                NODO ** pp - Dirección del puntero al primero o del 
**                  puntero sig del nodo anterior (puntero que apuntará
**                  al nuevo nodo)
**   Devuelve:    void
**
**  Descripción:  Enlaza un nuevo nodo
*/
void  enlaza(NODO * p, NODO ** pp);

/*
**   Parámetros:  NODO ** pp - Dirección del puntero al primero o del 
**                  puntero sig del nodo anterior (puntero con la 
**                  dirección del nodo a borrar)
**   Devuelve:    void
**
**  Descripción:  Borra un nodo
*/
void  borra (NODO ** pp);

/*
**   Parámetros:  NODO * p - Dirección del primer nodo que se va a imprimir
**   Devuelve:    void
**
**  Descripción:  Imprime por salida estándar los nodos de una lista
*/
void  imprimeLista (NODO * p);

/*
**   Parámetros:  NODO ** pp - Dirección del puntero al primero o del 
**                  puntero sig del nodo anterior (puntero con la 
**                  dirección del primer nodo a borrar)
**   Devuelve:    void
**
**  Descripción:  Borra todos los nodos de una lista.
*/
void  borraLista (NODO ** pp);

/*
**   Parámetros:  NODO * prim  - Nodo primero desde el que buscar
**                int    valor - Valor del campo info buscado
**     Devuelve:  NODO * - Dirección del nodo o NULL si no existe.
**
**  Descripción:  Busca un nodo con un valor en el campo info determinado
*/
NODO *buscaElemento ( );

#endif
