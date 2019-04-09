#include "funciones.h"
#include <iostream>
#include <vector>
#include "piezas.h"

// ===================== Funciones adicionales ========================== //
// Comprobar si el escaque referenciado está dentro de los límites del tablero
bool comprobar_limites(int col, int fil){
    bool flag = 1;
    if (col<1 || col>8 || fil<1 || fil>8)
        flag = 0;
    return flag;
};

// Comprobar si la casilla elegida está amenazada
bool comprobar_amenaza(tablero mi_tab, int jug, int columna, int fila, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey){
    bool flag = 0;
    for (unsigned long  i = 0; i <= v_peon.size() ; i++){
        if (v_peon[i].jugador != jug){
            v_peon[i].movs(mi_tab);
            for (unsigned long j = 0; j <= v_peon[i].atq_set.size(); j++){
                if (columna == v_peon[i].atq_set[j].first && fila == v_peon[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jug){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].atq_set.size(); j++){
                if (columna == v_caballo[i].atq_set[j].first && fila == v_caballo[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jug){
            v_alfil[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].atq_set.size(); j++){
                if (columna == v_alfil[i].atq_set[j].first && fila == v_alfil[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_torre.size() ; i++){
        if (v_torre[i].jugador != jug){
            v_torre[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].atq_set.size(); j++){
                if (columna == v_torre[i].atq_set[j].first && fila == v_torre[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_rey.size() ; i++){
        if (v_rey[i].jugador != jug){
            v_rey[i].movs(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_rey);
            for (unsigned long j = 0; j < v_rey[i].atq_set.size(); j++){
                if (columna == v_rey[i].atq_set[j].first && fila == v_rey[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    return flag;
};
