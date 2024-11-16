#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <chrono>
#include "algoritmos.h"

using namespace std;
using namespace chrono;


/*
En esta funcion convergen los dos algoritmos de levenshtein, el dinamico y el de fuerza bruta.
Se encarga de calcular la distancia de levenshtein entre dos strings y medir el tiempo que tarda en hacerlo.

Recibe:
    - s1: string
    - s2: string
    - outfile: ofstream

Devuelve:
    - void


El resultado se escribe en un archivo de salida en formato CSV, con los siguientes campos:
    - s1: string
    - s2: string
    - distancia dinamico: int
    - tiempo dinamico: int
    - distancia fuerza bruta: int
    - tiempo fuerza bruta: int
*/
void test_levenshtein(const string &s1, const string &s2, ofstream &outfile) {

    auto start = high_resolution_clock::now();
    int dist_dinamico = levenshtein(s1, s2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);


    outfile << s1 << "," << s2 << "," << dist_dinamico << "," << duration.count();

    start = high_resolution_clock::now();
    int dist_bruteforce = levenshtein_bruteforce(s1, s2, 0, 0);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);


    outfile << "," << dist_bruteforce << "," << duration.count() << endl;
}

void leer_datos(const string& archivo, const string& output_file) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    ofstream outfile(output_file);
    if (!outfile.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return;
    }


    outfile << "S1,S2,Distancia_Dinamico,Tiempo_Dinamico,Distancia_Bruteforce,Tiempo_Bruteforce" << endl;

    string line;

    regex regex_pattern("Caso \\d+: S1 = '([^']*)'\\s+S2 = '([^']*)'");  
    smatch match;

    while (getline(file, line)) {
        if (regex_search(line, match, regex_pattern)) {
            string s1 = match[1].str();
            string s2 = match[2].str();

            cout << "\nProbando con: S1 = '" << s1 << "', S2 = '" << s2 << "'" << endl;
            test_levenshtein(s1, s2, outfile);
        }
    }

    file.close();
    outfile.close();
}

int main() {
    string archivo = "dataset_caracteres_repetidos.txt";  
    string output_file = "Resultados/resultados.csv";  

    leer_datos(archivo, output_file);

    return 0;
}
