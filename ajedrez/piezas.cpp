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

void mover(){
}


/* ============================== PEON ============================== */
// Constructor
peon::peon(int col, int fil, int jug) : piezas(col, fil, jug){
    first_mov = 1;
    valor = 1;
    jaque_rey = 0;
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
    pair<int,int> casilla;
    if (jugador == 0){ // Si juegan blancas
        if (comprobar_limites(pos.first, pos.second+1)){
            if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act+1)].ocupado == 2){ // Comprobar escaque inmediato
                casilla.first = col_act;
                casilla.second = fil_act+1;
                mov_set.push_back(casilla);
                if (comprobar_limites(pos.first, pos.second+2)){
                    if (first_mov == 1 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act+2)].ocupado == 2){ // Comprobar segundo escaque si es primer movimiento
                        casilla.first = col_act;
                        casilla.second = fil_act+2;
                        mov_set.push_back(casilla);
                    };
                };
            };
            if (comprobar_limites(pos.first+1, pos.second+1)){
                casilla.first = col_act+1;
                casilla.second = fil_act+1;
                escaque_def.push_back(casilla);
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act+1)].ocupado == 1){ // Ataque a diagonal derecha
                    atq_set.push_back(casilla);
                };
            };
            if (comprobar_limites(pos.first-1, pos.second+1)){
                casilla.first = col_act-1;
                casilla.second = fil_act+1;
                escaque_def.push_back(casilla);
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act+1)].ocupado == 1){ // Ataque a diagonal izquierda
                    atq_set.push_back(casilla);
                };
            };
        };
    }
    else if (jugador == 1){ // Si juegan negras
        if (comprobar_limites(pos.first, pos.second-1)){
            if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act-1)].ocupado == 2){ // Comprobar escaque inmediato
                casilla.first = col_act;
                casilla.second = fil_act-1;
                mov_set.push_back(casilla);
                if (comprobar_limites(pos.first, pos.second-2)){
                    if (first_mov == 1 && mi_tab.mat_escaque[static_cast<unsigned long>(col_act)][static_cast<unsigned long>(fil_act-2)].ocupado == 2){ // Comprobar segundo escaque si es primer movimiento
                        casilla.first = col_act;
                        casilla.second = fil_act-2;
                        mov_set.push_back(casilla);
                    };
                };
            };
            if (comprobar_limites(pos.first+1, pos.second-1)){
                casilla.first = col_act+1;
                casilla.second = fil_act-1;
                escaque_def.push_back(casilla);
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act+1)][static_cast<unsigned long>(fil_act-1)].ocupado == 1){ // Ataque a diagonal derecha
                    atq_set.push_back(casilla);
                };
            };
            if (comprobar_limites(pos.first-1, pos.second-1)){
                casilla.first = col_act-1;
                casilla.second = fil_act-1;
                escaque_def.push_back(casilla);
                if (mi_tab.mat_escaque[static_cast<unsigned long>(col_act-1)][static_cast<unsigned long>(fil_act-1)].ocupado == 1){ // Ataque a diagonal izquierda
                    atq_set.push_back(casilla);
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
    escaques_ady[0].first = 2;  escaques_ady[0].second = 1;   escaques_ady[1].first = 1;  escaques_ady[1].second = 2;
    escaques_ady[2].first = -1;  escaques_ady[2].second = 2;  escaques_ady[3].first = -2;  escaques_ady[3].second = 1;
    escaques_ady[4].first = -2;  escaques_ady[4].second = -1;  escaques_ady[5].first = -1;  escaques_ady[5].second = -2;
    escaques_ady[6].first = 1;  escaques_ady[6].second = -2;   escaques_ady[7].first = 2;  escaques_ady[7].second = -1;
    for (unsigned long i = 0; i <= escaques_ady.size(); i++){
        if (comprobar_limites(col_act+escaques_ady[i].first, fil_act+escaques_ady[i].second)){
            casilla.first = col_act+escaques_ady[i].first;
            casilla.second = fil_act+escaques_ady[i].second;
            escaque_def.push_back(casilla); // Zona de influencia
            if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado == 2){ //Comprobar escaque superior derecha 1
                mov_set.push_back(casilla);
            }
            else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado != jugador){ // Posible ataque
                atq_set.push_back(casilla);
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
void alfil::movs(tablero mi_tab){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    jaque_rey;
    pair<int,int> casilla;
    int c = 1;
    bool n = 1;
    vector<pair<int,int>> escaques_ady;
    escaques_ady[0].first = 1;  escaques_ady[0].second = 1;    escaques_ady[1].first = -1;  escaques_ady[1].second = 1;
    escaques_ady[2].first = -1;  escaques_ady[2].second = -1;  escaques_ady[3].first = 1;  escaques_ady[3].second = -1;
    for (unsigned long i = 0; i <= escaques_ady.size(); i++){
        while (n==1){ // Comprobar escaque en vertical superior
            if (comprobar_limites(col_act+escaques_ady[i].first*c, fil_act+escaques_ady[i].first*c)){
                casilla.first = col_act+escaques_ady[i].first*c;
                casilla.second = fil_act+escaques_ady[i].second*c;
                escaque_def.push_back(casilla); // Zona de influencia
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == 2){ // Posible avance
                    mov_set.push_back(casilla);
                    c+=c;
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado != jugador){ // Posible ataque
                    atq_set.push_back(casilla);
                    n = 0;
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
void torre::movs(tablero mi_tab){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    escaque_def.clear();
    jaque_rey = 0;
    pair<int,int> casilla;
    int c = 1;
    bool n = 1;
    vector<pair<int,int>> escaques_ady;
    escaques_ady[0].first = 0;  escaques_ady[0].second = 1;   escaques_ady[1].first = 0;  escaques_ady[1].second = -1;
    escaques_ady[2].first = 1;  escaques_ady[2].second = 0;  escaques_ady[3].first = -1;  escaques_ady[3].second = 0;
    for (unsigned long i = 0; i <= escaques_ady.size(); i++){
        while (n==1){ // Comprobar escaque en vertical superior
            if (comprobar_limites(col_act+escaques_ady[i].first*c, fil_act+escaques_ady[i].first*c)){
                casilla.first = col_act+escaques_ady[i].first*c;
                casilla.second = fil_act+escaques_ady[i].second*c;
                escaque_def.push_back(casilla); // Zona de influencia
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado == 2){ // Posible avance
                    mov_set.push_back(casilla);
                    c+=c;
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first*c][fil_act+escaques_ady[i].second*c].ocupado != jugador){ // Posible ataque
                    atq_set.push_back(casilla);
                    n = 0;
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
    };
};

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
vector<vector<bool>> rey::comprobar_mov_rey(tablero mi_tab, int jug, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey){
    vector<vector<bool>> tablero_libre(8);
    for(unsigned long i = 0; i < 8; i++) tablero_libre[i].resize(8, 1);
    for (unsigned long  i = 0; i <= v_peon.size() ; i++){
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
    for (unsigned long  i = 0; i <= v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jug){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].mov_set.size(); j++){
                tablero_libre[v_caballo[i].mov_set[j].first][v_caballo[i].mov_set[j].second] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jug){
            v_alfil[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].mov_set.size(); j++){
                tablero_libre[v_alfil[i].mov_set[j].first][v_alfil[i].mov_set[j].second] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_torre.size() ; i++){
        if (v_torre[i].jugador != jug){
            v_torre[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].mov_set.size(); j++){
                tablero_libre[v_torre[i].mov_set[j].first][v_torre[i].mov_set[j].second] = 0;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_rey.size() ; i++){
        if (v_rey[i].jugador != jug){
            v_rey[i].movs(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_rey);
            for (unsigned long j = 0; j < v_rey[i].mov_set.size(); j++){
                tablero_libre[v_rey[i].mov_set[j].first][v_rey[i].mov_set[j].second] = 0;
            };
        };
    };
    return tablero_libre;
};
// Comprobar movimientos posibles
void rey::movs(tablero mi_tab, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey){
    int col_act = pos.first;
    int fil_act = pos.second;
    mov_set.clear();
    atq_set.clear();
    pair<int,int> casilla;
    vector<pair<int,int>> escaques_ady;
    escaques_ady[0].first = 0;  escaques_ady[0].second = 1;   escaques_ady[1].first = -1;  escaques_ady[1].second = 1;
    escaques_ady[2].first = -1;  escaques_ady[2].second = 0;  escaques_ady[3].first = -1;  escaques_ady[3].second = -1;
    escaques_ady[4].first = 0;  escaques_ady[4].second = -1;  escaques_ady[5].first = 1;  escaques_ady[5].second = -1;
    escaques_ady[6].first = 1;  escaques_ady[6].second = 0;   escaques_ady[7].first = 1;  escaques_ady[7].second = 1;
    vector<vector<bool>> escaques_libres = this->comprobar_mov_rey(mi_tab, this->jugador, v_peon, v_caballo, v_alfil, v_torre, v_rey);
    for (unsigned long i = 0; i <= escaques_ady.size(); i++){
        if (comprobar_limites(col_act+escaques_ady[i].first, fil_act+escaques_ady[i].second)){  //Comprobar escaque superior
            if (escaques_libres[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second]){
                casilla.first = col_act+escaques_ady[i].first;
                casilla.second = fil_act+escaques_ady[i].second;
                escaque_def.push_back(casilla);
                if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado == 2){
                    mov_set.push_back(casilla);
                }
                else if (mi_tab.mat_escaque[col_act+escaques_ady[i].first][fil_act+escaques_ady[i].second].ocupado != jugador){ // Posible ataque
                    atq_set.push_back(casilla);
                };
            };
        };
    };
    pair<bool,bool> habilitar_enroque = comprobar_enroque(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_rey); // Enroques habilitados
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
void rey::comprobar_jaque_rey(tablero mi_tab, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre){
    jaque = 0;
    for (unsigned long  i = 0; i <= v_peon.size() ; i++){
        if (v_peon[i].jugador != jugador){
            v_peon[i].movs(mi_tab);
            for (unsigned long j = 0; j <= v_peon[i].atq_set.size(); j++){
                if (pos.first == v_peon[i].atq_set[j].first && pos.second == v_peon[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jugador){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].atq_set.size(); j++){
                if (pos.first == v_caballo[i].atq_set[j].first && pos.second == v_caballo[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jugador){
            v_alfil[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].atq_set.size(); j++){
                if (pos.first == v_alfil[i].atq_set[j].first && pos.second == v_alfil[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_torre.size() ; i++){
        if (v_torre[i].jugador != jugador){
            v_torre[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].atq_set.size(); j++){
                if (pos.first == v_torre[i].atq_set[j].first && pos.second == v_torre[i].atq_set[j].second)
                    jaque = 1;
            };
        };
    };
};
// Comprobar enroque
pair<bool,bool> rey::comprobar_enroque(tablero mi_tab,  vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey){
    pair <bool,bool> habilitar_enroque(0,0);
    if (first_mov && jaque == 0){
        bool escaque1, escaque2;
        for (unsigned long i = 0; i <= v_torre.size(); i++){ // Busqueda de torres
            if (v_torre[i].jugador == jugador && v_torre[i].pos.first == 8){
                escaque1 = comprobar_amenaza(mi_tab, jugador, pos.first+1, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_rey);
                escaque2 = comprobar_amenaza(mi_tab, jugador, pos.first+2, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_rey);
                if (v_torre[i].first_mov == 1 && escaque1 && escaque2 && mi_tab.mat_escaque[pos.first+1][pos.second].ocupado == 2 && mi_tab.mat_escaque[pos.first+2][pos.second].ocupado == 2){
                    habilitar_enroque.second = 1; // Torre en hx (derecha desde blancos)
                };
            };
            if (v_torre[i].jugador == jugador && v_torre[i].pos.first == 1){
                escaque1 = comprobar_amenaza(mi_tab, jugador, pos.first-1, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_rey);
                escaque2 = comprobar_amenaza(mi_tab, jugador, pos.first-2, pos.second, v_peon, v_caballo, v_alfil, v_torre, v_rey);
                if (v_torre[i].first_mov == 1 && !escaque1 && !escaque2 && mi_tab.mat_escaque[pos.first-1][pos.second].ocupado == 2 && mi_tab.mat_escaque[pos.first-2][pos.second].ocupado == 2 && mi_tab.mat_escaque[pos.first-3][pos.second].ocupado == 2){
                    habilitar_enroque.first = 1; // Torre en ax (izquierda desde blancos)
                };
            };
        };
    };
    return habilitar_enroque;
};
// Comprobar mate
void rey::comprobar_mate_rey(tablero mi_tab, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey){
    mate = 1;
    vector<pair<int,int>> escaques_ady;
    escaques_ady[0].first = 0;  escaques_ady[0].second = 1;   escaques_ady[1].first = -1;  escaques_ady[1].second = 1;
    escaques_ady[2].first = -1;  escaques_ady[2].second = 0;  escaques_ady[3].first = -1;  escaques_ady[3].second = -1;
    escaques_ady[4].first = 0;  escaques_ady[4].second = -1;  escaques_ady[5].first = 1;  escaques_ady[5].second = -1;
    escaques_ady[6].first = 1;  escaques_ady[6].second = 0;   escaques_ady[7].first = 1;  escaques_ady[7].second = 1;
    for (unsigned long i = 0; i <= escaques_ady.size(); i++){ // Se comprueba si el rey se puede salvar moviéndose
        if (mate)
            mate = comprobar_amenaza(mi_tab, jugador, pos.first+escaques_ady[i].first, pos.second+escaques_ady[i].second, v_peon, v_caballo, v_alfil, v_torre, v_rey);
    };



};

