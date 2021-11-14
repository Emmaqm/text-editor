#ifndef PALABRA_H
#define PALABRA_H

#include "diccionario.h"

typedef char* Cadena;

struct str_pal{
    Cadena palabra;
    struct str_pal * sig;
};

typedef struct str_pal * Palabra;

typedef struct str_linea * Texto;

typedef unsigned int Posicion;



// Post-condición: Crea una palabra vacía al final de la línea.
Palabra crearPalabrasVacia();


// Post-condición: Devuelve la cantidad de palabras en la línea de la posición pasada por parámetro.
int largoLinea(Texto a, Posicion posicion);

/* Pre-condición: El texto debe tener al menos 1 línea. La posición de línea pasada por parámentro tiene que ser mayor o igual a 1 y
    menor o igual a la cantidad de líneas totales en el texto. La cantidad de palabras en línea debe ser menor al máximo de palabras en línea.
    La posición de palabra pasada por parámetro, debe ser menor o igual a la cantidad de palabras que haya en la línea +1 */
/* Post-condición: Ingresa una palabra en el texto, la posicion en línea y la posicion de la palabra en la línea pasados por parametro.
    Desplazando las demas palabras en el caso de que haya palabras posteriores en la misma línea a la posicion palabra a insertar,
    y desplazando palabras hacia la siguiente línea si alcanza el maximo de palabras por línea. */
int insertarPalabra(Texto &a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabra);

/* Pre-condición: El texto debe tener al menos 1 línea. La posición de línea pasada por parámentro tiene que ser mayor o igual a 1 y
    menor o igual a la cantidad de líneas en el texto. La posición de palabra pasada por parámetro debe ser menor o igual
    a la cantidad de palabras que haya en la línea*/  
/* Post-condición: Borra la palabra en la línea y posición de la palabra pasadas por parámetro. Si hay palabras en las siguientes lineas,
    las mueve una posición atrás. */
int borrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);

/* Pre-condición: El texto debe tener al menos 1 línea. La posición de línea pasada por paramentro tiene que ser mayor o igual a 1 y
    menor o igual a la cantidad de líneas en el texto. La palabra debe existir en la línea. */
/* Post-condición: Borra todas las ocurrencias de la palabra pasada por parámetro, en la línea pasada por parámetro.
    Cada vez que borra una palabra, mueve todas las palabras posteriores una posición hacia atras. 
    Si llega al máximo de palabras por línea, desplaza la palabra hacia la línea siguiente.*/
int borrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);

/* Pre-condición: El texto debe contener almenos una línea aunque ésta esté vacía. La posición de línea pasado por parámentro
    debe ser menor o igual a la cantidad de líneas en el texo. */
// Post-condición: Imprime la línea pasada por parámentro junto con sus palabras. En caso de no tener palabras, muestra la linea vacia.
int imprimirLinea(Texto a, Posicion posicionLinea);


/* Post-condición: Imprime la línea pasada por parámetro junto con su posicion, sin imprimir aquellas palabras
    que existan en el diccionario. En caso de estar vacía, imprimirá solo su posición. */
int imprimirLineaIncorrecta(Texto a, Diccionario d, Posicion posicionLinea);

#endif // PALABRA_H
