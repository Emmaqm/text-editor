#ifndef OBLIG_H
#define OBLIG_H
#include "linea.h"


typedef char* Cadena;

enum _retorno{
    OK, ERROR, NO_IMPLEMENTADA
};

typedef enum _retorno TipoRetorno;


// Post-condición: Crea una nueva linea al final del texto.
TipoRetorno InsertarLinea(Texto &a);

/* Pre-condición: La posición de línea pasada por parámetro debe ser mayor o igual a 1, y debe ser menor
    o igual a la cantidad de líneas del texto +1. */   
/* Post-condición: Inserta una línea vacía en el texto, si la línea se fuera a insertar entre medio de 2 líneas,
    mueve las demás líneas un lugar hacia adelante.*/
TipoRetorno InsertarLineaEnPosicion(Texto &a, Posicion posicion);

/* Pre-condición: El texto debe contener al menos 1 línea vacía. La posición de la línea pasada por parámetro
    debe ser menor o igual a la cantidad de líneas totales del texto, y debe ser mayor o igual a 1. */
/* Post-condición: Borra la línea en la posición indicada por parámetro y mueve todas las líneas que eventualmente se 
    encuentren en posiciones posteriores a la eliminada, una posición más hacia adelante. */
TipoRetorno BorrarLinea(Texto &a, Posicion posicion);

// Post-condición: Borra todo el contenido del texto.
TipoRetorno BorrarTodo(Texto &a);

// Pre-condición: El texto debe contener al menos 1 línea con 1 palabra. La palabra debe existir en el texto.
/* Post-condición: Borra la palabra pasada por parámetro, desplazando hacia adelante en cada línea 
    las palabras que eventualmente se encuentren en posiciones posteriores a la eliminada. */
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);

// Post-condición: Imprime el texto pasado por parámetro. Cuando el texto no tiene líneas muestra el mensaje "Texto vacío" 
TipoRetorno ImprimirTexto(Texto a);

/* Pre-condición: Debe haber líneas vacías en el texto y/o dentro de las líneas escritas debe haber una de las mismas
    que contenga menos de la cantidad máxima de palabras por línea establecida.*/
/* Post-condición: Cuando la línea no llega a la cantidad de palabras máximas y, si hay palabras en la siguiente línea, mueve las
    palabras siguientes una posición hacia atrás hasta alcanzar el máximo de palabras , eliminando las líneas que queden 
    completamente vacías y moviendo las líneas restantes una posición hacia atrás */
TipoRetorno ComprimirTexto(Texto &a);

/* Pre-condición: El texto debe tener al menos 1 línea. La posición de línea pasada por parámentro tiene que ser mayor o igual a 1 y
    menor o igual a la cantidad de líneas totales en el texto. La cantidad de palabras en línea debe ser menor al máximo de palabras en línea.
    La posición de palabra pasada por parámetro, debe ser menor o igual a la cantidad de palabras que haya en la línea +1 */
/* Post-condición: Ingresa una palabra en el texto, la posicion en línea y la posicion de la palabra en la línea pasados por parametro.
    Desplazando las demas palabras en el caso de que haya palabras posteriores en la misma línea a la posicion palabra a insertar,
    y desplazando palabras hacia la siguiente línea si alcanza el maximo de palabras por línea. */
TipoRetorno InsertarPalabra(Texto &a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabra);

/* Pre-condición: El texto debe tener al menos 1 línea. La posición de línea pasada por parámentro tiene que ser mayor o igual a 1 y
    menor o igual a la cantidad de líneas en el texto. La posición de palabra pasada por parámetro debe ser menor o igual
    a la cantidad de palabras que haya en la línea*/  
/* Post-condición: Borra la palabra en la línea y posición de la palabra pasadas por parámetro. Si hay palabras en las siguientes lineas,
    las mueve una posición atrás. */
TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);

/* Pre-condición: El texto debe tener al menos 1 línea. La posición de línea pasada por paramentro tiene que ser mayor o igual a 1 y
    menor o igual a la cantidad de líneas en el texto. La palabra debe existir en la línea. */
/* Post-condición: Borra todas las ocurrencias de la palabra pasada por parámetro, en la línea pasada por parámetro.
    Cada vez que borra una palabra, mueve todas las palabras posteriores una posición hacia atras. 
    Si llega al máximo de palabras por línea, desplaza la palabra hacia la línea siguiente.*/
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);

/* Pre-condición: El texto debe contener almenos una línea aunque ésta esté vacía. La posición de línea pasado por parámentro
    debe ser menor o igual a la cantidad de líneas en el texo. */
// Post-condición: Imprime la línea pasada por parámentro junto con sus palabras. En caso de no tener palabras, muestra la linea vacia.
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea);

// Pre-condición: La palabra pasada por parámetro no debe de existir dentro del Diccionario.
// Post-condición: Agrega la palabra ingresada por parámetro al Diccionario.
TipoRetorno IngresarPalabraDiccionario(Diccionario &a, Cadena c);

// Pre-condición: El diccionario no puede estar vacío y la palabra debe existir dentro del diccionario. 
// Post-condición: Borra del Dicccionario la palabra ingresada por parámetro.
TipoRetorno BorrarPalabraDiccionario(Diccionario &a, Cadena palabraABorrar);

// Pos-condición: Imprime todas las palabras del dicionario, en orden alfabético.
TipoRetorno ImprimirDiccionario(Diccionario d);


// Post-condición: Imprime el texto pasado por parámetro, sin imprimir aquellas palabras que existan en el diccionario.
//      En caso de estar vacío el texto, se imprime "Texto vacío".
TipoRetorno ImprimirTextoIncorrecto(Texto a, Diccionario d);


void comprobacion(TipoRetorno tr);


#endif // OBLIG_H
