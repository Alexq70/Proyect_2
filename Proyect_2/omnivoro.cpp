#include "omnivoro.h"
omnivoro::omnivoro() : criatura('O', "", coordenada(0, 0)) // llama al constructor de criatura
{
	this->id = "";
	this->tipo = 'O'; // O de omnivoro
	this->energia = 0;
	this->edad = 0;
	this->posicion.setX(0);
	this->posicion.setY(0);
	this->rapidez = false; // por defecto la rapidez es normal
}
omnivoro::omnivoro(char tipo,string id , int energia, int edad, coordenada c):criatura(tipo,id,c) {
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
	s << "criatura onmivoro" << endl
		<< "ID: " << id << endl
		<< "Edad: " << edad << endl
		<< "Tipo: " << tipo << endl
		<< "Energia: " << energia << endl;
	return s.str();
}

ostream& operator<<(ostream& os, omnivoro& o)
{
	os << o.toString();
	return os;
}
