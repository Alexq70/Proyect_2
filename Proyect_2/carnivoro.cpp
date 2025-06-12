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

carnivoro::carnivoro(const carnivoro& otro) {
	this->id = otro.id;
	this->tipo = otro.tipo;
	this->energia = otro.energia;
	this->edad = otro.edad;
	estra = nullptr;
}

elemento* carnivoro::clonar() const {
	return new carnivoro(*this); // usar *this
}
carnivoro::carnivoro(char tipo,string id , int energia, int edad, coordenada c) {
	this->id = id;
	this->tipo = tipo;
	this->energia = energia;
	this->edad = edad;
	this->posicion = c;
	estra = nullptr;
}

string carnivoro::getId() { return this->id; }
char carnivoro::getTipo()
{
	return this->tipo;
}
int carnivoro::getEnergia() { return this->energia; }
int carnivoro:: getEdad() { return this->edad; }

coordenada carnivoro::getCoordenada() { return posicion; }
//------------------------------------------------------------
void carnivoro::setTipo(char tipo) { this->tipo = tipo; }
void carnivoro::setEnergia(int energia) { this->energia = energia; }
void carnivoro::setEdad(int edad) { this->edad = edad; }
void carnivoro::setCoordenada(coordenada c) {
	this->posicion.setX(c.getX());
	this->posicion.setY(c.getY());
}
void carnivoro::menosEnergia() { energia += -1; }
void  carnivoro::masEdad() { edad += 1; }
//------------------------------------------------------------
carnivoro::~carnivoro() {}

char carnivoro::observarEntorno(matriz* m){
	coordenada copia = this->posicion; 
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
coordenada carnivoro::observarPosicion(matriz* m) {
	coordenada copia = this->posicion;
	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I()
	};

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
coordenada carnivoro::siguienteMovimiento(matriz* m) {
	coordenada copia = this->posicion;
	int cont = 0;
	vector<coordenada> elegibles;

	coordenada observadas[8] = { observarArriba(),observarD_arriba_D(),
		observarDerecha(),observarD_abajo_D(),observarAbajo(),
		observarD_abajo_I(), observarIzquierda(),
		observarD_arriba_I()
	};

	bool disponible[8] = { copia.moverseArriba(),copia.diagonalDerechaArriba(),copia.moverseDerecha(),
	copia.diagonalDerechaAbajo(),copia.moverseAbajo(),copia.diagonalIzquierdaAbajo(),copia.moverseIzquierda(),copia.diagonalIzquierdaArriba() };

	for (int i = 0; i < 8; i++) {
		if (disponible[i] && m->verificarCoordenada(observadas[i]) == nullptr) {
			elegibles.push_back(observadas[i]);
		}
	}

	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(0,(elegibles.size()-1));



	int ubicacion = dis(gen);


	return elegibles[ubicacion]; //retorna un movimiento diponible a su alrededor
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
	case 'K': {
		estra = new consumirRecurso();
	}
	case 'O': {
		estra = new depredacion();
	} break;
	case 'H': {
		estra = new depredacion();
	} break;
	case 'C': {
		if ((edad>10 && edad<30) && energia>50) {
			estra = new reproduccion();
		}
		else
			estra = new explorarMapa();
	} break;
	case 'P': {
		estra = new explorarMapa();
	}
	}
	return estra;
}

void carnivoro::realizarComportamiento(matriz* m) {
	coordenada aux = observarPosicion(m);
	explorarMapa* e = dynamic_cast<explorarMapa*>(estra);
	consumirRecurso* c = dynamic_cast<consumirRecurso*>(estra);
	depredacion* d = dynamic_cast<depredacion*>(estra);
	reproduccion* r = dynamic_cast<reproduccion*>(estra);
	if (e) {
		e->realizarEstrategia(this,m);
	}
	else if (c) {
		c->realizarEstrategia(this,aux,m);
	}
	else if (d) {
		d->realizarEstrategia(this,aux,m);
	}
	else if (r) {
		r->realizarEstrategia(this,m);
	}
}

void carnivoro::sobrevivir(matriz* m) {
	cambiarEstrategia(m);
	realizarComportamiento(m);
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
	s << "criatura Carnivora " << tipo << " "
		<< "ID: " << id << " "
		<< "Edad: " << edad << " "
		<< "Energia: " << energia << " "
		<< "Tipo: " << tipo << " ";
	return s.str();
} //

carnivoro& carnivoro::operator=(const carnivoro& otro) {
	this->id = otro.id;
	this->tipo = otro.tipo;
	this->energia = otro.energia;
	this->edad = otro.edad;
	return *this;
}

ostream& operator<<(ostream& os, carnivoro& c)
{
	os << c.toString();
	return os;
}
