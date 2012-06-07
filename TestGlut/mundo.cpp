#pragma once
#include <math.h>

class mundo {

private:

    int colisiones[256][325];
	double v0, t , a;

public:

	mundo ( void );
	mundo ( bool a );
    int detectar ( float x, float z ) ;
    double calculoVf ( double s ) ;
	~mundo ( void );

};
