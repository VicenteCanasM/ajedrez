#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <QPushButton>
#include <QIcon>
#include "tablero.h"

bool mueve_icono(tablero *echiquier, QPushButton *boton_destino, pair<int,int> origen,
                 pair<int,int> destino,  bool estado, vector<QIcon> iconos);

#endif // FUNCIONES_H
