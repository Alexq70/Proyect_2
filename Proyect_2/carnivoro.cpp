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
	coordenada copia = posicion; 
	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I(), };

	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
	copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba()};

	for (int i = 0; i < 8; i++) {
		coordenada actual = observadas[i];
		if (disponible[i]) {
			if (m->verificarCoordenada(actual)) {
				return m->verificarCoordenada(actual)->getTipo();
			}
		}
	}
	return 'n';
}

coordenada carnivoro::siguienteMovimiento(matriz* m) {
	coordenada copia = posicion;

	vector<coordenada> elegibles;

	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I(), };

	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
	copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba() };

	for (int i = 0; i < 8; i++) {
		coordenada actual = observadas[i];
		if (disponible[i]) {
			if (!m->verificarCoordenada(actual)) {
				elegibles.push_back(observadas[i]);
			}
		}
	}

	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(0,elegibles.size());
	int ubicacion = dis(gen);


	return elegibles[ubicacion];
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
	energia += 5;
}

//Metodos de observacion

coordenada carnivoro::observarArriba() { 
	coordenada observada;
	observada.setX(posicion.getX() -1);
	observada.setY(posicion.getY());
	return observada;

}
coordenada carnivoro::observarAbajo() {
	coordenada observada;
	observada.setX(posicion.getX() +1);
	observada.setY(posicion.getY());
	return observada;
}
coordenada carnivoro::observarIzquierda() {
	coordenada observada;
	observada.setX(posicion.getX());
	observada.setY(posicion.getY() -1);
	return observada;
}
coordenada carnivoro::observarDerecha() {
	coordenada observada;
	observada.setX(posicion.getX());
	observada.setY(posicion.getY() +1);
	return observada;
}
coordenada carnivoro::observarD_arriba_I() {
	coordenada observada;
	observada.setY(posicion.getY() - 1);
	observada.setX(posicion.getX() - 1);
	return observada;
} // observar diagonal arriba izquierda
coordenada carnivoro::observarD_arriba_D() {
	coordenada observada;
	observada.setY(posicion.getY() + 1);
	observada.setX(posicion.getX() - 1);
	return observada;
}// observar diagonal arriba derecha
coordenada carnivoro::observarD_abajo_I() { 
	coordenada observada;
	observada.setY(posicion.getY() - 1);
	observada.setX(posicion.getX() +1);
	return observada;
} // observar diagonal abajo izquierda
coordenada carnivoro::observarD_abajo_D() { 
	coordenada observada;
	observada.setY(posicion.getY() + 1);
	observada.setX(posicion.getX() + 1 );
	return observada;
}// observar diagonal abajo derecha

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
