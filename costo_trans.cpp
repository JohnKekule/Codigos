#include "costo.h"
#include "lectura_costos.h"
#include <iostream>



/*
    Esta funcion se encarga de devolver el costo de transposicion de dos caracteres.
    Esto lo realiza mediante la lectura de un archivo de texto que contiene los costos de transposicion de cada caracter.
    La lectra esta a cargo de la funcion leerMatrizCostos, que recibe como parametro el nombre del archivo de texto.
    El programa sabe perfectamente el costo de cada caracter, ya que estos se encuentran en orden alfabetico.
    Lo calcula mediante la resta de los caracteres, 'a' y 'a', 'b' y 'a', en la tabla ASCII, y de esta manera se obtiene el indice del caracter en la matriz de costos.

    Recibe:
        - a: char
        - b: char

    Devuelve:
        - int: costo de transposicion de a por b
*/
int costo_trans(char a, char b) {
    static vector<vector<int>> costos_trans = leerMatrizCostos("inputs/cost_transpose.txt");
    return costos_trans[a - 'a'][b - 'a'];
}
