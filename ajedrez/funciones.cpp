#include "funciones.h"

// ===================== Funciones adicionales ========================== //
// Modifica los iconos y atributo 'ocupado' de los escaques
void mueve_icono(tablero *echiquier, QPushButton *boton_destino, pair<int,int> origen,
                  pair<int,int> destino, vector<QIcon> iconos){
    echiquier->mat_escaque[destino.first][destino.second].t_icon = echiquier->mat_escaque[origen.first][origen.second].t_icon;
    echiquier->mat_escaque[origen.first][origen.second].t_icon = 0;
    echiquier -> mat_escaque[destino.first][destino.second].ocupado = echiquier -> mat_escaque[origen.first][origen.second].ocupado;
    echiquier -> mat_escaque[origen.first][origen.second].ocupado = 2;
    boton_destino -> setIcon(iconos.at(echiquier->mat_escaque[destino.first][destino.second].t_icon));
}

// Modifica los iconos y escaques con el botón deshacer
void mueve_icono_desh(tablero *echiquier, QPushButton *boton_origen, QPushButton *boton_destino, pair<int,int> origen,
                  pair<int,int> destino, vector<QIcon> iconos, int id_icono_cap){
    // Resitaución de iconos
    echiquier->mat_escaque[origen.first][origen.second].t_icon = echiquier->mat_escaque[destino.first][destino.second].t_icon;
    echiquier->mat_escaque[destino.first][destino.second].t_icon = id_icono_cap;
    // Actualización de escaques
    echiquier -> mat_escaque[origen.first][origen.second].ocupado = echiquier -> mat_escaque[destino.first][destino.second].ocupado;
    if (id_icono_cap == 0) echiquier -> mat_escaque[destino.first][destino.second].ocupado = 2;
    else if (echiquier->mat_escaque[origen.first][origen.second].ocupado == 0) echiquier -> mat_escaque[destino.first][destino.second].ocupado = 1;
    else echiquier -> mat_escaque[destino.first][destino.second].ocupado = 0;
    // Actualización de iconos
    boton_origen -> setIcon(iconos.at(echiquier->mat_escaque[origen.first][origen.second].t_icon));
    boton_destino -> setIcon(iconos.at(echiquier->mat_escaque[destino.first][destino.second].t_icon));
}

// Devuelve al tablero sus colores originales
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

// Colorear tablero
void colorea_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco,
                     QPalette negro, vector <pair <int,int>> pos){
    for (unsigned int i = 0; i < pos.size(); i++){
        if (echiquier.mat_escaque[pos[i].first][pos[i].second].color == 0) botones[pos[i].first][pos[i].second] -> setPalette(blanco);
        else botones[pos[i].first][pos[i].second] -> setPalette(negro);
        botones[pos[i].first][pos[i].second] -> update();
    }
}

// Obtiene la posición del botón según su nombre
pair <int, int> obten_pos(QString pos){
    QChar a = 'a';
    QChar uno = '1';
    int i = pos[0].unicode() - a.unicode();
    int j = pos[1].unicode() - uno.unicode();
    return pair<int, int> (i,j);
}

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
            int col_act = v_peon[i].pos.first;
            int fil_act = v_peon[i].pos.second;
            if (v_peon[i].jugador == 0){
                if (comprobar_limites(col_act+1, fil_act+1))
                    if(columna == col_act+1 && fila == fil_act+1)
                        flag = 1;
                if (comprobar_limites(col_act-1, fil_act+1))
                    if(columna == col_act-1 && fila == fil_act+1)
                        flag = 1;
            };
            if (v_peon[i].jugador == 1){
                if (comprobar_limites(col_act+1, fil_act-1))
                    if(columna == col_act+1 && fila == fil_act-1)
                        flag = 1;
                if (comprobar_limites(col_act-1, fil_act-1))
                    if(columna == col_act-1 && fila == fil_act-1)
                        flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_caballo.size() ; i++){
        if (v_caballo[i].jugador != jug){
            v_caballo[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_caballo[i].escaque_def.size(); j++){
                if (columna == v_caballo[i].escaque_def[j].first && fila == v_caballo[i].escaque_def[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_alfil.size() ; i++){
        if (v_alfil[i].jugador != jug){
            v_alfil[i].movsA(mi_tab);
            for (unsigned long j = 0; j < v_alfil[i].escaque_def.size(); j++){
                if (columna == v_alfil[i].escaque_def[j].first && fila == v_alfil[i].escaque_def[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_torre.size() ; i++){
        if (v_torre[i].jugador != jug){
            v_torre[i].movsT(mi_tab);
            for (unsigned long j = 0; j < v_torre[i].escaque_def.size(); j++){
                if (columna == v_torre[i].escaque_def[j].first && fila == v_torre[i].escaque_def[j].second)
                    flag = 1;
            };
        };
    };
    for (unsigned long  i = 0; i < v_dama.size() ; i++){
        if (v_dama[i].jugador != jug){
            v_dama[i].movs(mi_tab);
            for (unsigned long j = 0; j < v_dama[i].escaque_def.size(); j++){
                if (columna == v_dama[i].escaque_def[j].first && fila == v_dama[i].escaque_def[j].second)
                    flag = 1;
            };
        };
    };
    return flag; // 1 -> escaque amenazado; 0 -> escaque no amenazado
};

// Comprueba si la pieza está clavada o si puede para el jaque a su rey
bool movimiento_jaque(tablero mi_tab, pair<int,int> pos_o, pair<int,int> pos_d, vector<peon> v_peon, vector<caballo> v_caballo,
                      vector<alfil> v_alfil, vector<torre> v_torre, vector<dama> v_dama, vector<rey> v_rey){
    // Esta funcion ya sabe que en la casilla origen hay una pieza aliada, y que la casilla destino puede estar vacia (mov_set)
    // u ocupada por una pieza enemiga (atq_set). Permite comprobar ambos vectores de movimientos, pero por separado
    bool flag = 1;
    int jugador_turno = 2;
    // Se busca la pieza que se quiere mover y se comprueba si la posición destino es posible en caso de que el rey esté en jaque
    for (unsigned int i = 0; i < v_peon.size(); i++){
        // Se situa la pieza en la casilla hipotetica donde va a ir
        if (v_peon[i].pos.first == pos_o.first && v_peon[i].pos.second == pos_o.second){
            v_peon[i].pos.first = pos_d.first;
            v_peon[i].pos.second = pos_d.second;
            mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado = 2;
            mi_tab.mat_escaque[pos_d.first][pos_d.second].ocupado = v_peon[i].jugador;
            jugador_turno = v_peon[i].jugador;
        }
        // Si esa casilla destino esta ocupada por una enemiga, este se elimina y deja de hacer jaque
        if (v_peon[i].pos.first == pos_d.first && v_peon[i].pos.second == pos_d.second){
            v_peon[i].pos.first = -1;
            v_peon[i].pos.second = 20;
            v_peon[i].jaque_rey = 0;
        }
    }
    for (unsigned int i = 0; i < v_alfil.size(); i++){
        if (v_alfil[i].pos.first == pos_o.first && v_alfil[i].pos.second == pos_o.second){
            v_alfil[i].pos.first = pos_d.first;
            v_alfil[i].pos.second = pos_d.second;
            mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado = 2;
            mi_tab.mat_escaque[pos_d.first][pos_d.second].ocupado = v_alfil[i].jugador;
            jugador_turno = v_alfil[i].jugador;
        }
        if (v_alfil[i].pos.first == pos_d.first && v_alfil[i].pos.second == pos_d.second){
            v_alfil[i].pos.first = -1;
            v_alfil[i].pos.second = 20;
            v_alfil[i].jaque_rey = 0;
        }
    }
    for (unsigned int i = 0; i < v_caballo.size(); i++){
        if (v_caballo[i].pos.first == pos_o.first && v_caballo[i].pos.second == pos_o.second){
            v_caballo[i].pos.first = pos_d.first;
            v_caballo[i].pos.second = pos_d.second;
            mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado = 2;
            mi_tab.mat_escaque[pos_d.first][pos_d.second].ocupado = v_caballo[i].jugador;
            jugador_turno = v_caballo[i].jugador;
        }
        if (v_caballo[i].pos.first == pos_d.first && v_caballo[i].pos.second == pos_d.second){
            v_caballo[i].pos.first = -1;
            v_caballo[i].pos.second = 20;
            v_caballo[i].jaque_rey = 0;
        }
    }
    for (unsigned int i = 0; i < v_torre.size(); i++){
        if (v_torre[i].pos.first == pos_o.first && v_torre[i].pos.second == pos_o.second){
            v_torre[i].pos.first = pos_d.first;
            v_torre[i].pos.second = pos_d.second;
            mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado = 2;
            mi_tab.mat_escaque[pos_d.first][pos_d.second].ocupado = v_torre[i].jugador;
            jugador_turno = v_torre[i].jugador;
        }
        if (v_torre[i].pos.first == pos_d.first && v_torre[i].pos.second == pos_d.second){
            v_torre[i].pos.first = -1;
            v_torre[i].pos.second = 20;
            v_torre[i].jaque_rey = 0;
        }
    }
    for (unsigned int i = 0; i < v_dama.size(); i++){
        if (v_dama[i].pos.first == pos_o.first && v_dama[i].pos.second == pos_o.second){
            v_dama[i].pos.first = pos_d.first;
            v_dama[i].pos.second = pos_d.second;
            mi_tab.mat_escaque[pos_o.first][pos_o.second].ocupado = 2;
            mi_tab.mat_escaque[pos_d.first][pos_d.second].ocupado = v_dama[i].jugador;
            jugador_turno = v_dama[i].jugador;
        }
        if (v_dama[i].pos.first == pos_d.first && v_dama[i].pos.second == pos_d.second){
            v_dama[i].pos.first = -1;
            v_dama[i].pos.second = 20;
            v_dama[i].jaque_rey = 0;
        }
    }
    // Se comprueba si al mover la pieza el rey ya no está en jaque
    for (unsigned int i = 0; i < v_rey.size(); i++){
        if (v_rey[i].jugador == jugador_turno){
            v_rey[i].comprobar_jaque_rey(mi_tab, v_peon, v_caballo, v_alfil, v_torre, v_dama);
            if (v_rey[i].jaque == 1){
                flag = 0;
            }
        }
    }
    // flag = 1 -> movimiento posible;  flag = 0 -> movimiento rechazado (bien pieza clavada, bien no se defiende al rey)
    return flag;
}

// Generar string del movimiento realizado en notación algebraica
QString notacion_algebraica(vector<pair<int,int>> registro, QString pieza, bool captura){
    QString resultado = pieza;

    if (captura) resultado = resultado + "x";

    if  (registro[1].first == 0) resultado = resultado + "a";
    else if (registro[1].first == 1) resultado = resultado + "b";
    else if (registro[1].first == 2) resultado = resultado + "c";
    else if (registro[1].first == 3) resultado = resultado + "d";
    else if (registro[1].first == 4) resultado = resultado + "e";
    else if (registro[1].first == 5) resultado = resultado + "f";
    else if (registro[1].first == 6) resultado = resultado + "g";
    else if (registro[1].first == 7) resultado = resultado + "h";

    if  (registro[1].second == 0) resultado = resultado + "1";
    else if (registro[1].second == 1) resultado = resultado + "2";
    else if (registro[1].second == 2) resultado = resultado + "3";
    else if (registro[1].second == 3) resultado = resultado + "4";
    else if (registro[1].second == 4) resultado = resultado + "5";
    else if (registro[1].second == 5) resultado = resultado + "6";
    else if (registro[1].second == 6) resultado = resultado + "7";
    else if (registro[1].second == 7) resultado = resultado + "8";

    return resultado;
}

QString get_columna(int col){
    QString resultado;

    if  (col == 0) resultado = "a";
    else if (col == 1) resultado = "b";
    else if (col == 2) resultado = "c";
    else if (col == 3) resultado = "d";
    else if (col == 4) resultado = "e";
    else if (col == 5) resultado = "f";
    else if (col == 6) resultado = "g";
    else if (col == 7) resultado = "h";

    return resultado;
}
