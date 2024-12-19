/* Arán Iglesias Fernández
** Fichero : fecha.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fecha.h"

#define NOVALIDO 0
#define VALIDO   1
//Para identificar dias 
enum mes {enero = 1, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre,
    noviembre, diciembre};

//Funciones que se van a usar en estructura.c

void leeFecha( int formato, struct fecha *pfecha){
  int format = formato;
 
  switch(format){
  case YMD: //YMD (yyyy-mm-dd)
    
    printf("Introduzca la fecha en formato aaaa-mm-dd: ");
    scanf(" %4d-%2d-%2d", &pfecha->anio, &pfecha->mes, &pfecha->dia );
    
    while(getchar() != '\n'); //limpia el bufer si se escribe de mas
    
    break; //IMPORTANTE PONERLO
    
  case DMY: //DMY ( dd-mm-yy )
    printf("Introduzca la fecha en formato dd-mm-aaaa: ");
    scanf(" %2d-%2d-%4d", &pfecha->dia, &pfecha->mes, &pfecha->anio);//SCANF devuelve el numero de argumentos convertidos
    while(getchar() != '\n');
    break; 

    case MDY: //MDY ( mm-dd-yy )
    printf("Introduzca la fecha en formato mm/dd/aaaa: ");
    scanf(" %2d/%2d/%4d", &pfecha->mes, &pfecha->dia, &pfecha->anio);
    while(getchar() != '\n');
    break; 
  }
}

int compruebaFecha( struct fecha f){
  int ok = NOVALIDO;
  int b = 0;
  //febrero tiene 28 o 29 dia si es bidsiesto el año
  //un año bisiesto si año%4 = 0
  enum mes m;
  m= f.mes;

  switch(m){
    //meses con dia 31
  case enero:
  case marzo:
  case mayo:
  case julio:
  case septiembre:
  case octubre:
  case diciembre:
    if(f.dia < 31 && f.dia > 0)
      ok = VALIDO; 
    break;
    //meses con dia 30
  case abril:
  case junio:
  case agosto:
  case noviembre:
    if(f.dia < 30 && f.dia >0)
      ok = VALIDO;
    break;
    //si es bisiesto tiene 29 dias
    //nos lo piden hacer después asique
    //se queda normal
  case febrero:
     // si no es bis 0
    b = bisiesto(f);
    if(b == 1){
      if(f.dia <= 29 && f.dia > 0)
	ok = VALIDO;
    }
     else
       if(f.dia <=28 && f.dia > 0)
	 ok = VALIDO; 
	break; 
  }

  
  return ok; 
}

//numero negativo si 1 > 2, 0 si 1 = 2 y positivo si 2 > 1
int comparaFecha( struct fecha f1, struct fecha f2 ){
  int igual = 0;
  //si uno es mayor que otro dará negaivo
  if(f1.anio != f2.anio)
    igual = f1.anio - f2.anio;
  else 
    if(f1.mes != f2.mes)
      igual = f1.mes - f2.mes;
    else
      if(f1.dia != f2.dia )
	igual = f1.dia - f2.dia; 


  return igual; 
}

void escribeFecha( struct fecha f , int formato){
  //sepueden guardar en cadenas con sprintf y te ahorras esto
  switch(formato){
  case YMD:
    printf("%4d-%02d-%02d", f.anio, f.mes, f.dia);
    break;
    
  case DMY:
    printf("%02d-%02d-%4d", f.dia, f.mes, f.anio);
    break;
    
  case MDY:
    printf("%02d/%02d/%4d", f.mes, f.dia, f.anio);
    break; 
    
  }


}

//si es bisiesto devuelve 1
int bisiesto( struct fecha f ){
  int b = 0; 

  if((f.anio%4) == 0 && (f.anio%100) != 0)
    b = 1;
  else
    if((f.anio%100) == 0 && (f.anio%400) != 0)
      b = 0;
    else
      if ((f.anio%100) == 0 && (f.anio%400) == 0)
	b = 1; 
  
  


  return b;
}
