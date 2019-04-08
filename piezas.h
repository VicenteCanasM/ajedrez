#ifndef PIEZAS_H
#define PIEZAS_H

#include <iostream>
#include <vector>
#include "tablero.h"
using namespace  std;

// PIEZAS //
class piezas {
public:
    pair<int,int> pos;
    int jugador;
    int valor;
    vector<pair<int,int>> mov_set;
    vector<pair<int,int>> atq_set;
public:
    piezas(int, int, int);
    ~piezas();
    void mover();
};

// PEON //
class peon : public piezas {
public:
    bool first_mov;
public:
    peon(int, int, int);
    ~peon();
    void coronar();
    void movs(tablero);
};

// CABALLO //
class caballo : public piezas {
public:
    caballo(int, int, int);
    ~caballo();
    void movs(tablero);
};

// ALFIL //
class alfil : public piezas {
public:
    alfil(int, int, int);
    ~alfil();
    void movs(tablero);
};

// TORRE //
class torre : public piezas {
public:
    bool first_mov;
public:
    torre(int, int, int);
    ~torre();
    void movs(tablero);
};

// REY //
class rey : public piezas {
public:
    bool jaque;
    bool mate;
    bool first_mov;
public:
    rey(int, int, int);
    ~rey();
    vector<vector<bool>> comprobar_mov_rey(tablero, int, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<rey>);
    void comprobar_jaque_rey(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>);
    void comprobar_mate_rey(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>);
    void movs(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<rey>);
    pair<bool,bool> comprobar_enroque(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<rey>);
};


#endif // PIEZAS_H
