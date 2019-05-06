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
