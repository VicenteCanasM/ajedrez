#include <vector>
#include <iostream>
#include <QPushButton>
#include "tablero.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

escaque::escaque(bool col, int jugador, int icono){
    color = col;
    ocupado = jugador;
    pulsado = false;
    t_icon = icono;
    //hay_rey =
}

escaque::escaque(){
    color = false;
    ocupado = 2;
    pulsado = false;
    t_icon = 0;
}

tablero::tablero(){
}

tablero::tablero(vector < vector <int>> jugadores){
    bool color = true;
    mat_escaque.resize(8);
    for(unsigned long i = 0; i < 8; i++) mat_escaque[i].resize(8);
    for(unsigned long i = 0; i < static_cast<unsigned long>(filas); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(columnas); j++){
            escaque mi_escaque(color, jugadores[i][j], 0);
            mat_escaque[i][j] = mi_escaque;
            color = not color;
        }
        color = not color;
    }
}

void tablero::imprimir_tablero(){
    cout << endl;
    for (int  i = 7; i >= 0; i--){
        for (int j = 0; j < 8; j++){
            cout << mat_escaque[j][i].color << ' ';
        }
        cout << endl;
    }
}

void tablero::imprimir_tablero_jugador(){
    cout << endl;
    for (int  i = 7; i >= 0; i--){
        for (int j = 0; j < 8; j++){
            cout << mat_escaque[j][i].ocupado << ' ';
        }
        cout << endl;
    }
}

