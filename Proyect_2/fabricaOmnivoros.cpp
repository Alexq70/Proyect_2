#include "fabricaOmnivoros.h"

elemento* fabricaOmnivoros::crearElemento(char tipo, string id, coordenada c) {
	return new omnivoro(tipo, id, 100, 0, c);
}