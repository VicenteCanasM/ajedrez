#ifndef PIEZAS_H
#define PIEZAS_H

#include <iostream>
#include <vector>
#include "tablero.h"
using namespace  std;

// PIEZAS //
class piezas {
public:
    pair<int,int> pos; // Posición de la pieza en el tablero
    int jugador; // Color de la pieza: 0 -> blancas; 1 -> negras;
    int valor; // Valor numérico de la pieza
    vector<pair<int,int>> mov_set; // Posiciones libres a las que puede acceder la pieza
    vector<pair<int,int>> atq_set; // Posiciones a las que puede atacar la pieza (hay una pieza rival)
    vector<pair<int,int>> escaque_def; // Posiciones defendidas por la pieza (incluye posiciones en las que hay una pieza aliada, pero no enemiga)
    bool jaque_rey;
    vector<pair<int,int>> atq_rey;
public:
    piezas(int, int, int); // (columna, fila, color[0 -> blancas; 1 -> negras])
    ~piezas();
    void mover(pair<int,int>);
};



// CABALLO //
class caballo : public piezas {
public:
    caballo(int, int, int);
    ~caballo();
    void movs(tablero);
};

// ALFIL //
class alfil : virtual public piezas {
public:
    alfil(int, int, int);
    ~alfil();
    void movsA(tablero);
};

// TORRE //
class torre : virtual public piezas {
public:
    bool first_mov;
public:
    torre(int, int, int);
    ~torre();
    void movsT(tablero);
};

// DAMA //
class dama : virtual public torre, virtual public alfil {
public:
    dama(int, int, int);
    ~dama();
    void movs(tablero);
};

// PEON //
class peon : public piezas {
public:
    bool first_mov; // 1 -> si el peón aún no se ha movido; 0 -> caso contrario
    bool dos_pasos; // 1 -> si el peón acaba de avanzar dos casillas; 0 -> caso contrario ((HAY QUE HACER UN METODO PARA COMPROBARLO))
public:
    peon(int, int, int);
    ~peon();
    bool coronar(vector<dama>*); // Coronar el peón cuando llegue al extremo contrario
    void movs(tablero); // Genera los movimientos posibles de la pieza
};

// REY //
class rey : public piezas {
public:
    bool jaque; // 1 -> el rey está en jaque; 0 -> caso contrario
    bool mate; // 1 -> el rey está en jaque mate; 0 -> caso contrario
    bool first_mov;
public:
    rey(int, int, int);
    ~rey();
    vector<vector<bool>> comprobar_mov_rey(tablero, int, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>, vector<rey>);
    void comprobar_jaque_rey(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>);
    void comprobar_mate_rey(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>, vector<rey>);
    void movs(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>, vector<rey>);
    pair<bool,bool> comprobar_enroque(tablero, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>);
};

#endif // PIEZAS_H
