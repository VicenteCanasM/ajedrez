#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include <QPushButton>
using namespace std;

class escaque{
public:
    bool color; // Color del escaque
    bool hay_rey;
    bool pulsado;
    int ocupado;  // Color de la pieza que esté encima: 0 -> blanco, 1 -> negro, 2 -> vacio
    int t_icon;
    bool hay_peon_paso; // Indica si hay un peón adelantado
    escaque(bool, int, int, bool);
    escaque();
};

class tablero{
public:
    int filas = 8, columnas = 8;
    vector <vector <int>> jugadores;
    vector <vector <int>> colores_select;
    vector <vector <escaque>> mat_escaque;
    tablero();
    tablero(vector <vector <int>>, vector <vector< bool>>);
    void imprimir_tablero();
    void imprimir_tablero_jugador();
    void imprimir_tablero_reyes();
};


#endif // TABLERO_H
