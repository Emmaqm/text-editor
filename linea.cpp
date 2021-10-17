#include "oblig.h"
#include <stdlib.h>
#include <stdio.h>

Texto crearTexto()
{
    return NULL;
}

Texto InvertirTexto(Texto a)
{
    Texto aux = crearTexto();
    Texto aux2 = aux;

    while (a != NULL)
    {
        aux = new str_linea;
        aux->palabras = a->palabras;
        aux->sig = aux2;
        aux2 = aux;

        a = a->sig;
    }

    return aux2;
}

int largoTexto(Texto a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + largoTexto(a->sig);
    }
}

void insertarLinea(Texto &a)
{
    Texto aux = new str_linea;
    aux->palabras = crearPalabrasVacia();
    aux->sig = a;
    a = aux;
}

int insertarLineaEnPosicion(Texto &a, Posicion posicion)
{
    Texto aux = a;
    Texto ant = a;

    int largo = largoTexto(a);
    int count = largo;

    if (posicion > (largo + 1) || posicion == 0)
    {
        return 0;
    }
    else if (posicion == (largo + 1))
    {
        insertarLinea(a);
    }
    else
    {
        while (aux != NULL)
        {
            if (posicion == count)
            {
                Texto x = new str_linea;
                x->palabras = crearPalabrasVacia();
                x->sig = aux->sig;
                aux->sig = x;

                return 1;
            }

            ant = aux;
            aux = aux->sig;
            count--;
        }
    }
}

int borrarLinea(Texto &a, Posicion posicion)
{
    Texto aux = a;
    Texto ant = a;

    int largo = largoTexto(a);
    int count = largo;

    if (posicion > largo || posicion < 1)
    {
        return 0;
    }
    else
    {
        while (aux != NULL)
        {
            if (posicion == count)
            {
                if (ant == aux)
                {
                    Palabra auxP = aux->palabras;

                    while (aux->palabras != NULL)
                    {
                        aux->palabras = aux->palabras->sig;
                        delete auxP;
                        auxP = aux->palabras;
                    }

                    a = a->sig;
                    delete aux;

                    return 1;
                }
                else
                {
                    Palabra auxP = aux->palabras;

                    while (aux->palabras != NULL)
                    {
                        aux->palabras = aux->palabras->sig;
                        delete auxP;
                        auxP = aux->palabras;
                    }

                    ant->sig = aux->sig;
                    delete aux;

                    return 1;
                }
            }

            ant = aux;
            aux = aux->sig;
            count--;
        }
    }
}

void borrarTodo(Texto &a)
{
    int count = largoTexto(a);

    while (count != 0)
    {
        int response = borrarLinea(a, count);
        count--;
    }
}

void borrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar)
{
    int count = largoTexto(a);

    while (count != 0)
    {
        borrarOcurrenciasPalabraEnLinea(a, count, palabraABorrar);
        count--;
    }
}

void imprimirTexto(Texto a)
{
    int largo = largoTexto(a);
    int count = 0;

    while (count <= largo)
    {
        int x = ImprimirLinea(a, count);
        count++;
        printf("\n");
    }
    printf("\n");
}

void comprimirTexto(Texto &a)
{
    Texto aux = InvertirTexto(a);
    a = crearTexto();

    int countLI = 0; // Linea a Insertar
    int countPI = 0; // Palabra a Insertar

    while (aux != NULL)
    {

        Palabra pal = aux->palabras;
        while (pal != NULL)
        {
            if (countLI == 0)
            {
                insertarLinea(a);
                countLI++;
            }
            countPI++;

            if (countPI - 1 == MAX_CANT_PALABRAS_X_LINEA)
            {
                insertarLinea(a);
                countLI++;
                countPI = 1;
            }

            insertarPalabra(a, countLI, countPI, pal->palabra);
            pal = pal->sig;
        }
        aux = aux->sig;
    }
}