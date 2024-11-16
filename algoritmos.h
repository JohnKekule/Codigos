#ifndef ALGORITMOS_H
#define ALGORITMOS_H


#include <string>  // Asegúrate de incluir esta línea
#include <iostream>
#include <vector>


using namespace std;


/*
    Este es el header file de algoritmos.cpp
    Contiene las declaraciones de las funciones que se encargan de calcular la distancia de levenshtein entre dos strings.
    Se programo para mantener la programacion modular, ya que cada algoritmo tiene su propia implementacion y se pueden llamar en otros programas.
    De esta manera, se puede cambiar el algoritmo de levenshtein sin tener que modificar el codigo de otros programas.
    Estas funciones son las que se llaman en los programas de levenshtein, para obtener la distancia de levenshtein entre dos strings.
*/
int levenshtein(const string &s1, const string &s2);
int levenshtein_bruteforce(const string &s1, const string &s2, int i, int j);


#endif

