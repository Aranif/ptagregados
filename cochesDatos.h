/*
**      Fichero:  cochesDatos.h
**        Autor:  Departamento de Ingeniería Telemática
**        Fecha:  01/01/2020
**
**  Descripción:  Declaración de estructuras y funciones
**                de manejo de estas estructuras.
*/

#ifndef COCHES_DATOS_H
#define COCHES_DATOS_H

/* Includes del sistema */ 


/* Includes de la aplicación */


/* Definición de constantes */

/*   Tamaños de las tablas de caracteres */
#define TAM_PROVINCIA 2
#define TAM_LETRA_TIPO_1 2
#define TAM_LETRA_TIPO_2 3
#define TAM_DESCRIPCION 21

/*   Valores booleanos */
#define VERDADERO 1
#define FALSO 0

/*   Constantes de formato para printf */
#define FORM_SAL_DESCRIPCION "%-20s - "
#define FORM_SAL_TIPO1 "%s-%04u-%s"
#define FORM_SAL_TIPO2 "%04u-%3s"
#define FORM_SAL_PETICION_DATOS "Introduzca TIPO MATRÍCULA DESCRIPCIÓN: "

/*   Constantes de formato para scanf */
#define FORM_ENT_TIPO1 "%2s %4u %2s"
#define FORM_ENT_TIPO2 "%4u %3s"


/* Tipos definidos por el usuario */

//Estructura de una matrícula de tipo 1: PP-XXXX-LL
//Provincia y letra pueden tener una o más letras.
//El número será de 4 cifras siempre.
typedef struct {
  char provincia[TAM_PROVINCIA+1];
  unsigned int numero;
  char letra[TAM_LETRA_TIPO_1+1];
} mat1;

//Estructura de una matrícula de tipo 2: XXXX-LLL
//Siempre 4 cifras numéricas y 3 letras
typedef struct {
  unsigned int numero;
  char letra[TAM_LETRA_TIPO_2+1];
} mat2;

//Enumerado para identificar el tipo de matrícula del coche
enum tipoMat { tipo1=1, tipo2 };

//Unión con ambos tipos de matrícula
typedef union {
  mat1 tipo1;
  mat2 tipo2;
} mat;

//Estructura con los datos del coche
typedef struct {
  char descripcion[TAM_DESCRIPCION]; 
  enum tipoMat tipoMatricula; //Discriminador. Según su valor, se usa
                              // un campo u otro de la unión mat
  mat matricula;
} datosCoche;




/* Declaración de funciones exportadas. */

/*
**   Parámetros:  datosCoche coche Datos del coche
**     Devuelve:  void
**
**  Descripción:  Imprime datos por salida estándar
*/
void imprimeDatosCoche( datosCoche coche );

/*
**   Parámetros:  datosCoche * pDatosCoche Dirección donde
**                   almacenar los datos leídos
**     Devuelve:  int Valor booleano indicando si hay error
**
**  Descripción:  lee datos de un coche de la entrada estándar
*/
int leeDatosCoche(datosCoche *pDatosCoche);


#endif
