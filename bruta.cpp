#include <iostream>
#include <algorithm>
#include <climits> 
#include "costo.h"

using namespace std;

/*
    Funcion que calcula la distancia de levenshtein entre dos strings de manera recursiva.
    Esta funcion fue programada con la tecnica de fuerza bruta, por lo que su complejidad es exponencial.
    Se estudian los 4 posibles casos de operaciones a realizar en cada llamada recursiva.

    

    Recibe:
        - s1: string
        - s2: string
        - i: int
        - j: int

    Devuelve:
        - int: distancia de levenshtein entre s1 y s2


*/
int levenshtein_bruteforce(const string &s1, const string &s2, int i, int j) {
    if (i == s1.size()) {
        return (s2.size() - j) * costo_ins(s2[j]); 
    }
    if (j == s2.size()) {
        return (s1.size() - i) * costo_del(s1[i]);  
    }


    int minimo = INT_MAX;

    minimo = min(minimo, costo_sub(s1[i], s2[j]) + levenshtein_bruteforce(s1, s2, i + 1, j + 1));
    minimo = min(minimo, costo_ins(s2[j]) + levenshtein_bruteforce(s1, s2, i, j + 1));
    minimo = min(minimo, costo_del(s1[i]) + levenshtein_bruteforce(s1, s2, i + 1, j));
    if (i + 1 < s1.size() && j + 1 < s2.size() && s1[i] == s2[j + 1] && s1[i + 1] == s2[j]) {
        minimo = min(minimo, costo_trans(s1[i], s1[i + 1]) + levenshtein_bruteforce(s1, s2, i + 2, j + 2));
    }

    return minimo;
}


