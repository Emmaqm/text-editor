#ifndef LINEA_H
#define LINEA_H

#include "palabra.h"

#define MAX_CANT_PALABRAS_X_LINEA 3

struct str_linea{
    Palabra palabras;
    str_linea * sig;
};

typedef struct str_linea * Texto;

Texto crearTexto();

Texto InvertirTexto(Texto a);

int largoTexto(Texto a);

void insertarLinea(Texto &a);

int insertarLineaEnPosicion(Texto &a, Posicion posicion);

int borrarLinea(Texto &a, Posicion posicion);

void borrarTodo(Texto &a);

void borrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);

void imprimirTexto(Texto a);

void comprimirTexto(Texto &a);


#endif // LINEA_H
