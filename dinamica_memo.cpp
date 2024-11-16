#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "costo.h"

using namespace std;

/*
    Esta funcion se encarga de calcular la distancia de levenshtein entre dos strings.
    Para esto, se crea una matriz de tamaño N1+1 x N2+1, donde N1 y N2 son las longitudes de los strings s1 y s2, respectivamente.
    En la matriz se almacenan los costos de las operaciones de insercion, eliminacion y sustitucion, y se calcula el minimo costo de las operaciones para llegar a la distancia de levenshtein.
    Ademas, se considera el caso de transposicion, donde se intercambian dos caracteres adyacentes en los strings,  si y solo si estos quedan en su posicion final al momento de realizarla.
    La funcion devuelve el costo minimo de operaciones para llegar a la distancia de levenshtein entre s1 y s2.

    Recibe:
        - s1: string
        - s2: string

    Devuelve:
        - int: distancia de levenshtein entre s1 y s2
*/

int levenshtein(const string &s1, const string &s2) {
    int N1 = s1.size();
    int N2 = s2.size();
    
    vector<vector<int>> T(N1 + 1, vector<int>(N2 + 1));

    for (int i = 0; i <= N1; i++)
        T[i][0] = i * costo_del(s1[i - 1]); 
    for (int j = 0; j <= N2; j++)
        T[0][j] = j * costo_ins(s2[j - 1]); 


    for (int i = 1; i <= N1; i++) {
        for (int j = 1; j <= N2; j++) {
            int costo_insercion = T[i][j - 1] + costo_ins(s2[j - 1]);
            int costo_eliminacion = T[i - 1][j] + costo_del(s1[i - 1]);
            int costo_sustitucion = T[i - 1][j - 1] + costo_sub(s1[i - 1], s2[j - 1]);
            
            T[i][j] = min({costo_insercion, costo_eliminacion, costo_sustitucion});


            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                int costo_transposicion = T[i - 2][j - 2] + costo_trans(s1[i - 1], s1[i - 2]);
                T[i][j] = min(T[i][j], costo_transposicion);
            }
        }
    }
    
    return T[N1][N2];
}


