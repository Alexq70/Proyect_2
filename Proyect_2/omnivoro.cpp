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

omnivoro::omnivoro(const omnivoro& otro) {
	this->id = otro.id;
	this->tipo = otro.tipo;
	this->energia = otro.energia;
	this->edad = otro.edad;
	estra = nullptr;
}

elemento* omnivoro::clonar() const {
	return new omnivoro(*this); // usar *this
}
omnivoro::omnivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	estra = nullptr;
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
coordenada omnivoro::getCoordenada() { return posicion; }
//---------------------
void omnivoro::setTipo(char tipo) { this->tipo = tipo; }
void omnivoro::setEnergia(int energia) { this->energia = energia; }
void omnivoro::setEdad(int edad) { this->edad = edad; }
void omnivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}

void omnivoro::menosEnergia() { energia += -1; }
void omnivoro::masEdad() { edad += 1; }

omnivoro::~omnivoro()
{
}
//--------------------------------------------------------------------------
//Metodos de observacion

coordenada omnivoro::observarArriba() {
	coordenada observada;
	observada.setX(posicion.getX() - 1);
	observada.setY(posicion.getY());
	return observada;

}
coordenada omnivoro::observarAbajo() {
	coordenada observada;
	observada.setX(posicion.getX() + 1);
	observada.setY(posicion.getY());
	return observada;
}
coordenada omnivoro::observarIzquierda() {
	coordenada observada;
	observada.setX(posicion.getX());
	observada.setY(posicion.getY() - 1);
	return observada;
}
coordenada omnivoro::observarDerecha() {
	coordenada observada;
	observada.setX(posicion.getX());
	observada.setY(posicion.getY() + 1);
	return observada;
}
coordenada omnivoro::observarD_arriba_I() {
	coordenada observada;
	observada.setY(posicion.getY() - 1);
	observada.setX(posicion.getX() - 1);
	return observada;
} // observar diagonal arriba izquierda
coordenada omnivoro::observarD_arriba_D() {
	coordenada observada;
	observada.setY(posicion.getY() + 1);
	observada.setX(posicion.getX() - 1);
	return observada;
}// observar diagonal arriba derecha
coordenada omnivoro::observarD_abajo_I() {
	coordenada observada;
	observada.setY(posicion.getY() - 1);
	observada.setX(posicion.getX() + 1);
	return observada;
} // observar diagonal abajo izquierda
coordenada omnivoro::observarD_abajo_D() {
	coordenada observada;
	observada.setY(posicion.getY() + 1);
	observada.setX(posicion.getX() + 1);
	return observada;
}// observar diagonal abajo derecha

//-------------------------------------------------------------------------------------------------------------
char omnivoro::observarEntorno(matriz* m) {
	coordenada copia = posicion;
	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I(), };
	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
		copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba() };

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

coordenada omnivoro::observarPosicion(matriz* m) {
	coordenada copia = posicion;
	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I(), };

	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
	copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba() };

	for (int i = 0; i < 8; i++) {
		coordenada actual = observadas[i];
		if (disponible[i]) {
			if (m->verificarCoordenada(actual)) {
				return m->verificarCoordenada(actual)->getCoordenada();
			}
		}
	}
} //observa una posicion concreta del mapa

coordenada omnivoro::siguienteMovimiento(matriz* m) {
	coordenada copia = posicion;

	vector<coordenada> elegibles;

	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I(), };

	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
	copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba() };

	for (int i = 0; i < 8; i++) {
		if (disponible[i] && m->verificarCoordenada(observadas[i]) == nullptr) {
			elegibles.push_back(observadas[i]);
		}
	}

	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(0, elegibles.size()-1);
	int ubicacion = dis(gen);


	return elegibles[ubicacion];
		
}

estrategia* omnivoro::cambiarEstrategia(matriz* m) {
	char opcion = observarEntorno(m);
	switch (opcion) {
	case 'n': {
		estra = new explorarMapa();
	} break;
	case 'A': {
		estra = new consumirRecurso();
	} break;
	case 'O': {
		if ((edad > 10 && edad < 30) && energia > 50) {
			estra = new reproduccion();
		}
		else
			estra = new explorarMapa();
	} break;



	case 'H': {
		estra = new depredacion();
	} break;
	case 'K': {
		estra = new consumirRecurso();
	}
	case 'P': {
		estra = new consumirRecurso();
	} break;
	}
	return estra;
}

void omnivoro::realizarComportamiento(matriz* m) {
	coordenada aux = observarPosicion(m);
	explorarMapa* e = dynamic_cast<explorarMapa*>(estra);
	consumirRecurso* c = dynamic_cast<consumirRecurso*>(estra);
	depredacion* d = dynamic_cast<depredacion*>(estra);
	reproduccion* r = dynamic_cast<reproduccion*>(estra);
	if (e) {
		e->realizarEstrategia(this, m);
	}
	else if (c) {
		c->realizarEstrategia(this, aux, m);
	}
	else if (d) {
		d->realizarEstrategia(this, aux, m);
	}
	else if (r) {
		r->realizarEstrategia(this, m);
	}
}

void omnivoro::sobrevivir(matriz* m) {
	cambiarEstrategia(m);
	realizarComportamiento(m);
}

void omnivoro::consumirRec() {
	energia += 5; // Aumenta la energia al consumir un recurso
}
//--------------------------------------------------------------
string omnivoro::toString() {
	stringstream s;
	s << "criatura onmivoro" << " "
		<< "ID: " << id << " "
		<< "Edad: " << edad << " "
		<< "Energia: " << energia << " "
		<< "Tipo: " << tipo << " ";
	return s.str();
}

ostream& operator<<(ostream& os, omnivoro& o)
{
	os << o.toString();
	return os;
}
