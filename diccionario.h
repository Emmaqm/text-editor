#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <stdio.h>

typedef char* Cadena;

struct str_nodo {
    Cadena palabra;
    struct str_nodo * hizq;
    struct str_nodo * hder;
};
typedef struct str_nodo * Diccionario;

// Constructora

// Post-condicion: Crea un diccionario vacio
Diccionario crearVacio();

// Pre-condicion: La palabra ingresada por parametro no debe de existir dentro del Diccionario
// Post-condicion: Agrega la palabra ingresada por parametro al Diccionario
void agregar(Diccionario &a, Cadena c);

            // Predicado

// Post-condicion: Si el diccionario está vacio, devuelve true. De lo contrario, devuelve false.
bool isEmpty(Diccionario a);

// Pre-condicion: El diccionario no puede estar vacio.
// Post-condicion: Devuelve el valor que contiene el primer elemento del arbol;
Cadena raiz(Diccionario a);

// Pre-condicion: El diccionario no puede estar vacio.
// Post-condicion: Devuelve el valor que contiene el subArbol izquierdo del Diccionario
Diccionario subDirIzq(Diccionario a);

// Pre-condicion: El diccionario no puede estar vacio.
// Post-condicion: Devuelve el valor que contiene el subArbol derecho del Diccionario
Diccionario subDirDer(Diccionario a);

// Pre-condicion: El diccionario no puede estar vacio.
// Post-condicion: Si es Hoja(una palabra), devuelve true. De lo contrario, devuelve false.
bool esHoja(Diccionario a);


// Post-condicion: Borra del arbo, la palabra ingresada por parametro
void borrar(Diccionario &a, Cadena c);


// Pos-condicion: Imprime todas las palabras del dicionario, en orden alfabetico.
void imprimirDiccionario(Diccionario a);

// Pre-condicion: El diccionario no puede estar vacio.
// Post-condicion: Si la palabra ingresada por parametro, devuelve true. De lo contrario, devuelve false.
bool existeEnDiccionario(Diccionario a, Cadena c);

#endif
