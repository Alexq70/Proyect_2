#include "omnivoro.h"
#include"estrategia.h"
#include "matriz.h"
#include "estrategiaMovimiento.h"
#include "estrategiaAlimentacion.h"
#include "consumirRecurso.h"
#include "reproduccion.h"
#include "explorarMapa.h"
#include "depredacion.h"

bool omnivoro::operator==(omnivoro& o)
{
	if (this->id == o.id) {
		return true;
	}
	return false;
}
omnivoro::omnivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	//estra = new explorarMapa();
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
coordenada& omnivoro::getCoordenada() { return posicion; }
//---------------------
void omnivoro::setTipo(char tipo) { this->tipo = tipo; }
void omnivoro::setEnergia(int energia) { this->energia = energia; }
void omnivoro::setEdad(int edad) { this->edad = edad; }
void omnivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
omnivoro::~omnivoro()
{
}
//char omnivoro::observarEntorno(matriz* m) {
//	return 'n';
//}
//
//
//estrategia*  omnivoro::cambiarEstrategia(matriz* m) {
//	char opcion = observarEntorno(m);
//	switch (opcion) {
//	case 'n': {
//		estra = new explorarMapa();
//	} break;
//	case 'A': {
//		estra = new consumirRecurso();
//	} break;
//	case 'O': {
//		estra = new reproduccion();
//	} break;
//	case 'H': {
//		estra = new depredacion();
//	} break;
//	case 'K': {
//		estra = new consumirRecurso();
//	}
//	case 'x': {
//		estra = new cambiaDireccion();
//	}
//	}
//	return estra;
//}
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
