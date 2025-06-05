#include "fabricaPlanta.h"

elemento* fabricaPlanta::crearElemento(char tipo, string id, coordenada c) {
	return new planta(tipo, id, c);
}
