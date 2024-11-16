#include "costo.h"
#include "lectura_costos.h"
#include <iostream>


/* 
    Esta funcion se encarga de devolver el costo de eliminacion de un caracter.
    Esto lo realiza mediante la lectura de un archivo de texto que contiene los costos de eliminacion de cada caracter.
    La lectra esta a cargo de la funcion leerVectorCostos, que recibe como parametro el nombre del archivo de texto.
    El programa sabe perfectamente el costo de cada caracter, ya que estos se encuentran en orden alfabetico.
    Lo calcula mediante la resta de los caracteres 'a' y 'a' en la tabla ASCII, y de esta manera se obtiene el indice del caracter en el vector de costos.

    Recibe:
        - a: char

    Devuelve:
        - int: costo de eliminacion del caracter a

*/
int costo_del(char a) {
    static vector<int> costos_del = leerVectorCostos("inputs/cost_delete.txt"); 
    return costos_del[a - 'a'];
}
