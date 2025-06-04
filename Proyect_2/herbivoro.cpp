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

}
string herbivoro::getId() { return this->id; }
char herbivoro::getTipo()
{
	return this->tipo;
}
int herbivoro::getEnergia() { return this->energia; }
int herbivoro::getEdad() { return this->edad; }
coordenada herbivoro::getCoordenada() { return this->posicion; }
//---------------------
void herbivoro::setTipo(char tipo) { this->tipo = tipo; }
void herbivoro::setEnergia(int tipo) { this->energia = energia; }
void herbivoro::setEdad(int edad) { this->edad = edad; }
void herbivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
herbivoro::~herbivoro()
{
}
//--------------------
string herbivoro::toString() {
	stringstream s;
	s << "criatura herbivora"<<endl
		<< "ID: " << id << endl
	    << "Edad: " << edad << endl
		<< "Tipo: " << tipo << endl
		<< "Energia: " << energia << endl;
	return s.str();
}

ostream& operator<<(ostream& os, herbivoro& h)
{
	os << h.toString();
	return os;	
}
