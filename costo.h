#ifndef COSTO_H
#define COSTO_H

#include <vector>

using namespace std;


/*
    Este es el header file de costo.cpp
    Contiene las declaraciones de las funciones que se encargan de devolver el costo de cada operacion de levenshtein.

    Se programo para mantener la programacion modular, ya que cada operacion tiene su propio costo y se leen de archivos de texto diferentes.
    De esta manera, se puede cambiar el costo de cada operacion sin tener que modificar el codigo de levenshtein.
    Estas funciones son las que se llaman en los programas de levenshtein, para obtener el costo de cada operacion.
*/
int costo_trans(char a, char b);
int costo_sub(char a, char b);
int costo_ins(char b);
int costo_del(char a);


#endif