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

	string id = to_string(indice);
	coordenada c = coordenadaDisponible();

	switch (aleatorio) {
	case 0: {
		fabrica = new fabricaAgua();
		return fabrica->crearElemento('A', id, c);
	} break;
	case 1: {
		fabrica = new fabricaCarnivoros();
		return fabrica->crearElemento('C', id, c);
	} break;
	case 2: {
		fabrica = new fabricaPlanta();
		return fabrica->crearElemento('P', id, c);
	} break;
	case 3: {
		fabrica = new fabricaOmnivoros();
		return fabrica->crearElemento('O', id, c);
	} break;
	case 4: {
		fabrica = new fabricaHerbivoros();
		return fabrica->crearElemento('H', id, c);
	} break;
		  fabrica = nullptr;
		  indice++;
	}
}

	elemento* ecosistema::crearElementoEspecifico(char tipo) {
		string id = to_string(indice);
		coordenada c = coordenadaDisponible();
		switch (tipo) {
		case 'A': {
			fabrica = new fabricaAgua();
			return fabrica->crearElemento('A', id, c);
		} break;
		case 'C': {
			fabrica = new fabricaCarnivoros();
			return fabrica->crearElemento('C', id, c);
		} break;
		case 'P': {
			fabrica = new fabricaPlanta();
			return fabrica->crearElemento('P', id, c);
		} break;
		case 'O': {
			fabrica = new fabricaOmnivoros();
			return fabrica->crearElemento('O', id, c);
		} break;

		case 'H': {
			fabrica = new fabricaHerbivoros();
			return fabrica->crearElemento('H', id, c);
		} break;

		case 'K': {
			fabrica = new fabricaCarne();
			return fabrica->crearElemento('K', id, c);
		} break;

		}
		fabrica = nullptr;
		indice++;
}

coordenada ecosistema::coordenadaDisponible() {
	//Hacer un metodo en matriz que revise si la coorcenada que se le pasa esta disponible
	return coordenadaRandom(); // temporal para probar la fabrica
}
coordenada ecosistema::coordenadaRandom() {
		random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9); //aqui hay que asumir como que la matriz es cuadrada para generar unacoordenada coherente
	int x = dis(gen);
	int y = dis(gen);
	return coordenada(x, y);
}