//#include "StdAfx.h"
#include "mundo.cpp"

mundo :: mundo(void) {
}

mundo :: ~mundo(void) {
}

mundo :: mundo( bool a ) {

// --------------------------------- Horizontales -----------------------------------------//
    for( int i=0; i<146; i++) for( int c=0; c<4; c++) colisiones[i][c]=1;
    for( int i=0; i<50; i++) for( int c=60; c<63; c++) colisiones[i][c]=1;
    for( int i=0; i<56; i++) for( int c=290; c<324; c++) colisiones[i][c]=1;
    for( int i=57; i<146; i++) for( int c=300; c<324; c++) colisiones[i][c]=1;
    for( int i=57; i<111; i++) for( int c=96; c<106; c++) colisiones[i][c]=1;
    for( int i=57; i<146; i++) for( int c=128; c<134; c++) colisiones[i][c]=1;
    for(int i=51; i<146; i++) for( int c=200; c<203; c++) colisiones[i][c]=1;
    for(int i=51; i<61; i++) for( int c=200; c<207; c++) colisiones[i][c]=1;
    for(int i=57; i<125; i++) for( int c=247; c<253; c++) colisiones[i][c]=1;
    for(int i=112; i<126; i++) for( int c=220; c<225; c++) colisiones[i][c]=1;

// ---------------------------------- Izquierda -------------------------------------------//
    for(int i=132; i<146; i++) for( int c=0; c<201; c++) colisiones[i][c]=1;
    for(int i=129; i<146; i++) for( int c=60; c<129; c++) colisiones[i][c]=1;
    for(int i=136; i<146; i++) for( int c=201; c<324; c++) colisiones[i][c]=1;
    for(int i=119; i<126; i++) for( int c=220; c<253; c++) colisiones[i][c]=1;
    for(int i=103; i<110; i++) for( int c=200; c<220; c++) colisiones[i][c]=1;
    for(int i=122; i<126; i++) for( int c=274; c<292; c++) colisiones[i][c]=1;

// ----------------------------------- Derecha ------------------------------------------- //
    for(int i=46; i<50; i++) for( int c=0; c<63; c++) colisiones[i][c]=1;
    for(int i=111; i<119; i++) for( int c=60; c<106; c++) colisiones[i][c]=1;
    for(int i=0; i<11; i++) for( int c=0; c<324; c++) colisiones[i][c]=1;
    for(int i=57; i<64; i++) for( int c=96; c<128; c++) colisiones[i][c]=1;
    for(int i=57; i<64; i++) for( int c=200; c<253; c++) colisiones[i][c]=1;
    for(int i=57; i<64; i++) for( int c=274; c<325; c++) colisiones[i][c]=1;

// ------------------------------------- la L -------------------------------------------- //
    for(int i=57; i<110; i++) for( int c=143; c<192; c++) colisiones[i][c]=1;

// ------------------------------------- Escaleras --------------------------------------- //
    for(int i=35; i<111; i++) for( int c=58; c<65; c++) colisiones[i][c]=2;
    for(int i=125; i<146; i++) for( int c=274; c<288; c++) colisiones[i][c]=5;
    for(int i=115; i<146; i++) for( int c=64; c<90; c++) colisiones[i][c]=5;
    for(int i=94; i<102; i++) for( int c=269; c<287; c++) colisiones[i][c]=3;

// --------------------------------------- Rampa ----------------------------------------- //
    for(int i=80; i<103; i++) for( int c=287; c<305; c++) colisiones[i][c]=4;

// --------------------------------------- Tetera ----------------------------------------- //
    for(int i=110; i<120; i++) for( int c=212; c<222; c++) colisiones[i][c]=6;

// ---------------------------------------- Dulce ----------------------------------------- //
    for(int i=85; i<92; i++) for( int c=80; c<94; c++) colisiones[i][c]=7;

// ---------------------------------------- Cartel ----------------------------------------- //
    for(int i=46; i<57; i++) for( int c=222; c<242; c++) colisiones[i][c]=8;

// ---------------------------------------- Teatro ----------------------------------------- //
    for(int i=130; i<138; i++) for( int c=212; c<237; c++) colisiones[i][c]=9;

}

int  mundo :: detectar( float x, float z ) {
    int x1=x, z1=z;
    //cout << x1+128 << " " << z1+22 << endl;
    if(colisiones[x1+128][z1+22]==1) return 1;
    else if(colisiones[x1+128][z1+22]==2) return 2;
    else if(colisiones[x1+128][z1+22]==3) return 3;
    else if(colisiones[x1+128][z1+22]==4) return 4;
    else if(colisiones[x1+128][z1+22]==5) return 5;
    else if(colisiones[x1+128][z1+22]==6) return 6;
    else if(colisiones[x1+128][z1+22]==7) return 7;
    else if(colisiones[x1+128][z1+22]==8) return 8;
    else if(colisiones[x1+128][z1+22]==9) return 9;
    else return 0;
}

double  mundo :: calculoVf( double s) {
    double v=((v0*v0)+(2*(a*s)));
    double vf=pow(v,0.5);
    return vf;
}
