#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <QPushButton>
#include <QIcon>
#include "tablero.h"
#include "piezas.h"

void mueve_icono(tablero *echiquier,QPushButton *boton_destino, pair<int,int> origen,
                 pair<int,int> destino, vector<QIcon> iconos);

void mueve_icono_desh(tablero *echiquier, QPushButton *boton_origen, QPushButton *boton_destino, vector<vector<QPushButton*>> botones,
                      pair<int,int> origen, pair<int,int> destino, vector<QIcon> iconos, int, int);

void limpia_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco, QPalette negro);

void colorea_tablero(tablero echiquier, vector < vector < QPushButton*>> botones, QPalette blanco,
                     QPalette negro, vector <pair <int,int>> pos);

pair <int, int> obten_pos(QString pos);

bool comprobar_limites(int, int);

bool comprobar_amenaza(tablero, int, int, int, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>);

bool movimiento_jaque(tablero, pair<int,int>, pair<int,int>, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<dama>, vector<rey>);

QString notacion_algebraica(vector<pair<int,int>>, QString, bool);

QString get_columna(int);

#endif // FUNCIONES_H
