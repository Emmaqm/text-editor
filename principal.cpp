#include "oblig.h"
#include <stdio.h>

int main()
{
    TipoRetorno tr;

    Texto t = crearTexto();
    Diccionario d = crearDiccionario();

    int opcion = 1;
    char palabra[100];
    
    Posicion posicionLinea;
    Posicion posicionPalabra;

    while (opcion != 0)
    {
        printf("\n 1) Insertar \n 2) Borrar \n 3) Imprimir \n 4) Comprimir texto \n 5) Diccionario \n 0) Salir \n");
        printf("\n Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        int opcion2 = 1;
        switch (opcion)
        {

        case 1:
            printf("\n 1) Insertar linea vacia al final del documento \n 2) Insertar linea en posicion deseada \n 3) Insertar palabra \n 0) Salir \n");
            printf("\n Seleccione que desea ingresar: ");
            scanf("%d", &opcion2);

            switch (opcion2)
            {
            case 1:
                tr = InsertarLinea(t);
                comprobacion(tr);

                break;
            case 2:
                printf("\n Ingrese donde insertar la nueva linea vacia: ");
                scanf("%d", &posicionLinea);
                tr = InsertarLineaEnPosicion(t, posicionLinea);
                comprobacion(tr);

                break;
            case 3:
                printf("\n Ingrese palabra a ingresar en el texto: ");
                scanf("%s", palabra);
                printf("\n Ingrese linea donde se quiera ingresar la palabra: ");
                scanf("%d", &posicionLinea);
                printf("\n Ingrese posicion de la palabra en la linea: ");
                scanf("%d", &posicionPalabra);

                tr = InsertarPalabra(t, posicionLinea, posicionPalabra, palabra);
                comprobacion(tr);

                break;

            case 0:
                break;

            default:
                printf("Opción no válida");
                break;
            }

            break;

        case 2:
            printf("\n 1) Borrar palabra \n 2) Borrar linea \n 3) Borrar ocurrencias de palabra en linea \n 4) Borrar ocurrencias de palabra en Texto \n 5) Borrar todo el texto \n 0) Volver \n");
            printf("\n Seleccione que desea borrar: ");
            scanf("%i", &opcion2);

            switch (opcion2)
            {
            case 1:
                printf("\n Ingrese la posicion de la linea: ");
                scanf("%d", &posicionLinea);
                printf("\n Ingrese la posicion de la palabra: ");
                scanf("%d", &posicionPalabra);
                tr = BorrarPalabra(t, posicionLinea, posicionPalabra);
                comprobacion(tr);
                break;

            case 2:
                printf("Ingrese la linea que quiere borrar: ");
                scanf("%d", &posicionLinea);
                tr = BorrarLinea(t, posicionLinea);
                comprobacion(tr);
                break;

            case 3:
                printf("Ingrese la linea donde se encuentra la palabra a borrar: ");
                scanf("%d", &posicionLinea);
                printf("Ingrese la palabra a borrar en la linea: ");
                scanf("%s", &palabra);
                tr = BorrarOcurrenciasPalabraEnLinea(t, posicionLinea, palabra);
                comprobacion(tr);
                break;

            case 4:
                printf("ingrese la palabra que desea borrar: ");
                scanf("%s", &palabra);
                tr = BorrarOcurrenciasPalabraEnTexto(t, palabra);
                comprobacion(tr);
                break;

            case 5:
                tr = BorrarTodo(t);
                comprobacion(tr);
                break;

            case 0:
                break;

            default:
                printf("Opción no válida");
            }

            break;

        case 3:
            printf("\n 1) Imprimir linea  \n 2) Imprimir texto completo \n 3) Imprimir texto incorrecto \n 0) Volver \n");
            printf("\n Seleccione que desea imprimir: ");
            scanf("%d", &opcion2);
            switch (opcion2)
            {
            case 1: // caso 1
                printf("\n Ingrese linea a imprimir ");
                scanf("%d", &posicionLinea);
                tr = ImprimirLinea(t, posicionLinea);
                comprobacion(tr);
                break;
            case 2:
                printf("Texto: \n");
                tr = ImprimirTexto(t);
                comprobacion(tr);
                break;
            case 3:
                printf("Texto: \n");
                tr = ImprimirTextoIncorrecto(t, d);
                comprobacion(tr);
                break;
            case 0:
                break;
            default:
                printf("Opción no válida");
            }

            break;

        case 4:
            tr = ComprimirTexto(t);
            comprobacion(tr);
            break;

        case 5:
            printf("\n 1) Insertar palabra en el diccionario \n 2) Borrar palabra en el diccionario \n 3) Imprimir diccionario alfabeticamente \n 0) Salir \n");
            printf("\n Ingrese la opcion deseada: ");
            scanf("%d", &opcion2);
            switch (opcion2)
            {
            case 1:
                printf("\n Ingrese la palabra a insertar: ");
                scanf("%s", &palabra);
                tr = IngresarPalabraDiccionario(d, palabra);
                comprobacion(tr);
                break;

            case 2:
                printf("\n Ingrese la palabra a borrar: ");
                scanf("%s", &palabra);
                tr = BorrarPalabraDiccionario(d, palabra);
                comprobacion(tr);
                break;

            case 3:
                printf("Diccionario: \n");
                tr = ImprimirDiccionario(d);
                comprobacion(tr);
                break;

            case 0:
                tr = ImprimirTextoIncorrecto(t, d);
                comprobacion(tr);
                break;
            default:
                printf("Opción no válida");
                break;
            }
        }
    }

    return 0;
}
