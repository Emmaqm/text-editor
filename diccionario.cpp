#include "diccionario.h"
#include <stdlib.h>
#include <strings.h>



//pre: n/a
//post: devuelve un arbol vacio.
Diccionario crearVacio(){
    return NULL;
}
// O(1)

//pre: x no pertenece a a
//post: agrega x al arbol a
void agregar(Diccionario &a, Cadena c){
    if (a == NULL){
        a = new struct str_nodo;
        a->palabra = c;
        a->hizq = NULL;
        a->hder = NULL;
    }else if (strcasecmp(a->palabra, c) > 0){
        agregar(a->hizq, c);
    }else if (strcasecmp(a->palabra, c) < 0){
        agregar(a->hder, c);
    }
}
// O(log2 n) en un arbol balanceado

// Predicado

//pre: n/a
//post: devuelve true si el arbol a es vac�o, false en caso contrario.
bool isEmpty(Diccionario a){
    if (a == NULL){
        return true;
    }else{
        return false;
    }
}
// O(1)

//pre: el arbol a no puede ser vacio
//post: devuelve el valor que contiene el primer elemento del arbol a
Cadena raiz(Diccionario a){
    return a->palabra;
}
// O(1)

//pre: el arbol a no puede ser vacio
//post: devuelve el subarbol izquierdo del arbol a
Diccionario subDirIzq(Diccionario a){
    return a->hizq;
}
// O(1)

//pre: el arbol a no puede ser vacio
//post: devuelve el subarbol derecho del arbol a
Diccionario subDirDer(Diccionario a){
    return a->hder;
}
// O(1)

//pre: el arbol a no es vacio
//post: devuelve true si a es hoja.
bool esHoja(Diccionario a){
    return isEmpty(subDirIzq(a)) && isEmpty(subDirDer(a));
}
// O(1)

//pre: a no es vacio.
//post: devuelve el menor entero del arbol a.
Cadena minimo(Diccionario a){
    if (isEmpty(subDirIzq(a))){
        return raiz(a);
    }else{
        return minimo(subDirIzq(a));
    }
}
// O(n) si est� desbalanceado
// O(log2 n) si es un arbol balanceado

//pre: n/a
//post: borra x del arbol a
void borrar(Diccionario &a, Cadena c){
    if (!isEmpty(a)){
        if (strcasecmp(raiz(a), c) == 0){
            if (isEmpty(subDirIzq(a)) && isEmpty(subDirDer(a))){
                // el nodo es una hoja
                delete a;
                a = crearVacio();
            }else if (!isEmpty(subDirDer(a))){
                // el nodo tiene subarbol derecho
                Cadena min_der = minimo(subDirDer(a));
                a->palabra = min_der;
                borrar(a->hder, min_der);
            }else{
                // el nodo no tiene subarbol derecho, pero s� tiene subarbol izquierdo.
                Diccionario aux = a->hizq;
                delete a;
                a = aux;
            }
        }else if (strcasecmp(raiz(a), c) < 0){
            borrar(a->hder, c);
        }else if (strcasecmp(raiz(a), c) > 0){
            borrar(a->hizq, c);
        }
    }
}


void imprimirDiccionario(Diccionario a){
    if (!isEmpty(a)){
        imprimirDiccionario(subDirIzq(a));
        printf("%s ", raiz(a));
        imprimirDiccionario(subDirDer(a));
    }
}

bool existeEnDiccionario(Diccionario a, Cadena c)
{
    if (!isEmpty(a)){
        if (strcasecmp(raiz(a), c) == 0){
            return true;
        }else if (strcasecmp(raiz(a), c) < 0){
            existeEnDiccionario(subDirDer(a), c);
        }else if (strcasecmp(raiz(a), c) > 0){
            existeEnDiccionario(subDirIzq(a), c);
        }
    }else{
        return false;
    }
}

