#include "agua.h"

agua::agua() : recurso('A', "", coordenada(0, 0))  // Constructor por defecto
{
	this->id = "";
	this->tipo = 'A'; // A de agua
	this->posicion = coordenada(0, 0); // Inicializar coordenada en (0,0)
}

agua::agua(char tipo,string id , coordenada p):recurso(tipo,id,p) {
	this->id = id;
	this->tipo = tipo;
	this->posicion = p;
}
string agua::getId() { return this->id; }
char agua::getTipo() { return this->tipo; }
coordenada agua::getCoordenada() { return this->posicion; }
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
