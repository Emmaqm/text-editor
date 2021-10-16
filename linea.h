#ifndef LINEA_H
#define LINEA_H

#include "palabra.h"

struct str_linea{
    Palabra palabras;
    str_linea * sig;
};

typedef struct str_linea * Texto;

Texto crearTexto();

int largoTexto(Texto a);

void insertarLinea(Texto &a);

void imprimirTexto(Texto a);

void imprimirLinea(Texto a);

Texto InvertirTexto(Texto a);

int insertarLineaEnPosicion(Texto &a, Posicion posicion);

int borrarLinea(Texto &a, Posicion posicion);

void borrarTodo(Texto &a);


#endif // LINEA_H
