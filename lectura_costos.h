#ifndef LECTURA_COSTOS_H
#define LECTURA_COSTOS_H

#include <vector>
#include <string>

using namespace std;


/*
    Este es el header file de lectura_costos.cpp
    Contiene las declaraciones de las funciones que se encargan de leer los costos de las operaciones de levenshtein.
    Se programo para mantener la programacion modular, ya que cada operacion tiene su propio costo y se leen de archivos de texto diferentes.
    De esta manera, se puede cambiar el costo de cada operacion sin tener que modificar el codigo de levenshtein.
    Estas funciones son las que se llaman en los programas de levenshtein, para obtener el costo de cada operacion.
*/
vector<vector<int>> leerMatrizCostos(const string &nombreArchivo);

vector<int> leerVectorCostos(const string &nombreArchivo);

#endif
