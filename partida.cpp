#include "partida.h"

partida::partida(){

}

partida::~partida(){

};

vector<vector<bool>> comprobar_mov_escaque(tablero mi_tab, int jug, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey){
    vector<vector<bool>> tablero_libre(8);
    for(unsigned long i = 0; i < 8; i++) tablero_libre[i].resize(8, 1);
    for (unsigned long  i = 0; i <= v_peon.size() ; i++){
        if (v_peon[i].jugador != jug){
            v_peon[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_peon[i].mov_set.size(); j++){
                if (comprobar_limites(v_peon[i].mov_set[j].first+1, v_peon[i].mov_set[j].second))
                    tablero_libre[v_peon[i].mov_set[j].first+1][v_peon[i].mov_set[j].second] = 0;
                if (comprobar_limites(v_peon[i].mov_set[j].first-1, v_peon[i].mov_set[j].second))
                    tablero_libre[v_peon[i].mov_set[j].first-1][v_peon[i].mov_set[j].second] = 0;
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
