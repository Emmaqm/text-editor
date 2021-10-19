#include "oblig.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Palabra crearPalabrasVacia()
{
    return NULL;
}

int largoLinea(Texto a, Posicion posicion)
{
    int largo = largoTexto(a);

    if (a == NULL)
    {
        return 0;
    }
    else if (posicion < 1 || posicion > largo)
    {
        return 0;
    }
    else
    {
        int count = largo;
        int countP = 0;

        while (a != NULL)
        {
            if (count == posicion)
            {
                Palabra aux = a->palabras;

                while (aux != NULL)
                {
                    countP++;
                    aux = aux->sig;
                }
            }

            count--;
            a = a->sig;
        }

        return countP;
    }
}

int insertarPalabra(Texto &a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabra)
{
    Texto aux = a;
    Texto ant = a;


    int countL = largoTexto(a);
    int largoL = countL;
    int countP = 1;
    int largoP = largoLinea(a, posicionLinea);
    bool inserted = false;

    Cadena c;
    c = (Cadena) malloc(25);
    strncpy(c, palabra, (strlen(palabra) + 1));

    if ((posicionLinea <= countL) && (posicionLinea >= 1) && (posicionPalabra >= 1) && (posicionPalabra <= largoP + 1))
    {

        while (aux != NULL) // Recorrer lineas
        {
            if (countL == posicionLinea)
            {

                Palabra auxP = aux->palabras;
                Palabra antP = auxP;

                if (auxP == NULL)
                {
                    auxP = new str_pal;
                    auxP->palabra = c;
                    //strcpy(auxP->palabra, palabra);
                    auxP->sig = NULL;
                    aux->palabras = auxP;

                    inserted = true;
                }
                else
                {
                    while (auxP != NULL) // Recorrer palabras
                    {
                        if (countP == posicionPalabra && inserted == false)
                        {
                            if (antP == auxP)
                            {
                                antP = new str_pal;
                                antP->palabra = c;
                                //strcpy(antP->palabra, palabra);
                                antP->sig = auxP;
                                aux->palabras = antP;

                                inserted = true;
                            }
                            else
                            {
                                antP->sig = new str_pal;
                                antP->sig->palabra = c;
                                //strcpy(antP->sig->palabra, palabra);
                                antP->sig->sig = auxP;

                                inserted = true;
                            }
                        }
                        else if (auxP->sig == NULL && inserted == false)
                        {
                            auxP->sig = new str_pal;
                            auxP->sig->palabra = c;
                            //strcpy(auxP->sig->palabra, palabra);
                            auxP->sig->sig = NULL;

                            inserted = true;
                        }

                        if (inserted == true && auxP->sig == NULL && (largoP + 1) > MAX_CANT_PALABRAS_X_LINEA)
                        {

                            if (aux == a)
                            { // Si esta en la ultima linea (Primer nodo)
                                insertarLinea(a);
                            }

                            insertarPalabra(a, posicionLinea + 1, 1, auxP->palabra);
                            antP->sig = NULL;
                            delete auxP;
                            auxP = antP;
                        }

                        antP = auxP;
                        auxP = auxP->sig;
                        countP++;
                    }
                }
            }

            aux = aux->sig;
            countL--;
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int borrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra)
{
    Texto aux = a;
    Texto ant = a;

    int countL = largoTexto(a);
    int cantidadL = countL;
    int countP = 1;
    int cantidadP = largoLinea(a, posicionLinea);

    if ((posicionLinea <= countL) && (posicionLinea >= 1) && (posicionPalabra >= 1) && (posicionPalabra <= cantidadP))
    { // Si la posicion de la linea y de la palabra existen:

        while (aux != NULL) //Recorro el texto linea por linea
        {
            if (countL == posicionLinea) //Si el contador llego a la posicion en linea
            {
                //Creo una linea auxiliar y anterior
                Palabra auxP = aux->palabras; //AuxL apunta al primer nodo de aux (la linea original en la posicionLinea)
                Palabra antP = auxP;
                // hasta aca OK

                while (auxP != NULL) // Recorro la linea palabra por palabraa
                {
                    if (countP == posicionPalabra) // Si el contador llegó a la posicionPalabra
                    {
                        if (antP == auxP)
                        { //Si antp y auxp estan con el mismo nodo

                            auxP = auxP->sig;
                            delete antP;
                            aux->palabras = auxP;
                            return 1; //Done
                        }
                        else
                        {
                            antP->sig = auxP->sig;
                            delete auxP;
                            return 1;
                        }
                    }
                    antP = auxP;
                    auxP = auxP->sig;
                    countP++;
                }
            }

            aux = aux->sig; //Avanzo de linea
            countL--;
        }
    }
    else
    {
        return 0;
    }
}

int borrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar)
{
    Texto aux = a;

    int largoL = largoTexto(a);
    int countL = largoL;

    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if ((posicionLinea <= countL) && (posicionLinea >= 1))
        {
            while (aux != NULL)
            {
                if (countL == posicionLinea)
                {
                    Palabra auxP = aux->palabras;
                    Palabra antP = auxP;

                    while (auxP != NULL)
                    {
                        if (antP == auxP)
                        {
                            if (strcmp(auxP->palabra, palabraABorrar) == 0)
                            {
                                antP = auxP->sig;
                                delete auxP;
                                aux->palabras = antP;
                                auxP = antP;
                            }
                            else
                            {
                                auxP = auxP->sig;
                            }
                        }
                        else
                        {
                            if (strcmp(auxP->palabra, palabraABorrar) == 0)
                            {
                                antP->sig = auxP->sig;
                                delete auxP;
                                auxP = antP->sig;
                            }
                            else
                            {
                                antP = auxP;
                                auxP = auxP->sig;
                            }
                        }
                    }

                    return 1;
                }
                aux = aux->sig;
                countL--;
            }
        }
        else
        {
            return 0;
        }
    }
}

int imprimirLinea(Texto a, Posicion posicionLinea)
{
    Texto aux = InvertirTexto(a);
    int countT = largoTexto(a);
    int countL = 1;

    if ((posicionLinea <= countT) && (posicionLinea >= 1))
    { 

        while (aux != NULL) 
        {
            if (countL == posicionLinea)
            {
                printf("%d: ", countL);
                while (aux->palabras != NULL)
                {                    
                    printf("%s ", aux->palabras->palabra);
                    aux->palabras = aux->palabras->sig;
                }

                return 1;
            }

            countL++;
            aux = aux->sig;
        }
    }else{
        return 0;
    }
}
