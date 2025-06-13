#include "ecosistema.h"
#include <random>

ecosistema::ecosistema(){
	fabrica = nullptr;
	this->coleccion = new coleccionVector<elemento>();
	elementos = new matriz(coleccion);
	indice = 0;
	horario = "dia";
}
ecosistema::~ecosistema(){}

elemento* ecosistema::crearElemento() {
	setIndice();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 4);
	int aleatorio = dis(gen);
	elemento* e = nullptr;
	string id = to_string(indice);

	switch (aleatorio) {
	case 0: {
		fabrica = new fabricaAgua();
		e= fabrica->crearElemento('A', id,  coordenadaRandom());
		coleccion->agregarObjeto(e);
		return e;
	} break;
	case 1: {
		fabrica = new fabricaCarnivoros();
		e = fabrica->crearElemento('C', id, coordenadaRandom());
		coleccion->agregarObjeto(e);
		return e;
	} break;
	case 2: {
		fabrica = new fabricaPlanta();
		e = fabrica->crearElemento('P', id, coordenadaRandom());
		coleccion->agregarObjeto(e);
		return e;
	} break;
	case 3: {
		fabrica = new fabricaOmnivoros();
		e = fabrica->crearElemento('O', id, coordenadaRandom());
		coleccion->agregarObjeto(e);
		return e;
	} break;
	case 4: {
		fabrica = new fabricaHerbivoros();
		e = fabrica->crearElemento('H', id, coordenadaRandom());
		coleccion->agregarObjeto(e);
		return e;
	} break;
		  fabrica = nullptr;
	}
}

	elemento* ecosistema::crearElementoEspecifico(char tipo) {
		setIndice();
		string id = to_string(indice);
		elemento* e = nullptr;
		if (coordenadaDisponible(coordenadaRandom()) == false) {
			cout << "No hay coordenada disponible" << endl;
			return nullptr; // No hay coordenada disponible
		}
		coordenada c = coordenadaRandom(); // Generar una coordenada aleatoria
		switch (tipo) {
		case 'A': {
			fabrica = new fabricaAgua();
			e=fabrica->crearElemento('A', id, c);
			coleccion->agregarObjeto(e);
			return e;
		} break;
		case 'C': {
			fabrica = new fabricaCarnivoros();
			e = fabrica->crearElemento('C', id, c);
			coleccion->agregarObjeto(e);
			return e;
		} break;
		case 'P': {
			fabrica = new fabricaPlanta();
			e = fabrica->crearElemento('P', id, c);
			coleccion->agregarObjeto(e);
			return e;
		} break;
		case 'O': {
			fabrica = new fabricaOmnivoros();
			e = fabrica->crearElemento('O', id, c);
			coleccion->agregarObjeto(e);
			return e;
		} break;

		case 'H': {
			fabrica = new fabricaHerbivoros();
			e = fabrica->crearElemento('H', id, c);
			coleccion->agregarObjeto(e);
			return e;
		} break;

		case 'K': {
			fabrica = new fabricaCarne();
			e = fabrica->crearElemento('K', id, c);
			coleccion->agregarObjeto(e);
			return e;
		} break;

		}
		fabrica = nullptr;
}

bool ecosistema::coordenadaDisponible(coordenada c) {
	coordenada cor=elementos->coordenadaDisponibleM(c);
	if (cor.getX() != -1 && cor.getY() != -1) {
		return true; // La coordenada está disponible
	}
	return false; // La coordenada no está disponible
}
coordenada ecosistema::coordenadaRandom() {
	return elementos->coordenadaRandom();
}

matriz* ecosistema::getMatriz()
{
	return this->elementos;
}

void ecosistema::setHorario() {
	if (horario == "dia") {
		horario = "noche";
	}
	else
		horario = "dia";
}
string ecosistema::getHorario() { return this->horario; }

coleccionVector<elemento>* ecosistema::getColoeccion()
{
	return this->coleccion;
}

void ecosistema::setIndice() {
	indice += 1;
}

void ecosistema::iniciarSimulacion() {
	// Semilla para aleatoriedad (solo si no se ha llamado antes)
	srand(time(0));

	// Cantidades aleatorias de criaturas entre 2 y 4
	int numCarnivoros = 2 + rand() % 3; // 2, 3 o 4
	int numHerbivoros = 2 + rand() % 3;
	int numOmnivoros = 2 + rand() % 3;

	// Cantidades aleatorias de recursos entre 8 y 12
	int numPlantas = 8 + rand() % 5; // 8 a 12
	int numAgua = 8 + rand() % 5;

	// Crear carnívoros
	for (int i = 0; i < numCarnivoros; i++) {
		crearElementoEspecifico('C');
	}

	// Crear herbívoros
	for (int i = 0; i < numHerbivoros; i++) {
		crearElementoEspecifico('H');
	}

	// Crear omnívoros
	for (int i = 0; i < numOmnivoros; i++) {
		crearElementoEspecifico('O');
	}

	// Crear plantas
	for (int i = 0; i < numPlantas; i++) {
		crearElementoEspecifico('P');
	}

	// Crear agua
	for (int i = 0; i < numAgua; i++) {
		crearElementoEspecifico('A');
	}
}



