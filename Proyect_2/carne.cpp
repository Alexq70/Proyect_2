#include "carne.h"


bool carne::operator==(carne& p)
{
	if (this->id == p.id) {
		return true;
	}
	return false;
}
elemento* carne::clonar() const {
	return new carne(*this);
}
carne::carne(char tipo, string id, coordenada p) {
	this->id = id;
	this->tipo = tipo;
	this->posicion = p;
}
string carne::getId() { return this->id; }
char carne::getTipo()
{
	return this->tipo;
}
coordenada carne::getCoordenada() { return posicion; }
//---------------------
void carne::setTipo(char tipo) { this->tipo = tipo; }
void carne::setId(string id) { this->id = id; }
void carne::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
//---------------------

carne::~carne()
{
}

string carne::toString() {
	stringstream s;
	s << "recurso tipo carne" << " "
		<< "ID: " << id << " "
		<< "Tipo: " << tipo << " "
		<< this->posicion << " ";
	return s.str();
}

ostream& operator<<(ostream& os, carne& p)
{
	os << p.toString();
	return os;
}