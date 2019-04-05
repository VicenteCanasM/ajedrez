#include "funciones.h"

// ===================== Funciones adicionales ========================== //

bool comprobar_limites(int col, int fil){
    bool flag = 1;
    if (col<1 || col>8 || fil<1 || fil>8)
        flag = 0;
    return flag;
};
