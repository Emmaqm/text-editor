#include "oblig.h"
#include <stdio.h>
/*
int main()
{
    Texto t = crearTexto();
    TipoRetorno tr;
    int opcion = 1;
    char palabra[25];
    Posicion posicionLinea;
    Posicion posicionPalabra;

    tr = InsertarLinea(t);

    while (opcion != 0)
    {
        printf("\n 1) Insertar \n 2) Borrar \n 3) Imprimir \n 4) Comprimir Texto \n 0) Salir \n");
        printf("\n Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        int opcion2 = 1;
        switch (opcion)
        {

        case 1:
            printf("\n 1) Insertar Linea Vacia al final del documento \n 2) Insertar linea en posicion deseada \n 3) Insertar Palabra \n 0) Salir \n" );
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
            printf("\n 1) Borrar palabra \n 2) Borrar linea \n 3) Borrar ocurrencias de palabra en linea \n 4) Borrar ocurrencias de Palabra en Texto \n 5) Borrar todo el texto \n 0) Volver \n");
            printf("\n Seleccione que desea borrar: ");
            scanf("%i", &opcion2);

            switch (opcion2)
            {
            case 1:
                printf("\n ingrese la posicion de la linea: ");
                scanf("%d", &posicionLinea);
                printf("\n ingrese la posicion de la palabra: ");
                scanf("%d", &posicionPalabra);
                tr = BorrarPalabra(t, posicionLinea, posicionPalabra);
                comprobacion(tr);
                break;

            case 2:
                printf("ingrese la linea que quiere borrar: ");
                scanf("%d", &posicionLinea);
                tr = BorrarLinea(t, posicionLinea);
                comprobacion(tr);
                break;

            case 3:
                printf("Ingrese la linea donde se encuentra la palabra a borrar: ");
                scanf("%d", &posicionLinea);
                printf("ingrese la palabra a borrar en la linea: ");
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
            printf("\n 1) Imprimir linea  \n 2) Imprimir texto completo \n 0) Volver \n");
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

        case 0:
            break;

        default:
            printf("Opción no válida");
            break;
        }
    }

    return 0;
}
*/

int main() {
    Diccionario dir = crearVacio();
    Texto t = crearTexto();

    char a1[25] = "aloja";
    char a2[25] = "Baloncesto";
    char a3[25] = "Caduco";
    char a4[25] = "Descremado";
    char a5[25] = "Aloja";

    agregar(dir, a1);

    borrar(dir, a3);

    //imprimirDiccionario(dir);

    InsertarLinea(t);
    InsertarLinea(t);
    InsertarLinea(t);

    char a[30] = "Palabra21";
    char b[30] = "Palabra22";
    char c[30] = "Palabra11";
    char d[30] = "Palabra12";
    char e[30] = "Palabra13";
    char f[30] = "Palabra31";


    InsertarPalabra(t, 2, 1, a);
    InsertarPalabra(t, 2, 2, b);
    InsertarPalabra(t, 1, 1, c);
    InsertarPalabra(t, 1, 2, d);
    InsertarPalabra(t, 1, 3, e);
    InsertarPalabra(t, 3, 1, f);

    ImprimirTexto(t);

    agregar(dir, d);
    agregar(dir, a);
    agregar(dir, b);

    imprimirTextoIncorrecto(t, dir);
}


