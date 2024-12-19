/*
**      Fichero:  cochesDatos.c
**        Autor:  
**        Fecha:  
**
**  Descripcin:  Definic de funciones
**                de manejo de estructuras de datos de coche.
*/

/* Includes del sistema */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Includes de la aplicac*/
#include "cochesDatos.h"


/* Declaracin de funciones locales. */

/*
**   Parmetros:  Datos de coche
**                
**     Devuelve:  void
**
**  Descripcin:  recibe una structura con
**                datos completos de los coches.
**                
*/
void imprimeDatosCoche( datosCoche coche );
int leeDatosCoche(datosCoche *pDatosCoche);





/* Definiciones de funciones  */
/************************************************************/
void imprimeDatosCoche( datosCoche coche ){
    printf(FORM_SAL_DESCRIPCION, coche.descripcion);
    
	if (coche.tipoMatricula == tipo1) {
    printf(FORM_SAL_TIPO1, coche.matricula.tipo1.provincia, coche.matricula.tipo1.numero, coche.matricula.tipo1.letra);
  } else {
    printf(FORM_SAL_TIPO2, coche.matricula.tipo2.numero, coche.matricula.tipo2.letra);
  }
}


int leeDatosCoche(datosCoche *pDatosCoche)
{
    // Pide al usuario que introduzca los datos
    printf(FORM_SAL_PETICION_DATOS);
    int error = FALSO;// siempre sera falso(0) hasta lo contrario
    // Lee el tipo de matrcula
    int tipoMat;
    
     if (scanf("%d", &tipoMat) != 1) {
        // Si la entrada del tipo de matrcula no es vlida
        error = VERDADERO;
        // Limpiar stdin
        while (getchar() != '\n');
        return error;
    }
    //como pDatosCoche es un puntero 
    // lo pongo con -> si no fuese puntero
    // seria pDato.tipoMatricula
    pDatosCoche->tipoMatricula  = tipoMat; //(enum tipoMat) para hacer el cast de 1 o 2
                                                        // a tipo1 o tipo2

    // Lee los datos segn el tipo de matrcula
    switch (pDatosCoche->tipoMatricula)
    {
        //lee y a la vez comprueba
    case tipo1:
        if(fscanf(stdin, FORM_ENT_TIPO1, pDatosCoche->matricula.tipo1.provincia, &pDatosCoche->matricula.tipo1.numero, pDatosCoche->matricula.tipo1.letra) != 3)
        	error = VERDADERO;
        
        break;
    case tipo2:
        if(fscanf(stdin, FORM_ENT_TIPO2, &pDatosCoche->matricula.tipo2.numero, pDatosCoche->matricula.tipo2.letra) != 2)
        	error = VERDADERO;
        
        break;
    default:
        // Tipo de matrula no vo
        error = VERDADERO;
        break;
    }

     // Limpiar stdin si hay error en lectura de matrcula
    if (error) {
        while (getchar() != '\n');
        return error;
    }

//lee descripcion
    if (scanf("%20s", pDatosCoche->descripcion) != 1) {
        error = VERDADERO;
        while (getchar() != '\n');
    }
    
    while (getchar() != '\n');//por si quedan caracteres por leerf
    
    return error; // No hay error
}


/************************************************************/

