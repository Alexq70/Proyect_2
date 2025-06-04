#include "planta.h"

planta::planta(char tipo,string id, coordenada p) {
	this->id = id;
	this->tipo = tipo;
	this->posicion = p;
}
string planta::getId() { return this->id; }
char planta::getTipo()
{
	return this->tipo;
}
coordenada planta::getCoordenada() { return this->posicion; }
//---------------------
void planta::setTipo(char tipo) { this->tipo = tipo; }
void planta::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
//---------------------

planta::~planta()
{
}

string planta::toString() {
	stringstream s;
	s << "recurso tipo planta" << endl
		<< "ID: " << id << endl
		<< "Tipo: " << tipo << endl;
	return s.str();
}

ostream& operator<<(ostream& os, planta& p)
{
	os << p.toString();
	return os;
}
