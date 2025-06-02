#include "criatura.h"

criatura::criatura(string id, string tipo, int energia, int edad): id(id), tipo(tipo), energia(energia), edad(edad){}
criatura::~criatura(){}
//---------------------
string criatura::getId() { return this->id; }
string criatura::getTipo() { return this->tipo; }
int criatura::getEnergia() { return this->energia; }
int criatura::getEdad() { return this->edad; }
//---------------------
void criatura::setTipo(string tipo) { this->tipo = tipo; }
void criatura::setEnergia(int tipo) { this->energia = energia; }
void criatura::setEdad(int edad) { this->edad = edad; }
//---------------------
string criatura::toString(){
	stringstream s;
	  s << "ID: " << id << endl
		<< "Edad: " << edad << endl
		<< "Tipo: " << tipo << endl
		<< "Energia: " << energia << endl;
	return s.str();
} // no hice ninguno virtual ouro porque todos implementan lo mismo