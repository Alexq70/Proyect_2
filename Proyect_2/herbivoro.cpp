#include "herbivoro.h"
#include"estrategia.h"
#include "matriz.h"
#include "estrategiaMovimiento.h"
#include "estrategiaAlimentacion.h"
#include "consumirRecurso.h"
#include "reproduccion.h"
#include "explorarMapa.h"
#include "depredacion.h"

bool herbivoro::operator==(herbivoro& h)
{
	if (this->id == h.id) {
		return true;
	}
	return false;
}

herbivoro::herbivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	estra = new explorarMapa();
}
string herbivoro::getId() { return this->id; }
char herbivoro::getTipo()
{
	return this->tipo;
}
int herbivoro::getEnergia() { return this->energia; }
int herbivoro::getEdad() { return this->edad; }
coordenada& herbivoro::getCoordenada() { return posicion; }
//---------------------
void herbivoro::setTipo(char tipo) { this->tipo = tipo; }
void herbivoro::setEnergia(int energia) { this->energia = energia; }
void herbivoro::setEdad(int edad) { this->edad = edad; }
void herbivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
herbivoro::~herbivoro()
{
}
char herbivoro::observarEntorno(matriz* m) {
	return 'n';
}
estrategia* herbivoro::cambiarEstrategia(matriz* m) {
	char opcion = observarEntorno(m);
	switch (opcion) {
	case 'n': {
		estra = new explorarMapa();
	} break;
	case 'A': {
		estra = new consumirRecurso();
	} break;
	case 'H': {
		estra = new reproduccion();
	} break;
	}
	return estra;
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
