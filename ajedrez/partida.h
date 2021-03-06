#ifndef PARTIDA_H
#define PARTIDA_H
#include <vector>
#include <iostream>
#include "piezas.h"
#include "tablero.h"
#include "funciones.h"
using namespace std;

class partida {
public:
    vector <peon> v_peon;
    vector <caballo> v_caballo;
    vector <alfil> v_alfil;
    vector <torre> v_torre;
    vector <rey> v_rey;
    vector <dama> v_dama;
    int turno;
public:
    partida();
    ~partida();
    vector<vector<bool>> comprobar_mov_escaque(tablero, int, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<rey>, vector<dama>);
};

#endif // PARTIDA_H
