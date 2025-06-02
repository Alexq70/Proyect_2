#include "criatura.h"

criatura::criatura(string id, string tipo, int energia, int edad, coordenada c): id(id), tipo(tipo), energia(energia), edad(edad), posicion(c){
}
criatura::~criatura(){}
//---------------------
string criatura::getId() { return this->id; }
string criatura::getTipo() { return this->tipo; }
int criatura::getEnergia() { return this->energia; }
int criatura::getEdad() { return this->edad; }
coordenada criatura::getCoordenada() { return this->posicion; }
//---------------------
void criatura::setTipo(string tipo) { this->tipo = tipo; }
void criatura::setEnergia(int tipo) { this->energia = energia; }
void criatura::setEdad(int edad) { this->edad = edad; }
void criatura::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX()); 
	this->posicion.setY(c.getY());
}
//--------------------
string criatura::toString(){
	stringstream s;
	  s << "ID: " << id << endl
		<< "Edad: " << edad << endl
		<< "Tipo: " << tipo << endl
		<< "Energia: " << energia << endl
	    << posicion.toString();
	return s.str();
} // no hice ninguno virtual ouro porque todos implementan lo mismo