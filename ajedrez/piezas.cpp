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

void piezas::mover(pair<int,int> nueva_pos){
    for(unsigned long i = 0; i <= mov_set.size(); i++){
        if(nueva_pos.first == mov_set[i].first && nueva_pos.second == mov_set[i].second){
            pos.first = nueva_pos.first;
            pos.second = nueva_pos.second;
        }
    }
};


/* ============================== PEON ============================== */
// Constructor
peon::peon(int col, int fil, int jug) : piezas(col, fil, jug){
    first_mov = 1;
    valor = 1;
    jaque_rey = 0;
    dos_pasos = 0;
};
// Destructor
peon::~peon(){
};
// Comprobar movimientos posibles
void peon::movs(tablero mi_tab){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    jaque_rey = 0;
    dos_pasos = 0;
    pair<int,int> casilla;
    if (jugador == 0){ // Si juegan blancas
        if (comprobar_limites(pos.first, pos.second+1)){
            if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act+1)].ocupado == 2){ // Comprobar escaque inmediato
                casilla.first = col_act;
                casilla.second = fil_act+1;
                mov_set.push_back(casilla); // Movimiento peón
                if (comprobar_limites(pos.first, pos.second+2)){
                    if (first_mov == 1 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act+2)].ocupado == 2){ // Comprobar segundo escaque si es primer movimiento
                        casilla.first = col_act;
                        casilla.second = fil_act+2;
                        dos_pasos = 1;
                        mov_set.push_back(casilla); // Movimiento inicial doble
                    };
                };
            };
            if (comprobar_limites(pos.first+1, pos.second+1)){
                casilla.first = col_act+1;
                casilla.second = fil_act+1;
                escaque_def.push_back(casilla); // Zona de influencia
                /*if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act+1)].ocupado == 0 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act)].peon_2_pasos == 1 ){
                    atq_set.push_back(casilla); // Capturar al paso derecha
                }*/
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act+1)].ocupado == 1){ // Ataque a diagonal derecha
                    atq_set.push_back(casilla); // Ataque
                    if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act+1)].hay_rey)
                        jaque_rey = 1;
                };
            };
            if (comprobar_limites(pos.first-1, pos.second+1)){
                casilla.first = col_act-1;
                casilla.second = fil_act+1;
                escaque_def.push_back(casilla); // Zona de influencia
                /*if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act+1)].ocupado == 0 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act)].peon_2_pasos == 1 ){
                    atq_set.push_back(casilla); // Capturar al paso izquierda
                }*/
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act+1)].ocupado == 1){ // Ataque a diagonal izquierda
                    atq_set.push_back(casilla); // Ataque
                    if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act+1)].hay_rey)
                        jaque_rey = 1;
                };
            };
        };
    }
    else if (jugador == 1){ // Si juegan negras
        if (comprobar_limites(pos.first, pos.second-1)){
            if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act-1)].ocupado == 2){ // Comprobar escaque inmediato
                casilla.first = col_act;
                casilla.second = fil_act-1;
                mov_set.push_back(casilla); // Movimiento peón
                if (comprobar_limites(pos.first, pos.second-2)){
                    if (first_mov == 1 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act-2)].ocupado == 2){ // Comprobar segundo escaque si es primer movimiento
                        casilla.first = col_act;
                        casilla.second = fil_act-2;
                        dos_pasos = 1;
                        mov_set.push_back(casilla); // Movimiento inicial doble
                    };
                };
            };
            if (comprobar_limites(pos.first+1, pos.second-1)){
                casilla.first = col_act+1;
                casilla.second = fil_act-1;
                escaque_def.push_back(casilla); // Zona de influencia
                /*if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act-1)].ocupado == 0 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act)].peon_2_pasos == 1 ){
                    atq_set.push_back(casilla); // Capturar al paso derecha
                }*/
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act-1)].ocupado == 0){ // Ataque a diagonal derecha
                    atq_set.push_back(casilla); // Ataque
                    if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act-1)].hay_rey)
                        jaque_rey = 1;
                };
            };
            if (comprobar_limites(pos.first-1, pos.second-1)){
                casilla.first = col_act-1;
                casilla.second = fil_act-1;
                escaque_def.push_back(casilla); // Zona de influencia
                /*if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act-1)].ocupado == 0 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act)].peon_2_pasos == 1 ){
                    atq_set.push_back(casilla); // Capturar al paso izquierda
                }*/
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act-1)].ocupado == 0){ // Ataque a diagonal izquierda
                    atq_set.push_back(casilla); // Ataque
                    if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act-1)].hay_rey)
                        jaque_rey = 1;
                };
            };
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
    jaque_rey = 0;
};
// Destructor
caballo::~caballo(){
};
// Comprobar movimientos posibles
void caballo::movs(tablero mi_tab){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    jaque_rey = 0;
    pair<int,int> casilla;
    vector<pair<int,int>> escaques_ady;
    escaques_ady.push_back(pair<int,int>(2,1));     escaques_ady.push_back(pair<int,int>(1,2));
    escaques_ady.push_back(pair<int,int>(-1,2));     escaques_ady.push_back(pair<int,int>(-2,1));
    escaques_ady.push_back(pair<int,int>(-2,-1));     escaques_ady.push_back(pair<int,int>(-1,-2));
    escaques_ady.push_back(pair<int,int>(1,-2));     escaques_ady.push_back(pair<int,int>(2,-1));
    for (unsigned long i = 0; i <= escaques_ady.size(); i++){
        if (comprobar_limites(col_act+escaques_ady[i].first, fil_act+escaques_ady[i].second)){
            casilla.first = col_act+escaques_ady[i].first;
            casilla.second = fil_act+escaques_ady[i].second;
            escaque_def.push_back(casilla); // Zona de influencia
            if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado == 2){
                mov_set.push_back(casilla); // Posible movimiento
            }
            else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado == (jugador + 1)%2){
                atq_set.push_back(casilla); // Posible ataque
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].hay_rey)
                    jaque_rey = 1; // Jaque al rey enemigo
            };
        };
    };
};

/* ============================== ALFIL ============================== */
// Constructor
alfil::alfil(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 3;
    jaque_rey = 0;
};
// Destructor
alfil::~alfil(){
};
// Comprobar movimientos posibles
void alfil::movsA(tablero mi_tab){
    int col_act = pos.first;
    int fil_act = pos.second;
    vector<pair<int,int>> atq_rey_aux;
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    atq_rey.clear();
    jaque_rey = 0;
    pair<int,int> casilla;
    int c = 1;
    bool n = 1;
    vector<pair<int,int>> escaques_ady;
    escaques_ady.push_back(pair<int,int>(1,1));     escaques_ady.push_back(pair<int,int>(-1,1));
    escaques_ady.push_back(pair<int,int>(-1,-1));     escaques_ady.push_back(pair<int,int>(1,-1));
    for (unsigned long i = 0; i < escaques_ady.size(); i++){
        while (n==1){
            if (comprobar_limites(col_act+escaques_ady[i].first*c, fil_act+escaques_ady[i].second*c)){
                casilla.first = col_act+escaques_ady[i].first*c;
                casilla.second = fil_act+escaques_ady[i].second*c;
                escaque_def.push_back(casilla); // Zona de influencia
                atq_rey_aux.push_back(casilla); // Posible zona a tapar durante el jaque
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == 2){
                    mov_set.push_back(casilla); // Posible movimiento
                    c++;
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == (jugador + 1)%2){
                    atq_set.push_back(casilla); // Posible ataque
                    n = 0;
                    if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].hay_rey){
                        jaque_rey = 1; // Jaque al rey enemigo
                        atq_rey = atq_rey_aux;
                        c++;
                        casilla.first = col_act+escaques_ady[i].first*c;
                        casilla.second = fil_act+escaques_ady[i].second*c;
                        if (comprobar_limites(casilla.first, casilla.second) && mi_tab.mat_escaque[casilla.first][casilla.second].ocupado == 2)
                            escaque_def.push_back(casilla);
                    };
                }
                else {
                    n = 0;
                };
            }
            else { // Ningún movimiento más
                n = 0;
            };
        };
        n = 1;  c = 1;
        atq_rey_aux.clear();
    };
};

/* ============================== TORRE ============================== */
// Constructor
torre::torre(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 5;
    jaque_rey = 0;
};
// Destructor
torre::~torre(){
};
// Comprobar movimientos posibles
void torre::movsT(tablero mi_tab){
    int col_act = pos.first;
    int fil_act = pos.second;
    vector<pair<int,int>> atq_rey_aux;
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    atq_rey.clear();
    jaque_rey = 0;
    pair<int,int> casilla;
    int c = 1;
    bool n = 1;
    vector<pair<int,int>> escaques_ady;
    escaques_ady.push_back(pair<int,int>(0,1));     escaques_ady.push_back(pair<int,int>(0,-1));
    escaques_ady.push_back(pair<int,int>(1,0));     escaques_ady.push_back(pair<int,int>(-1,0));
    for (unsigned long i = 0; i < escaques_ady.size(); i++){
        while (n==1){
            if (comprobar_limites(col_act+escaques_ady[i].first*c, fil_act+escaques_ady[i].second*c)){
                casilla.first = col_act+escaques_ady[i].first*c;
                casilla.second = fil_act+escaques_ady[i].second*c;
                escaque_def.push_back(casilla); // Zona de influencia
                atq_rey_aux.push_back(casilla); // Posible zona a tapar durante el jaque
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == 2){ // Posible avance
                    mov_set.push_back(casilla); // Posible movimiento
                    c++;
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == (jugador + 1)%2){ // Posible ataque
                    atq_set.push_back(casilla); // Posible ataque
                    n = 0;
                    if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].hay_rey){
                        jaque_rey = 1; // Jaque al rey enemigo
                        atq_rey = atq_rey_aux;
                        c++;
                        casilla.first = col_act+escaques_ady[i].first*c;
                        casilla.second = fil_act+escaques_ady[i].second*c;
                        if (comprobar_limites(casilla.first, casilla.second) && mi_tab.mat_escaque[casilla.first][casilla.second].ocupado == 2)
                            escaque_def.push_back(casilla);
                    };
                }
                else {
                    n = 0;
                };
            }
            else { // Ningún movimiento más
                n = 0;
            };
        };
        n = 1;  c = 1;
        atq_rey_aux.clear();
    };
};

/* ============================== DAMA ============================== */
// Constructor
dama::dama(int col, int fil, int jug) : piezas(col, fil, jug),torre(col, fil, jug), alfil(col, fil, jug) {
    valor = 10;
};
// Destructor
dama::~dama(){
};
// Comprobar movimientos posibles
void dama::movs(tablero mi_tab){
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    atq_rey.clear();
    vector<pair<int,int>> mov_set_aux;
    vector<pair<int,int>> atq_set_aux;
    vector<pair<int,int>> escaque_def_aux;
    vector<pair<int,int>> atq_rey_aux;
    bool jaque_rey_1;
    //jaque_rey = 0;
    movsA(mi_tab);
    mov_set_aux = mov_set;
    atq_set_aux = atq_set;
    escaque_def_aux = escaque_def;
    atq_rey_aux = atq_rey;
    jaque_rey_1 = jaque_rey;
    jaque_rey = 0;
    movsT(mi_tab);
    mov_set.insert(mov_set.end(), mov_set_aux.begin(), mov_set_aux.end());
    atq_set.insert(atq_set.end(), atq_set_aux.begin(), atq_set_aux.end());
    escaque_def.insert(escaque_def.end(), escaque_def_aux.begin(), escaque_def_aux.end());
    atq_rey.insert(atq_rey.end(), atq_rey_aux.begin(), atq_rey_aux.end());
    jaque_rey = jaque_rey || jaque_rey_1;

    /*vector<pair<int,int>> escaques_ady;
    escaques_ady.push_back(pair<int,int>(0,1));     escaques_ady.push_back(pair<int,int>(0,-1));
    escaques_ady.push_back(pair<int,int>(1,0));     escaques_ady.push_back(pair<int,int>(-1,0));
    escaques_ady.push_back(pair<int,int>(1,1));     escaques_ady.push_back(pair<int,int>(-1,1));
    escaques_ady.push_back(pair<int,int>(-1,-1));     escaques_ady.push_back(pair<int,int>(1,-1));
    for (unsigned long i = 0; i < escaques_ady.size(); i++){
        while (n==1){
            if (comprobar_limites(col_act+escaques_ady[i].first*c, fil_act+escaques_ady[i].second*c)){
                casilla.first = col_act+escaques_ady[i].first*c;
                casilla.second = fil_act+escaques_ady[i].second*c;
                escaque_def.push_back(casilla); // Zona de influencia
                atq_rey_aux.push_back(casilla); // Posible zona a tapar durante el jaque
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == 2){ // Posible avance
                    mov_set.push_back(casilla); // Posible movimiento
                    c++;
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == (jugador + 1)%2){ // Posible ataque
                    atq_set.push_back(casilla); // Posible ataque
                    n = 0;
                    if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].hay_rey){
                        jaque_rey = 1; // Jaque al rey enemigo
                        atq_rey = atq_rey_aux;
                    };
                }
                else {
                    n = 0;
                };
            }
            else { // Ningún movimiento más
                n = 0;
            };
        };
        n = 1;  c = 1;
        atq_rey_aux.clear();
    };*/
}


/* ============================== REY ============================== */
// Constructor
rey::rey(int col, int fil, int jug) : piezas(col, fil, jug){
    valor = 0;
    jaque = 0;
    mate = 0;
};
// Destructor
rey::~rey(){
};
// Comprobar casillas fuera de peligro
vector<vector<bool>> rey::comprobar_mov_rey(tablero mi_tab, int jug, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama){
    vector<vector<bool>> tablero_libre(8);
    for(unsigned long i = 0; i < 8; i++) tablero_libre[i].resize(8, 1);
    for (unsigned long  i = 0; i < v_peon.size() ; i++){
        if (v_peon[i].jugador != jug){
            int col_act = v_peon[i].pos.first;
            int fil_act = v_peon[i].pos.second;
            if (v_peon[i].jugador == 0){
                if (comprobar_limites(col_act+1, fil_act+1))
                    tablero_libre[col_act+1][fil_act+1] = 0;
                if (comprobar_limites(col_act-1, fil_act+1))
                    tablero_libre[fil_act-1][fil_act+1] = 0;
            };
            if (v_peon[i].jugador == 1){
                if (comprobar_limites(col_act+1, fil_act-1))
                    tablero_libre[col_act+1][fil_act-1] = 0;
                if (comprobar_limites(col_act-1, fil_act-1))
                    tablero_libre[fil_act-1][fil_act-1] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i < v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jug){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].escaque_def.size(); j++){
                tablero_libre[v_caballo[i].escaque_def[j].first][v_caballo[i].escaque_def[j].second] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i < v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jug){
            v_alfil[i].movsA(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].escaque_def.size(); j++){
                tablero_libre[v_alfil[i].escaque_def[j].first][v_alfil[i].escaque_def[j].second] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i < v_torre.size() ; i++){
        if (v_torre[i].jugador != jug){
            v_torre[i].movsT(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].escaque_def.size(); j++){
                tablero_libre[v_torre[i].escaque_def[j].first][v_torre[i].escaque_def[j].second] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i < v_dama.size() ; i++){
        if (v_dama[i].jugador != jug){
            v_dama[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_dama[i].escaque_def.size(); j++){
                tablero_libre[v_dama[i].escaque_def[j].first][v_dama[i].escaque_def[j].second] = 0;
            };
        };
    };
    return tablero_libre;
};
// Comprobar movimientos posibles
void rey::movs(tablero mi_tab, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    vector<pair<int,int>> escaques_ady;
    escaques_ady.push_back(pair<int,int>(0,1));     escaques_ady.push_back(pair<int,int>(0,-1));
    escaques_ady.push_back(pair<int,int>(1,0));     escaques_ady.push_back(pair<int,int>(-1,0));
    escaques_ady.push_back(pair<int,int>(1,1));     escaques_ady.push_back(pair<int,int>(-1,1));
    escaques_ady.push_back(pair<int,int>(-1,-1));     escaques_ady.push_back(pair<int,int>(1,-1));
    vector<vector<bool>> escaques_libres = this->comprobar_mov_rey(mi_tab, this->jugador, v_peon, v_caballo, v_alfil, v_torre, v_dama);
    for (unsigned long i = 0; i < escaques_ady.size(); i++){
        if (comprobar_limites(col_act+escaques_ady[i].first, fil_act+escaques_ady[i].second)){  //Comprobar escaque superior
            if (escaques_libres[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second]){
                casilla.first = col_act+escaques_ady[i].first;
                casilla.second = fil_act+escaques_ady[i].second;
                escaque_def.push_back(casilla);
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado == 2){
                    mov_set.push_back(casilla);
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado == (jugador + 1)%2){ // Posible ataque
                    atq_set.push_back(casilla);
                };
            };
        };
    };
    pair<bool,bool> habilitar_enroque = comprobar_enroque(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_dama); // Enroques habilitados
    if (habilitar_enroque.first){ //Comprobar enroque a torre en ax
        casilla.first = col_act+2;
        casilla.second = fil_act;
        mov_set.push_back(casilla);
    };
    if (habilitar_enroque.second){ //Comprobar enroque a torre en hx
        casilla.first = col_act-2;
        casilla.second = fil_act;
        mov_set.push_back(casilla);
    };
};
// Comprobar jaque
void rey::comprobar_jaque_rey(tablero mi_tab, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama){
    jaque = 0;
    for (unsigned long  i = 0; i < v_peon.size() ; i++){
        if (v_peon[i].jugador != jugador){
            v_peon[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_peon[i].atq_set.size(); j++){
                if (pos.first == v_peon[i].atq_set[j].first && pos.second == v_peon[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jugador){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].atq_set.size(); j++){
                if (pos.first == v_caballo[i].atq_set[j].first && pos.second == v_caballo[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jugador){
            v_alfil[i].movsA(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].atq_set.size(); j++){
                if (pos.first == v_alfil[i].atq_set[j].first && pos.second == v_alfil[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_torre.size() ; i++){
        if (v_torre[i].jugador != jugador){
            v_torre[i].movsT(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].atq_set.size(); j++){
                if (pos.first == v_torre[i].atq_set[j].first && pos.second == v_torre[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_dama.size() ; i++){
        if (v_dama[i].jugador != jugador){
            v_dama[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_dama[i].atq_set.size(); j++){
                if (pos.first == v_dama[i].atq_set[j].first && pos.second == v_dama[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
};
// Comprobar enroque
pair<bool,bool> rey::comprobar_enroque(tablero mi_tab,  vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama){
    pair <bool,bool> habilitar_enroque(0,0);
    if (first_mov && jaque == 0){
        bool escaque1, escaque2;
        for (unsigned long i = 0; i < v_torre.size(); i++){ // Busqueda de torres
            if (v_torre[i].jugador == jugador && v_torre[i].pos.first == 8){
                escaque1 = comprobar_amenaza(mi_tab, jugador, pos.first+1, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_dama);
                escaque2 = comprobar_amenaza(mi_tab, jugador, pos.first+2, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_dama);
                if (v_torre[i].first_mov == 1 && escaque1 && escaque2 && mi_tab.mat_escaque[pos.first+1][pos.second].ocupado == 2 && mi_tab.mat_escaque[pos.first+2][pos.second].ocupado == 2){
                    habilitar_enroque.second = 1; // Torre en hx (derecha desde blancos)
                };
            };
            if (v_torre[i].jugador == jugador && v_torre[i].pos.first == 1){
                escaque1 = comprobar_amenaza(mi_tab, jugador, pos.first-1, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_dama);
                escaque2 = comprobar_amenaza(mi_tab, jugador, pos.first-2, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_dama);
                if (v_torre[i].first_mov == 1 && !escaque1 && !escaque2 && mi_tab.mat_escaque[pos.first-1][pos.second].ocupado == 2 && mi_tab.mat_escaque[pos.first-2][pos.second].ocupado == 2 && mi_tab.mat_escaque[pos.first-3][pos.second].ocupado == 2){
                    habilitar_enroque.first = 1; // Torre en ax (izquierda desde blancos)
                };
            };
        };
    };
    return habilitar_enroque;
};
// Comprobar mate
void rey::comprobar_mate_rey(tablero mi_tab, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama, vector<rey> v_rey){
    mate = 1;
    vector<pair<int,int>> escaques_ady(8);
    //mi_tab.imprimir_tablero_reyes();
    escaques_ady[0].first = 0;  escaques_ady[0].second = 1;   escaques_ady[1].first = -1;  escaques_ady[1].second = 1;
    escaques_ady[2].first = -1;  escaques_ady[2].second = 0;  escaques_ady[3].first = -1;  escaques_ady[3].second = -1;
    escaques_ady[4].first = 0;  escaques_ady[4].second = -1;  escaques_ady[5].first = 1;  escaques_ady[5].second = -1;
    escaques_ady[6].first = 1;  escaques_ady[6].second = 0;   escaques_ady[7].first = 1;  escaques_ady[7].second = 1;
    // Se comprueba si el rey se puede salver moviéndose
    for (unsigned long i = 0; i < escaques_ady.size(); i++){
        if (mate){
            //mate = comprobar_amenaza(mi_tab, jugador, pos.first+escaques_ady[i].first, pos.second+escaques_ady[i].second, v_peon, v_caballo, v_alfil, v_torre, v_dama);
            this -> movs(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_dama);
            mate = mov_set.empty();
        }
    };
    // Se comprueba si la(s) pieza(s) que hace(n) jaque pueden ser capturadas
    vector<pair<int,int>> pos_piezas_jaque;
    if (mate){
        // Buscar la(s) pieza(s) que hace(n) jaque
        for(unsigned long i = 0; i < v_peon.size(); i++){
            v_peon[i].movs(mi_tab);
            if (v_peon[i].jaque_rey == 1 && v_peon[i].jugador != jugador)
                pos_piezas_jaque.push_back(v_peon[i].pos);
        }
        for(unsigned long i = 0; i < v_caballo.size(); i++){
            v_caballo[i].movs(mi_tab);
            if (v_caballo[i].jaque_rey == 1 && v_caballo[i].jugador != jugador)
                pos_piezas_jaque.push_back(v_caballo[i].pos);
        }
        for(unsigned long i = 0; i < v_alfil.size(); i++){
            v_alfil[i].movsA(mi_tab);
            if (v_alfil[i].jaque_rey == 1 && v_alfil[i].jugador != jugador)
                pos_piezas_jaque.push_back(v_alfil[i].pos);
        }
        for(unsigned long i = 0; i < v_torre.size(); i++){
            v_torre[i].movsT(mi_tab);
            if (v_torre[i].jaque_rey == 1 && v_torre[i].jugador != jugador)
                pos_piezas_jaque.push_back(v_torre[i].pos);
        }
        for(unsigned long i = 0; i < v_dama.size(); i++){
            v_dama[i].movs(mi_tab);
            if (v_dama[i].jaque_rey == 1 && v_dama[i].jugador != jugador)
                pos_piezas_jaque.push_back(v_dama[i].pos);
        }

        // Comprobar si alguna pieza puede comerse a la que está haciendo jaque
        bool flag1 = 0;
        //unsigned long flag2 = 0;
        if (pos_piezas_jaque.size()==1){
        //for (unsigned long k = 0; k <= pos_piezas_jaque.size(); k++){
            for(unsigned long i = 0; i < v_peon.size(); i++){
                if(v_peon[i].jugador == jugador && flag1 == 0){
                    v_peon[i].movs(mi_tab);
                    for(unsigned long j = 0; j < v_peon[i].atq_set.size(); j++){
                        if (v_peon[i].atq_set[j].first == pos_piezas_jaque[0].first && v_peon[i].atq_set[j].second == pos_piezas_jaque[0].second)
                            flag1 = 1;
                    }
                }
            }
            for(unsigned long i = 0; i < v_caballo.size(); i++){
                if(v_caballo[i].jugador == jugador && flag1 == 0){
                    v_caballo[i].movs(mi_tab);
                    for(unsigned long j = 0; j < v_caballo[i].atq_set.size(); j++){
                        if (v_caballo[i].atq_set[j].first == pos_piezas_jaque[0].first && v_caballo[i].atq_set[j].second == pos_piezas_jaque[0].second)
                            flag1 = 1;
                    }
                }
            }
            for(unsigned long i = 0; i < v_alfil.size(); i++){
                if(v_alfil[i].jugador == jugador && flag1 == 0){
                    v_alfil[i].movsA(mi_tab);
                    for(unsigned long j = 0; j < v_alfil[i].atq_set.size(); j++){
                        if (v_alfil[i].atq_set[j].first == pos_piezas_jaque[0].first && v_alfil[i].atq_set[j].second == pos_piezas_jaque[0].second)
                            flag1 = 1;
                    }
                }
            }
            for(unsigned long i = 0; i < v_torre.size(); i++){
                if(v_torre[i].jugador == jugador && flag1 == 0){
                    v_torre[i].movsT(mi_tab);
                    for(unsigned long j = 0; j < v_torre[i].atq_set.size(); j++){
                        if (v_torre[i].atq_set[j].first == pos_piezas_jaque[0].first && v_torre[i].atq_set[j].second == pos_piezas_jaque[0].second)
                            flag1 = 1;
                    }
                }
            }
            for(unsigned long i = 0; i < v_dama.size(); i++){
                if(v_dama[i].jugador == jugador && flag1 == 0){
                    v_dama[i].movs(mi_tab);
                    for(unsigned long j = 0; j < v_dama[i].atq_set.size(); j++){
                        if (v_dama[i].atq_set[j].first == pos_piezas_jaque[0].first && v_dama[i].atq_set[j].second == pos_piezas_jaque[0].second)
                            flag1 = 1;
                    }
                }
            }
            for(unsigned long i = 0; i < v_rey.size(); i++){
                if(v_rey[i].jugador == jugador && flag1 == 0){
                    v_rey[i].movs(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_dama);
                    for(unsigned long j = 0; j < v_rey[i].atq_set.size(); j++){
                        if (v_rey[i].atq_set[j].first == pos_piezas_jaque[0].first && v_rey[i].atq_set[j].second == pos_piezas_jaque[0].second)
                            flag1 = 1;
                    }
                }
            }
            if (flag1 == 1)
                mate = 0;
        };
    };
    // Se comprueba si una pieza puede interponerse entre el rey y la(s) pieza(s) que hace(n) jaque
    if (mate && pos_piezas_jaque.size()==1){ // Si sigue el rey en mate (hipotetico) y solo una pieza le hace jaque
        for(unsigned long i = 0; i < v_alfil.size(); i++){ // Se buscan todos los alfiles enemigos
            if (v_alfil[i].jaque_rey && v_alfil[i].jugador != jugador){ // Se comprueba que el alfil sea enemigo y hace jaque
                v_alfil[i].movsA(mi_tab);
                for(unsigned long j = 0; j < v_peon.size(); j++){ // Se comprueba cual de las piezas (peon) aliadas puede defender
                    v_peon[j].movs(mi_tab);
                    if (v_peon[j].jugador == jugador){ // Se comprueba que la pieza (peon) sea aliada
                        for(unsigned long k = 0; k < v_peon[j].mov_set.size(); k++){ // Se recorre todo el set de movimientos de la pieza aliada
                            for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){ // Y el la trayectoria de la pieza enemiga para hacer jaque
                                if (v_peon[j].mov_set[k].first == v_alfil[i].atq_rey[h].first && v_peon[j].mov_set[k].second == v_alfil[i].atq_rey[h].second){
                                    mate = 0; // Si en algun punto coinciden, se supone que la pieza aliada puede defender al rey
                                }
                            }
                        }
                    }
                };
                for(unsigned long j = 0; j < v_caballo.size(); j++){
                    if (v_caballo[j].jugador == jugador){
                        v_caballo[j].movs(mi_tab);
                        for(unsigned long k = 0; k < v_caballo[j].mov_set.size(); k++){
                            for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                                if (v_caballo[j].mov_set[k].first == v_alfil[i].atq_rey[h].first && v_caballo[j].mov_set[k].second == v_alfil[i].atq_rey[h].second){
                                    mate = 0;
                                }
                            }
                        }
                    }
                };
                for(unsigned long j = 0; j < v_alfil.size(); j++){
                    if (v_alfil[j].jugador == jugador){
                        v_alfil[j].movsA(mi_tab);
                        for(unsigned long k = 0; k < v_alfil[j].mov_set.size(); k++){
                            for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                                if (v_alfil[j].mov_set[k].first == v_alfil[i].atq_rey[h].first && v_alfil[j].mov_set[k].second == v_alfil[i].atq_rey[h].second){
                                    mate = 0;
                                }
                            }
                        }
                    }
                };
                for(unsigned long j = 0; j < v_torre.size(); j++){
                    if (v_torre[j].jugador == jugador){
                        v_torre[j].movsT(mi_tab);
                        for(unsigned long k = 0; k < v_torre[j].mov_set.size(); k++){
                            for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                                if (v_torre[j].mov_set[k].first == v_alfil[i].atq_rey[h].first && v_torre[j].mov_set[k].second == v_alfil[i].atq_rey[h].second){
                                    mate = 0;
                                }
                            }
                        }
                    }
                };
                for(unsigned long j = 0; j < v_dama.size(); j++){
                    if (v_dama[j].jugador == jugador){
                        v_dama[j].movs(mi_tab);
                        for(unsigned long k = 0; k < v_dama[j].mov_set.size(); k++){
                            for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                                if (v_dama[j].mov_set[k].first == v_alfil[i].atq_rey[h].first && v_dama[j].mov_set[k].second == v_alfil[i].atq_rey[h].second){
                                    mate = 0;
                                }
                            }
                        }
                    }
                };
            }
        }
    };
    for(unsigned long i = 0; i < v_torre.size(); i++){
        if (v_torre[i].jaque_rey && v_torre[i].jugador != jugador){
            v_torre[i].movsT(mi_tab);
            for(unsigned long j = 0; j < v_peon.size(); j++){
                if (v_peon[j].jugador == jugador){
                    v_peon[j].movs(mi_tab);
                    for(unsigned long k = 0; k < v_peon[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_torre[i].atq_rey.size(); h++){
                            if (v_peon[j].mov_set[k].first == v_torre[i].atq_rey[h].first && v_peon[j].mov_set[k].second == v_torre[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_caballo.size(); j++){
                if (v_caballo[j].jugador == jugador){
                    v_caballo[j].movs(mi_tab);
                    for(unsigned long k = 0; k < v_caballo[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_torre[i].atq_rey.size(); h++){
                            if (v_caballo[j].mov_set[k].first == v_torre[i].atq_rey[h].first && v_caballo[j].mov_set[k].second == v_torre[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_alfil.size(); j++){
                v_alfil[j].movsA(mi_tab);
                if (v_alfil[j].jugador == jugador){
                    for(unsigned long k = 0; k < v_alfil[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_torre[i].atq_rey.size(); h++){
                            if (v_alfil[j].mov_set[k].first == v_torre[i].atq_rey[h].first && v_alfil[j].mov_set[k].second == v_torre[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_torre.size(); j++){
                if (v_torre[j].jugador == jugador){
                    v_torre[j].movsT(mi_tab);
                    for(unsigned long k = 0; k < v_torre[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_torre[i].atq_rey.size(); h++){
                            if (v_torre[j].mov_set[k].first == v_torre[i].atq_rey[h].first && v_torre[j].mov_set[k].second == v_torre[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_dama.size(); j++){
                if (v_dama[j].jugador == jugador){
                    v_dama[j].movs(mi_tab);
                    for(unsigned long k = 0; k < v_dama[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                            if (v_dama[j].mov_set[k].first == v_torre[i].atq_rey[h].first && v_dama[j].mov_set[k].second == v_torre[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
        }
    };
    for(unsigned long i = 0; i < v_dama.size(); i++){
        if (v_dama[i].jaque_rey && v_dama[i].jugador != jugador){
            v_dama[i].movs(mi_tab);
            for(unsigned long j = 0; j < v_peon.size(); j++){
                if (v_peon[j].jugador == jugador){
                    v_peon[j].movs(mi_tab);
                    for(unsigned long k = 0; k < v_peon[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_dama[i].atq_rey.size(); h++){
                            if (v_peon[j].mov_set[k].first == v_dama[i].atq_rey[h].first && v_peon[j].mov_set[k].second == v_dama[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_caballo.size(); j++){
                if (v_caballo[j].jugador == jugador){
                    v_caballo[j].movs(mi_tab);
                    for(unsigned long k = 0; k < v_caballo[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                            if (v_caballo[j].mov_set[k].first == v_dama[i].atq_rey[h].first && v_caballo[j].mov_set[k].second == v_dama[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_alfil.size(); j++){
                if (v_alfil[j].jugador == jugador){
                    v_alfil[j].movsA(mi_tab);
                    for(unsigned long k = 0; k < v_alfil[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_dama[i].atq_rey.size(); h++){
                            if (v_alfil[j].mov_set[k].first == v_dama[i].atq_rey[h].first && v_alfil[j].mov_set[k].second == v_dama[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_torre.size(); j++){
                if (v_torre[j].jugador == jugador){
                    v_torre[j].movsT(mi_tab);
                    for(unsigned long k = 0; k < v_torre[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_dama[i].atq_rey.size(); h++){
                            if (v_torre[j].mov_set[k].first == v_dama[i].atq_rey[h].first && v_torre[j].mov_set[k].second == v_dama[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
            for(unsigned long j = 0; j < v_dama.size(); j++){
                if (v_dama[j].jugador == jugador){
                    v_dama[j].movs(mi_tab);
                    for(unsigned long k = 0; k < v_dama[j].mov_set.size(); k++){
                        for(unsigned long h = 0; h < v_alfil[i].atq_rey.size(); h++){
                            if (v_dama[j].mov_set[k].first == v_dama[i].atq_rey[h].first && v_dama[j].mov_set[k].second == v_dama[i].atq_rey[h].second){
                                mate = 0;
                            }
                        }
                    }
                }
            };
        }
    };
};

