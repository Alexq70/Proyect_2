#include "carnivoro.h"
#include"estrategia.h"
#include "matriz.h"
#include "estrategiaMovimiento.h"
#include "estrategiaAlimentacion.h"
#include "consumirRecurso.h"
#include "reproduccion.h"
#include "explorarMapa.h"
#include "depredacion.h"

bool carnivoro::operator==(carnivoro& c)
{
	if (this->id == c.id) {
		return true;
	}
	return false;
}

carnivoro::carnivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	estra = new consumirRecurso();
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
coordenada& carnivoro::getCoordenada() { return posicion; }
//---------------------
void carnivoro::setTipo(char tipo) { this->tipo = tipo; }
void carnivoro::setEnergia(int energia) { this->energia = energia; }
void carnivoro::setEdad(int edad) { this->edad = edad; }
void carnivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
//--------------------
carnivoro::~carnivoro() {}

char carnivoro::observarEntorno(matriz* m){
	coordenada original = posicion;
	original.moverseArriba();
	m->coordenadaDisponibleM(original);

	return 'n'; // retorna esto cuando no tiene nada alrededor, tiene que habe run caso x para que cambie de direccion
}

estrategia* carnivoro::cambiarEstrategia(matriz* m) {
	char opcion = observarEntorno(m);
	switch (opcion) {
	case 'n': {
		estra = new explorarMapa();
	} break;
	case 'A': {
		estra = new consumirRecurso();
	} break;
	case 'O': {
		estra = new depredacion();
	} break;
	case 'H': {
		estra = new depredacion();
	} break;
	case 'C': {
		estra = new reproduccion();
	} break;
	case 'K': {
		estra = new consumirRecurso();
	}
	}
	return estra;
}
//-----------------------------
void carnivoro::consumirRec() {

}
void carnivoro::cazar(){

}

string carnivoro::toString() {
	stringstream s;
	s << "criatura Carnivora " << tipo << endl
		<< "ID: " << id << endl
		<< "Edad: " << edad << endl
	    << "Tipo: " << tipo << endl
		<< "Energia: " << energia << endl;
	return s.str();
} //

ostream& operator<<(ostream& os, carnivoro& c)
{
	os << c.toString();
	return os;
}
