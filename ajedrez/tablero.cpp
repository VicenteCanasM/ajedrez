#include <vector>
#include <iostream>
#include <QPushButton>
#include "tablero.h"
#include <iostream>

using namespace std;

escaque::escaque(bool col, int jugador){
    color = col;
    ocupado = jugador;
    pulsado = false;
}

escaque::escaque(){
    color = false;
    ocupado = 2;
    pulsado = false;
}

tablero::tablero(vector < vector <int>> jugadores){
    bool color = true;
    mat_escaque.resize(8);
    for(unsigned long i = 0; i < 8; i++) mat_escaque[i].resize(8);
    for(unsigned long i = 0; i < static_cast<unsigned long>(filas); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(columnas); j++){
            escaque mi_escaque(color, jugadores[i][j]);
            mat_escaque[i][j] = mi_escaque;
            color = not color;
        }
        color = not color;
    }
}

void tablero::imprimir_tablero(){
    for (int  i = 7; i >= 0; i--){
        for (int j = 0; j < 8; j++){
            cout << mat_escaque[i][j].color << ' ';
        }
        cout << endl;
    }
}
