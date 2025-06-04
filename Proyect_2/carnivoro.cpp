#include "carnivoro.h"

carnivoro::carnivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	this->rapidez = false; // por defecto la rapidez es normal
}
void carnivoro::comer()
{
	// Implementar la lógica de comer para el carnivoro
	// Por ejemplo, podría reducir la energía al comer un recurso
}
string carnivoro::getId() { return this->id; }
char carnivoro::getTipo()
{
	return this->tipo;
}
int carnivoro::getEnergia() { return this->energia; }
int carnivoro::getEdad() { return this->edad; }
coordenada carnivoro::getCoordenada() { return this->posicion; }
//---------------------
void carnivoro::setTipo(char tipo) { this->tipo = tipo; }
void carnivoro::setEnergia(int tipo) { this->energia = energia; }
void carnivoro::setEdad(int edad) { this->edad = edad; }
void carnivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
//--------------------
carnivoro::~carnivoro() {}

void carnivoro::setRapidez(bool r) { this->rapidez = r; }

string carnivoro::toString() {
	stringstream s;
	s << criatura::toString()
	  << "Rapidez: " << (this->rapidez ? "Alta" : "Normal") << endl; //la parte del decorador
	return s.str();
} //