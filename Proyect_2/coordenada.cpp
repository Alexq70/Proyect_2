#include "coordenada.h"

coordenada::coordenada(int x, int y):x(x) , y(y){}
coordenada::~coordenada() {}
//------------------------------------------
int coordenada::getX(){
	return x;
}
int coordenada::getY(){
	return y;
}
//------------------------------------------
void coordenada::setX(int x) {
	this->x = x;
}
void coordenada::setY(int y) {
	this->y = y;
}
string coordenada:: toString() {
	stringstream s;
	s << "    COORDENADA" << endl
	    << "X: " << x << endl
		<< "Y: " << y << endl;
	return s.str();
}