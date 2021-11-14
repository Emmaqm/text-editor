#ifndef LINEA_H
#define LINEA_H

#include "palabra.h"

#define MAX_CANT_PALABRAS_X_LINEA 3

struct str_linea{
    Palabra palabras;
    str_linea * sig;
};

typedef struct str_linea * Texto;


// Post-condición: Crea un texto vacío.
Texto crearTexto();

// Pre-condición: El texto no puede estar vacío.
// Post-condición: Imprime el texto, invirtiendo la posición de las palabras.
Texto InvertirTexto(Texto a);

// Post-condición: Devuelve la cantidad de líneas en el texto.
int largoTexto(Texto a);


// Post-condición: Crea una nueva linea al final del texto.
void insertarLinea(Texto &a);

/* Pre-condición: La posición de línea pasada por parámetro debe ser mayor o igual a 1, y debe ser menor
    o igual a la cantidad de líneas del texto +1. */   
/* Post-condición: Inserta una línea vacía en el texto, si la línea se fuera a insertar entre medio de 2 líneas,
    mueve las demás líneas un lugar hacia adelante.*/
int insertarLineaEnPosicion(Texto &a, Posicion posicion);

/* Pre-condición: El texto debe contener al menos 1 línea vacía. La posición de la línea pasada por parámetro
    debe ser menor o igual a la cantidad de líneas totales del texto, y debe ser mayor o igual a 1. */
/* Post-condición: Borra la línea en la posición indicada por parámetro y mueve todas las líneas que eventualmente se 
    encuentren en posiciones posteriores a la eliminada, una posición más hacia adelante. */
int borrarLinea(Texto &a, Posicion posicion);

// Post-condición: Borra todo el contenido del texto.
void borrarTodo(Texto &a);

// Pre-condición: El texto debe contener al menos 1 línea con 1 palabra. La palabra debe existir en el texto.
/* Post-condición: Borra la palabra pasada por parámetro, desplazando hacia adelante en cada línea 
    las palabras que eventualmente se encuentren en posiciones posteriores a la eliminada. */
void borrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);

// Post-condición: Imprime el texto pasado por parámetro. Cuando el texto no tiene líneas muestra el mensaje "Texto vacío" 
void imprimirTexto(Texto a);


// Post-condición: Imprime el texto pasado por parámetro, sin imprimir aquellas palabras que existan en el diccionario.
//      En caso de estar vacío el texto, se imprime "Texto vacío".
void imprimirTextoIncorrecto(Texto a, Diccionario d);

/* Pre-condición: Debe haber líneas vacías en el texto y/o dentro de las líneas escritas debe haber una de las mismas
    que contenga menos de la cantidad máxima de palabras por línea establecida.*/
/* Post-condición: Cuando la línea no llega a la cantidad de palabras máximas y, si hay palabras en la siguiente línea, mueve las
    palabras siguientes una posición hacia atrás hasta alcanzar el máximo de palabras , eliminando las líneas que queden 
    completamente vacías y moviendo las líneas restantes una posición hacia atrás */
void comprimirTexto(Texto &a);


#endif // LINEA_H
