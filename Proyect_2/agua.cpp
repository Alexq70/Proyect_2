#include "agua.h"

bool agua::operator==(agua& a)
{
	if (this->id == a.id) {
		return true;
	}
	return false;
}

agua::agua(char tipo,string id , coordenada p) {
	this->id = id;
	this->tipo = tipo;
	this->posicion = p;
}
string agua::getId() { return this->id; }
char agua::getTipo() { return this->tipo; }
coordenada& agua::getCoordenada() { return posicion; }
//---------------------
void agua::setTipo(char tipo) { this->tipo = tipo; }
void agua::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
agua::~agua()
{
}
//---------------------
string agua::toString() {
	stringstream s;
	s << "Recurso de Agua" << endl
		<< "ID: " << id << endl
		<< "Tipo: " << tipo << endl;
	return s.str();
}

ostream& operator<<(ostream& os, agua& a)
{
	os << a.toString();
	return os;
}
