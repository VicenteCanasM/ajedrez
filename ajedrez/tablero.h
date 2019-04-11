#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include <QPushButton>
using namespace std;

class escaque{
public:
    bool color;
    bool hay_rey;
    bool pulsado;
    int ocupado;
    vector<pair<int,int>> zona_def; // Indica si la casilla este defendida (1) o no (0) y porque pieza <blanca,negra>
    escaque(bool, int);
    escaque();
};

class tablero{
public:
    int filas = 8, columnas = 8;
    vector <vector <int>> jugadores;
    vector <vector <int>> colores_select;
    vector <vector <escaque>> mat_escaque;
    tablero(vector <vector <int>>);
    void imprimir_tablero();
};



#endif // TABLERO_H
