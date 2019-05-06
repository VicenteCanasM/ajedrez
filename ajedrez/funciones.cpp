#include "funciones.h"
#include <iostream>
#include <vector>
#include "piezas.h"

// ===================== Funciones adicionales ========================== //
// Comprobar si el escaque referenciado está dentro de los límites del tablero
bool comprobar_limites(int col, int fil){
    bool flag = 1;
    if (col<0 || col>7 || fil<0 || fil>7) flag = 0;
    return flag;
};

// Comprobar si la casilla elegida está amenazada
bool comprobar_amenaza(tablero mi_tab, int jug, int columna, int fila, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<rey> v_rey, vector<dama> v_dama){
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
    for (unsigned long  i = 0; i <= v_dama.size() ; i++){
        if (v_dama[i].jugador != jug){
            v_dama[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_dama[i].atq_set.size(); j++){
                if (columna == v_dama[i].atq_set[j].first && fila == v_dama[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i <= v_rey.size() ; i++){
        if (v_rey[i].jugador != jug){
            v_rey[i].movs(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_rey, v_dama);
            for (unsigned long j = 0; j < v_rey[i].atq_set.size(); j++){
                if (columna == v_rey[i].atq_set[j].first && fila == v_rey[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    return flag;
};

// Realización del movimiento
void movimiento(tablero mi_tab, QIcon icono, QIcon nada, QPushButton b_origen, QPushButton b_destino, pair<int,int> pos_o, pair<int,int> pos_d){
    // Modificación de iconos
    b_destino.setIcon(icono);
    b_origen.setIcon(nada);
    mi_tab.mat_escaque[pos_d.first][pos_d.second].ocupado = mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado;
    mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado = 2;

    // Modificación de piezas

};
// Devolver path del icono necesario
QString nuevo_icono(int ind){
    QString icono;
    if (ind == 0){
        icono = "";
    }
    else if (ind == 1) {
        icono = "pieces/merida_new/wp.svg";
    }
    else if (ind == 2) {
        icono = "pieces/merida_new/wn.svg";
    }
    else if (ind == 3) {
        icono = "pieces/merida_new/wb.svg";
    }
    else if (ind == 4) {
        icono = "pieces/merida_new/wr.svg";
    }
    else if (ind == 5) {
        icono = "pieces/merida_new/wq.svg";
    }
    else if (ind == 6) {
        icono = "pieces/merida_new/wk.svg";
    }
    else if (ind == 7) {
        icono = "pieces/merida_new/bp.svg";
    }
    else if (ind == 8) {
        icono = "pieces/merida_new/bn.svg";
    }
    else if (ind == 9) {
        icono = "pieces/merida_new/bb.svg";
    }
    else if (ind == 10) {
        icono = "pieces/merida_new/br.svg";
    }
    else if (ind == 11) {
        icono = "pieces/merida_new/bq.svg";
    }
    else if (ind == 12) {
        icono = "pieces/merida_new/bk.svg";
    }
    return icono;
};
