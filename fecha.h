#ifndef FECHA_H
#define FECHA_H

struct fecha {
  int dia;
  int mes;
  int anio;
};

#define YMD 1
#define DMY 2
#define MDY 3

#define AMBAS_BISIESTO   "Ambas fechas son en bisiesto\n"
#define PRIMERA_BISIESTO "La primera fecha es en bisiesto\n"
#define SEGUNDA_BISIESTO "La segunda fecha es en bisiesto\n"
#define NINGUNA_BISIESTO "Ninguna de las dos fechas es en bisiesto\n"

void leeFecha( int formato, struct fecha *pfecha);
int compruebaFecha( struct fecha f);
int comparaFecha( struct fecha f1, struct fecha f2 );
void escribeFecha( struct fecha f , int formato);
int bisiesto( struct fecha f );

#endif
