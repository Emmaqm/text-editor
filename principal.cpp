#include "oblig.h"
#include "linea.h"

#include <stdio.h>

int main(){
    Texto t;
    TipoRetorno tr = CrearTexto(t); // un texto vacio
    //-------------------------


    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);

    char a[] = "Hola";
    char b[] = "Como";
    char c[] = "Estas";
    char d[] = "Bien";
    char e[] = "Emma";
    char f[] = "Vos";
    
    //printf("%s", t->palabras->palabra);

    tr = InsertarPalabra(t, 1, 1, a);
    tr = InsertarPalabra(t, 1, 2, b);
    tr = InsertarPalabra(t, 1, 1, a);
    tr = InsertarPalabra(t, 1, 1, a);

    tr = InsertarPalabra(t, 3, 1, f);
    tr = InsertarPalabra(t, 3, 2, f);

    tr = InsertarPalabra(t, 5, 1, f);
    tr = InsertarPalabra(t, 5, 2, c);
    tr = InsertarPalabra(t, 5, 3, f);
    tr = InsertarPalabra(t, 5, 4, e);
    tr = InsertarPalabra(t, 5, 5, f);

    tr = InsertarPalabra(t, 7, 1, d);
    tr = InsertarPalabra(t, 8, 1, f);

    tr = InsertarPalabra(t, 8, 1, e);

    //tr = ComprimirTexto(t);

    tr = ImprimirTexto(t);

    

    return 0;
}
