#include "fabricaCarne.h"


elemento* fabricaCarne::crearElemento(char tipo, string id, coordenada c) {
	return new carne(tipo, id, c);
}
