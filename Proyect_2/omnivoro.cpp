#include "omnivoro.h"
omnivoro::omnivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	this->rapidez = false; // por defecto la rapidez es normal
}
void omnivoro::comer()
{
}
string omnivoro::getId() { return this->id; }
char omnivoro::getTipo()
{
	return this->tipo;
}
int omnivoro::getEnergia() { return this->energia; }
int omnivoro::getEdad() { return this->edad; }
coordenada omnivoro::getCoordenada() { return this->posicion; }
//---------------------
void omnivoro::setTipo(char tipo) { this->tipo = tipo; }
void omnivoro::setEnergia(int tipo) { this->energia = energia; }
void omnivoro::setEdad(int edad) { this->edad = edad; }
void omnivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
omnivoro::~omnivoro()
{
}
//--------------------
string omnivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}