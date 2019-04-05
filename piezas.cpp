#include "piezas.h"
#include "funciones.h"

// ============================== PIEZAS ============================== //
piezas::piezas(int col, int fil, int jug){
    jugador = jug;
    pos.first = col;
    pos.second = fil;
}

piezas::~piezas(){
}

void ataque_set(){
}

void mover(){
}


/* ============================== PEON ============================== */
// Constructor
peon::peon(int col, int fil, int jug) : piezas(col, fil, jug){
    first_mov = 1;
    valor = 1;
};
// Destructor
peon::~peon(){
};
// Comprobar movimientos posibles
void peon::movs(){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    if (jugador == 0){ // Si juegan blancas
        if (/*escaque(col_act, fil_act+1).ocupado == 2*/true){ // Comprobar escaque inmediato
            casilla.first = col_act;
            casilla.second = fil_act+1;
            mov_set.push_back(casilla);
            if (first_mov == 1 && /*escaque(col_act, fil_act+2).ocupado == 2*/true){ // Comprobar segundo escaque si es primer movimiento
                casilla.first = col_act;
                casilla.second = fil_act+2;
                mov_set.push_back(casilla);
            };
        };
        if (/*escaque(col_act+1, fil_act+1).ocupado == 1*/true){ // Ataque a diagonal derecha
            casilla.first = col_act+1;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        };
        if (/*escaque(col_act-1, fil_act+1).ocupado == 1*/true){ // Ataque a diagonal izquierda
            casilla.first = col_act-1;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        };
    }
    else if (jugador == 1){ // Si juegan negras
        if (/*escaque(col_act, fil_act-1).ocupado == 2*/true){ // Comprobar escaque inmediato
            casilla.first = col_act;
            casilla.second = fil_act-1;
            mov_set.push_back(casilla);
            if (first_mov == 1 && /*escaque(col_act, fil_act-2).ocupado == 2*/true){ // Comprobar segundo escaque si es primer movimiento
                casilla.first = col_act;
                casilla.second = fil_act-2;
                mov_set.push_back(casilla);
            };
        };
        if (/*escaque(col_act+1, fil_act-1).ocupado == 1*/true){ // Ataque a diagonal derecha
            casilla.first = col_act+1;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        };
        if (/*escaque(col_act-1, fil_act-1).ocupado == 1*/true){ // Ataque a diagonal izquierda
            casilla.first = col_act-1;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        };
    };
};
// Coronar
void peon::coronar(){
    if (jugador == 0 && pos.second == 8){

    };
    if (jugador == 1 && pos.second == 1){

    };
};

/* ============================== CABALLO ============================== */
// Constructor
caballo::caballo(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 3;
};
// Destructor
caballo::~caballo(){
};
// Comprobar movimientos posibles
void caballo::movs(){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    if (comprobar_limites(col_act+2, fil_act+1)){
        if (/*escaque(col_act+2, fil_act+1).ocupado == 2*/true){ //Comprobar escaque superior derecha 1
            casilla.first = col_act+2;
            casilla.second = fil_act+1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+2, fil_act+1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+2;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act+1, fil_act+2)){
        if (/*escaque(col_act+1, fil_act+2).ocupado == 2*/true){ //Comprobar escaque superior derecha 2
            casilla.first = col_act+1;
            casilla.second = fil_act+2;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+1, fil_act+2).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+1;
            casilla.second = fil_act+2;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-1, fil_act+2)){
        if (/*escaque(col_act-1, fil_act+2).ocupado == 2*/true){ //Comprobar escaque superior izquierda 1
            casilla.first = col_act-1;
            casilla.second = fil_act+2;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-1, fil_act+2).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-1;
            casilla.second = fil_act+2;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-2, fil_act+1)){
        if (/*escaque(col_act-2, fil_act+1).ocupado == 2*/true && comprobar_limites(col_act-2, fil_act+1)){ //Comprobar escaque superior izquierda 2
            casilla.first = col_act-2;
            casilla.second = fil_act+1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-2, fil_act+1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-2;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-2, fil_act-1)){
        if (/*escaque(col_act-2, fil_act-1).ocupado == 2*/true){ //Comprobar escaque inferior izquierda 1
            casilla.first = col_act-2;
            casilla.second = fil_act-1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-2, fil_act-1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-2;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-1, fil_act-2)){
        if (/*escaque(col_act-1, fil_act-2).ocupado == 2*/true){ //Comprobar escaque inferior izquierda 2
            casilla.first = col_act-1;
            casilla.second = fil_act-2;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-1, fil_act-2).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-1;
            casilla.second = fil_act-2;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act+1, fil_act-2)){
        if (/*escaque(col_act+1, fil_act-2).ocupado == 2*/true){ //Comprobar escaque inferior derecha 1
            casilla.first = col_act+1;
            casilla.second = fil_act-2;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+1, fil_act-2).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+1;
            casilla.second = fil_act-2;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act+2, fil_act-1)){
        if (/*escaque(col_act+2, fil_act-1).ocupado == 2*/true){ //Comprobar escaque inferior derecha 2
            casilla.first = col_act+2;
            casilla.second = fil_act-1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+2, fil_act-1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+2;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        }
    };
};

/* ============================== ALFIL ============================== */
// Constructor
alfil::alfil(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 3;
};
// Destructor
alfil::~alfil(){
};
// Comprobar movimientos posibles
void alfil::movs(){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    int c = 1;
    bool n = 1;
    while (n==1){ // Comprobar escaque en diagonal superior derecha
        if (comprobar_limites(col_act+c, fil_act+c)){
            if (/*escaque(col_act+c, fil_act+c).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act+c;
                casilla.second = fil_act+c;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act+c, fil_act+c).ocupado != torre.jugador*/true){ // Posible ataque
                casilla.first = col_act+c;
                casilla.second = fil_act+c;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else {
            n = 0;
        };
    };
    c = 1;  n = 1;
    while (n==1){ // Comprobar escaque en diagonal superior izquierda
        if (comprobar_limites(col_act-c, fil_act+c)){
            if (/*escaque(col_act-c, fil_act+c).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act-c;
                casilla.second = fil_act+c;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act-c, fil_act+c).ocupado != torre.jugador*/true){ // Posible ataque
                casilla.first = col_act-c;
                casilla.second = fil_act+c;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else {
            n = 0;
        };
    };
    c = 1;  n = 1;
    while (n==1){ // Comprobar escaque en diagonal inferior izquierda
        if (comprobar_limites(col_act-c, fil_act-c)){
            if (/*escaque(col_act-c, fil_act-c).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act-c;
                casilla.second = fil_act-c;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act-c, fil_act-c).ocupado != torre.jugador*/true){ // Posible ataque
                casilla.first = col_act-c;
                casilla.second = fil_act-c;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else {
            n = 0;
        };
    };
    c = 1;  n = 1;
    while (n==1){ // Comprobar escaque en diagonal inferior derecha
        if (comprobar_limites(col_act+c, fil_act-c)){
            if (/*escaque(col_act+c, fil_act-c).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act+c;
                casilla.second = fil_act-c;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act+c, fil_act-c).ocupado != torre.jugador*/true){ // Posible ataque
                casilla.first = col_act+c;
                casilla.second = fil_act-c;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else {
            n = 0;
        };
    };
};

/* ============================== TORRE ============================== */
// Constructor
torre::torre(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 5;
};
// Destructor
torre::~torre(){
};
// Comprobar movimientos posibles
void torre::movs(){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    int c = 1;
    bool n = 1;
    while (n==1){ // Comprobar escaque en vertical superior
        if (comprobar_limites(col_act, fil_act+c)){
            if (/*escaque(col_act, fil_act+c).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act;
                casilla.second = fil_act+c;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act, fil_act+c).ocupado != torre.jugador */true){ // Posible ataque
                casilla.first = col_act;
                casilla.second = fil_act+c;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else { // Ningún movimiento más
            n = 0;
        };
    };
    c = 1;  n = 1;
    while (n==1){ // Comprobar escaque en vertical inferior
        if (comprobar_limites(col_act, fil_act-c)){
            if (/*escaque(col_act, fil_act-c).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act;
                casilla.second = fil_act-c;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act, fil_act-c).ocupado != torre.jugador */true){ // Posible ataque
                casilla.first = col_act;
                casilla.second = fil_act-c;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else { // Ningún movimiento más
            n=0;
        };
    };
    c = 1;  n = 1;
    while (n==1){ // Comprobar escaque en horizontal derecha
        if (comprobar_limites(col_act+c, fil_act)){
            if (/*escaque(col_act+c, fil_act).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act+c;
                casilla.second = fil_act;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act+c, fil_act).ocupado != torre.jugador */true){ // Posible ataque
                casilla.first = col_act+c;
                casilla.second = fil_act;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else { // Ningún movimiento más
            n=0;
        };
    };
    c = 1;
    n = 1;
    while (n==1){ // Comprobar escaque en horizontal izquierda
        if (comprobar_limites(col_act-c, fil_act)){
            if (/*escaque(col_act-c, fil_act).ocupado == 2*/true){ // Posible avance
                casilla.first = col_act-c;
                casilla.second = fil_act;
                mov_set.push_back(casilla);
                c+=c;
            }
            else if (/*escaque(col_act-c, fil_act).ocupado != torre.jugador */true){ // Posible ataque
                casilla.first = col_act-c;
                casilla.second = fil_act;
                atq_set.push_back(casilla);
                n = 0;
            }
        }
        else { // Ningún movimiento más
            n=0;
        };
    };
};

/* ============================== REY ============================== */
rey::rey(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 0;
    jaque = 0;
    mate = 0;
};

rey::~rey(){
};

void rey::movs(){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    if (comprobar_limites(col_act, fil_act+1)){
        if (/*escaque(col_act, fil_act+1).ocupado == 2*/true){ //Comprobar escaque superior
            casilla.first = col_act;
            casilla.second = fil_act+1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act, fil_act+1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-1, fil_act+1)){
        if (/*escaque(col_act-1, fil_act+1).ocupado == 2*/true){ //Comprobar escaque superior izquierda
            casilla.first = col_act-1;
            casilla.second = fil_act+1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-1, fil_act+1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-1;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-1, fil_act)){
        if (/*escaque(col_act-1, fil_act).ocupado == 2*/true){ //Comprobar escaque izquierda
            casilla.first = col_act-1;
            casilla.second = fil_act;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-1, fil_act).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-1;
            casilla.second = fil_act;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act-1, fil_act-1)){
        if (/*escaque(col_act-1, fil_act-1).ocupado == 2*/true){ //Comprobar escaque inferior izquierda
            casilla.first = col_act-1;
            casilla.second = fil_act-1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act-1, fil_act-1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act-1;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act, fil_act-1)){
        if (/*escaque(col_act, fil_act-1).ocupado == 2*/true){ //Comprobar escaque inferior
            casilla.first = col_act;
            casilla.second = fil_act-1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act, fil_act-1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act+1, fil_act-1)){
        if (/*escaque(col_act+1, fil_act-1).ocupado == 2*/true){ //Comprobar escaque inferior derecha
            casilla.first = col_act+1;
            casilla.second = fil_act-1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+1, fil_act-1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+1;
            casilla.second = fil_act-1;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act+1, fil_act)){
        if (/*escaque(col_act+1, fil_act).ocupado == 2*/true){ //Comprobar escaque derecha
            casilla.first = col_act+1;
            casilla.second = fil_act;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+1, fil_act).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+1;
            casilla.second = fil_act;
            atq_set.push_back(casilla);
        }
    };
    if (comprobar_limites(col_act+1, fil_act+1)){
        if (/*escaque(col_act+1, fil_act+1).ocupado == 2*/true){ //Comprobar escaque superior derecha
            casilla.first = col_act+1;
            casilla.second = fil_act+1;
            mov_set.push_back(casilla);
        }
        else if (/*escaque(col_act+1, fil_act+1).ocupado != torre.jugador*/true){ // Posible ataque
            casilla.first = col_act+1;
            casilla.second = fil_act+1;
            atq_set.push_back(casilla);
        }
    };
}

