#include "lectura_costos.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;



/*
    Esta es la funcion que se encarga de leer la matriz de costos de un archivo de texto.
    La matriz de costos se utiliza para las operaciones de sustitucion y transposicion.
    La matriz de costos se lee de un archivo de texto que contiene los costos
    de sustitucion y transposicion de cada caracter.
    La matriz de costos es de tamaño 26x26, ya que se consideran los 26 caracteres del alfabeto (ingles) en minusculas.
    La funcion devuelve la matriz de costos leida del archivo de texto.
*/
vector<vector<int>> leerMatrizCostos(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
    }

    vector<vector<int>> matrizCostos(26, vector<int>(26));
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (!(archivo >> matrizCostos[i][j])) {
                throw runtime_error("Formato incorrecto en el archivo de matriz de costos: " + nombreArchivo);
            }
        }
    }

    archivo.close();


    return matrizCostos;
}


/*
    Esta es la funcion que se encarga de leer el vector de costos de un archivo de texto.
    El vector de costos se utiliza para las operaciones de insercion y eliminacion.
    El vector de costos se lee de un archivo de texto que contiene los costos
    de insercion y eliminacion de cada caracter.
    El vector de costos es de tamaño 26, ya que se consideran los 26 caracteres del alfabeto (ingles) en minusculas.
    La funcion devuelve el vector de costos leido del archivo de texto.
*/
vector<int> leerVectorCostos(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
    }

    vector<int> vectorCostos(26);
    for (int i = 0; i < 26; ++i) {
        if (!(archivo >> vectorCostos[i])) {
            throw runtime_error("Formato incorrecto en el archivo de vector de costos: " + nombreArchivo);
        }
    }

    archivo.close();


    return vectorCostos;
}
