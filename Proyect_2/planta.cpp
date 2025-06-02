#include "planta.h"

planta::planta(string id,coordenada p) : recurso(id,"P",p) {}
planta::~planta() {}

string planta::toString() {
	stringstream s;
	s << recurso::toString();
	return s.str();
}