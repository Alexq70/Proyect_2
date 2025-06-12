#include "planta.h"

bool planta::operator==(planta& p)
{
	if (this->id == p.id) {
		return true;
	}
	return false;
}
elemento* planta::clonar() const {
	return new planta(*this);
}
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
coordenada planta::getCoordenada() { return posicion; }
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
	s << "recurso tipo planta" << " "
		<< "ID: " << id << " "
		<< "Tipo: " << tipo << " ";
	return s.str();
}

ostream& operator<<(ostream& os, planta& p)
{
	os << p.toString();
	return os;
}
