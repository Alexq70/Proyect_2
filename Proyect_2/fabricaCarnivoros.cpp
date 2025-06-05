#include "fabricaCarnivoros.h"

elemento* fabricaCarnivoros::crearElemento(char tipo, string id, coordenada c) {
	return new carnivoro(tipo,id,100,0, c);
}