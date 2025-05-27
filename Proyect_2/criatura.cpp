#include "criatura.h"

criatura::criatura(string id, string tipo): id(id), tipo(tipo){}
criatura::~criatura(){}
//---------------------
string criatura::getId() { return this->id; }
string criatura::getTipo() { return this->tipo; }
//---------------------
void criatura::setTipo(string tipo) { this->tipo = tipo; }
//---------------------
string criatura::toString(){
	stringstream s;
	  s << "ID: " << id << endl
		<< "Tipo: " << tipo << endl;
	return s.str();
} // no hice ninguno virtual ouro porque todos implementan lo mismo