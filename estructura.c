/* Arán Iglesias Fernández
** Fichero : estructura.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fecha.h"

#define PARAMNOVA "El parámetro no es válido\n"
#define ERRORFECHA "Formato de fecha incorrecto\n"
#define IG " es igual a "
#define AN " es anterior a "
#define PO " es posterior a "
#define NOBISIESTO "Ninguna de las dos fechas es en bisiesto\n"
#define AMBOSBISIE "Ambas fechas son en bisiesto\n"
#define PRIMERBISI "La primera fecha es en bisiesto\n"
#define SEGUNDBISI "La segunda fecha es en bisiesto\n"
#define BISIESTO 1
#define NOBISIES 0



int main(int argc, char * argv[]){
  int bis = 0;
  int bis1 = 0; 
  
  
  if(argc <  2 )
    printf("El programa necesita un parámetro\n1. YMD\n2. DMY\n3. MDY\n");
  
  else{//empieza el programa
    struct fecha f[2];
    int form = atoi(argv[1]);

    if(form != YMD && form != DMY && form != MDY)
      fprintf(stdout, PARAMNOVA);
    
    else{//empezamos a leer y a comprobar
      
      leeFecha(form, f);
      
      if(compruebaFecha(f[0]) == 0)
	fprintf(stdout, ERRORFECHA);
      
      else{//leemos el segundo
	
	leeFecha(form, f +1);
	
	if(compruebaFecha(f[1]) == 0)
	  fprintf(stdout, ERRORFECHA);
	 
	else{
	  int comp = 0;
	  
	  //-1 si fecha 1 > fecha2 y 1 para lo contrario
	  comp = comparaFecha(f[0], *(f +1));

	  //iguales
	  if(comp == 0){
	    escribeFecha(f[0], form);
	    printf(IG);
	    escribeFecha(f[1], form);
	    printf("\n");
	    
	  }
	  //1 anterior a 2
	  if(comp < 0 ){
	    escribeFecha(f[0], form);
	    printf(AN);
	    escribeFecha(f[1], form);
	    printf("\n");
	  }
	  //1 posterior a 2
	  if(comp > 0 ){
	    escribeFecha(f[0], form);
	    printf(PO);
	    escribeFecha(f[1], form);
	    printf("\n");
	  }
	  
	  //fin de comparar igualdad

	  //Compruebo que son bisiestos
	  bis = bisiesto(f[0]);
	  bis1 = bisiesto(f[1]);

	  if(bis != 1 && bis1 != 1)
	    printf(NOBISIESTO);
	  if(bis == 1 && bis1 == 1)
	    printf(AMBOSBISIE);
	  if(bis == 1 && bis1!= 1)
	    printf(PRIMERBISI);
	  if(bis != 1 && bis1 == 1)
	    printf(SEGUNDBISI);
	  

       
	}//cuarto else, si no hay errores busca igualdad
      }//tercer else, comprueba 1fecha
    }//segundo else 
  }//primer else 

  
   
  return 0;
}
