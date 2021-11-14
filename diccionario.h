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

// Post-condición: Crea un diccionario vacío
Diccionario crearDiccionario();

// Pre-condición: La palabra ingresada por parámetro no debe de existir dentro del Diccionario.
// Post-condición: Agrega la palabra ingresada por parámetro al Diccionario.
int ingresarPalabraDiccionario(Diccionario &a, Cadena c);

// Predicado

// Post-condición: Si el diccionario está vacío, devuelve true. De lo contrario, devuelve false.
bool isEmpty(Diccionario a);

// Pre-condición: El diccionario no puede estar vacío.
// Post-condición: Devuelve el valor que contiene el primer elemento del arbol.
Cadena raiz(Diccionario a);

// Pre-condición: El diccionario no puede estar vacío.
// Post-condición: Devuelve el valor que contiene el subArbol izquierdo del Diccionario.
Diccionario subDirIzq(Diccionario a);

// Pre-condición: El diccionario no puede estar vacío.
// Post-condición: Devuelve el valor que contiene el subArbol derecho del Diccionario.
Diccionario subDirDer(Diccionario a);

// Pre-condición: El diccionario no puede estar vacío.
// Post-condición: Si es Hoja (una palabra), devuelve true. De lo contrario, devuelve false.
bool esHoja(Diccionario a);

// Pre-condición: El diccionario no puede estar vacío y la palabra debe existir dentro del diccionario. 
// Post-condición: Borra del Dicccionario, la palabra ingresada por parámetro.
int borrarPalabraDiccionario(Diccionario &a, Cadena palabraABorrar);

// Pos-condición: Imprime todas las palabras del dicionario, en orden alfabético.
void imprimirDiccionario(Diccionario a);

// Pre-condición: El diccionario no puede estar vacío.
// Post-condición: Si la palabra ingresada por parámetro existe en el texto, devuelve true. De lo contrario, devuelve false.
bool existeEnDiccionario(Diccionario a, Cadena c);

#endif
