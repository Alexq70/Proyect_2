#include "recurso.h"
recurso::recurso(string id, string tipo, coordenada p) : id(id), tipo(tipo), posicion(p) {}
recurso::~recurso() {}
//---------------------
string recurso::getId() { return this->id; }
string recurso::getTipo() { return this->tipo; }
coordenada recurso::getCoordenada() { return this->posicion; }
//---------------------
void recurso::setTipo(string tipo) { this->tipo = tipo; }
void recurso::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
//---------------------
string recurso::toString() {
	stringstream s;
	  s << "ID: " << this->id << "\n"
		<< "Tipo: " << this->tipo << "\n\n";
	return s.str();
} 

