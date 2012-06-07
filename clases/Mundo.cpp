#pragma once
#include <math.h>

class Mundo {

private:
    int colisiones[256][325][26];

public:
	Mundo ();
    double calculoS ( ) ;
    bool d(float x, float z) ;
	~Mundo ( void );

};
