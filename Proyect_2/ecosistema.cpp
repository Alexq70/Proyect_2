#include "ecosistema.h"
#include <random>

ecosistema::ecosistema(){
	fabrica = nullptr;
	this->coleccion = new coleccionVector<elemento*>();
	elementos = new matriz(coleccion);
}
ecosistema::~ecosistema(){}

elemento* ecosistema::crearElemento() {
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
		  indice++;
	}
}

	elemento* ecosistema::crearElementoEspecifico(char tipo) {
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
		indice++;
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
