#include "costo.h"
#include "lectura_costos.h"
#include <iostream>


/* 
    Esta funcion se encarga de devolver el costo de insercion de un caracter.
    Esto lo realiza mediante la lectura de un archivo de texto que contiene los costos de insercion de cada caracter.
    La lectra esta a cargo de la funcion leerVectorCostos, que recibe como parametro el nombre del archivo de texto.
    El programa sabe perfectamente el costo de cada caracter, ya que estos se encuentran en orden alfabetico.
    Lo calcula mediante la resta de los caracteres 'b' y 'a' en la tabla ASCII, y de esta manera se obtiene el indice del caracter en el vector de costos.

    Recibe:
        - b: char

    Devuelve:
        - int: costo de insercion del caracter b
*/
int costo_ins(char b) {
    static vector<int> costos_ins = leerVectorCostos("inputs/cost_insert.txt");
    return costos_ins[b - 'a'];
}
