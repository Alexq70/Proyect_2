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
herbivoro::herbivoro(const herbivoro& otro) {
	this->id = otro.id;
	this->tipo = otro.tipo;
	this->energia = otro.energia;
	this->edad = otro.edad;
	estra = nullptr;
}

elemento* herbivoro::clonar() const {
	return new herbivoro(*this); // usar *this
}
herbivoro::herbivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	estra = nullptr;
}
string herbivoro::getId() { return this->id; }
char herbivoro::getTipo()
{
	return this->tipo;
}
int herbivoro::getEnergia() { return this->energia; }
int herbivoro::getEdad() { return this->edad; }
coordenada herbivoro::getCoordenada() { return posicion; }
//---------------------
void herbivoro::setTipo(char tipo) { this->tipo = tipo; }
void herbivoro::setEnergia(int energia) { this->energia = energia; }
void herbivoro::setEdad(int edad) { this->edad = edad; }
void herbivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}

void herbivoro::menosEnergia() { energia += -1; }
void  herbivoro::masEdad() { edad += 1; }
herbivoro::~herbivoro()
{
}
//--------------------------------------------------------------------
char herbivoro::observarEntorno(matriz* m) {
	coordenada copia = posicion;
	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I(), };

	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
		copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba() };

	for (int i = 0; i < 8; i++) {
		coordenada actual = observadas[i];
		if(disponible[i]) {
			if (m->verificarCoordenada(actual)) {
				return m->verificarCoordenada(actual)->getTipo();
			}
		}
	}
	return 'n';
}

coordenada herbivoro::observarPosicion(matriz* m) {
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

coordenada herbivoro::siguienteMovimiento(matriz* m) {
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

//----------------------------------------------------------------------
estrategia* herbivoro::cambiarEstrategia(matriz* m) {
	char opcion = observarEntorno(m);
	switch (opcion) {
	case 'n': {
		estra = new explorarMapa();
	} break;
	case 'A': {
		estra = new consumirRecurso();
	} break;
	case 'P': {
		estra = new consumirRecurso();
	} break;
	case 'H': {
		if ((edad > 10 && edad < 30) && energia > 50) {
			estra = new reproduccion();
		}
		else
			estra = new explorarMapa();
	} break;
	case 'K': {
		estra = new explorarMapa();
	}
	}
	return estra;
}

void herbivoro::realizarComportamiento(matriz* m) {
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

void herbivoro::sobrevivir(matriz* m) {
	cambiarEstrategia(m);
	realizarComportamiento(m);
}

void herbivoro::consumirRec() {
	energia += 5;
}
//------------------------------------
//Metodos de observacion

coordenada herbivoro::observarArriba() {
	coordenada observada;
	observada.setX(posicion.getX() - 1);
	observada.setY(posicion.getY());
	return observada;

}
coordenada herbivoro::observarAbajo() {
	coordenada observada;
	observada.setX(posicion.getX() + 1);
	observada.setY(posicion.getY());
	return observada;
}
coordenada herbivoro::observarIzquierda() {
	coordenada observada;
	observada.setX(posicion.getX());
	observada.setY(posicion.getY() - 1);
	return observada;
}
coordenada herbivoro::observarDerecha() {
	coordenada observada;
	observada.setX(posicion.getX());
	observada.setY(posicion.getY() + 1);
	return observada;
}
coordenada herbivoro::observarD_arriba_I() {
	coordenada observada;
	observada.setY(posicion.getY() - 1);
	observada.setX(posicion.getX() - 1);
	return observada;
} // observar diagonal arriba izquierda
coordenada herbivoro::observarD_arriba_D() {
	coordenada observada;
	observada.setY(posicion.getY() + 1);
	observada.setX(posicion.getX() - 1);
	return observada;
}// observar diagonal arriba derecha
coordenada herbivoro::observarD_abajo_I() {
	coordenada observada;
	observada.setY(posicion.getY() - 1);
	observada.setX(posicion.getX() + 1);
	return observada;
} // observar diagonal abajo izquierda
coordenada herbivoro::observarD_abajo_D() {
	coordenada observada;
	observada.setY(posicion.getY() + 1);
	observada.setX(posicion.getX() + 1);
	return observada;
}// observar diagonal abajo derecha

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
