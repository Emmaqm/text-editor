#ifndef OBLIG_H
#define OBLIG_H
#include "linea.h"


typedef char* Cadena;

enum _retorno{
    OK, ERROR, NO_IMPLEMENTADA
};

typedef enum _retorno TipoRetorno;

 //postcondicion Crea una linea nueva al final del texto
TipoRetorno InsertarLinea(Texto &a);

/*precondicion La linea pasada por parametro debe ser mayor o igual a 1 y debe ser menor o igual a la cantidad de lineas
del texto +1*/   
/*postcondicion Inserta una linea vacia en el texto, si la linea se fuera a insertar entre medio de 2 lineas mueve
las demas lineas un lugar hacia abajo
*/
TipoRetorno InsertarLineaEnPosicion(Texto &a, Posicion posicion);

/*precondicion El texto deberá contener al menos 1 linea vacia, la posicion de la linea pasada por parametro
debe ser menor o igual a la cantidad de lineas totales del texto y debe ser mayor o igual a 1
*/
/*postcondicion Borra la línea en la posición indicada y mueve todas las líneas que se encuentran a partir de la posición
indicada, una posición más hacia arriba*/
TipoRetorno BorrarLinea(Texto &a, Posicion posicion);

//postcondicion Borra todo el texto 
TipoRetorno BorrarTodo(Texto &a);

//precondicion El texto deberá contener al menos 1 linea con 1 palabra, la palabra debe estar en el texto.
/*postcondicion Borra la palabra que se ha enviado por parametro si existe en el texto, desplazando hacia adelante en cada línea
las palabras que eventualmente se encuentren en posiciones posteriores a la eliminada.
*/
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);

/*postcondicion Imprime el texto que se envia por parametro, cuando el texto no tiene líneas muestra el mensaje
"Texto vacio"*/
TipoRetorno ImprimirTexto(Texto a);

/*precondicion Debe haber lineas vacias en el texto y/o dentro de las lineas escritas debe haber una de las mismas
que contenga menos de la cantidad maxima palabras establecidas.*/
/*postcondicion Cuando la linea no llega a la cantidad de palabras maximas y si hay palabras en la siguiente linea sube todas las palabras que se 
pueda una posicion hacia arriba, eliminando las lineas que queden completamente vacias y subiendo las lineas restantes una posicion hacia arriba*/
TipoRetorno ComprimirTexto(Texto &a);

/*precondicion El texto debe tener al menos 1 linea, la posicion linea pasada por paramentro tiene que ser mayor o igual a 1,
la posicion de la linea debe ser menor o igual a la cantidad de lineas totales en el texto, la posicion palabra pasada
por parametro debe ser menor o igual a la cantidad de palabras que haya en la linea*/
/*postcondicion Ingresa una palabra en el texto seleccionando la linea y la posicion de la palabra en la linea, desplazando 
las demas palabras en el caso de que haya palabras posteriores en la misma linea a a la posicion palabra a insertar y desplazando palabras 
hacia la siguiente linea si es que alcanzo el maximo de palabras por linea */
TipoRetorno InsertarPalabra(Texto &a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabra);

/*precondicion El texto debe tener al menos 1 linea, la posicion linea pasada por paramentro tiene que ser mayor o igual a 1,
la posicion de la linea debe ser menor o igual a la cantidad de lineas totales en el texto, la posicion palabra pasada
por parametro debe ser menor o igual a la cantidad de palabras que haya en la linea*/  
/*postcondicion Borra la palabra en la linea y posicion de la palabra pasadas por parametro,si hay palabras en la 
siguiente linea sube todas las palabras que se pueda una posicion hacia arriba*/
TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);

/*precondicion El texto debe tener al menos 1 linea, la posicion linea pasada por paramentro tiene que ser mayor o igual a 1,
la posicion de la linea debe ser menor o igual a la cantidad de lineas totales en el texto, la la palabra debe existir 
en la linea  */
/*postcondicion Borra todas las ocurrencias de la palabra palabraABorrar en la línea indicada, cada vez que borra una 
palabra mueve todas las palabras de la línea que se encuentran a partir de la posición borrada una
posición hacia delante, si llega al maximo de palabras por linea desplaza la palabra hacia la linea de abajo  .*/
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);

/*precondicion El texto ya debera contener almenos una linea vacia, el numero de linea pasado como paramentro
debe ser menor o igual a la cantidad de lineas totales del texo*/
//postcondicion Imprime la linea pasada como paramentro junto con sus palabras si es que tiene alguna sino muestra la linea vacia.
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea);

TipoRetorno IngresarPalabraDiccionario(Diccionario &a, Cadena c);

TipoRetorno BorrarPalabraDiccionario(Diccionario &a, Cadena palabraABorrar);

TipoRetorno ImprimirDiccionario(Diccionario d);

TipoRetorno ImprimirTextoIncorrecto(Texto a, Diccionario d);

void comprobacion(TipoRetorno tr);


#endif // OBLIG_H
