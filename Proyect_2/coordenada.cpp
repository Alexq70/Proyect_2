#include "coordenada.h"

coordenada::coordenada(int x, int y):x(x) , y(y){}
coordenada::~coordenada() {}


string coordenada:: toString() {
	stringstream s;
	s << "    COORDENADA" << endl
	    << "X: " << x << endl
		<< "Y: " << y << endl;
	return s.str();
}