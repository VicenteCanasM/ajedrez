#include <vector>
#include <iostream>
#include "piezas.h"

bool comprobar_limites(int, int);

bool comprobar_amenaza(tablero, int, int, int, vector<peon>, vector<caballo>, vector<alfil>, vector<torre>, vector<rey>, vector<dama>);

void movimiento(tablero, QIcon, QIcon, QPushButton, QPushButton, bool, pair<int,int>, pair<int,int>);

QString nuevo_icono(int);
