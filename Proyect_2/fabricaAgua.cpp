#include "fabricaAgua.h"


elemento* fabricaAgua::crearElemento(char tipo, string id, coordenada c) {
	return new agua(tipo, id, c);
}
