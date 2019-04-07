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
    void ataque_set();
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
    torre(int, int, int);
    ~torre();
    void movs(tablero);
};

// REY //
class rey : public piezas {
public:
    bool jaque;
    bool mate;
public:
    rey(int, int, int);
    ~rey();
    void movs(tablero);
};


#endif // PIEZAS_H
