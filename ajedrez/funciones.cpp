#include "funciones.h"

void mueve_icono(tablero *echiquier, QPushButton *boton_destino, pair<int,int> origen,
                  pair<int,int> destino, vector<QIcon> iconos){
    echiquier->mat_escaque[destino.first][destino.second].t_icon = echiquier->mat_escaque[origen.first][origen.second].t_icon;
    echiquier->mat_escaque[origen.first][origen.second].t_icon = 0;
    echiquier -> mat_escaque[destino.first][destino.second].ocupado = echiquier -> mat_escaque[origen.first][origen.second].ocupado;
    echiquier -> mat_escaque[origen.first][origen.second].ocupado = 2;
    boton_destino -> setIcon(iconos.at(echiquier->mat_escaque[destino.first][destino.second].t_icon));
}

void limpia_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco, QPalette negro){
    for (unsigned int i = 0; i < 8 ; i++){
        for (unsigned int j = 0; j < 8; j++){
            botones[i][j] -> setAutoFillBackground(true);
            if (echiquier.mat_escaque[i][j].color == 0) botones[i][j] -> setPalette(blanco);
            else botones[i][j] -> setPalette(negro);
            botones[i][j] -> update();
        }
    }
}

void colorea_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco,
                     QPalette negro, vector <pair <int,int>> pos){
    for (unsigned int i = 0; i < pos.size(); i++){
        if (echiquier.mat_escaque[pos[i].first][pos[i].second].color == 0) botones[pos[i].first][pos[i].second] -> setPalette(blanco);
        else botones[pos[i].first][pos[i].second] -> setPalette(negro);
        botones[pos[i].first][pos[i].second] -> update();
    }
}


pair <int, int> obten_pos(QString pos){
    QChar a = 'a';
    QChar uno = '1';
    int i = pos[0].unicode() - a.unicode();
    int j = pos[1].unicode() - uno.unicode();
    return pair<int, int> (i,j);
}

// ===================== Funciones adicionales ========================== //
// Comprobar si el escaque referenciado está dentro de los límites del tablero
bool comprobar_limites(int col, int fil){
    bool flag = 1;
    if (col<0 || col>7 || fil<0 || fil>7) flag = 0;
    return flag;
};

// Comprobar si la casilla elegida está amenazada
bool comprobar_amenaza(tablero mi_tab, int jug, int columna, int fila, vector<peon> v_peon, vector<caballo> v_caballo, vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama){
    bool flag = 0;
    for (unsigned long  i = 0; i < v_peon.size() ; i++){
        if (v_peon[i].jugador != jug){
            v_peon[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_peon[i].atq_set.size(); j++){
                if (columna == v_peon[i].atq_set[j].first && fila == v_peon[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jug){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].atq_set.size(); j++){
                if (columna == v_caballo[i].atq_set[j].first && fila == v_caballo[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jug){
            v_alfil[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].atq_set.size(); j++){
                if (columna == v_alfil[i].atq_set[j].first && fila == v_alfil[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_torre.size() ; i++){
        if (v_torre[i].jugador != jug){
            v_torre[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].atq_set.size(); j++){
                if (columna == v_torre[i].atq_set[j].first && fila == v_torre[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_dama.size() ; i++){
        if (v_dama[i].jugador != jug){
            v_dama[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_dama[i].atq_set.size(); j++){
                if (columna == v_dama[i].atq_set[j].first && fila == v_dama[i].atq_set[j].second)
                    flag = 1;
            };
        };
    };
    return flag;
};


