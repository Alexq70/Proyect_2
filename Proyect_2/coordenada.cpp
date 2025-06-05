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

//------------------------------------------
bool coordenada::moverseIzquierda() {
	if (y>0 && y<=14) {
		y += -1;
		return true;
	}
	return false;
}
bool  coordenada::moverseDerecha() {
	if(y >= 0 && y < 14) {
		y += 1;
		return true;
	}
}
bool  coordenada::moverseArriba() {
	if(x > 0 && x <= 14) {
		x += -1;
		return true;
	}
	return false;
}
bool  coordenada::moverseAbajo() {
	if(x >= 0 && x < 14) {
		x += 1;
		return true;
	}
	return false;
}
bool coordenada::diagonalDerechaArriba() {
	if(moverseDerecha() && moverseArriba()) {
		return true;
	}
	return false;
}
bool coordenada::diagonalDerechaAbajo() {
	if (moverseDerecha() && moverseAbajo()) {
		return true;
	}
	return false;
}
bool coordenada::diagonalIzquierdaAbajo() {
	if (moverseIzquierda() && moverseAbajo()) {
		return true;
	}
	return false;
}
bool coordenada::diagonalIzquierdaArriba() {
	if(moverseIzquierda() && moverseArriba()) {
		return true;
	}
	return false;
}

string coordenada::toString() {
	stringstream s;
	s << "Coordenada:" << " (" << x << "," << y << ")";
	return s.str();
}