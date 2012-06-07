//#include "StdAfx.h"
#include "Mundo.cpp"

Mundo :: Mundo(void) {
    colisiones[129][0][13]=1;
}

Mundo :: ~Mundo(void) {
}

double  Mundo :: calculoS() {
    return 2.5;
    //return capInicial * pow(1 + interes / periodos, periodos * anios);
}

bool  Mundo :: d( float x, float z ) {
    int x1=x, z1=z;
    if(colisiones[x1][z1][13]) return true;
    else return false;
}
