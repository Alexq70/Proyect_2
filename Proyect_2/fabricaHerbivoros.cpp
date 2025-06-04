#include "fabricaHerbivoros.h"

elemento* fabricaHerbivoros::crearElemento(char tipo, string id, coordenada c) {
	return new herbivoro(tipo, id, 100, 0, c);
}