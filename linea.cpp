#include "linea.h"
#include <stdlib.h>
#include <stdio.h>

Texto crearTexto()
{
    return NULL;
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

void imprimirTexto(Texto a)
{
    Texto aux = InvertirTexto(a);

    if (a == NULL)
    {
        printf("Texto vacio.");
    }
    else
    {
        int count = 1;

        while (aux != NULL)
        {

            printf("%d: ", count);
            imprimirLinea(aux);
            printf("\n");

            count++;
            aux = aux->sig;
        }
    }
}

void imprimirLinea(Texto a)
{
    while (a->palabras != NULL)
    {
        printf("%s ", a->palabras->palabra);
        a->palabras = a->palabras->sig;
    }
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
                if (ant == aux)
                {
                    ant = new str_linea;
                    ant->palabras = crearPalabrasVacia();
                    ant->sig = a;
                    a = ant;

                    return 1;
                }
                else
                {
                    Texto x = new str_linea;
                    x->palabras = crearPalabrasVacia();
                    x->sig = aux->sig;

                    aux->sig = x;   

                    return 1;
                }
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
                    a = a->sig;
                    delete aux;

                    return 1;
                }
                else
                {
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
    Texto aux = a;

    while (aux != NULL)
    {
        a = aux->sig;
        delete aux;
        aux = a;
    }
}
