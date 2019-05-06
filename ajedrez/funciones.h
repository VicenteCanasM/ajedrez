#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <QPushButton>
#include <QIcon>
#include "tablero.h"

void mueve_icono(tablero *echiquier,QPushButton *boton_destino, pair<int,int> origen,
                 pair<int,int> destino, vector<QIcon> iconos);
void limpia_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco, QPalette negro);
void colorea_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco,
                     QPalette negro, vector <pair <int,int>> pos);
pair <int, int> obten_pos(QString pos);

#endif // FUNCIONES_H
