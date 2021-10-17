#include "oblig.h"
#include "linea.h"

#include <stdio.h>

int main(){
    Texto t;
    TipoRetorno tr = CrearTexto(t); // un texto vacio

    char a[] = "Hola";
    char b[] = "Como";
    char c[] = "Estas";
    char d[] = "Bien";
    char e[] = "Emma";
    char f[] = "Vos";

    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);

    tr = InsertarPalabra(t, 1, 1, a);
    tr = InsertarPalabra(t, 1, 2, a);
    tr = InsertarPalabra(t, 1, 3, a);

    tr = InsertarPalabra(t, 2, 1, b);

    tr = InsertarPalabra(t, 4, 1, b);
    tr = InsertarPalabra(t, 4, 2, a);
    tr = InsertarPalabra(t, 4, 3, d);

    tr = InsertarPalabra(t, 6, 1, b);
    tr = InsertarPalabra(t, 6, 2, b);
    tr = InsertarPalabra(t, 6, 3, b);


    tr = InsertarPalabra(t, 2, 1, a);


    tr = InsertarPalabra(t, 7, 1, d);
    tr = InsertarPalabra(t, 7, 1, a);

    tr = InsertarPalabra(t, 1, 1, a);
    tr = InsertarPalabra(t, 1, 1, d);

    tr = InsertarPalabra(t, 9, 1, a);
    tr = InsertarPalabra(t, 9, 1, b);
    tr = InsertarPalabra(t, 9, 1, b);
    tr = InsertarPalabra(t, 9, 1, b);
    
    tr = ImprimirTexto(t);

    return 0;
}
