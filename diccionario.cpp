#include "diccionario.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>


Diccionario crearDiccionario(){
    return NULL;
}


bool isEmpty(Diccionario a){
    if (a == NULL){
        return true;
    }else{
        return false;
    }
}

Cadena raiz(Diccionario a){
    return a->palabra;
}


Diccionario subDirIzq(Diccionario a){
    return a->hizq;
}


Diccionario subDirDer(Diccionario a){
    return a->hder;
}


bool esHoja(Diccionario a){
    return isEmpty(subDirIzq(a)) && isEmpty(subDirDer(a));
}


Cadena minimo(Diccionario a){
    if (isEmpty(subDirIzq(a))){
        return raiz(a);
    }else{
        return minimo(subDirIzq(a));
    }
}

int ingresarPalabraDiccionario(Diccionario &a, Cadena c){
    if(existeEnDiccionario(a, c) == true)
    {
        return 0;
    }

    Cadena c2;
    c2 = (Cadena) malloc(sizeof(*c));
    strncpy(c2, c, (strlen(c) + 1));
    
    if (a == NULL){
        a = new struct str_nodo;
        a->palabra = c2;
        a->hizq = NULL;
        a->hder = NULL;
        return 1;
    }else if (strcasecmp(a->palabra, c2) > 0){
        ingresarPalabraDiccionario(a->hizq, c2);
        return 1;
    }else if (strcasecmp(a->palabra, c2) < 0){
        ingresarPalabraDiccionario(a->hder, c2);
        return 1;
    }
}


int borrarPalabraDiccionario(Diccionario &a, Cadena palabraABorrar){
    if (!isEmpty(a)){
        if (strcasecmp(raiz(a), palabraABorrar) == 0){
            if (isEmpty(subDirIzq(a)) && isEmpty(subDirDer(a))){
                delete a;
                a = crearDiccionario();
            }else if (!isEmpty(subDirDer(a))){
                Cadena min_der = minimo(subDirDer(a));
                a->palabra = min_der;
                borrarPalabraDiccionario(a->hder, min_der);
            }else{
                Diccionario aux = a->hizq;
                delete a;
                a = aux;
            }
        }else if (strcasecmp(raiz(a), palabraABorrar) < 0){
            borrarPalabraDiccionario(a->hder, palabraABorrar);
        }else if (strcasecmp(raiz(a), palabraABorrar) > 0){
            borrarPalabraDiccionario(a->hizq, palabraABorrar);
        }
    }
    return 0;
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

