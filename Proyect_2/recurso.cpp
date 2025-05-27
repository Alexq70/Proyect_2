#include "recurso.h"
recurso::recurso(string id, string tipo) : id(id), tipo(tipo) {}
recurso::~recurso() {}
//---------------------
string recurso::getId() { return this->id; }
string recurso::getTipo() { return this->tipo; }
//---------------------
void recurso::setTipo(string tipo) { this->tipo = tipo; }
//---------------------
string recurso::toString() {
	stringstream s;
	  s << "ID: " << this->id << "\n"
		<< "Tipo: " << this->tipo << "\n\n";
	return s.str();
} 

