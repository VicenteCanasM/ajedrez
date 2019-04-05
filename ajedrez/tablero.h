#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include <QPushButton>
using namespace std;

class escaque{
public:
    bool color;
    bool pulsado;
    int ocupado;
    escaque(bool, int);
    escaque();
};

class tablero{
public:
    unsigned long filas = 8, columnas = 8;
    vector <vector <int>> jugadores;
    vector <vector <int>> colores_select;
    vector <vector <escaque>> mat_escaque;
    tablero(vector <vector <int>>);
    void imprimir_tablero();
};



#endif // TABLERO_H
