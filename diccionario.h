#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <stdio.h>
#include "palabra.h"
    
struct str_nodo {
    Cadena palabra;
    struct str_nodo * hizq;
    struct str_nodo * hder;
};
typedef struct str_nodo * Diccionario;

// Constructora

//pre: n/a
//post: devuelve un arbol vacio.
Diccionario crearVacio();

//pre: x no pertenece a a
//post: agrega x al arbol a
void agregar(Diccionario &a, Cadena c);

// Predicado

//pre: n/a
//post: devuelve true si el arbol a es vac�o, false en caso contrario.
bool isEmpty(Diccionario a);

//pre: el arbol a no puede ser vacio
//post: devuelve el valor que contiene el primer elemento del arbol a
Cadena raiz(Diccionario a);

//pre: el arbol a no puede ser vacio
//post: devuelve el subarbol izquierdo del arbol a
Diccionario subArbIzq(Diccionario a);

//pre: el arbol a no puede ser vacio
//post: devuelve el subarbol derecho del arbol a
Diccionario subArbDer(Diccionario a);

//pre: el arbol a no es vacio
//post: devuelve true si a es hoja.
bool esHoja(Diccionario a);

//pre: n/a
//post: borra x del arbol a
void borrar(Diccionario &a, Cadena c);


void imprimirDiccionario(Diccionario a);

#endif
