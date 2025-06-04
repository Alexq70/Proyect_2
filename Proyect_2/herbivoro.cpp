#include "herbivoro.h"

herbivoro::herbivoro() : criatura('H', "0", coordenada(0, 0))  // Llamando al constructor de la clase base criatura
{
	this->id = "0";
	this->tipo = 'H'; // H de herbivoro
	this->energia = 0;
	this->edad = 0;
	this->posicion.setX(0);
	this->posicion.setY(0);
}

herbivoro::herbivoro(char tipo,string id , int energia, int edad, coordenada c):criatura(tipo,id,c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;

string herbivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}